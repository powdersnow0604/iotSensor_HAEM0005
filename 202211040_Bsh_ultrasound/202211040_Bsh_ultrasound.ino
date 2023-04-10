int trigPin = 2; int echoPin = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  float duration, distance;
  digitalWrite(trigPin,HIGH); delay(10);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = ((float)(340*duration)/10000)/2;
  Serial.print("Duration"); Serial.print(duration);
  Serial.print("\nDistance"); Serial.print(distance);
  Serial.println("cm\n"); delay(500);

}
