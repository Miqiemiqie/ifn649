int led2 = 9;
int led = 12; 
int beep = 15;
const int soilPin = 16;
const int lightPin = 17;

void setup() {
  pinMode(led, OUTPUT); 
  pinMode(beep, OUTPUT);
  pinMode(soilPin, INPUT);
  pinMode(lightPin, INPUT);
  pinMode(led2,OUTPUT);
  
  Serial.begin(9600);
  Serial1.begin(9600); // Bluetooth module
}

//rx：receive msg
// tx: translate msg

void loop() {
  int val = analogRead(soilPin); 
  int light = analogRead(lightPin);
  
  Serial.print("Soil : ");
  Serial.print(val);Serial.print(" "); Serial.print("lightPin : "); Serial.println(light);
  Serial1.print("Soil : ");
  Serial1.print(val);Serial.print(" "); Serial1.print("lightPin : "); Serial1.println(light);
  
  if(Serial1.available()){ //if bluetooth works, continue the following 
        String myString;
        myString = Serial1.readString();
        Serial.println("    ");
        Serial.println(myString);
        Serial.println("    ");
        digitalWrite(led2,HIGH);
  }
  else
  {
    digitalWrite(led2,LOW);
  }
  
  if(val>100)  {
    analogWrite(beep, 200);
  }else 
  {
    analogWrite(beep, 0);
  }
  
  if(light<200)  {
    analogWrite(led, 200); 
  }
  else {
  analogWrite(led, 0);
  }
  delay(100);
  delay(1000);
 
}
