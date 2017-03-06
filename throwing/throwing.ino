#include <LiquidCrystal.h>

 //throwing_with_slave
//digital_pins:
//tx1 to rx 1 of master


int sp1 = 31;
int sp2 = 33;
int sp3 = 35;
int inc = 37;
int dec = 39;
int enable=6; //for motor direction independant of master
//variables:
byte inc_val=3; 
byte dec_val=3; //values may change
int sp_val=0;
int a[4]={76,102,128,0}; //30% pwm, 40% pwm, 50% pwm,0% pwm
//motor connections:
int IN1=2;
int IN2=3;
int pwm=5;
byte x;
int offset_inc,offset_dec;

byte flag = 0;

int resett = 9;



LiquidCrystal lcd(12, 11 , 23 , 25 , 27 , 29); //36=D4,34=D5,33=D6,32=D7

void setup() {
 
 Serial.begin(9600);
 pinMode(inc,INPUT);
 pinMode(dec,INPUT);
 pinMode(sp1,INPUT);
 pinMode(sp2,INPUT);
 pinMode(sp3,INPUT);
 pinMode(IN1,OUTPUT);
 pinMode(IN2,OUTPUT);
 pinMode(pwm,OUTPUT);
 pinMode(enable,OUTPUT);
 digitalWrite(enable,HIGH);
 Serial1.begin(9600);
 lcd.begin(16,2);
}

