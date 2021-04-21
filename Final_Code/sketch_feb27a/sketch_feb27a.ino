#include <stdio.h>
//#include <stdlib.h> // For exit() function
#include<SoftwareSerial.h>
SoftwareSerial gsm(2,3);

int main()
{
  char c[1000];
    FILE *fptr;
    fptr = fopen("text.txt", "r");
    //if (fptr == NULL)
    //{
      //  printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        //exit(1);         
    //}

    // reads text until newline 
    fscanf(fptr,"%[^\n]", c);
    fclose(fptr);
}
void setup()
{
    
    delay(100);
    Serial.begin(9600);
    gsm.begin(9600);
    gsm.println("AT+CMGF=1");
    delay(1000);
    gsm.println("AT+CMGS=\"+919491357924\"\r");
    delay(1000);
    gsm.println(c);
    delay(100);
    gsm.println((char)26);
    delay(1000);
    
    //return 0;
}


void loop()
{
  
}






