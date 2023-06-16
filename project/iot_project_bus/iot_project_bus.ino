#include <Stepper.h>
#include <math.h>

#define steplen 22.2
#define pi 3.14

Stepper myStepper(2048,11,9,10,8);
Stepper Step(2048,3,5,6,4);

void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(14);
  Step.setSpeed(14);
  pinMode(2,OUTPUT); //trigpin
  pinMode(7,INPUT); //echopin
}

void loop() {
  if(Serial.available())
  {
    Serial.read();
   
    myStepper.step(-2048*6);
    delay(20000);

    //delay((60/16 * 2048*5/2048)*1000 + 500);

    digitalWrite(2,HIGH); delay(10);
    digitalWrite(2,LOW);
    float distance = ((float)(340*pulseIn(7,HIGH))/10000)/2 +1;
    int angle = 180/pi * (pi/2 - acos(distance/steplen)) * 2048/360 * 2.5;
    
    Step.step(-angle);
    //delay((60/16 * angle/2048)*1000 + 500);
    delay(5000);

    Step.step(angle);
    //delay((60/16 * angle/2048)*1000 + 500);


    myStepper.step(2048*6);
    //delay((60/16 * 2048*5/2048)*1000 + 500);
    delay(20000);
    Serial.print('d');
  }
}
