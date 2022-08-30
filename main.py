import time

import paho.mqtt.publish as publish

Soil = 0
lightPin = 0

publish.single("ledControl", "LED-ON", hostname="65.0.3.38")

print("Done")
time.sleep(1)
dsadsasa