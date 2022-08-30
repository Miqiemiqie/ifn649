int led2 = 9;
int led = 12; 
int beep = 15;
const int soilPin = 16;
const int lightPin = 17;

void setup() {
  pinMode(led, OUTPUT); // pinmode：数据的流入流出
  pinMode(beep, OUTPUT);
  pinMode(soilPin, INPUT);
  pinMode(lightPin, INPUT);
  pinMode(led2,OUTPUT);
  
  Serial.begin(9600); //begin 设置波特率
  Serial1.begin(9600); // Bluetooth module
}

//rx：receive msg
// tx: translate msg

void loop() {
  int val = analogRead(soilPin); //ana: 电压->数字 0～1024
  int light = analogRead(lightPin);
  
  Serial.print("Soil : ");
  Serial.print(val);Serial.print(" "); Serial.print("lightPin : "); Serial.println(light);//println：换行
  Serial1.print("Soil : ");
  Serial1.print(val);Serial.print(" "); Serial1.print("lightPin : "); Serial1.println(light);
  
  if(Serial1.available()){ //如果蓝牙有数据执行下面操作
        String myString;
        //myString = Serial1.readStringUntil('\n');
        myString = Serial1.readString();
        Serial.println("    ");
        Serial.println(myString);
        Serial.println("    ");
        //if(myString=="LED-ON\n"){
          //delay(200);
          digitalWrite(led2,HIGH);
          //delay(200);
        //}//open LED
        //if(myString=="LED-OFF"){
        //}
  }else
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
  //analogWrite：模拟量的输出
  delay(1000);
 
}
