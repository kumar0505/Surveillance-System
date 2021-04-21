//# Open a file
File fo = open("/mnt/sd/test.txt", "wb+")      //Writing wb+ instead of wb would give both read and write access.
fo.write( "Line 1\n");
fo.write( "Line 2\n");
fo.write( "Line 3\n");
fo.write( "Line 4\n");

//# Close opend file
fo.close()





 Read file until there's nothing else in it:

    while (myFile.available()) {
      Serial.write(myFile.read());             We can also write to a file instead of printing directly into the serial monitor
    }


SD.read() //to save the string into a variable
