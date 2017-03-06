#include <SoftwareSerial.h>
#include <Cytron_PS2Shield.h>

Cytron_PS2Shield ps2(10, 11);

int x0 =  49;
int x1 =  47;
int x2 =  53;
int x3 =  51;
int x4 =  43;
int reset_M = 5;
int reset_S = 45;

int sp1 = 31;        //left
int sp2 = 33;       //up
int sp3 = 35;      //right
int inc = 37;
int dec = 39;

int r1 = 27;        //left up m2 clockwise
//int r2 = 23;        //m2 anticlockwise
//int r3 = 25;         //right up m1 clockwise
int r4 = 41;        //m1 anticlockwise
int f1 = 29;       //feeding relay

void setup() {
  Serial.begin(9600);
  pinMode(sp1, OUTPUT);
  pinMode(sp2, OUTPUT);
  pinMode(sp3, OUTPUT);
  pinMode(inc, OUTPUT);
  pinMode(dec, OUTPUT);
  pinMode(r1, OUTPUT);
//  pinMode(r2, OUTPUT);
//  pinMode(r3, OUTPUT);
  pinMode(r4, OUTPUT);
  pinMode(f1, OUTPUT);
  digitalWrite(f1, LOW);
  pinMode(x0, OUTPUT);
  pinMode(x1, OUTPUT);
  pinMode(x2, OUTPUT);
  pinMode(x3, OUTPUT);
  pinMode(x4, OUTPUT);
  pinMode(reset_M, INPUT);
  pinMode(reset_S, OUTPUT);
  digitalWrite(reset_S, HIGH);
  ps2.begin(9600);

}

