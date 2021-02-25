#include <BluetoothSerial.h>
#include <string.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#define TEMPO 1000

BluetoothSerial SerialBT;
int LED_BUILTIN = 2;
int esquerdavar = 102;
int direitavar = 101;
int frentevar = 100;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  pinMode(LED_BUILTIN, OUTPUT); //definindo pino como saida
  digitalWrite (LED_BUILTIN, HIGH); //teste para ver se o led acende
 
}

void iniciarComandos(char comando[15]){ //função que le o vetor comandos vindo do loop
  int tamanho = 15; //tamanho estático do vetor comando  
  int z =1;
  for(int x=0; x<tamanho; x++){ //para ler o vetor
    if(comando[x] == 'f'){ //se le 'f' chama a função frente()
      frente(z); //pisca o led 1x
      Serial.println("andando para frente");
      z++;
    }
    if(comando[x] == 'e'){//se ler 'e' chama a função esuqerda
      esquerda(z);//pisca o led 2x
      Serial.println("andando para esquerda");
      z++;
    }
    if(comando[x] == 'd'){//se ler 'd' chama a função direita
      direita(z);//pisca o led 3x
      Serial.println("andando para direita");
      z++;
    }
  }  
}


   
void loop(){
  if(SerialBT.available()){ //verifica se recebe algum dado via bluetooth
    int x = 0;
    char comandos[15];
    char data;

    data = SerialBT.read(); //data recebe o dado do bluetooth
   
    while(x<15 && data != 'i'){ //x<15 pois o tamanho do vetor é 15
       if(data == 'f' || data == 'e' || data == 'd'){
        comandos[x] = data;
       
        x++;
        data = SerialBT.read();
       }else{
        data = SerialBT.read();
       }
    }
    iniciarComandos(comandos);
    }
 }

int frente(int z){
  SerialBT.write(frentevar);
  SerialBT.write(z);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(TEMPO);
  digitalWrite(LED_BUILTIN, LOW);
  delay(TEMPO);
  Serial.println("frente ok!");
}
int esquerda(int z){
  SerialBT.write(esquerdavar);
  SerialBT.write(z);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(TEMPO);
  digitalWrite(LED_BUILTIN, LOW);
  delay(TEMPO);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(TEMPO);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("esquerda ok!");
}
int direita(int z){
  Serial.println(direitavar);
  Serial.println(z);
  SerialBT.write(direitavar);
  SerialBT.write(z);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(TEMPO);
  digitalWrite(LED_BUILTIN, LOW);
  delay(TEMPO);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(TEMPO);
  digitalWrite(LED_BUILTIN, LOW);
  delay(TEMPO);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(TEMPO);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("direita ok!");
}
