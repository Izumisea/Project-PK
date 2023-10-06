#include <Servo.h>

int ArmLeft = 512;
int ArmRight = 512;
int ForearmLeft = 512;
int ForearmRight = 512;
int pot5 = 512;
int pot6 = 512;

float ArmLeft_Scaled;
float ArmRight_Scaled;
float ForearmLeft_Scaled;
float ForearmRight_Scaled;

float pot5Scaled;
float pot6Scaled;

float ArmLeft_Smoothed = 512;
float ArmRight_Smoothed = 512;
float ForearmLeft_Smoothed = 512;
float ForearmRight_Smoothed = 512;

float pot5Smoothed = 512;
float pot6Smoothed = 512;

float ArmLeft_SmoothedPrev = 512;
float ArmRight_SmoothedPrev = 512;
float ForearmLeft_SmoothedPrev = 512;
float ForearmRight_SmoothedPrev = 512;
float pot5SmoothedPrev = 512;
float pot6SmoothedPrev = 512;

unsigned long currentMillis;
long previousMillis = 0;    // set up timers
long interval = 5;        // time constant for timer

int stepFlag = 0;
long previousStepMillis = 0;

Servo ArmLeft_Servo;
Servo ArmRight_Servo;
Servo ForearmLeft_Servo;
Servo ForearmRight_Servo;

Servo servo6;
Servo servo7;

void setup() {

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);

  Serial.begin(115200);

  ArmLeft_Servo.attach(4);
  ArmRight_Servo.attach(5);
  ForearmLeft_Servo.attach(6);
  ForearmRight_Servo.attach(7);

  servo6.attach(8);
  servo7.attach(9);

  ArmLeft_Servo.writeMicroseconds(2000);
  ArmRight_Servo.writeMicroseconds(1000);
  ForearmLeft_Servo.writeMicroseconds(1000);
  ForearmRight_Servo.writeMicroseconds(2000);

  servo6.writeMicroseconds(1500);
  servo7.writeMicroseconds(1450);

}

void loop() {

  currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {  // start 5ms timed loop  
      previousMillis = currentMillis;

      // step sequencer

      if (stepFlag == 0 && currentMillis - previousStepMillis > 500) {
        ArmLeft = 512;
        ArmRight = 1024;
        ForearmLeft = 1024;
        ForearmRight = 512;
        stepFlag = 1;           
        previousStepMillis = currentMillis;
      }

      else if (stepFlag == 1 && currentMillis - previousStepMillis > 1000) {
       ArmLeft = 1024;
        ArmRight = 0;
        ForearmLeft = 0;
        ForearmRight = 1024;
        stepFlag = 2;           
        previousStepMillis = currentMillis;
      }

      else if (stepFlag == 2 && currentMillis - previousStepMillis > 1500) {
        ArmLeft = 0;
        ArmRight = 1024;
        ForearmLeft = 1024;
        ForearmRight = 0;
        stepFlag = 3;           
        previousStepMillis = currentMillis;
      }

      if (stepFlag == 3 && currentMillis - previousStepMillis > 1500) {
        ArmLeft = 1024;
        ArmRight = 0;
        ForearmLeft = 0;
        ForearmRight = 1024;

        stepFlag = 4;           
        previousStepMillis = currentMillis;
      }

      if (stepFlag == 4 && currentMillis - previousStepMillis > 1500) {
         ArmLeft = 0;
        ArmRight = 1024;
        ForearmLeft = 1024;
        ForearmRight = 0;

        stepFlag = 5;           
        previousStepMillis = currentMillis;
      }
      if (stepFlag == 5 && currentMillis - previousStepMillis > 1500) {
       ArmLeft = 1024;
        ArmRight = 0;
        ForearmLeft = 0;
        ForearmRight = 1024;


        stepFlag = 1;           
        previousStepMillis = currentMillis;
      }

      // end of step sequencer

      
    
      // scale all pots for the servo microseconds range
    
      ArmLeft_Scaled = ((ArmLeft - 512) * -1.6) + 1200;
      ArmRight_Scaled = ((ArmRight - 512) * -1.6) + 1200;
      ForearmLeft_Scaled = ((ForearmLeft - 512) * -1.6) + 1200;
      ForearmRight_Scaled = ((ForearmRight - 512) * -1.6) + 1200;
   
  
  
    
      // smooth pots
      
      ArmLeft_Smoothed = (ArmLeft_Scaled * 0.01) + (ArmLeft_SmoothedPrev * 0.99);
      ArmRight_Smoothed = (ArmRight_Scaled * 0.01) + (ArmRight_SmoothedPrev * 0.99);
      ForearmLeft_Smoothed = (ForearmLeft_Scaled * 0.01) + (ForearmLeft_SmoothedPrev * 0.99);
      ForearmRight_Smoothed = (ForearmRight_Scaled * 0.01) + (ForearmRight_SmoothedPrev * 0.99);
  
    
      // bookmark previous values
    
      ArmLeft_SmoothedPrev = ArmLeft_Smoothed;
      ArmRight_SmoothedPrev = ArmRight_Smoothed;
      ForearmLeft_SmoothedPrev = ForearmLeft_Smoothed;
      ForearmRight_SmoothedPrev = ForearmRight_Smoothed;
  
      pot5SmoothedPrev = pot5Smoothed;
      pot6SmoothedPrev = pot6Smoothed;
  

      // write servos

      ArmLeft_Servo.writeMicroseconds(ArmLeft_Smoothed);      
      ArmRight_Servo.writeMicroseconds(ArmRight_Smoothed);     
      ForearmLeft_Servo.writeMicroseconds(ForearmLeft_Smoothed);     
      ForearmRight_Servo.writeMicroseconds(ForearmRight_Smoothed);                    


  } // end of timed loop


} // end if main loop