void loop() {
  // *************** RESET********************
  if (ps2.readButton(PS2_DOWN) == 0)
  {
    digitalWrite(reset_S,LOW);
    pinMode(reset_M,OUTPUT);
   
  }
  
  if (ps2.readButton(PS2_DOWN) == 1)
  {
    digitalWrite(reset_S,HIGH);
  }
 
  // THROWING
  //--------------------------------------------------------------------------------------
  //--------------------------------------------------------------------------------------
  if (ps2.readButton(PS2_TRIANGLE) == 0)
  {
    digitalWrite(inc, HIGH);
    Serial.println("should increment");
  }

  if (ps2.readButton(PS2_TRIANGLE) == 1)
  {
    digitalWrite(inc, LOW);
  }

  if (ps2.readButton(PS2_CROSS) == 0)
  {
    digitalWrite(dec, HIGH);
    Serial.println("should decrement");
  }

  if (ps2.readButton(PS2_CROSS) == 1)
  {
    digitalWrite(dec, LOW);
  }

  if (ps2.readButton(PS2_SQUARE) == 0)
  {
    Serial1.begin(9600); //stop condition
    Serial1.write(0x04);
    Serial1.end();
    Serial.println("0x04 sent");
    digitalWrite(sp3, LOW);
    digitalWrite(sp2, LOW);
    digitalWrite(sp1, LOW);
  }

  if (ps2.readButton(PS2_UP) == 0)
  { //150
    Serial1.begin(9600);
    Serial1.write(0x01);
    Serial1.end();
    Serial.println("0x01 sent");
    digitalWrite(sp1, HIGH);
    digitalWrite(sp2, LOW);
    digitalWrite(sp3, LOW);
  }

  if (ps2.readButton(PS2_LEFT) == 0 )
  { //100
    Serial1.begin(9600);
    Serial1.write(0x02);
    Serial1.end();
    Serial.println("0x02 sent");
    digitalWrite(sp1, LOW);
    digitalWrite(sp2, HIGH);
    digitalWrite(sp3, LOW);
  }

  if (ps2.readButton(PS2_RIGHT) == 0)
  { //55
    Serial1.begin(9600);
    Serial1.write(0x03);
    Serial1.end();
    Serial.println("0x03 sent");
    digitalWrite(sp1, LOW);
    digitalWrite(sp2, LOW);
    digitalWrite(sp3, HIGH);
  }
  //--------------------------------------------------------------------------------
  //--------------------------------------------------------------------------------
  if (ps2.readButton(PS2_CIRCLE) == 0)
  { //for loading/feeding
    digitalWrite(f1, HIGH);
  }

  if (ps2.readButton(PS2_CIRCLE) == 1)
  {
    digitalWrite(f1, LOW);
  }

  //------------------------------------------------------------------------------------
  //------------------------------------------------------------------------------------
  //Base
  if ((ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) >= 120) && (ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) <= 132) && (ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) >= 120) && (ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) <= 132) && (ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS) >= 120) && (ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS) <= 132) && (ps2.readButton(PS2_JOYSTICK_LEFT_X_AXIS) >= 120) && (ps2.readButton(PS2_JOYSTICK_LEFT_X_AXIS) <= 132 )) //stop
  {
    digitalWrite(x0, LOW);
    digitalWrite(x1, LOW);
    digitalWrite(x2, LOW);
    digitalWrite(x3, LOW);
    digitalWrite(x4, LOW);
    Serial.println("stop");
  }

  //CLOCKWISE
  if ((ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS) >= 120) && (ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS) <= 132) && ((ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) >= 120 && ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) <= 132)) && ((ps2.readButton(PS2_JOYSTICK_LEFT_X_AXIS) >= 0  && ps2.readButton(PS2_JOYSTICK_LEFT_X_AXIS) < 120)) )
  {
    digitalWrite(x0, LOW);
    digitalWrite(x1, LOW);
    digitalWrite(x2, LOW);
    digitalWrite(x3, LOW);
    digitalWrite(x4, HIGH);
    Serial.println("CLOCKWISE");
    //left x axis 0 to 120
  }

  //ANTICLOCKWISE
  if ((ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS) >= 120) && (ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS) <= 132) && ((ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) >= 120 && ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) <= 132)) && ((ps2.readButton(PS2_JOYSTICK_LEFT_X_AXIS) > 132 && ps2.readButton(PS2_JOYSTICK_LEFT_X_AXIS) <= 255)) )
  {
    digitalWrite(x0, LOW);
    digitalWrite(x1, LOW);
    digitalWrite(x2, LOW);
    digitalWrite(x3, HIGH);
    digitalWrite(x4, LOW);
    Serial.println("ANTICLOCKWISE");
    //left x axis 132 to 255
  }

  //LEFT
  if ((ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) >= 0) && (ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) < 30) && ((ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) >= 120 && ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) <= 132)))
  {
    digitalWrite(x0, LOW);
    digitalWrite(x1, LOW);
    digitalWrite(x2, LOW);
    digitalWrite(x3, HIGH);
    digitalWrite(x4, HIGH);
    Serial.println("LEFT FULL");
    //right x axis 0 to 30
  }
  if ((ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) >= 30) && (ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) < 60) && ((ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) >= 120 && ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) <= 132)))
  {
    digitalWrite(x0, LOW);
    digitalWrite(x1, LOW);
    digitalWrite(x2, HIGH);
    digitalWrite(x3, LOW);
    digitalWrite(x4, LOW);
    Serial.println("LEFT 3");
    //right x axis 30 to 60
  }
  if ((ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) >= 60) && (ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) < 90) && ((ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) >= 120 && ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) <= 132)))
  {
    digitalWrite(x0, LOW);
    digitalWrite(x1, LOW);
    digitalWrite(x2, HIGH);
    digitalWrite(x3, LOW);
    digitalWrite(x4, HIGH);
    Serial.println("LEFT 2");
    //right x axis 60 to 90
  }
  if ((ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) >= 90) && (ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) < 120) && ((ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) >= 120 && ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) <= 132)))
  {
    digitalWrite(x0, LOW);
    digitalWrite(x1, LOW);
    digitalWrite(x2, HIGH);
    digitalWrite(x3, HIGH);
    digitalWrite(x4, LOW);
    Serial.println("LEFT 1");
    //right x axis 90 to 120

  }//END OF LEFT

  // RIGHT
  if ((ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) >= 220) && (ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) <= 255) && ((ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) >= 120 && ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) <= 132)))
  {
    digitalWrite(x0, LOW);
    digitalWrite(x1, LOW);
    digitalWrite(x2, HIGH);
    digitalWrite(x3, HIGH);
    digitalWrite(x4, HIGH);
    Serial.println("RIGHT FULL");
  }
  if ((ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) >= 190) && (ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) < 220) && ((ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) >= 120 && ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) <= 132)))
  {
    digitalWrite(x0, LOW);
    digitalWrite(x1, HIGH);
    digitalWrite(x2, LOW);
    digitalWrite(x3, LOW);
    digitalWrite(x4, LOW);
    Serial.println("RIGHT 3");
  }
  if ((ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) >= 160) && (ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) < 190) && ((ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) >= 120 && ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) <= 132)))
  {
    digitalWrite(x0, LOW);
    digitalWrite(x1, HIGH);
    digitalWrite(x2, LOW);
    digitalWrite(x3, LOW);
    digitalWrite(x4, HIGH);
    Serial.println("RIGHT 2");
  }
  if ((ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) > 132) && (ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) < 160) && ((ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) >= 120 && ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) <= 132)))
  {
    digitalWrite(x0, LOW);
    digitalWrite(x1, HIGH);
    digitalWrite(x2, LOW);
    digitalWrite(x3, HIGH);
    digitalWrite(x4, LOW);
    Serial.println("RIGHT 1");
  }//END OF RIGHT

  //DIFFERENTIAL RIGHT
  //while right,forward
  if ((ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) >= 0) && (ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) < 120)&& (ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) > 132) && (ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) <= 255))
  {
    digitalWrite(x0, LOW);
    digitalWrite(x1, HIGH);
    digitalWrite(x2, LOW);
    digitalWrite(x3, HIGH);
    digitalWrite(x4, HIGH);
    Serial.println("FORWARD right");
  }
  //while right,backward
 
  if ((ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) > 132) && (ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) <= 255) && (ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) > 132) && (ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) <= 255))
  {
    digitalWrite(x0, LOW);
    digitalWrite(x1, HIGH);
    digitalWrite(x2, HIGH);
    digitalWrite(x3, LOW);
    digitalWrite(x4, LOW);
    Serial.println("BACKWARD right");
  }//END OF RIGHT DIFFERENTIAL

  //LEFT DIFFERENTIAL
  //while left,forward
  if ((ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) >=0) && (ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) < 120) && (ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) >= 0) && (ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) < 120))
  {
    digitalWrite(x0, LOW);
    digitalWrite(x1, HIGH);
    digitalWrite(x2, HIGH);
    digitalWrite(x3, LOW);
    digitalWrite(x4, HIGH);
    Serial.println("FORWARD left");
  }
  //while left, backward
   if ((ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) > 132) && (ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) <=255 ) && (ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) >= 0) && (ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) < 120))
  {
    digitalWrite(x0, LOW);
    digitalWrite(x1, HIGH);
    digitalWrite(x2, HIGH);
    digitalWrite(x3, HIGH);
    digitalWrite(x4, LOW);
    Serial.println("BACKWARD left");
  }//END OF LEFT DIFFERENTIAL

  //BACKWARD
  if ((ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS) > 132) && (ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS) <= 255) && ((ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) >= 120 && ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) <= 132)))
  {
    digitalWrite(x0, LOW);
    digitalWrite(x1, HIGH);
    digitalWrite(x2, HIGH);
    digitalWrite(x3, HIGH);
    digitalWrite(x4, HIGH);

    
    Serial.println("BACKWARD");
  }

  //FORWARD
