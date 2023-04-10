#include <IRremote.h>
int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN); decode_results results;
void setup()
{   Serial.begin(9600);
pinMode(5,OUTPUT);
Serial.println("Enabling IRin");
irrecv.enableIRIn(); // Start the receiver
Serial.println("Enabled IRin");  }

void loop() {
  if (irrecv.decode(&results)) {
  Serial.println(results.value, HEX); 
  irrecv.resume(); // Receive the next value
  if (results.value == 0xFF30CF) digitalWrite(5,HIGH);
  if (results.value == 0xFF18E7) digitalWrite(5,LOW);  

}  }
