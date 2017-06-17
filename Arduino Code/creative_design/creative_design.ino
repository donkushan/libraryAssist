#include <SPI.h>
#include <MFRC522.h>
#include <NexScrolltext.h>
#include <Nextion.h>

#define SS_PIN 53
#define RST_PIN 5
#ddeffine BAUD 9600

MFRC522 RFID_reader(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(BAUD);
  Serial1.begin(BAUD);
  SPI.begin();
  RFID_reader.PCD_Init();
  nexInit();
  Serial.println("Device Connection Established!");

  
}

void loop() {
  if (!RFID_reader.PICC_IsNewCardPresent                                                                                                                                                                            )
 
------------------------------------------------------------------------------------------------------}
