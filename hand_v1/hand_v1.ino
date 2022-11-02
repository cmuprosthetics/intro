#include <Servo.h>

const int f1_pin = 11;
const int f2_pin = 6;
const int f3_pin = 10;
const int t_pin = 5;
const int p_pin = 3;
const int ts_pin = 9;

Servo f1;
Servo f2;
Servo f3;
Servo t;
Servo p;
Servo ts;



void setup() {
  // put your setup code here, to run once:
  f1.attach(f1_pin);
  f2.attach(f2_pin);
  f3.attach(f3_pin);
  t.attach(t_pin);
  ts.attach(ts_pin);
  p.attach(p_pin);
//  Serial.begin(9600);
  f1.write(0);
  f2.write(0);
  f3.write(0);
  t.write(90);
  ts.write(75); //works, range is from 45 to 75
  p.write(0); //works

}

void loop() {
  // put your main code here, to run repeatedly:
  f3.write(0);
  delay(1000);
  f3.write(180);
  delay(1000);

}
