#include <SD.h>
#include <SPI.h>

#include<SoftwareSerial.h>
SoftwareSerial gsm(2,3);
String textForSMS;
String message;
 //String message[100];
  int i=0;
  File *file_in;
  file_in = fopen("text.txt", "r");
  /*stores and prints the data from the string*/
  fscanf(file_in,"%s", message);
  textForSMS = message;
  sendSMS(textForSMS);
  delay(1000);
String messaged;

void setup()
{
  delay(100);
  Serial.begin(9600);
  gsm.begin(9600);
  //pinMode(message, INPUT);
  gsm.println("AT+CMGF=1");
  delay(1000);
  //gsm.println("AT+CMGS=\"+919491357924\"\r");
  //delay(1000);
  //gsm.println("Hello");
  //delay(100);
  //gsm.println((char)26);
  //delay(1000); 
}
void sendSMS(String messaged)
{
   delay(100);
  Serial.begin(9600);
  gsm.begin(9600);
  gsm.println("AT+CMGF=1");
  delay(1000);
  gsm.println("AT+CMGS=\"+919162886660\"\r");
  delay(1000);
  gsm.println(messaged);
  delay(100);
  gsm.println((char)26);
  delay(1000); 
}
void loop()
{
  //if(gsm.available()==)
 
}

