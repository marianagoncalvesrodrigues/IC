#include <BluetoothSerial.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
int freq = 5000;
int ledChannel = 0; //canal em que vamos escrever a resolução
int resolution = 8; //resolução do "led"
int LED_BUILTIN = 2; //led onboard do esp32

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(LED_BUILTIN, ledChannel); //atribuir o canal no led
}

void loop(){
  
  if(SerialBT.available()){
    int valor = SerialBT.read(); //le um dado do app e manda pro esp
    ledcWrite(ledChannel, valor); //escreve o valor do slider no esp
    Serial.println("\n");
    Serial.println(valor);
  }
  delay(20);
}
