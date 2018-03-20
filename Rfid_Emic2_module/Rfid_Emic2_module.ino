#include "SPI.h"
#include "MFRC522.h" 
#include <SoftwareSerial.h>
#include <SD.h>
#include "EMIC2.h"
#define RX_PIN 5
#define TX_PIN 6
EMIC2 emic;
const int pinRST = 9;
const int pinSDA = 10;
MFRC522 mfrc522(pinSDA, pinRST); 
void setup() {
  SPI.begin(); 
  mfrc522.PCD_Init(); 
  Serial.begin(9600); 
  pinMode(8,OUTPUT);
  emic.begin(RX_PIN,TX_PIN);
  emic.setVoice(8);
}
void loop() {
  if (mfrc522.PICC_IsNewCardPresent()) {
    if(mfrc522.PICC_ReadCardSerial()) { 
      digitalWrite(8, HIGH);   
      delay(500);
      digitalWrite(8,LOW);
      delay(500);
      
      byte myid[4] ={0x80,0x91,0xDE,0xA4};   //Card SK
      byte myid1[4] ={0x90,0x91,0xF3,0xA2};  //Card PK
      byte myid2[4] ={0x9B,0x20,0xBA,0x79};   //Card A
      byte myid3[4] ={0xAC,0x8E,0x85,0x89};  //Card B

      int count = 0;
      for (byte i = 0; i < mfrc522.uid.size; ++i) {
        if (mfrc522.uid.uidByte[i] == myid[i]) {
          count++;
        }
      }
      if (count == 4) {
            emic.setVolume(30);
            emic.setRate(90);
            emic.speak("Welcome Sai Krishna! Please enter the medicine name:");
      }
      
      int count1 = 0;
      for (byte i = 0; i < mfrc522.uid.size; ++i) {
        if (mfrc522.uid.uidByte[i] == myid1[i]) {
          count1++;
        }
      }
      if (count1 == 4) {
            emic.setVolume(30);
            emic.setRate(90);
            emic.speak("Welcome Priyakanth! Please enter the medicine name:");
      }
      
      int count2 = 0;
      for (byte i = 0; i < mfrc522.uid.size; ++i) {
        if (mfrc522.uid.uidByte[i] == myid2[i]) {
          count2++;
        }
      }
      if (count2 == 4) {
            emic.setVolume(30);
            emic.setRate(90);
            emic.speak("Welcome Apoorva! Please enter the medicine name:");
      }
      
      int count3 = 0;
      for (byte i = 0; i < mfrc522.uid.size; ++i) {
        if (mfrc522.uid.uidByte[i] == myid3[i]) {
          count3++;
        }
      }
      if (count3 == 4) {
            emic.setVolume(30);
            emic.setRate(90);
            emic.speak("Welcome Bushra! Please enter the medicine name:");
      }
      Serial.println(); // Print out of id is complete.
    }
  }
}
