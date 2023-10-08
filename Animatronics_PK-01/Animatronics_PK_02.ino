#include <Servo.h>

int ArmLeft = 512;
int ArmRight = 512;
int ForearmLeft = 512;
int ForearmRight = 512;
int Body = 512;
int Headx = 512;
int Heady = 512;


float ArmLeft_Scaled;
float ArmRight_Scaled;
float ForearmLeft_Scaled;
float ForearmRight_Scaled;
float Body_Scaled;
float Headx_Scaled;
float Heady_Scaled;


float ArmLeft_Smoothed = 512;
float ArmRight_Smoothed = 512;
float ForearmLeft_Smoothed = 512;
float ForearmRight_Smoothed = 512;
float Body_Smoothed = 512;
float Headx_Smoothed = 512;
float Heady_Smoothed = 512;


float ArmLeft_SmoothedPrev = 512;
float ArmRight_SmoothedPrev = 512;
float ForearmLeft_SmoothedPrev = 512;
float ForearmRight_SmoothedPrev = 512;
float Body_SmoothedPrev = 512;
float Headx_SmoothedPrev = 512;
float Heady_SmoothedPrev = 512;


unsigned long currentMillis;
long previousMillis = 0;    // set up timers
long interval = 5;        // time constant for timer

int stepFlag = 0;
long previousStepMillis = 0;

Servo ArmLeft_Servo;
Servo ArmRight_Servo;
Servo ForearmLeft_Servo;
Servo ForearmRight_Servo;
Servo Body_Servo;
Servo Headx_Servo;
Servo Heady_Servo;



void setup() {

  Serial.begin(115200);

  ArmLeft_Servo.attach(4);
  ArmRight_Servo.attach(5);
  ForearmLeft_Servo.attach(6);
  ForearmRight_Servo.attach(7);
  Body_Servo.attach(8);
  Headx_Servo.attach(9);
  Heady_Servo.attach(10);


 // ArmLeft_Servo.writeMicroseconds(2000);
 // ArmRight_Servo.writeMicroseconds(1000);
 // ForearmLeft_Servo.writeMicroseconds(1000);
 // ForearmRight_Servo.writeMicroseconds(2000);
 // Body_Servo.writeMicroseconds(1500);
 // Headx_Servo.writeMicroseconds(1500);
 // Heady_Servo.writeMicroseconds(1500);



}


void FirstAllUp(){
 ArmLeft = 512;
 ArmRight = 1024;
 ForearmLeft = 1024;
 ForearmRight = 512;
}
void AllDown(){
  ArmLeft = 0;
  ArmRight = 1024;
  ForearmLeft = 1024;
  ForearmRight = 0;
}
void AllUp(){
  ArmLeft = 1024;
  ArmRight = 0;
  ForearmLeft = 0;
  ForearmRight = 1024;
}
void WaveDown(){
  ArmLeft = 0;
  ForearmLeft = 1024;
}
void WaveUp(){
  ArmLeft = 1024;
  ForearmLeft = 0;
}


void BodyToRight(){
 Body = 100;
}
void BodyToLeft(){
 Body = 800;
}
void BodyCenter(){
 Body = 512;
}


void HeadCenter(){
 Headx = 512;
 Heady = 512;
}
void HeadUpLeft(){
 Headx = 1024;
 Heady = 800;
}
void HeadUpRight(){
 Headx = 0;
 Heady = 800;
}

