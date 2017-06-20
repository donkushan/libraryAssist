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

  // Setup Wi-Fi connection
//  sendCommand("AT+RST\r\n", 2000, DEBUG); // reset module
//  sendCommand("AT+CWMODE=1\r\n", 1000, DEBUG); // configure as access point
//  sendCommand("AT+CWJAP=\"NOKIA\",\"heshansandeepa94\"\r\n", 3000, DEBUG);
//  sendCommand("AT+CIPMUX=0\r\n", 1000, DEBUG); // configure for single connections
//  Serial.println("Wi-Fi connection established!");
//  Serial.println("Setup complete!");
  
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

///**
//   Initialization for the Display ////////// display ////////// display ////////// display //////////
//*/
//NexPage home_page = NexPage(0, 0, "home_page");
//NexPage login_page = NexPage(1, 0, "login_page");
//NexPage id_page = NexPage(2, 0, "id_page");
//NexPage search_page = NexPage(4, 0, "serch_page");
//NexPage search_bk_page = NexPage(5, 0, "search_bk_page");
//NexPage lend_page = NexPage(6, 0, "lend_page");
//NexPage return_page = NexPage(7, 0, "return_page");
//NexPage guest_page = NexPage(8, 0, "guest_page");
//
//// Setup for login_page
//NexText login_user = NexText(1, 3, "login_user");
//NexText login_password = NexText(1, 5, "login_password");
//NexButton login_login = NexButton(1, 7, "login_login");
//
//// Setup for id_page
//NexButton id_proceed = NexButton(2, 7, "id_proceed");
//NexScrolltext id_id_details = NexScrolltext(2, 4, "is_is_details");
//
//// Setup for search_page
//NexButton search_scan = NexButton(4, 2, "search_scan");
//NexText scan_floor = NexText(4, 3, "scan_floor");
//NexText scan_rack = NexText(4, 4, "scan_rack");
//NexText scan_deck = NexText(4, 5, "scan_deck");
//
//// Setup for search_bk_page
//NexButton srch_bk_prcd = NexButton(5, 9, "srch_bk_prcd");
//NexText srch_bk_name = NexText(4, 4, "srch_bk_name");
//NexText srch_bk_author = NexText(4, 5, "srch_bk_author");
//NexScrolltext srch_bk_det = NexScrolltext(4, 6, "srch_bk_det");
//
//// Setup for lend_page
//NexButton lend_scan_id = NexButton(6, 4, "lend_scan_id");
//NexButton lend_scan_bk = NexButton(6, 6, "lend_scan_bk");
//NexButton lend_proceed = NexButton(6, 8, "lend_proceed");
//NexText lend_user_st = NexText(6, 5, "lend_user_st");
//NexText lend_book_st = NexText(6, 7, "lend_book_st");
//NexText lend_status = NexText(6, 9, "lend_status");
//NexScrolltext lend_user_det = NexScrolltext(6, 10, "lend_user_det");
//NexScrolltext lend_book_det = NexScrolltext(6, 11, "lend_book_det");
//
//// Setup for return_page
//NexButton retn_scan_id = NexButton(7, 4, "retn_scan_id");
//NexButton retn_scan_bk = NexButton(7, 7, "retn_scan_bk");
//NexButton retn_proceed = NexButton(7, 8, "retn_proceed");
//NexText retn_user_st = NexText(7, 5, "retn_user_st");
//NexText retn_book_st = NexText(7, 6, "retn_book_st");
//NexText retn_st = NexText(7, 9, "retn_st");
//NexScrolltext retn_user_det = NexScrolltext(7, 10, "retn_user_det");
//NexScrolltext retn_book_det = NexScrolltext(7, 11, "retn_book_det");
//
//// Setup for guest_page
//NexButton guest_proceed = NexButton(8, 9, "guest_proceed");
//NexText guest_name = NexText(8, 5, "guest_name");
//NexText guest_author = NexText(8, 7, "guest_author");
//NexScrolltext guest_det = NexScrolltext(8, 8, "guest_det");
//
//// Touch listener fo touch event detection
//NexTouch *nex_listen_list[] =
//{
//  &login_user,
//  &login_password,
//  &login_login,
//  &id_proceed,
//  &id_id_details,
//  &search_scan,
//  &scan_floor,
//  &scan_rack,
//  &scan_deck,
//  &srch_bk_prcd,
//  &srch_bk_name,
//  &srch_bk_author,
//  &srch_bk_det,
//  &lend_scan_id,
//  &lend_scan_bk,
//  &lend_proceed,
//  &lend_user_st,
//  &lend_book_st,
//  &lend_status,
//  &lend_user_det,
//  &lend_book_det,
//  &retn_scan_id,
//  &retn_scan_bk,
//  &retn_proceed,
//  &lend_user_st,
//  &lend_book_st,
//  &lend_status,
//  &lend_user_det,
//  &lend_book_det,
//  &guest_proceed,
//  &guest_name,
//  &guest_author,
//  &guest_det,
//  NULL
//};

//// login_login button function
//void loginToAdmin(void *ptr) {
//  //    memset(buffer_1, 0, sizeof(buffer_1));
//  ////    memset(buffer_2, 0, sizeof(buffer_2));
//  //    login_user.getText(buffer_1, sizeof(buffer_1));
//  ////    login_password.getText(buffer_2, sizeof(buffer_2));
//  //    Serial.println(buffer_1);
//
//  Serial.println("success!");
//  sendCommand("AT+CIPSTART=\"TCP\",\"192.168.137.55\",1250\r\n", 2000, DEBUG); // reset module
//  delay(2000);
//  sendCIPData("fuckass\r\n");
//  sendCommand("AT+CIPCLOSE", 1000, DEBUG);
//
//}
