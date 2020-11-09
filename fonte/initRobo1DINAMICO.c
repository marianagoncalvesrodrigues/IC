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
  pinMode(LED_BUILTIN, OUTPUT); //definindo pino como saida
  digitalWrite (LED_BUILTIN, HIGH); //teste para ver se o led acende
  
}

void iniciar(char *comando){ //função que le o vetor comandos vindo do loop
  int tamanho = strlen(comando); //tamanho dinamico do vetor comando  
  for(int x=0; x<tamanho; x++){ //para ler o vetor
    if(comando[x] == 'f'){ //se le 'f' chama a função frente() 
      frente(); //pisca o led duas vezes
      Serial.println("andando para frente");
    }
    if(comando[x] == 'e'){
      esquerda();
      Serial.println("andando para esquerda");
    }
    if(comando[x] == 'd'){
      direita();
      Serial.println("andando para direita");
    }
  }  
}

void loop(){
  if(SerialBT.available()){ //verifica se recebe algum dado via bluetooth
    char *comandos = NULL; 
    char data;
    int x = 1;

    data = SerialBT.read(); //data recebe o dado do bluetooth
    
    while(x<15 && data != 'i'){ //x<15 pois o tamanho do vetor é 15
       if(data == 'f' || data == 'e' || data == 'd'){
        Serial.println("alocando..");
        comandos = (char*) realloc (comandos, x * sizeof(char)); // para alocar dinamicamente
        if (comandos == NULL){
          free(comandos);
          exit(1);
        }

        comandos[x-1] = data; //guarda o comando recebido do bluetooth no espaço [x-1] do vetor
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
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("frente ok!");
}
void esquerda(){
  digitalWrite(LED_BUILTIN, HIGH);
  delay(3000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(3000);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(3000);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("esquerda ok!");
}
void direita(){
  digitalWrite(LED_BUILTIN, HIGH);
  delay(5000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(5000);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(5000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(5000);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(5000);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("direita ok!");
}
