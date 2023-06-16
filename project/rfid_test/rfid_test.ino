#include <SPI.h>
#include <MFRC522.h>
#include <SoftwareSerial.h>

#define RST_PIN 9  
#define SS_PIN 10  
                   
SoftwareSerial bluetooth(3, 2);

MFRC522 mfrc(SS_PIN, RST_PIN);  

void setup() {
  bluetooth.begin(9600);
  Serial.begin(9600);
  SPI.begin();  
  mfrc.PCD_Init();
}

void loop() {
  if (!mfrc.PICC_IsNewCardPresent() || !mfrc.PICC_ReadCardSerial()) {
    delay(500);
    return;
  }

  /*밑의 if문의 조건의 숫자가 카드 고유의 인식번호임*/
  if (mfrc.uid.uidByte[0] == 164 && mfrc.uid.uidByte[1] == 96 && mfrc.uid.uidByte[2] == 4 && mfrc.uid.uidByte[3] == 4) {
    bluetooth.print("selected");
    
    while (!bluetooth.available()) {delay(10);}
    String stt = bluetooth.readString();
    if (stt == "7016") {
      Serial.println("7016 has selected");
    }
    else if (stt == "1711") {
      Serial.println("1711 has selected");
    }
    else if (stt == "7018") {
      Serial.println("7018 has selected");
    }
    else if (stt == "7212") {
      Serial.println("7212 has selected");
    }
  } 
  else {
    bluetooth.print("wrong");

    delay(5000);
  }

}
