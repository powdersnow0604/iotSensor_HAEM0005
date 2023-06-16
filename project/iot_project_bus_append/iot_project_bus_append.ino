#include <SoftwareSerial.h>
#include <Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial bluetooth(13, 12);
Servo servo1; //servo1 변수 선언
Servo servo2; //servo2 변수 선언
int motor1 = 9; //motor1을 입출력 3번 핀에 연결
int motor2 = 6; //motor2을 입출력 5번 핀에 연결

String busnum;
void setup() {
  bluetooth.begin(9600);
  Serial.begin(9600);
  pinMode(10,OUTPUT); //led
  pinMode(11,INPUT); //push button
  servo1.attach(motor1);
  servo2.attach(motor2);
  lcd.begin();
  lcd.backlight();
  servo1.write(0);
  delay(1000);
  servo2.write(0);
  delay(1000);
}

void loop() {
  if(bluetooth.available())
  {
    busnum = bluetooth.readString();

    /*lcd-1602*/
    lcd.setCursor(6, 0);
    lcd.print(busnum);

    digitalWrite(10,HIGH);
    while(digitalRead(11)==0) {delay(10);}
    digitalWrite(10,LOW);
    
    /*의자접기*/
    servo1.write(90);
    delay(1000);
    servo2.write(90);
    delay(1000);
    Serial.print('s');
    while(Serial.available()==0) {delay(10);}
    Serial.read();

    /*의자 펴기*/
    servo1.write(0);
    delay(1000);
    servo2.write(0);
    delay(1000);

    lcd.clear();
  }
}