if((ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS) >= 0) && (ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS) < 120) && ((ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) >= 120 && ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) <= 132)) )
  {
    
    digitalWrite(x0, HIGH);
    digitalWrite(x1, LOW);
    digitalWrite(x2, LOW);
    digitalWrite(x3, LOW);
    digitalWrite(x4, LOW);
    Serial.println("FORWARD");
  }

  //------------------------------------------------------------------------------------------------------------------------
  //------------------------------------------------------------------------------------------------------------------------
  //RELAY
  if ((ps2.readButton(PS2_RIGHT_1)  == 0) && (ps2.readButton(PS2_RIGHT_2)  == 1)  && (ps2.readButton(PS2_LEFT_1)  == 1)  && (ps2.readButton(PS2_LEFT_2)  == 1))
  {
    digitalWrite(r1 , HIGH);
    //digitalWrite(r2 , LOW);
    //digitalWrite(r3 , LOW);
    digitalWrite(r4 , LOW);

  }
  if ((ps2.readButton(PS2_RIGHT_1)  == 1) && (ps2.readButton(PS2_RIGHT_2)  == 0)  && (ps2.readButton(PS2_LEFT_1)  == 1)  && (ps2.readButton(PS2_LEFT_2)  == 1))
  {
    digitalWrite(r1 , HIGH);
    //digitalWrite(r2 , HIGH);
    //digitalWrite(r3 , LOW);
    digitalWrite(r4 , HIGH);

  }
  if ((ps2.readButton(PS2_RIGHT_1)  == 1) && (ps2.readButton(PS2_RIGHT_2)  == 1)  && (ps2.readButton(PS2_LEFT_1)  == 1)  && (ps2.readButton(PS2_LEFT_2)  == 1))
  {
    digitalWrite(r1 , LOW);
  //  digitalWrite(r2 , LOW);
   // digitalWrite(r3 , HIGH);
    digitalWrite(r4 , LOW);

  }
