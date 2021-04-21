
#include <SPI.h>
#include <SD.h>
#include<SoftwareSerial.h>
SoftwareSerial gsm(2,3);

char message[10];
File myFile;

void setup() {
  // Open serial communications and wait for port to open:
  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH);
  
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.print("Initializing SD card...");

  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");

 
  // re-open the file for reading:
  myFile = SD.open("text.txt");
  if (myFile) {
    Serial.println("text.txt:");
  int i;
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      //Serial.write(myFile.read());
      //char message="";
      for(i=0;i<sizeof message;i++) 
      message[i]= myFile.read();
          Serial.println(message);
    }
    // close the file:
    myFile.close();
  } 

  else {
    // if the file didn't open, print an error:
    Serial.println("error opening text.txt");
  }
           
  Serial.println(message);
  Serial.println("GSM Initializing..");

  delay(100);
  Serial.begin(9600);
  gsm.begin(9600);
  gsm.println("AT+CMGF=1");
  delay(1000);
  gsm.println("AT+CMGS=\"+917013331288\"\r");
  delay(1000);
  //gsm.println("message");
  gsm.println(message);
  delay(100);
  gsm.println((char)26);
  delay(1000);
  Serial.println("GSM Done.....");

}

void loop() {
  // nothing happens after setup
}


