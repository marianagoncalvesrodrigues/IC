// include library to read and write from flash memory
#include <EEPROM.h>

#define EEPROM_SIZE 10
#define EEPROM_END 5

int dado=0;//começar a leitura no endereço 0

void setup() { 
  Serial.begin(115200);
  EEPROM.begin(EEPROM_SIZE);
}

void loop() {
  if(Serial.available()){
    char data= Serial.read();
    if(data=='w'){
      Serial.println("escrevendo dado 7 no end 5");
      EEPROM.write(EEPROM_END, 7);
      EEPROM.commit();
    }
    if(data=='r'){
      dado = EEPROM.read(EEPROM_END);
      Serial.print("dado lido: ");
      Serial.println(dado);
    }
    
  }

  delay(4000);  
}
