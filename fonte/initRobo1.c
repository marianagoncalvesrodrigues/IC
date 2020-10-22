#include <BluetoothSerial.h>

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

void iniciar(char comand){
  for(char comando[x]; x<15; x++){
    comando[x]= comand;
  }
  char data = SerialBT.read();
  if(data == i){
    for(comando[x]; x<15; x++){
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
  
}

void loop(){
  if(SerialBT.available()){
    for(char i[x]; x<15; x++){
      i[x]= SerialBT.read();
      iniciar(i[x]);
    }
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
