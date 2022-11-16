#include <Servo.h>

const int flexPin = A1;      // Pin connected to voltage divider output
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

int a1 = 0;
int a2 = 0;
int a3 = 0;
int a4 = 0;
int a5 = 0;
Servo ts;

// Change these constants according to your project's design
const float VCC = 5;      // voltage at Ardunio 5V line
const float R_DIV = 200000.0;  // resistor used to create a voltage divider
const float flatResistance = 27000.0; // resistance when flat, Sensor 1: T1-50, T2-45, T3-35
const float bendResistance = 55000.0;  // resistance at 90 deg, Retesting, max hit at 65, angle<90, T3-50

void setup() {
  Serial.begin(9600);
  pinMode(flexPin, INPUT);

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
  // Read the ADC, and calculate voltage and resistance from it
  int ADCflex = analogRead(flexPin);
  float Vflex = ADCflex * VCC / 1023.0;
  float Rflex = R_DIV * (VCC / Vflex - 1.0);
 // Serial.println("Resistance: " + String(Rflex) + " ohms");

  // Use the calculated resistance to estimate the sensor's bend angle:
  float angle = map(Rflex, flatResistance, bendResistance, 0, 90.0);
  //Serial.println("Bend: " + String(angle) + " degrees");
  //Serial.println();
  
  a1 = a2;
  a2 = a3;
  a3 = a4;
  a4 = a5;

  int a = 0;
  if (angle > 180){a = 180;}
  else if (angle > 0) {a = angle;}

  if (a > a4 + 5) {a = a4 + 5;}
  
  a5 = a;
  int res = (a1 + a2 + a3 + a4 + a5) / 5;

  Serial.println(res);

  if(res<0)
  {
    f1.write(0);
  }
  else if(res>180)
  {
    f2.write(180);
  }
  else
  {
    f1.write(angle);
  }
   
  delay(500);
}
