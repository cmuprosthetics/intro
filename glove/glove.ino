#include <Servo.h>

const int flex1_pin = A1;      // Pin connected to voltage divider output
const int flex2_pin = A2;
const int flex3_pin = A3;
const int flex4_pin = A4;

const int f1_pin = 11;
const int f2_pin = 6;
const int f3_pin = 10;
const int t_pin = 5;
const int p_pin = 3;
const int ts_pin = 9;

int f1_pos = 0;
int f2_pos = 0;
int f3_pos = 0;

Servo f1;
Servo f2;
Servo f3;
Servo t;
Servo p;
Servo ts;


void setup() {
  Serial.begin(9600);
  pinMode(flex1_pin, INPUT);
  pinMode(flex2_pin, INPUT);
  pinMode(flex3_pin, INPUT);
  pinMode(flex4_pin, INPUT);
  
  f1.attach(f1_pin);
  f2.attach(f2_pin);
  f3.attach(f3_pin);
  t.attach(t_pin);
  ts.attach(ts_pin);
  p.attach(p_pin);
  f1.write(0);
  f2.write(0);
  f3.write(0);
  t.write(90);
  ts.write(75); //works, range is from 45 to 75
  p.write(0); //works
  
}

void loop() {
  // Read the ADC, and calculate voltage and resistance from it
//  int flex1 = analogRead(flex4_pin);
//  if(flex1<250) {
//    f1.write(0);
//    f2.write(0);
//    f3.write(0);
//    t.write(0);
//  }
//  else {
//    f1.write(180);
//    f2.write(180);
//    f3.write(180);
//    t.write(180);
//  }

  
  int flex1 = analogRead(flex1_pin);
  if abs(flex1 - f1_pos < 60) {
    if(flex1<250) {
      f1.write(0);
    }
    else {
      f1.write(180);
    }
  }
  f1_pos = flex1;

  
  int flex2 = analogRead(flex2_pin);
  if abs(flex2 - f2_pos < 60) {
    if(flex2<380) {
      f2.write(0);
    }
    else {
      f2.write(180);
    }
  }
  f2_pos = flex2;

  int flex3 = analogRead(flex3_pin);
  if abs(flex3 - f3_pos < 60) {
    if(flex3<250) {
      f3.write(0);
    }
    else {
      f3.write(120);
    }
  }
  f3_pos = flex3;

//  int flex4 = analogRead(flex4_pin);
//  if(flex4<250) {
//    t.write(0);
//  }
//  else {
//    t.write(180);
//  }

}
