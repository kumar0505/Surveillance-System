#include <SoftwareSerial.h>

SoftwareSerial gsm(2,3);
int counter = 0;
String msg1;

void setup() {
  gsm.begin(9600);
  Serial.begin(9600);
  delay(100);
}

void loop() {
  while (!Serial.available()) {} // wait for data to arrive
  // serial read section
  while (Serial.available()) {
    
    if(Serial.available()>0) {
      
      msg1 = Serial.readStringUntil('\n');
      Serial.println("Serial data available");
        Serial.println("Storing in String");

      if(counter<1) {
        SendMessage();
          Serial.println("Done Sending Message");

        counter++;
      }
    }
    delay(500);
  }
  //if (mySerial.available()>0) Serial.write(mySerial.read());
}


void SendMessage() {
   delay(100);
  Serial.begin(9600);
  gsm.begin(9600);
  gsm.println("AT+CMGF=1");
  //Sets the GSM Module in Text Mode
  delay(1000);
  gsm.println("AT+CMGS=\"+919162886660\"\r");
  delay(1000);
  // gsm.println("AT+CMGS=\"+917988198580\"\r");
  //delay(1000);
   //gsm.println("AT+CMGS=\"+919468221657\"\r");
  //delay(1000);
  // Delay of 1000 milli seconds or 1 second
  gsm.println(msg1);
  // Replace x with mobile number
  delay(1000);
  //gsm.println("Hello");
  // The SMS text you want to send
  Serial.println("In GSM");
  delay(100);
  gsm.println((char)26);
  // ASCII code of CTRL+Z
  delay(1000);
    //Serial.print(numb);
    Serial.println(msg1);
}


