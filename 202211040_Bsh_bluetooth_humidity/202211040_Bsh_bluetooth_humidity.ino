#include <SoftwareSerial.h>
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11

SoftwareSerial bluetooth(7, 8);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  bluetooth.begin(9600);
  //Serial.begin(9600);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(3000);
  int h = dht.readHumidity();
  int t = dht.readTemperature();
  bluetooth.print("Humidity: ");
  bluetooth.print(h);
  bluetooth.print(" %\t");
  bluetooth.print("Temperature: ");
  bluetooth.print(t);
  bluetooth.println(" C");
}
