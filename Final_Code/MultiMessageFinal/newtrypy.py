import serial
import time

arduino = serial.Serial('COM14',9600,timeout = 1)
time.sleep(2)

i = 0

while(i<1):
  arduino.flush()
  text_file = open("text.txt","r")
  line1 = text_file.readline() 
  arduino.write(line1)
  #time.sleep(1)
  i = i + 1
  #time.sleep(.5)
  print line1
  #exit()
text_file.close()

