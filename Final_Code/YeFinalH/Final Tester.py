import cv2, os
import numpy as np
cam = cv2.VideoCapture(0)
detector=cv2.CascadeClassifier('C:\\Users\\DELL\\face_model\\xml\\frontal_face.xml')
import pickle
filename = 'svc_face.pkl'
svm = pickle.load(open(filename, 'rb'))
filename1 = 'pca_face.pkl'
pca1 = pickle.load(open(filename1, 'rb'))
filename2 = 'sc_face.pkl'
sc = pickle.load(open(filename2, 'rb'))
filename3= 'labels.pkl'
label = pickle.load(open(filename3, 'rb'))
q=1
while(q):
    ret, img = cam.read()
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    image= np.array(gray, 'uint8')
    faces = detector.detectMultiScale(gray, 1.3, 5)
    
    for (x,y,w,h) in faces:
        cv2.rectangle(img,(x,y),(x+w,y+h),(255,0,0),2)
        
        #incrementing sample number 
        #sampleNum=sampleNum+1
        #saving the captured face in the dataset folder
        
        cv2.imwrite("current.jpg", image[y:y+h,x:x+w]) #

        #cv2.imshow('frame',img)
        q=0

    #wait for 100 miliseconds 
   #if cv2.waitKey(100) & 0xFF == ord('q'):
        #break
    # break if the sample number is morethan 20
    #elif sampleNum>20:
        #break#
cam.release()
img=cv2.imread("current.jpg", 0)
size=(47,62)
image=[]
image.append(cv2.resize(img, size))
test=np.asarray(image)
test.shape
t=test.reshape(len(test),-1)
t.shape
pred=svm.predict(pca1.transform(sc.transform(t)))
pred
pred[0]
pred.astype(str)
filename= "result.txt"
f=open(filename, "w")
f.write(pred[0].astype(str))
f.close()
"""
import serial
import time

arduino = serial.Serial('COM14',9600,timeout = 1)
time.sleep(2)

i = 0

while(i<1):
  arduino.flush()
  #text_file = open("result.txt","r")
  #line1 = text_file.readline() 
  arduino.write(pred.astype(str)) #replaced variable 'line1'
  time.sleep(1)
  i = i + 1
  time.sleep(.5)
  #print line1
  #exit()
#text_file.close()
"""
