#include <SoftwareSerial.h>
SoftwareSerial gsm(2,3);
int counter = 0;
String msg1;

void setup() 
{
  gsm.begin(9600);
  Serial.begin(9600);
  delay(100);
}

void loop() 
{
  while (!Serial.available()) {} 
  while (Serial.available()) 
  {
    if(Serial.available()>0) 
    { 
      msg1 = Serial.readStringUntil('\n');
      if(counter<1) 
      {
        SendMessage1();
            delay(2000);
        SendMessage2();
            delay(2000);
        SendMessage3();
            delay(2000);
        SendMessage4();
        counter++;
      }
    }
    //delay(500);
  }
}

void SendMessage1() 
{
  delay(100);
  Serial.begin(9600);
  gsm.begin(9600);
  gsm.println("AT+CMGF=1");
  delay(500);
  gsm.println("AT+CMGS=\"+917013331288\"\r");
  delay(500);
  gsm.println(msg1);
  //delay(1000);
  delay(100);
  gsm.println((char)26);
  delay(500);
}

void SendMessage2() 
{
  delay(100);
  Serial.begin(9600);
  gsm.begin(9600);
  gsm.println("AT+CMGF=1");
  delay(500);
  gsm.println("AT+CMGS=\"+918168022883\"\r");
  delay(500);
  gsm.println(msg1);
  //delay(1000);
  delay(100);
  gsm.println((char)26);
  delay(500);
}
void SendMessage3() 
{
  delay(100);
  Serial.begin(9600);
  gsm.begin(9600);
  gsm.println("AT+CMGF=1");
  delay(500);
  gsm.println("AT+CMGS=\"+917696230425\"\r");
  delay(500);
  gsm.println(msg1);
  //delay(1000);
  delay(100);
  gsm.println((char)26);
  delay(500);
}

void SendMessage4() 
{
  delay(100);
  Serial.begin(9600);
  gsm.begin(9600);
  gsm.println("AT+CMGF=1");
  delay(500);
  gsm.println("AT+CMGS=\"+919491357924\"\r");
  delay(500);
  gsm.println(msg1);
  //delay(1000);
  delay(100);
  gsm.println((char)26);
  delay(500);
}

