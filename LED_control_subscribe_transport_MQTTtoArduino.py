import time
import serial
import string
import paho.mqtt.publish as publish
import paho.mqtt.client as mqtt

ser = serial.Serial("/dev/rfcomm0",9600)

def on_connect(client, userdata, flags, rc):
    print("Connected to MQTT")
    client.subscribe("ledControl")
def on_message(client, userdata, msg):
    print(str(msg.payload))
    ser.write(str.encode(str(msg.payload)))

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

client.connect("65.0.3.38",1883,60)
client.loop_forever()

