
#include <SoftwareSerial.h>
int dirR1 = 33;
int dirR2 = 31;
int dirL1 = 35;
int dirL2 = 37;

int dirF1 = 27;
int dirF2 = 29;
int dirB1 = 23;
int dirB2 = 25;

int pwmR = 6;
int pwmL = 7;
int pwmF = 5;
int pwmB = 4;

int x0 = 49;
int x1 = 47;
int x2 = 53;
int x3 = 51;
int x4 = 43;

void setup() 
{
  pinMode(dirR1 , OUTPUT);
  pinMode(dirR2 , OUTPUT);
  pinMode(dirL2 , OUTPUT);
  pinMode(dirL1 , OUTPUT);
  pinMode(dirF1,OUTPUT);
  pinMode(dirF2,OUTPUT);
  pinMode(dirB1,OUTPUT);
  pinMode(dirB2,OUTPUT);
  pinMode(pwmR,OUTPUT);
  pinMode(pwmL,OUTPUT);
  pinMode(pwmB,OUTPUT);
  pinMode(pwmF,OUTPUT);
  pinMode(x0,INPUT);
  pinMode(x1 , INPUT);
  pinMode(x2 , INPUT);
  pinMode(x3 , INPUT);
  pinMode(x4 , INPUT);
  Serial.begin(9600);
 
}

