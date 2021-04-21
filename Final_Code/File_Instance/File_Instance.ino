#include <SPI.h>
#include <SD.h>

File myfile;    //This creates a file instance

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");

  if (SD.exists("test.txt")) {                 // Testing whether the file name mentioned exists or not
    Serial.println("test.txt exists.");
  } else {
    Serial.println("test.txt doesn't exist.");
  }




    // Open the file for reading:
  myFile = SD.open("test.txt");
  if (myFile) {
    Serial.println("test.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }

  
}

void loop() {
  // nothing happens after setup finishes.
}


