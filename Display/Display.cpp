#include <Arduino.h>
#include <Display.h>

Display::Display() {

    num=0;
    EXT=0;
    MSB=0;
    MID=0;
    LSB=0;
    a=0;
    b=0;
    c=0;
    d=0;
    e=0;
    f=0;
    g=0;
    h=0; 
}
void Display:: start (int a1,int b1,int c1,int d1,int e1,int f1,int g1,int h1) {
  a=a1;
  b=b1;
  c=c1;
  d=d1;
  e=e1;
  f=f1;
  g=g1;
  h=h1;
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(h,OUTPUT);
  }


void Display::init(int A,int B,int C,int D,int E,int F,int G,int H){

    digitalWrite(a,A);
    digitalWrite(b,B);
    digitalWrite(c,C);
    digitalWrite(d,D);
    digitalWrite(e,E);
    digitalWrite(f,F);
    digitalWrite(g,G);
    digitalWrite(h,H);
  }
void Display::MSB_() {
  
  if(MSB==0) {
    init(0,0,0,0,0,0,0,0);
    init(0,1,0,0,0,0,0,0);
    init(0,0,0,0,0,0,0,0);
    }
  if(MSB==1) {
    init(0,0,0,0,0,0,0,1);
    init(0,1,0,0,0,0,0,1);
    init(0,0,0,0,0,0,0,1);
    }

  if(MSB==2) {
    init(0,0,0,0,0,0,1,0);
    init(0,1,0,0,0,0,1,0);
    init(0,0,0,0,0,0,1,0);
    }
    
  if(MSB==3) {
    init(0,0,0,0,0,0,1,1);
    init(0,1,0,0,0,0,1,1);
    init(0,0,0,0,0,0,1,1);
    }
    
  if(MSB==4) {
    init(0,0,0,0,0,1,0,0);
    init(0,1,0,0,0,1,0,0);
    init(0,0,0,0,0,1,0,0);
    }
    
  if(MSB==5) {
    init(0,0,0,0,0,1,0,1);
    init(0,1,0,0,0,1,0,1);
    init(0,0,0,0,0,1,0,1);
    }

  if(MSB==6) {
    init(0,0,0,0,0,1,1,0);
    init(0,1,0,0,0,1,1,0);
    init(0,0,0,0,0,1,1,0);
    }
    
  if(MSB==7) {
    init(0,0,0,0,0,1,1,1);
    init(0,1,0,0,0,1,1,1);
    init(0,0,0,0,0,1,1,1);
    } 
    
  if(MSB==8) {
    init(0,0,0,0,1,0,0,0);
    init(0,1,0,0,1,0,0,0);
    init(0,0,0,0,1,0,0,0);
    }
    
  if(MSB==9) {
    init(0,0,0,0,1,0,0,1);
    init(0,1,0,0,1,0,0,1);
    init(0,0,0,0,1,0,0,1);
    }
  
  }

void Display :: MID_() {
  
  if(MID==0) {
    init(0,0,0,0,0,0,0,0);
    init(0,0,1,0,0,0,0,0);
    init(0,0,0,0,0,0,0,0);
    }
  if(MID==1) {
    init(0,0,0,0,0,0,0,1);
    init(0,0,1,0,0,0,0,1);
    init(0,0,0,0,0,0,0,1);
    }

  if(MID==2) {
    init(0,0,0,0,0,0,1,0);
    init(0,0,1,0,0,0,1,0);
    init(0,0,0,0,0,0,1,0);
    }
    
  if(MID==3) {
    init(0,0,0,0,0,0,1,1);
    init(0,0,1,0,0,0,1,1);
    init(0,0,0,0,0,0,1,1);
    }
    
  if(MID==4) {
    init(0,0,0,0,0,1,0,0);
    init(0,0,1,0,0,1,0,0);
    init(0,0,0,0,0,1,0,0);
    }
    
  if(MID==5) {
    init(0,0,0,0,0,1,0,1);
    init(0,0,1,0,0,1,0,1);
    init(0,0,0,0,0,1,0,1);
    }

  if(MID==6) {
    init(0,0,0,0,0,1,1,0);
    init(0,0,1,0,0,1,1,0);
    init(0,0,0,0,0,1,1,0);
    }
    
  if(MID==7) {
    init(0,0,0,0,0,1,1,1);
    init(0,0,1,0,0,1,1,1);
    init(0,0,0,0,0,1,1,1);
    } 
    
  if(MID==8) {
    init(0,0,0,0,1,0,0,0);
    init(0,0,1,0,1,0,0,0);
    init(0,0,0,0,1,0,0,0);
    }
    
  if(MID==9) {
    init(0,0,0,0,1,0,0,1);
    init(0,0,1,0,1,0,0,1);
    init(0,0,0,0,1,0,0,1);
    }
    }

void Display :: LSB_() {
  
  if(LSB==0) {
    init(0,0,0,0,0,0,0,0);
    init(0,0,0,1,0,0,0,0);
    init(0,0,0,0,0,0,0,0);
    }
  if(LSB==1) {
    init(0,0,0,0,0,0,0,1);
    init(0,0,0,1,0,0,0,1);
    init(0,0,0,0,0,0,0,1);
    }

  if(LSB==2) {
    init(0,0,0,0,0,0,1,0);
    init(0,0,0,1,0,0,1,0);
    init(0,0,0,0,0,0,1,0);
    }
    
  if(LSB==3) {
    init(0,0,0,0,0,0,1,1);
    init(0,0,0,1,0,0,1,1);
    init(0,0,0,0,0,0,1,1);
    }
    
  if(LSB==4) {
    init(0,0,0,0,0,1,0,0);
    init(0,0,0,1,0,1,0,0);
    init(0,0,0,0,0,1,0,0);
    }
    
  if(LSB==5) {
    init(0,0,0,0,0,1,0,1);
    init(0,0,0,1,0,1,0,1);
    init(0,0,0,0,0,1,0,1);
    }

  if(LSB==6) {
    init(0,0,0,0,0,1,1,0);
    init(0,0,0,1,0,1,1,0);
    init(0,0,0,0,0,1,1,0);
    }
    
  if(LSB==7) {
    init(0,0,0,0,0,1,1,1);
    init(0,0,0,1,0,1,1,1);
    init(0,0,0,0,0,1,1,1);
    } 
    
  if(LSB==8) {
    init(0,0,0,0,1,0,0,0);
    init(0,0,0,1,1,0,0,0);
    init(0,0,0,0,1,0,0,0);
    }
    
  if(LSB==9) {
    init(0,0,0,0,1,0,0,1);
    init(0,0,0,1,1,0,0,1);
    init(0,0,0,0,1,0,0,1);
    }
    }
void Display:: Clear() {

  Display();
  init(0,0,0,0,1,0,1,0);
  init(1,0,0,0,1,0,1,0);
  init(0,0,0,0,1,0,1,0);
  MSB_();
  MID_();
  LSB_();

 
}

void Display:: view( int val ) {
   int rem;
   
   num=val;
   MSB=num/100;
   rem=num%100;
   MID=rem/10;
   LSB=rem%10;

   init(0,0,0,0,0,0,0,0);
   init(1,0,0,0,0,0,0,0);
   init(0,0,0,0,0,0,0,0);  
   MSB_();
   MID_();
   LSB_();
}