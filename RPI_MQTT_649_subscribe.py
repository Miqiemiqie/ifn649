import paho.mqtt.client as mqtt
import paho.mqtt.publish as publish

def on_connect(client, userdata, flags, rc):
    print("Connected to MQTT")
    client.subscribe("ifn649")
def on_message(client, userdata, msg):
    print(msg.topic+""+str(msg.payload))
    publish.single("ledControl","LED-ON\n",hostname="65.0.3.38")

client = mqtt.Client()
client.on_message = on_message
client.on_connect = on_connect

client.connect("65.0.3.38",1883,60)

client.loop_forever()