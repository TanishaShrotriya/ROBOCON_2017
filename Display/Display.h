#ifndef Display_
#define Display_

#include <Arduino.h>
class Display {

    int num,EXT,MSB,MID,LSB;
    int a,b,c,d,e,f,g,h; //connector pins
  public:
    
    Display();
    void start(int a1,int b1,int c1,int d1,int e1,int f1,int g1,int h1);
    void init(int A,int B,int C,int D,int E,int F,int G,int H);
    void Clear();
    void view( int val );
    void MSB_();
    void MID_();
    void LSB_();
    
  };
#endif
