#include <Display.h>
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
int a[4]={77,128,229,0}; //30% pwm, 50u% pwm, 90% pwm,0% pwm
//motor connections:
int dir=2;
//int brk=3;
int pwm=5;
byte x;
//int offset_inc,offset_dec;
byte flag = 0;
//int resett = 9;

Display show;

void setup() {
 
 show.start(29,27,25,23,47,45,43,41);
 //show.start(A15,A14,A13,A12,A11,A10,A9,A8);
 show.Clear();
 Serial.begin(9600);
 pinMode(inc,INPUT);
 pinMode(dec,INPUT);
 pinMode(sp1,INPUT);
 pinMode(sp2,INPUT);
 pinMode(sp3,INPUT);
 pinMode(dir,OUTPUT);
// pinMode(brk,OUTPUT);
 pinMode(pwm,OUTPUT);
 pinMode(enable,OUTPUT);
 digitalWrite(enable,HIGH);
 Serial1.begin(9600);

}

void loop() {

 if(Serial1.available()) {
    x=Serial1.read();
    if((x==0x01) && (digitalRead(sp1) == HIGH) && (digitalRead(sp2) == LOW) && (digitalRead(sp3) == LOW)) {
      sp_val=a[0];
      show.view(map(sp_val,0,255,0,100));
      Serial.println(map(sp_val,0,255,0,100));
    }
    else if((x==0x02) && (digitalRead(sp1) == LOW) && (digitalRead(sp2) == HIGH) && (digitalRead(sp3) == LOW)) {
      sp_val=a[1];
      show.view(map(sp_val,0,255,0,100));
      Serial.println(map(sp_val,0,255,0,100));
    }
    else if((x==0x03) && (digitalRead(sp1) == LOW) && (digitalRead(sp2) == LOW) && (digitalRead(sp3) == HIGH)) {
      sp_val=a[2];
      show.view(map(sp_val,0,255,0,100));
      Serial.println(map(sp_val,0,255,0,100));
    }
    
    else if(x==0x04) {
      sp_val=a[3];
    }
   
   
  }
  
if((digitalRead(sp1) == LOW) && (digitalRead(sp2) == LOW) && (digitalRead(sp3) == LOW)) 
{
  for(int i=1;i<=sp_val;i=i+5)
  {
  
   digitalWrite(dir,HIGH);
   analogWrite(pwm,sp_val-i);
   show.view(map(sp_val,0,255,0,100));
   delay(1000);
  }
   //analogWrite(pwm,0);
}
else {
  
      if(digitalRead(enable)==HIGH) { 

              digitalWrite(dir,HIGH);
              //digitalWrite(brk,LOW);
              analogWrite(pwm,sp_val);
      }
      if(digitalRead(enable)==LOW){
    
              digitalWrite(dir,LOW);
              //digitalWrite(brk,HIGH);
              analogWrite(pwm,sp_val);

        }

        if(sp_val <= 252) {
         
              if(digitalRead(sp1) == HIGH && digitalRead(inc) == HIGH) {
                  flag=1;
                  //Serial.println(digitalRead(inc));
                  //Serial.println(digitalRead(sp1));
              }
        
              if(digitalRead(sp1) == HIGH && digitalRead(inc) == LOW && flag==1) {
                  flag=0;
                  sp_val = sp_val + inc_val;
                  show.view(map(sp_val,0,255,0,100));
                  analogWrite(pwm,sp_val);  
                  Serial.println(map(sp_val,0,255,0,100));
                  //Serial.println(flag);
                }
              if(digitalRead(sp2) == HIGH && digitalRead(inc) == HIGH) {
                  flag=2;
                  //Serial.println(flag);
              }
              if(digitalRead(sp2) == HIGH && digitalRead(inc) == LOW && flag == 2) {
                  flag=0;
                  sp_val = sp_val + inc_val;
                  show.view(map(sp_val,0,255,0,100));
                  analogWrite(pwm,sp_val); 
                  Serial.println(map(sp_val,0,255,0,100));
              }
        
              if(digitalRead(sp3) == HIGH && digitalRead(inc) == HIGH) {
                  flag=3;
                  //    Serial.println(flag);
              }
        
              if(digitalRead(sp3) == HIGH && digitalRead(inc) == LOW && flag == 3) {
                  flag=0;
                  sp_val = sp_val + inc_val;
                  show.view(map(sp_val,0,255,0,100));
                  analogWrite(pwm,sp_val);
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
              show.view(map(sp_val,0,255,0,100));
              analogWrite(pwm,sp_val);
              Serial.println(map(sp_val,0,255,0,100));
              //Serial.println(flag);
        }
        if(digitalRead(sp2) == HIGH && digitalRead(inc) == HIGH) {
              flag=2;
              //Serial.println(flag);
        }
        if(digitalRead(sp2) == HIGH && digitalRead(inc) == LOW && flag == 2) {
              flag=0;
              sp_val = sp_val + 1;
              show.view(map(sp_val,0,255,0,100));
              analogWrite(pwm,sp_val);      
              Serial.println(map(sp_val,0,255,0,100));
        }
        
        
        if(digitalRead(sp3) == HIGH && digitalRead(inc) == HIGH) {
             flag=3;
         //    Serial.println(flag);
        }
        
        if(digitalRead(sp3) == HIGH && digitalRead(inc) == LOW && flag == 3) {
             flag=0;
             sp_val = sp_val + 1;
             show.view(map(sp_val,0,255,0,100));
             analogWrite(pwm,sp_val);
             Serial.println(map(sp_val,0,255,0,100));
        }
        }
        if(sp_val > 0 && sp_val <= 252 ) {
        if(digitalRead(sp1) == HIGH && digitalRead(dec) ==HIGH) {
             flag=4;
           //  Serial.println(flag);
        }
        if(digitalRead(sp1) == HIGH && digitalRead(dec)==LOW && flag == 4) {
              flag=0;
              sp_val = sp_val - dec_val;
              show.view(map(sp_val,0,255,0,100));
              analogWrite(pwm,sp_val);
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
              show.view(map(sp_val,0,255,0,100));
              analogWrite(pwm,sp_val);
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
              show.view(map(sp_val,0,255,0,100));
              analogWrite(pwm,sp_val);
              Serial.println(map(sp_val,0,255,0,100));
        //      Serial.println(flag);
        }
        
        
        }

        if(sp_val>252 && sp_val<=255) {
        if(digitalRead(sp1) == HIGH && digitalRead(dec) ==HIGH) {
             flag=4;
           //  Serial.println(flag);
        }
        if(digitalRead(sp1) == HIGH && digitalRead(dec)==LOW && flag == 4) {
              flag=0;
              sp_val = sp_val - 1;
              show.view(map(sp_val,0,255,0,100));
              analogWrite(pwm,sp_val);
              Serial.println(map(sp_val,0,255,0,100));
              //Serial.println(flag);
        }
        
        if(digitalRead(sp2) == HIGH && digitalRead(dec)==HIGH) {
              flag=5;
              //Serial.println(flag);
        }  
        
        if(digitalRead(sp2) == HIGH && digitalRead(dec)==LOW && flag==5) {
              flag=0;
              sp_val = sp_val - 1;
              show.view(map(sp_val,0,255,0,100));
              analogWrite(pwm,sp_val);
              Serial.println(map(sp_val,0,255,0,100));
              //Serial.println(flag);
          }
        if(digitalRead(sp3) == HIGH && digitalRead(dec) ==HIGH) {
              flag=6;
              //Serial.println(flag);
        }
        if(digitalRead(sp3) == HIGH && digitalRead(dec)==LOW && flag==6) {
              flag=0;
              sp_val = sp_val - 1;
              show.view(map(sp_val,0,255,0,100));
              analogWrite(pwm,sp_val);
              Serial.println(map(sp_val,0,255,0,100));
        //      Serial.println(flag);
        }
        
        
        }
}
}

