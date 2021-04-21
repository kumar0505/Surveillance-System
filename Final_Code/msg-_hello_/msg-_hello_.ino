#include<SoftwareSerial.h>
SoftwareSerial gsm(2,3);

String message = "Hello";

 char txtMsg[200];
  
void setup()
{
  delay(100);
  Serial.begin(9600);
  gsm.begin(9600);
  gsm.println("AT+CMGF=1");
  delay(1000);
  gsm.println("AT+CMGS=\"+919162886660\"\r");
  delay(1000);
  gsm.println(message);
  
  Serial.print("Now, enter SMS content: ");
  char txtMsg[20];
  readSerial(txtMsg);
  Serial.println(txtMsg);

  gsm.println(txtMsg);
  delay(100);
  gsm.println((char)26);
  delay(1000); 
}

int readSerial(char result[]) {
  int i = 0;
  while (1) {
    while (Serial.available() > 0) {
      char inChar = Serial.read();
      if (inChar == '\n') {
        result[i] = '\0';
        Serial.flush();
        return 0;
      }
      if (inChar != '\r') {
        result[i] = inChar;
        i++;
      }
    }
  }
}

void loop()
{
  
}