//  if ((ps2.readButton(PS2_RIGHT_1)  == 1) && (ps2.readButton(PS2_RIGHT_2)  == 1)  && (ps2.readButton(PS2_LEFT_1)  == 1)  && (ps2.readButton(PS2_LEFT_2)  == 0))
//  {
//    digitalWrite(r1 , LOW);
//    digitalWrite(r2 , LOW);
//    digitalWrite(r3 , HIGH);
//    digitalWrite(r4 , HIGH);
//
//  }
//  if ((ps2.readButton(PS2_RIGHT_1)  == 0) && (ps2.readButton(PS2_RIGHT_2)  == 1)  && (ps2.readButton(PS2_LEFT_1)  == 0)  && (ps2.readButton(PS2_LEFT_2)  == 1))
//  {
//    digitalWrite(r1 , HIGH);
//    digitalWrite(r2 , LOW);
//    digitalWrite(r3 , HIGH);
//    digitalWrite(r4 , LOW);
//
//  }
//  if ((ps2.readButton(PS2_RIGHT_1)  == 1) && (ps2.readButton(PS2_RIGHT_2)  == 0)  && (ps2.readButton(PS2_LEFT_1)  == 1)  && (ps2.readButton(PS2_LEFT_2)  == 0))
//  {
//    digitalWrite(r1 , HIGH);
//    digitalWrite(r2 , HIGH);
//    digitalWrite(r3 , HIGH);
//    digitalWrite(r4 , HIGH);
//
//  }
//  if ((ps2.readButton(PS2_RIGHT_1)  == 0) && (ps2.readButton(PS2_RIGHT_2)  == 1)  && (ps2.readButton(PS2_LEFT_1)  == 1)  && (ps2.readButton(PS2_LEFT_2)  == 0))
//  {
//    digitalWrite(r1 , HIGH);
//    digitalWrite(r2 , LOW);
//    digitalWrite(r3 , HIGH);
//    digitalWrite(r4 , HIGH);
//
//  }
//  if ((ps2.readButton(PS2_RIGHT_1)  == 1) && (ps2.readButton(PS2_RIGHT_2)  == 0)  && (ps2.readButton(PS2_LEFT_1)  == 0)  && (ps2.readButton(PS2_LEFT_2)  == 1))
//  {
//    digitalWrite(r1 , HIGH);
//    digitalWrite(r2 , HIGH);
//    digitalWrite(r3 , HIGH);
//    digitalWrite(r4 , LOW);
//
//  }
//  if ((ps2.readButton(PS2_RIGHT_1)  == 1) && (ps2.readButton(PS2_RIGHT_2)  == 1)  && (ps2.readButton(PS2_LEFT_1)  == 1)  && (ps2.readButton(PS2_LEFT_2)  == 1))
//  {
//    digitalWrite(r1 , LOW);
//    digitalWrite(r2 , LOW);
//    digitalWrite(r3 , LOW);
//    digitalWrite(r4 , LOW);
//
//  }
}


