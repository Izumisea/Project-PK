const int Flower_1 = A0; 
const int LED_1  = 3;  

const int Flower_2 = A1; 
const int LED_2 = 4;

const int Flower_3 = A2;
const int LED_3 = 5;

const int Flower_4 = A3; 
const int LED_4 = 6;

const int Flower_1_THRESHOLD = 500;
const int Flower_2_THRESHOLD = 500;
const int Flower_3_THRESHOLD = 500;
const int Flower_4_THRESHOLD = 500;


// variables will change:
int Flower_1_Value;
int Flower_2_Value;
int Flower_3_Value;
int Flower_4_Value;

int Flower_1_Score = 0;
int Flower_2_Score = 0;
int Flower_3_Score = 0;
int Flower_4_Score = 0;

void setup() {
  pinMode(LED_1, OUTPUT); // set arduino pin to output mode
  pinMode(LED_2, OUTPUT); // set arduino pin to output mode
  pinMode(LED_3, OUTPUT); // set arduino pin to output mode
  pinMode(LED_4, OUTPUT); // set arduino pin to output mode
}

void loop() {
  Flower_1_Value = analogRead(Flower_1); // read the input on analog pin
  Flower_2_Value = analogRead(Flower_2);
  Flower_3_Value = analogRead(Flower_3);
  Flower_4_Value = analogRead(Flower_4);

  if(Flower_1_Value < Flower_1_THRESHOLD && Flower_1_Score == 0){
    digitalWrite(LED_1, HIGH); // turn on LED
  }else{
    Flower_1_Score = 1;
  }


 if(Flower_2_Value < Flower_2_THRESHOLD &&  Flower_2_Score == 0){
    digitalWrite(LED_2, HIGH); // turn on LED
  }else{
    Flower_2_Score = 1;
  }
    

  if(Flower_3_Value < Flower_3_THRESHOLD &&  Flower_3_Score == 0){
    digitalWrite(LED_3, HIGH); // turn on LED
  }else{
    Flower_3_Score = 1;
    
  }
    

  if(Flower_4_Value < Flower_4_THRESHOLD &&  Flower_4_Score == 0){
    digitalWrite(LED_4, HIGH); // turn on LED
  }else{
    Flower_4_Score = 1;
  }
    
if (Flower_1_Score >= 1){
  digitalWrite(LED_1, LOW);  
 }   
if (Flower_2_Score >= 1){
  digitalWrite(LED_2, LOW);  
 }   
if (Flower_3_Score >= 1){
  digitalWrite(LED_3, LOW);  
 }   
if (Flower_4_Score >= 1){
  digitalWrite(LED_4, LOW);  
 }   
   
   
   

    
}