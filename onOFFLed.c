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

void loop() {
  if (Serial.available()) {
    char data = Serial.read();    
    if (data == 'a'){
      
      digitalWrite(LED_BUILTIN, HIGH);  
    }
    else if(data == 'b'){
      digitalWrite(LED_BUILTIN, LOW);
    }
  }
  delay(20);
}
