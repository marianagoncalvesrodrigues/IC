#include <BluetoothSerial.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
int freq = 5000;
int ledChannel = 0;
int resolution = 8;
int LED_BUILTIN = 2;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(LED_BUILTIN, ledChannel);
}

void loop(){
  
  if(SerialBT.available()){
    int valor = SerialBT.read();
    ledcWrite(ledChannel, valor);
    Serial.println("\n");
    Serial.println(valor);
  }
  delay(20);
}
