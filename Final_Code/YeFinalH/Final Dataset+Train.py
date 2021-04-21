import cv2, os
import numpy as np
cam = cv2.VideoCapture(0)
detector=cv2.CascadeClassifier('C:\\Users\\DELL\\face_model\\xml\\frontal_face.xml')
Id=input('enter your id: ')
sampleNum=0
os.mkdir("people/"+Id.lower())
while(True):
    ret, img = cam.read()
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    image= np.array(gray, 'uint8')
    faces = detector.detectMultiScale(gray, 1.3, 5)
    
    for (x,y,w,h) in faces:
        cv2.rectangle(img,(x,y),(x+w,y+h),(255,0,0),2)
        
        #incrementing sample number 
        sampleNum=sampleNum+1
        #saving the captured face in the dataset folder
        #cv2.imwrite()
        cv2.imwrite("people/"+Id.lower() + '/' + str(sampleNum) + ".jpg", image[y:y+h,x:x+w]) #

        cv2.imshow('frame',img)
    #wait for 100 miliseconds 
    if cv2.waitKey(100) & 0xFF == ord('q'):
        break
    # break if the sample number is morethan 20
    elif sampleNum>20:
        break
cam.release()    
cv2.destroyAllWindows()
cam.release()
def collect_dataset():
    images = []
    labels = []
    labels_dic = {}
    size=(47,62)
    #people = [person for person in os.listdir("Male_female/")]
    people = [person for person in os.listdir("people/")]
    #people = [person for person in os.listdir("people/")]
    for i, person in enumerate(people):
        labels_dic[i] = person
        for image in os.listdir("people/" + person):
            if image.endswith('.jpg'):
                img=cv2.imread("people/" + person + '/' + image, 0)
                images.append(cv2.resize(img, size)) 
                labels.append(i)
    return (images, np.array(labels), labels_dic)
images, labels, labels_dic = collect_dataset()
print (len(images))
print (labels_dic)
X_train=np.asarray(images)
Y_train=labels
X_train.shape
Y_train.shape
train=X_train.reshape(len(X_train),-1)
from sklearn.decomposition import PCA
import matplotlib.pyplot as plt
pca1 = PCA()
pca1.fit(train)
plt.plot(np.cumsum(pca1.explained_variance_ratio_))
plt.xlabel('number of components')
plt.ylabel('cumulative explained variance')
plt.show()
pca1 = PCA()
def test_dataset():
    images = []
    labels = []
    labels_dic = {}
    size=(47,62)
    #people = [person for person in os.listdir("Male_female/")]
    people = [person for person in os.listdir("people/")]
    #people = [person for person in os.listdir("people/")]
    for i, person in enumerate(people):
        labels_dic[i] = person
        for image in os.listdir("people/" + person):
            if image.endswith('.jpg'):
                img=cv2.imread("people/" + person + '/' + image, 0)
                images.append(cv2.resize(img, size)) 
                labels.append(i)
    return (images, np.array(labels), labels_dic)
images, labels, labels_dic = test_dataset()
len(images)
labels_dic
X_test= np.asarray(images)
X_test.shape
test=X_test.reshape(len(X_test),-1)
test.shape
Y_test=labels
Y_test.shape
np.unique(Y_test)
from sklearn.preprocessing import StandardScaler
sc= StandardScaler()
X_ntrain=sc.fit_transform(train)
X_ntest= sc.transform(test)
pca1.n_components
new_train=pca1.fit_transform(X_ntrain)
new_train.shape
from sklearn.svm import SVC
svm= SVC(kernel='linear', probability=True)
svm.fit(new_train,Y_train)
svm.score(pca1.transform(X_ntest), Y_test)
pred=svm.predict(pca1.transform(X_ntest))
from sklearn.metrics import accuracy_score
accuracy_score(Y_test,pred)
import pickle

filename = 'svc_face.pkl'
f=open(filename, 'wb')
pickle.dump(svm,f)

f.close()
filename = 'pca_face.pkl'
f=open(filename, 'wb')
pickle.dump(pca1,f)
 

f.close()
filename = 'sc_face.pkl'
f=open(filename, 'wb')
pickle.dump(sc,f)
 

f.close()
filename='labels.pkl'
f=open(filename,'wb')
pickle.dump(labels_dic,f)
f.close()
