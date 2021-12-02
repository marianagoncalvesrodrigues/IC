#include <SoftwareSerial.h>
 
SoftwareSerial bluetooth(10, 11); // RX, TX do Arduino
String command = "";
char b1;
   
void setup()  
{  
  Serial.begin(9600);  
  Serial.println("Digite algo para enviar por bluetooth:");  //Printa uma frase no monitor serial para saber que está tudo pronto
  bluetooth.begin(9600);  
}  
   
void loop()  
{  
  // Lê os dados do serial do Arduino e envia por Bluetooth
  if (Serial.available()>0) {  // Se existem dados para leitura
    delay(10);
    bluetooth.write(Serial.read());  
  }  
 
  // Lê os dados do bluetooth
  if (bluetooth.available()>0) { // Se existem dados para leitura
   
    b1 = bluetooth.read(); //Variável para armazenar o dado atual
    command += b1; //Variável para armazenar todos os dados
   
    if (b1 == '\n'){ //Se o dado atual for um pulador de linha (\n)
      Serial.print(command); //Printa o comando
      command = ""; //Limpa o comando para futuras leituras
    }
  }
}
