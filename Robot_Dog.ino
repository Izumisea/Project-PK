#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;


const int pinServo1 = 5;  // NodeMCU Pin D1
const int pinServo2 = 4;  // NodeMCU Pin D2
const int pinServo3 = 14; // NodeMCU Pin D5
const int pinServo4 = 12; // NodeMCU Pin D6
const int pinServo5 = 13; // NodeMCU Pin D7
const int pinServo6 = 2;  // NodeMCU Pin D4



void LeftUp(){
  servo1.write(90);
  servo2.write(0);
  servo3.write(90);
  servo4.write(180);
}

void RightUp(){
  servo1.write(180);
  servo2.write(90);
  servo3.write(0);
  servo4.write(90);
 
}

void Straight(){
  servo1.write(180);
  servo2.write(0);
  servo3.write(0);
  servo4.write(180);
}

void Down(){
  servo1.write(0);
  servo2.write(180);
  servo3.write(180);
  servo4.write(0);
}

void push(){
 servo5.write(180);
}
void back(){
 servo5.write(0);
}
void mid(){
 servo5.write(90);
}

void WalkF(){

  Straight();
  delay(1500);
  LeftUp();
  delay(1000);
  servo5.write(0);
  delay(1000);
  Straight();
  delay(1000);
  RightUp();
  delay(1000);
  servo5.write(180);
  delay(1000);
}


void setup() {
  Serial.begin(115200);

  servo1.attach(pinServo1);
  servo2.attach(pinServo2);
  servo3.attach(pinServo3);
  servo4.attach(pinServo4);
  servo5.attach(pinServo5);
  servo6.attach(pinServo6);
}

void loop() {

 WalkF();
}

/*
 Straight();
  delay(1500);
  LeftUp();
  delay(1500);
  Straight();
  delay(1500);
  RightUp();
  delay(1500);
*/
