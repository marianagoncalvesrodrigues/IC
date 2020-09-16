#include <BluetoothSerial.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;


void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

int sensorPin = 13;
int sensorValue;
 
void setup()
{
  Serial.begin(115200); // starts the serial port at 9600
}
 
void loop()
{
  if(SerialBT.available()){
   sensorValue = analogRead(sensorPin); // read analog input pin 0
   SerialBT.write(sensorValue); 
   Serial.print(sensorValue, DEC); // prints the value read
   Serial.print(" \n"); // prints a space between the numbers
   delay(1000); // wait 100ms for next reading
  }
