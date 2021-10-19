#include <ESP8266WiFi.h>                                               
#include <FirebaseArduino.h>                                        
 
#define FIREBASE_HOST "projete2021-217c6-default-rtdb.firebaseio.com" //Link do firebase
#define FIREBASE_AUTH "W8HYca18p0xnaZaDZyVEgegXZJYZTECq9O0yhhIX" //Chave de acesso ao firebase
#define WIFI_SSID "Ar******" //Nome do wifi
#define WIFI_PASSWORD "45******" //Senha do wifi                              
                                                     
int solenoid = 16;  //Solenoides declaradas nos pinos do esp (D0, D1, D2, D3)
int solenoid1 = 5;
int solenoid2 = 4;
int solenoid3 = 0;
String remedio1 = "";
String remedio2 = "";
String remedio3 = "";
String remedio4 = "";
                                                              
void setup() 
{                                                                             //
  Serial.begin(9600);                                                         //
  delay(1000);                                                                //
                                                                              //
  pinMode(solenoid, OUTPUT);                                                  //
  pinMode(solenoid1, OUTPUT);                                                 //
  pinMode(solenoid2, OUTPUT);                                                 //
  pinMode(solenoid3, OUTPUT);                                                 //
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                       //
  Serial.print("Connecting to ");                                             //
  Serial.print(WIFI_SSID);                                                    // Parte somente para a conexão do wifi
  while (WiFi.status() != WL_CONNECTED)                                       //
  {                                                                           //
    Serial.print(".");                                                        //
    delay(500);                                                               //
  }                                                                           //
  Serial.println();                                                           //
  Serial.print("Connected to ");                                              //
  Serial.println(WIFI_SSID);                                                  //
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);                               // 
}                                                                             //
                                                                              //     
void loop() 
{                                    
  remedio1 = Firebase.getString("remedio1");
  remedio2 = Firebase.getString("remedio2");
  remedio3 = Firebase.getString("remedio3");
  remedio4 = Firebase.getString("remedio4");
  
  if (med1 == "1")                                  //Caso o valor da linha "remedio1" dentro do firebase for 1, ativa a solenoide, 
                                                                            //permanece por 5 minutos ativada (300k ms)e dps desativa, e manda 0 pra linha dnv.
  
  {                                                         
    Serial.println("Solenoide 1");                                                        
    digitalWrite(solenoid, HIGH);
    delay(300000); 
    digitalWrite(solenoid, LOW);
    Firebase.setString("remedio1", "0");       
  }

  else if (remedio2 == "1")                            //O mesmo para todas as outras
  {                                                  
    Serial.println("Solenoide 2");
    digitalWrite(solenoid1, HIGH);
    delay(300000); 
    digitalWrite(solenoid1, LOW);
    Firebase.setString("remedio2", "0");       
    
  }
                                                            
   else if (remedio3 == "1") 
  {                                                 
    Serial.println("Solenoide 3");
    digitalWrite(solenoid2, HIGH);
    delay(300000); 
    digitalWrite(solenoid2, LOW);
    Firebase.setString("remedio3", "0");                                                       
  }
   else if (remedio4 == "1") 
  {                                                 
    Serial.println("Solenoide 4");
    digitalWrite(solenoid3, HIGH);
    delay(300000); 
    digitalWrite(solenoid3, LOW);
    Firebase.setString("remedio4", "0");                                                            
  }
  
  else 
  {
    Serial.println("Command Error! Please send 1");
  }
}