void loop() {
  if((digitalRead(sp1) == HIGH) && (digitalRead(sp2) == HIGH) && (digitalRead(sp3) == HIGH))
  {
    lcd.clear();
    pinMode(resett,OUTPUT);
  }

 if(Serial1.available()) {
    x=Serial1.read();
    if(x==0x01) {
      sp_val=a[0];
      lcd.clear();
      lcd.setCursor(5,0);
      lcd.print(map(sp_val,0,255,0,100));
      Serial.println(map(sp_val,0,255,0,100));
    }
    else if(x==0x02) {
      sp_val=a[1];
      lcd.clear();
      lcd.setCursor(5,0);
      lcd.print(map(sp_val,0,255,0,100));
      Serial.println(map(sp_val,0,255,0,100));
    }
    else if(x==0x03) {
      sp_val=a[2];
      lcd.clear();
      lcd.setCursor(5,0);
      lcd.print(map(sp_val,0,255,0,100));
      Serial.println(map(sp_val,0,255,0,100));
    }
    
    else if(x==0x04) {
      sp_val=a[3];
    }
   
   
  }
  
if((digitalRead(sp1) == LOW) && (digitalRead(sp2) == LOW) && (digitalRead(sp3) == LOW)) 
{
  for(int i=1;i<=sp_val;i++)
  {
  
   digitalWrite(IN1,HIGH);
   analogWrite(pwm,sp_val-i);
   
  }
}
else {
  
if(digitalRead(enable)==HIGH) {

  digitalWrite(IN1,HIGH);
  //digitalWrite(IN2,LOW);
  analogWrite(pwm,sp_val);
}
if(digitalRead(enable)==LOW){
  
  digitalWrite(IN1,LOW);
  //digitalWrite(IN2,HIGH);
  analogWrite(pwm,sp_val);

}

if(sp_val!=252) {

if(digitalRead(sp1) == HIGH && digitalRead(inc) == HIGH) {
      flag=1;
      //Serial.println(digitalRead(inc));
      //Serial.println(digitalRead(sp1));
}

if(digitalRead(sp1) == HIGH && digitalRead(inc) == LOW && flag==1) {
      flag=0;
      sp_val = sp_val + inc_val;
      analogWrite(pwm,sp_val);  
      lcd.clear();
      lcd.setCursor(5,0);
      lcd.print(map(sp_val,0,255,0,100));
      Serial.println(map(sp_val,0,255,0,100));
      //Serial.println(flag);
}
if(digitalRead(sp2) == HIGH && digitalRead(inc) == HIGH) {
      flag=2;
      Serial.println(flag);
}
if(digitalRead(sp2) == HIGH && digitalRead(inc) == LOW && flag == 2) {
      flag=0;
      sp_val = sp_val + inc_val;
      analogWrite(pwm,sp_val);
      lcd.clear();
      lcd.setCursor(5,0);
      lcd.print(map(sp_val,0,255,0,100));
     // Serial.println(flag);
     Serial.println(map(sp_val,0,255,0,100));
}


if(digitalRead(sp3) == HIGH && digitalRead(inc) == HIGH) {
     flag=3;
 //    Serial.println(flag);
}

if(digitalRead(sp3) == HIGH && digitalRead(inc) == LOW && flag == 3) {
     flag=0;
     sp_val = sp_val + inc_val;
     analogWrite(pwm,sp_val);
     lcd.clear();
     Serial.println(flag);
     lcd.setCursor(5,0);
     lcd.print(map(sp_val,0,255,0,100));
     Serial.println(map(sp_val,0,255,0,100));
}
}
 
if((sp_val >= 252) && (sp_val < 255)) {

if(digitalRead(sp1) == HIGH && digitalRead(inc) == HIGH) {
      flag=1;
      //Serial.println(digitalRead(inc));

      //Serial.println(digitalRead(sp1));
}

if(digitalRead(sp1) == HIGH && digitalRead(inc) == LOW && flag==1) {
      flag=0;
      sp_val = sp_val + 1;
      analogWrite(pwm,sp_val);  
      lcd.clear();
      lcd.setCursor(5,0);
      lcd.print(map(sp_val,0,255,0,100));
      Serial.println(map(sp_val,0,255,0,100));
      //Serial.println(flag);
}
if(digitalRead(sp2) == HIGH && digitalRead(inc) == HIGH) {
      flag=2;
      Serial.println(flag);
}
if(digitalRead(sp2) == HIGH && digitalRead(inc) == LOW && flag == 2) {
      flag=0;
      sp_val = sp_val + 1;
      analogWrite(pwm,sp_val);
      lcd.clear();
      lcd.setCursor(5,0);
      lcd.print(map(sp_val,0,255,0,100));
     // Serial.println(flag);
     Serial.println(map(sp_val,0,255,0,100));
}


if(digitalRead(sp3) == HIGH && digitalRead(inc) == HIGH) {
     flag=3;
 //    Serial.println(flag);
}

if(digitalRead(sp3) == HIGH && digitalRead(inc) == LOW && flag == 3) {
     flag=0;
     sp_val = sp_val + 1;
     analogWrite(pwm,sp_val);
     lcd.clear();
     Serial.println(flag);
     lcd.setCursor(5,0);
     lcd.print(map(sp_val,0,255,0,100));
     Serial.println(map(sp_val,0,255,0,100));
}
}
if(sp_val!=0) {
if(digitalRead(sp1) == HIGH && digitalRead(dec) ==HIGH) {
     flag=4;
   //  Serial.println(flag);
}
if(digitalRead(sp1) == HIGH && digitalRead(dec)==LOW && flag == 4) {
      flag=0;
      sp_val = sp_val - dec_val;
      analogWrite(pwm,sp_val);
      lcd.clear();
      lcd.setCursor(5,0);
      lcd.print(map(sp_val,0,255,0,100));
      Serial.println(map(sp_val,0,255,0,100));
      //Serial.println(flag);
}

if(digitalRead(sp2) == HIGH && digitalRead(dec)==HIGH) {
      flag=5;
      //Serial.println(flag);
}  

if(digitalRead(sp2) == HIGH && digitalRead(dec)==LOW && flag==5) {
      flag=0;
      sp_val = sp_val - dec_val;
      analogWrite(pwm,sp_val);
      lcd.clear();
      lcd.setCursor(5,0);
      lcd.print(map(sp_val,0,255,0,100));
      Serial.println(map(sp_val,0,255,0,100));
      //Serial.println(flag);
  }
if(digitalRead(sp3) == HIGH && digitalRead(dec) ==HIGH) {
      flag=6;
      //Serial.println(flag);
}
if(digitalRead(sp3) == HIGH && digitalRead(dec)==LOW && flag==6) {
      flag=0;
      sp_val = sp_val - dec_val;
      analogWrite(pwm,sp_val);  
      lcd.clear();
      lcd.setCursor(5,0);
      lcd.print(map(sp_val,0,255,0,100) );
      Serial.println(map(sp_val,0,255,0,100));
//      Serial.println(flag);
}


}
}
}

