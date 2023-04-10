int Pin = A0;
int reading;
float tempC;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  reading = analogRead(Pin);
  tempC = (5.0*reading*100.0)/1024.0;
  Serial.print(tempC);
  Serial.println(" 도");
  delay(1000);
}
