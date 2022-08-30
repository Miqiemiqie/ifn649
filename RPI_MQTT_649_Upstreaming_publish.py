import serial
import time
import string
import paho.mqtt.publish as publish

ser = serial.Serial("/dev/rfcomm0",9600)

while True:
    if ser.in_waiting > 0:
        rawserial = ser.readline()
        cookedserial = rawserial.decode('utf-8').strip('\r\n')
        publish.single("ifn649",cookedserial, hostname="65.0.3.38")
        print(cookedserial)