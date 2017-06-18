#include <SPI.h>
#include <MFRC522.h>
//#include <NexScrolltext.h>
//#include <Nextion.h>

#define SS_PIN 53
#define RST_PIN 5
#define BAUD 9600

MFRC522 RFID_Reader(SS_PIN, RST_PIN);

byte nUID_PICC[4];

void setup() {
  Serial.begin(BAUD);
  Serial1.begin(BAUD);
  SPI.begin();
  RFID_Reader.PCD_Init();
//  nexInit();
  Serial.println("Device Connection Established!");

  
}

void loop() {
  if (!RFID_Reader.PICC_IsNewCardPresent());
    return;

  if (!RFID_Reader.PICC_ReadCardSerial())
    return;

  for (byte i=0; i<4; i++){
    nUID_PICC[i] = RFID_Reader.uid.uidByte[i];
  }

  String RFIDID = "";
  String lastRfid = "";
  
  for (byte i=0; i<RFID_Reader.uid.size; i++) {
    RFIDID += RFID_Reader.uid.uidByte[i] < 0x10 ? "0" : "";
    RFIDID += String(RFID_Reader.uid.uidByte[i], HEX);
  }

  RFIDID.trim();
  RFIDID.toUpperCase();

  if (RFIDID == lastRfid)
    return;
    
  lastRfid = RFIDID;
  
  RFID_Reader.PICC_HaltA();
  RFID_Reader.PCD_StopCrypto1();

  Serial.println(RFIDID);
  Serial.println("Scanning complete!");

}
