#include <BluetoothSerial.h>
#include <string.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
int LED_BUILTIN = 2;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite (LED_BUILTIN, HIGH);
  
}

void iniciar(char *comando){
  int tamanho = strlen(comando);   
  for(int x=0; x<tamanho; x++){
    if(comando[x] == 'f'){
      frente();
    }
    if(comando[x] == 'e'){
      esquerda();
    }
    if(comando[x] == 'd'){
      direita();
    }
  }  
}

void loop(){
  if(SerialBT.available()){
    char *comandos = NULL;
    char data;
    int x = 1;

    data = SerialBT.read();
    
    while(x<15 && data != 'i'){
       if(data == 'f' || data == 'e' || data == 'd'){
        Serial.println("alocando..");
        comandos = (char*) realloc (comandos, x * sizeof(char));
        if (comandos == NULL){
          free(comandos);
          exit(1);
        }

        comandos[x-1] = data;
        Serial.println("alocado o valor:");
        Serial.println(data);

        data = SerialBT.read();
        x++;
       }else{
        data = SerialBT.read();
       }
    }
    Serial.println(data);
    iniciar(comandos);
  } 
}



void frente(){
  digitalWrite(LED_BUILTIN, HIGH);
  delay(2000);
  digitalWrite(LED_BUILTIN, LOW);
}
void esquerda(){
  digitalWrite(LED_BUILTIN, HIGH);
  delay(2000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(2000);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(2000);
  digitalWrite(LED_BUILTIN, LOW);
}
void direita(){
  digitalWrite(LED_BUILTIN, HIGH);
  delay(2000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(2000);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(2000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(2000);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(2000);
  digitalWrite(LED_BUILTIN, LOW);
}
