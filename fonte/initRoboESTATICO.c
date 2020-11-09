#include <BluetoothSerial.h>
#include <string.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#define int tempo = 3000;

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
  int tamanho = 15; //tamanho estático do vetor comando  
  for(int x=0; x<tamanho; x++){ //para ler o vetor
    if(comando[x] == 'f'){ //se le 'f' chama a função frente() 
      frente(); //pisca o led 1x
      Serial.println("andando para frente");
    }
    if(comando[x] == 'e'){//se ler 'e' chama a função esuqerda
      esquerda();//pisca o led 2x
      Serial.println("andando para esquerda");
    }
    if(comando[x] == 'd'){//se ler 'd' chama a função direita
      direita();//pisca o led 3x
      Serial.println("andando para direita");
    }
  }  
}


    
void loop(){
  if(SerialBT.available()){ //verifica se recebe algum dado via bluetooth
    char comandos[15]; 
    char data;
    int x = 0;

    data = SerialBT.read(); //data recebe o dado do bluetooth
    
    while(x<15 && data != 'i'){ //x<15 pois o tamanho do vetor é 15
       if(data == 'f' || data == 'e' || data == 'd'){
        comandos[x] = data;
        data = SerialBT.read();
        x++;
       }else{
        data = SerialBT.read();
       }
    }
    Serial.println(data);
    iniciar(comandos);
  } 
      iniciar(comandos);//chama inciar
 }


void frente(){
  digitalWrite(LED_BUILTIN, HIGH);
  delay(tempo);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("frente ok!");
}
void esquerda(){
  digitalWrite(LED_BUILTIN, HIGH);
  delay(tempo);
  digitalWrite(LED_BUILTIN, LOW);
  delay(tempo);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(tempo);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("esquerda ok!");
}
void direita(){
  digitalWrite(LED_BUILTIN, HIGH);
  delay(tempo);
  digitalWrite(LED_BUILTIN, LOW);
  delay(tempo);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(tempo);
  digitalWrite(LED_BUILTIN, LOW);
  delay(tempo);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(tempo);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("direita ok!");
}
