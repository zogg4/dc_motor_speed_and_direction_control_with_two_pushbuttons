int speedPin=5; //connected to pin 1 of L293D motor controller 
int direction1=4; //connected to pin 2 of L293D motor controller
int direction2=3; // connected to pin 7 of L293D motor controller
int motorSpeed=0;  //min=0 max=255
int buttonPin1=8;
int buttonPin2=9;
int buttonPin1Value;
int buttonPin2Value;
int delayTime=250; //0,25 sec

void setup() {

pinMode(speedPin,OUTPUT);
pinMode(direction1,OUTPUT);
pinMode(direction2,OUTPUT);
pinMode(buttonPin1,INPUT);
pinMode(buttonPin2,INPUT);
digitalWrite(buttonPin1,HIGH); 
digitalWrite(buttonPin2,HIGH);
Serial.begin(9600);

}

void loop() {

buttonPin1Value=digitalRead(buttonPin1);
buttonPin2Value=digitalRead(buttonPin2);
Serial.print("Motor Speed : ");
Serial.println(motorSpeed);

if (buttonPin1Value==0){
  motorSpeed=motorSpeed-10;
  delay(delayTime);
}
if (buttonPin2Value==0){
  motorSpeed=motorSpeed+10;
  delay(delayTime);
}
if (motorSpeed>255){
  motorSpeed=255;
}
if (motorSpeed<-255){
  motorSpeed=-255;
}
if (motorSpeed==10){
  motorSpeed=100;    //min ~100 for motor to start moving
}
if (motorSpeed==-10){
  motorSpeed=-100;
}
if (motorSpeed==90 || motorSpeed==95){
  motorSpeed=0;
}
if (motorSpeed==-90 || motorSpeed==-95){
  motorSpeed=0;
}
if (motorSpeed==0){
  analogWrite(speedPin,0);
}
if (motorSpeed>0){
  digitalWrite(direction1,LOW);
  digitalWrite(direction2,HIGH);
  analogWrite(speedPin,motorSpeed);
}
if (motorSpeed<0){
  digitalWrite(direction1,HIGH);
  digitalWrite(direction2,LOW);
  analogWrite(speedPin,abs(motorSpeed));
}

}