void loop() {

  currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {  // start 5ms timed loop  
      previousMillis = currentMillis;

      // step sequencer

      if (stepFlag == 0 && currentMillis - previousStepMillis > 500) {
      //---------------------------------------------------------------
      //InsertMovement(1st Sequence)
      FirstAllUp();
      HeadCenter();
      
      

      //---------------------------------------------------------------
        stepFlag = 1;           
        previousStepMillis = currentMillis;
      }

      else if (stepFlag == 1 && currentMillis - previousStepMillis > 1000) {
      //---------------------------------------------------------------
      //InsertMovement(2nd Sequence)
      HeadCenter();
      AllUp();
      
      
      
      //---------------------------------------------------------------       
        stepFlag = 2;           
        previousStepMillis = currentMillis;
      }

      else if (stepFlag == 2 && currentMillis - previousStepMillis > 1500) {
      //---------------------------------------------------------------
      //InsertMovement(3rd Sequence)
      AllDown();
      

      //---------------------------------------------------------------
        stepFlag = 3;           
        previousStepMillis = currentMillis;
      }

      if (stepFlag == 3 && currentMillis - previousStepMillis > 1500) {
      //---------------------------------------------------------------
      //InsertMovement(4th Sequence)
      WaveUp();
      BodyToLeft();
      

      //---------------------------------------------------------------
        stepFlag = 4;           
        previousStepMillis = currentMillis;
      }

      if (stepFlag == 4 && currentMillis - previousStepMillis > 1500) {
      //---------------------------------------------------------------
      //InsertMovement(5th Sequence)
      WaveDown();
      BodyCenter();
      

      //---------------------------------------------------------------
        stepFlag = 5;           
        previousStepMillis = currentMillis;
      }

      if (stepFlag == 5 && currentMillis - previousStepMillis > 1500) {
      //---------------------------------------------------------------
      //InsertMovement(6th Sequence)
      HeadUpLeft();

      //---------------------------------------------------------------
        stepFlag = 6;           
        previousStepMillis = currentMillis;
      }

     if (stepFlag == 6 && currentMillis - previousStepMillis > 1500) {
      //---------------------------------------------------------------
      //InsertMovement(6th Sequence)
      HeadUpRight();

      //---------------------------------------------------------------
        stepFlag = 7;           
        previousStepMillis = currentMillis;
      }

     if (stepFlag == 7 && currentMillis - previousStepMillis > 1500) {
      //---------------------------------------------------------------
      //InsertMovement(6th Sequence)
      HeadCenter();

      //---------------------------------------------------------------
        stepFlag = 1;           
        previousStepMillis = currentMillis;
      }


      // end of step sequencer

      
    
      // scale all pots for the servo microseconds range
    
      ArmLeft_Scaled = ((ArmLeft - 512) * -1.6) + 1200;
      ArmRight_Scaled = ((ArmRight - 512) * -1.6) + 1200;
      ForearmLeft_Scaled = ((ForearmLeft - 512) * -1.6) + 1200;
      ForearmRight_Scaled = ((ForearmRight - 512) * -1.6) + 1200;
      Body_Scaled = (Body - 512) + 1500;
      Headx_Scaled = (Headx - 512) + 1500;
      Heady_Scaled = (Heady - 512) + 1500;


    
      // smooth pots
      
      ArmLeft_Smoothed = (ArmLeft_Scaled * 0.01) + (ArmLeft_SmoothedPrev * 0.99);
      ArmRight_Smoothed = (ArmRight_Scaled * 0.01) + (ArmRight_SmoothedPrev * 0.99);
      ForearmLeft_Smoothed = (ForearmLeft_Scaled * 0.01) + (ForearmLeft_SmoothedPrev * 0.99);
      ForearmRight_Smoothed = (ForearmRight_Scaled * 0.01) + (ForearmRight_SmoothedPrev * 0.99);
      Body_Smoothed = (Body_Scaled * 0.01) + (Body_SmoothedPrev * 0.99);
      Headx_Smoothed = (Headx_Scaled * 0.01) + (Headx_SmoothedPrev * 0.99);
      Heady_Smoothed = (Heady_Scaled * 0.01) + (Heady_SmoothedPrev * 0.99);


  
    
      // bookmark previous values
    
      ArmLeft_SmoothedPrev = ArmLeft_Smoothed;
      ArmRight_SmoothedPrev = ArmRight_Smoothed;
      ForearmLeft_SmoothedPrev = ForearmLeft_Smoothed;
      ForearmRight_SmoothedPrev = ForearmRight_Smoothed;
      Body_SmoothedPrev = Body_Smoothed;
      Headx_SmoothedPrev = Headx_Smoothed;
      Heady_SmoothedPrev = Heady_Smoothed;

  

      // write servos

      ArmLeft_Servo.writeMicroseconds(ArmLeft_Smoothed);      
      ArmRight_Servo.writeMicroseconds(ArmRight_Smoothed);     
      ForearmLeft_Servo.writeMicroseconds(ForearmLeft_Smoothed);     
      ForearmRight_Servo.writeMicroseconds(ForearmRight_Smoothed);         
      Body_Servo.writeMicroseconds(Body_Smoothed);  
      Headx_Servo.writeMicroseconds(Headx_Smoothed);  
      Heady_Servo.writeMicroseconds(Heady_Smoothed);  


  } // end of timed loop


} // end if main loop