void loop()
{

  // STOP
  if((digitalRead(x0) == LOW) && (digitalRead(x1) == LOW) && (digitalRead(x2) == LOW) && (digitalRead(x3) == LOW) && (digitalRead(x4) == LOW)) //stop
  {
    digitalWrite(dirR1 , HIGH);
    digitalWrite(dirR2 , HIGH);
    digitalWrite(dirL1 , HIGH);
    digitalWrite(dirL2 , HIGH);
    analogWrite(pwmR , 0);
    analogWrite(pwmL , 0);
    Serial.println("stop");

    digitalWrite(dirF1 , HIGH);
    digitalWrite(dirF2 , HIGH);
    digitalWrite(dirB1 , HIGH);
    digitalWrite(dirB2 , HIGH);
    analogWrite(pwmF , 0);
    analogWrite(pwmB , 0);    
  }

  //CLOCKWISE
 if((digitalRead(x0) == LOW) && (digitalRead(x1) == LOW) && (digitalRead(x2) == LOW) && (digitalRead(x3) == LOW) && (digitalRead(x4) == HIGH))
  {
    digitalWrite(dirR1 , LOW);
    digitalWrite(dirR2 , HIGH);
    digitalWrite(dirL1 , HIGH);
    digitalWrite(dirL2 , LOW);
    digitalWrite(dirF1 , HIGH);
    digitalWrite(dirF2 , LOW);
    digitalWrite(dirB1 , LOW);
    digitalWrite(dirB2 , HIGH);
    analogWrite(pwmR , 50);
    analogWrite(pwmL , 50);
    analogWrite(pwmF , 80);
    analogWrite(pwmB , 80);
    Serial.println("CLOCKWISE");
  }

  //ANTICLOCKWISE
 if((digitalRead(x0) == LOW) && (digitalRead(x1) == LOW) && (digitalRead(x2) == LOW) && (digitalRead(x3) == HIGH) && (digitalRead(x4) == LOW)) 
  {
    digitalWrite(dirR1 , HIGH);
    digitalWrite(dirR2 , LOW);
    digitalWrite(dirL1 , LOW);
    digitalWrite(dirL2 , HIGH);
    digitalWrite(dirF1 , LOW);
    digitalWrite(dirF2 , HIGH);
    digitalWrite(dirB1 , HIGH);
    digitalWrite(dirB2 , LOW);
    analogWrite(pwmR , 50);
    analogWrite(pwmL , 50);
    analogWrite(pwmF , 80);
    analogWrite(pwmB , 80);
    Serial.println("ANTICLOCKWISE");
  }

  //LEFT
   if((digitalRead(x0) == LOW) && (digitalRead(x1) == LOW) && (digitalRead(x2) == LOW) && (digitalRead(x3) == HIGH) && (digitalRead(x4) == HIGH)) 
  {
    digitalWrite(dirR1 , HIGH);
    digitalWrite(dirR2 , LOW);
    digitalWrite(dirL1 , HIGH);
    digitalWrite(dirL2 , LOW);
    analogWrite(pwmR , 255);
    analogWrite(pwmL , 255);
    Serial.println("FULL LEFT");

    digitalWrite(dirF1 , HIGH);
    digitalWrite(dirF2 , HIGH);
    digitalWrite(dirB1 , HIGH);
    digitalWrite(dirB2 , HIGH);
  }
   if((digitalRead(x0) == LOW) && (digitalRead(x1) == LOW) && (digitalRead(x2) == HIGH) && (digitalRead(x3) == LOW) && (digitalRead(x4) == LOW)) 
  {
    digitalWrite(dirR1 , HIGH);
    digitalWrite(dirR2 , LOW);
    digitalWrite(dirL1 , HIGH);
    digitalWrite(dirL2 , LOW);
    analogWrite(pwmR , 100);
    analogWrite(pwmL , 100);
    Serial.println("LEFT 3");

    digitalWrite(dirF1 , HIGH);
    digitalWrite(dirF2 , HIGH);
    digitalWrite(dirB1 , HIGH);
    digitalWrite(dirB2 , HIGH);
  }
   if((digitalRead(x0) == LOW) && (digitalRead(x1) == LOW) && (digitalRead(x2) == HIGH) && (digitalRead(x3) == LOW) && (digitalRead(x4) == HIGH)) 
  {
    digitalWrite(dirR1 , HIGH);
    digitalWrite(dirR2 , LOW);
    digitalWrite(dirL1 , HIGH);
    digitalWrite(dirL2 , LOW);
    analogWrite(pwmR , 75);
    analogWrite(pwmL , 75);
    Serial.println("LEFT 2");

    digitalWrite(dirF1 , HIGH);
    digitalWrite(dirF2 , HIGH);
    digitalWrite(dirB1 , HIGH);
    digitalWrite(dirB2 , HIGH);
  }
   if((digitalRead(x0) == LOW) && (digitalRead(x1) == LOW) && (digitalRead(x2) == HIGH) && (digitalRead(x3) == HIGH) && (digitalRead(x4) == LOW)) 
  {
    digitalWrite(dirR1 , HIGH);
    digitalWrite(dirR2 , LOW);
    digitalWrite(dirL1 , HIGH);
    digitalWrite(dirL2 , LOW);
    analogWrite(pwmR , 50);
    analogWrite(pwmL , 50);
    Serial.println("LEFT 1");

    digitalWrite(dirF1 , HIGH);
    digitalWrite(dirF2 , HIGH);
    digitalWrite(dirB1 , HIGH);
    digitalWrite(dirB2 , HIGH);    
  } //END OF LEFT

  // RIGHT
  if((digitalRead(x0) == LOW) && (digitalRead(x1) == LOW) && (digitalRead(x2) == HIGH) && (digitalRead(x3) == HIGH) && (digitalRead(x4) == HIGH)) 
  {
    digitalWrite(dirR2 , HIGH);
    digitalWrite(dirR1 , LOW);
    digitalWrite(dirL2 , HIGH);
    digitalWrite(dirL1 , LOW);
    analogWrite(pwmR , 255);
    analogWrite(pwmL , 255);
    Serial.println("RIGHT FULL");

    digitalWrite(dirF1 , HIGH);
    digitalWrite(dirF2 , HIGH);
    digitalWrite(dirB1 , HIGH);
    digitalWrite(dirB2 , HIGH);    
  }
   if((digitalRead(x0) == LOW) && (digitalRead(x1) == HIGH) && (digitalRead(x2) == LOW) && (digitalRead(x3) == LOW) && (digitalRead(x4) == LOW)) 
  {
    digitalWrite(dirR2 , HIGH);
    digitalWrite(dirR1 , LOW);
    digitalWrite(dirL2 , HIGH);
    digitalWrite(dirL1 , LOW);
    analogWrite(pwmR , 100);
    analogWrite(pwmL , 100);
    Serial.println("RIGHT 3");

    digitalWrite(dirF1 , HIGH);
    digitalWrite(dirF2 , HIGH);
    digitalWrite(dirB1 , HIGH);
    digitalWrite(dirB2 , HIGH);    
  }
   if((digitalRead(x0) == LOW) && (digitalRead(x1) == HIGH) && (digitalRead(x2) == LOW) && (digitalRead(x3) == LOW) && (digitalRead(x4) == HIGH)) 
  {
    digitalWrite(dirR2 , HIGH);
    digitalWrite(dirR1 , LOW);
    digitalWrite(dirL2 , HIGH);
    digitalWrite(dirL1 , LOW);
    analogWrite(pwmR , 75);
    analogWrite(pwmL , 75);
    Serial.println("RIGHT 2");

    digitalWrite(dirF1 , HIGH);
    digitalWrite(dirF2 , HIGH);
    digitalWrite(dirB1 , HIGH);
    digitalWrite(dirB2 , HIGH);    
  }
   if((digitalRead(x0) == LOW) && (digitalRead(x1) == HIGH) && (digitalRead(x2) == LOW) && (digitalRead(x3) == HIGH) && (digitalRead(x4) == LOW)) 
  {
    digitalWrite(dirR2 , HIGH);
    digitalWrite(dirR1 , LOW);
    digitalWrite(dirL2 , HIGH);
    digitalWrite(dirL1 , LOW);
    analogWrite(pwmR , 50);
    analogWrite(pwmL , 50);
    Serial.println("RIGHT 1");

    digitalWrite(dirF1 , HIGH);
    digitalWrite(dirF2 , HIGH);
    digitalWrite(dirB1 , HIGH);
    digitalWrite(dirB2 , HIGH);    
  }//END OF RIGHT
  
//DIFFERENTIAL RIGHT
//while right,forward
  if((digitalRead(x0) == LOW) && (digitalRead(x1) == HIGH) && (digitalRead(x2) == LOW) && (digitalRead(x3) == HIGH) && (digitalRead(x4) == HIGH)) 
  {
    digitalWrite(dirR1 , LOW);
    digitalWrite(dirR2 , HIGH);
    digitalWrite(dirL1 , LOW);
    digitalWrite(dirL2 , HIGH);
    analogWrite(pwmR , 200);
    analogWrite(pwmL , 100); 
    Serial.println("forward 30");

    digitalWrite(dirF1 , HIGH);
    digitalWrite(dirF2 , HIGH);
    digitalWrite(dirB1 , HIGH);
    digitalWrite(dirB2 , HIGH);    
  }
 //while right,backward 
  else if((digitalRead(x0) == LOW) && (digitalRead(x1) == HIGH) && (digitalRead(x2) == HIGH) && (digitalRead(x3) == LOW) && (digitalRead(x4) == LOW))
  {
    digitalWrite(dirR1 , LOW);
    digitalWrite(dirR2 , HIGH);
    digitalWrite(dirL1 , LOW);
    digitalWrite(dirL2 , HIGH);
    analogWrite(pwmR , 100);
    analogWrite(pwmL , 200); 
    Serial.println("backward 30");

    digitalWrite(dirF1 , HIGH);
    digitalWrite(dirF2 , HIGH);
    digitalWrite(dirB1 , HIGH);
    digitalWrite(dirB2 , HIGH);
  }//END OF RIGHT DIFFERENTIAL
 
 //LEFT DIFFERENTIAL
 //while left,forward
 if((digitalRead(x0) == LOW) && (digitalRead(x1) == HIGH) && (digitalRead(x2) == HIGH) && (digitalRead(x3) == LOW) && (digitalRead(x4) == HIGH))
  {
    digitalWrite(dirR1 , HIGH);
    digitalWrite(dirR2 , LOW);
    digitalWrite(dirL1 , HIGH);
    digitalWrite(dirL2 , LOW);
    analogWrite(pwmR , 200);
    analogWrite(pwmL , 100); 
    Serial.println("forward 30");

    digitalWrite(dirF1 , HIGH);
    digitalWrite(dirF2 , HIGH);
    digitalWrite(dirB1 , HIGH);
    digitalWrite(dirB2 , HIGH);    
  }
  //while left, backward
  else if((digitalRead(x0) == LOW) && (digitalRead(x1) == HIGH) && (digitalRead(x2) == HIGH) && (digitalRead(x3) == HIGH) && (digitalRead(x4) == LOW))
  {
    digitalWrite(dirR1 , HIGH);
    digitalWrite(dirR2 , LOW);
    digitalWrite(dirL1 , HIGH);
    digitalWrite(dirL2 , LOW);
    analogWrite(pwmR , 100);
    analogWrite(pwmL , 200); 
    Serial.println("backward 30");

    digitalWrite(dirF1 , HIGH);
    digitalWrite(dirF2 , HIGH);
    digitalWrite(dirB1 , HIGH);
    digitalWrite(dirB2 , HIGH);    
  }//END OF LEFT DIFFERENTIAL

  //FORWARD
  if((digitalRead(x0) == LOW) && (digitalRead(x1) == HIGH) && (digitalRead(x2) == HIGH) && (digitalRead(x3) == HIGH) && (digitalRead(x4) == HIGH))
  {
    digitalWrite(dirR1 , HIGH);
    digitalWrite(dirR2 , HIGH);
    digitalWrite(dirL1 , HIGH);
    digitalWrite(dirL2 , HIGH);
    digitalWrite(dirF1 , HIGH);
    digitalWrite(dirF2 , LOW);
    digitalWrite(dirB1 , HIGH);
    digitalWrite(dirB2 , LOW);
    analogWrite(pwmR , 0);
    analogWrite(pwmL , 0);
    analogWrite(pwmF , 150);
    analogWrite(pwmB , 150);
    Serial.println("NEW FWD");
  }
  //BACKWARD
   if((digitalRead(x0) == HIGH) && (digitalRead(x1) == LOW) && (digitalRead(x2) == LOW) && (digitalRead(x3) == LOW) && (digitalRead(x4) == LOW))
  {
    digitalWrite(dirR1 , HIGH);
    digitalWrite(dirR2 , HIGH);
    digitalWrite(dirL1 , HIGH);
    digitalWrite(dirL2 , HIGH);
    digitalWrite(dirF1 , LOW);
    digitalWrite(dirF2 , HIGH);
    digitalWrite(dirB1 , LOW);
    digitalWrite(dirB2 , HIGH);
    analogWrite(pwmR , 0);
    analogWrite(pwmL , 0);
    analogWrite(pwmF , 150);
    analogWrite(pwmB , 150);
    Serial.println("NEW BACK");
  }
}

