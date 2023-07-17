import cv2
import mediapipe as mp
from hand_module import HandDetector
import serial.tools.list_ports
import time

ports = serial.tools.list_ports.comports()
serialInst = serial.Serial()
portsList = []
portVar = "COM3"
for onePort in ports:
    portsList.append(str(onePort))
    print(str(onePort))
val = input("Select Port:COM")

for x in range(0,len(portsList)):
    if portsList[x].startswith("COM" + str(val)):
        portVar = "COM3"
        print(portVar)
serialInst.baudrate= 38400
serialInst.port = portVar
serialInst.open()
handDetector = HandDetector()


cap = cv2.VideoCapture(0)

while True:
    success , img = cap.read()
    img= handDetector.find_hands(img)
    land_mark_list=handDetector.find_position(img,draw=False)
    #print(land_mark_list)
    fingers_up = handDetector.fingers_up()
    print(fingers_up)



    if fingers_up is not None:
        max_fingers_up_count= fingers_up.count(1)
        print(max_fingers_up_count)
        command = str(max_fingers_up_count)
        serialInst.write(command.encode('utf-8'))
       



        #cv2.putText(img , f'Fingers up:{str(max_fingers_up_count)}',(100,100),cv2.FONT_HERSHEY_COMPLEX,1,(0,255,255),2)


    #cv2.imshow('image',img)

    flipped = cv2.flip(img, 1)
    cv2.imshow("dd",flipped)
    if cv2.waitKey(2) & 0xff == ord('q'):
        exit()
        break
