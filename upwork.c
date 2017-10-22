*
* NOTE: The library file MFRC522.h has a lot of useful info. Please read it.
*
* ----------------------------------------------------------------------------
* Typical pin layout used:
* -----------------------------------------------------------------------------------------
* MFRC522 Arduino Arduino Arduino Arduino Arduino
* Reader/PCD Uno Mega Nano v3 Leonardo/Micro Pro Micro
* Signal Pin Pin Pin Pin Pin Pin
* -----------------------------------------------------------------------------------------
* RST/Reset RST 9 5 D9 RESET/ICSP-5 RST
* SPI SS SDA(SS) 10 53 D10 10 10
* SPI MOSI MOSI 11 / ICSP-4 51 D11 ICSP-4 16
* SPI MISO MISO 12 / ICSP-1 50 D12 ICSP-1 14
* SPI SCK SCK 13 / ICSP-3 52 D13 ICSP-3 15
*
*/
#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>

#define RST_PIN 5 // Configurable, see typical pin layout above // was 9
#define SS_PIN_1 53 // Configurable, see typical pin layout above // was 10
#define SS_PIN_2 2 // Configurable, see typical pin layout above // was 8
#define SS_PIN_3 3 // Configurable, see typical pin layout above
#define SS_PIN_4 4 // Configurable, see typical pin layout above

#define NR_OF_READERS 4
#define NR_OF_KEYES 4

int RELAY_CH[] = {45, 46, 47, 48}; // Was: 2, 3
int NUM_RELAY_CH = 4;

#define BUTTON 4

byte ssPins[] = {SS_PIN_1, SS_PIN_2, SS_PIN_3, SS_PIN_4};
// format = {SS_PIN_1, SS_PIN_2, SS_PIN_3, etc.}

MFRC522 mfrc522[NR_OF_READERS]; // Create MFRC522 instance.

bool finished = false;
bool in_progress = false;

bool reader1_triggered = false;
bool reader1_complete = false;
bool reader2_triggered = false;
bool reader2_complete = false;
bool reader3_triggered = false;
bool reader3_complete = false;
bool reader4_triggered = false;
bool reader4_complete = false;

String ok_RFID_reader1 = "b09b894d";
String ok_RFID_reader2 = "60f71b83";
String ok_RFID_reader3 = "e6a0227e";
String ok_RFID_reader4 = "10dc1783";
String RFID_whitelist[] = {"b09b894d", "60f71b83", "e6a0227e", "10dc1783"}; // Add as many as needed
String read_rfid;

void setup() {
    Serial.begin(9600); // Initialize serial communications with the PC
    while (!Serial); // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
    
    SPI.begin(); // Init SPI bus
    SPI.setClockDivider(SPI_CLOCK_DIV128);
    //MFRC522.MFRC522_SPICLOCK = SPI_CLOCK_DIV4;
    
    pinMode(BUTTON, INPUT);
    
    for(uint8_t i=0; i<NUM_RELAY_CH; i++) {
        pinMode(RELAY_CH[i], OUTPUT);
        pinMode(RELAY_CH[i], LOW);
    }
    
    for (uint8_t reader = 0; reader < NR_OF_READERS; reader++) {
        mfrc522[reader].PCD_Init(ssPins[reader], RST_PIN); // Init each MFRC522 card
        Serial.print(F("Reader "));
        Serial.print(reader);
        Serial.print(F(": "));
        mfrc522[reader].PCD_DumpVersionToSerial();
        delay(200);
    }
}




// Convert card UID to string
void dump_byte_array(byte *buffer, byte bufferSize) {
    read_rfid="";
    for (byte i = 0; i < bufferSize; i++) {
        read_rfid=read_rfid + String(buffer[i], HEX);
    }
}




void loop() {
    for (uint8_t reader = 0; reader < NR_OF_READERS; reader++) {
        // Look for new cards
        
        if (mfrc522[reader].PICC_IsNewCardPresent() && mfrc522[reader].PICC_ReadCardSerial()) {
            Serial.print(F("Reader "));
            Serial.print(reader);
            // Show some details of the PICC (that is: the tag/card)
            Serial.print(F(": Card UID:"));
            dump_byte_array(mfrc522[reader].uid.uidByte, mfrc522[reader].uid.size);
            Serial.println(read_rfid);
            // Stop encryption on PCD
            mfrc522[reader].PCD_StopCrypto1();
            
            authenticate_Card(reader, read_rfid);
            
            delay(800);
        }
    }
    
    int button1 = digitalRead(BUTTON);
    if(button1 == HIGH) {
        // Activate RELAY_CH
    }
    
    // Ruler Pillar Light Function
    if(reader1_triggered) {
        // Activate RELAY_CH
        digitalWrite(RELAY_CH[0], HIGH);
    }
    if(reader2_triggered) {
        // Activate RELAY_CH
        digitalWrite(RELAY_CH[1], HIGH);
    }
    if(reader3_triggered) {
        // Activate RELAY_CH
        digitalWrite(RELAY_CH[2], HIGH);
    }
    if(reader4_triggered) {
        // Activate RELAY_CH
        digitalWrite(RELAY_CH[3], HIGH);
    }
}

void authenticate_Card(int reader_id, String uid) {
    in_progress = true;
    
    if(reader_id == 0) {
        if(uid == ok_RFID_reader1) {
            Serial.println("Authenticated Ruler 1");
            reader1_triggered = true;
            // Light response handled in loop()
        }
    }
    if(reader_id == 1) {
        if(uid == ok_RFID_reader2) {
            Serial.println("Authenticated Ruler 2");
            reader2_triggered = true;
            // Light response handled in loop()
        }
    }
    if(reader_id == 2) {
        if(uid == ok_RFID_reader3) {
            Serial.println("Authenticated Ruler 3");
            reader3_triggered = true;
            // Light response handled in loop()
        }
    }
    if(reader_id == 3) {
        if(uid == ok_RFID_reader4) {
            Serial.println("Authenticated Ruler 4");
            reader4_triggered = true;
            // Light response handled in loop()
        }
    }
    else {
        for(uint8_t i = 0; i < NR_OF_KEYES; i++) {
            if(uid == ok_RFID_reader1) {
                if(reader1_triggered) {
                    reader1_complete = true;
                    reader1_triggered = false;
                }
                // Turn off ruler lights
                
            }
            if(uid == ok_RFID_reader2) {
                if(reader2_triggered) {
                    reader2_complete = true;
                    reader2_triggered = false;
                }
                // Turn off ruler lights
                
            }
            if(uid == ok_RFID_reader3) {
                if(reader3_triggered) {
                    reader3_complete = true;
                    reader3_triggered = false;
                }
                // Turn off ruler lights
                
            }
            if(uid == ok_RFID_reader4) {
                if(reader4_triggered) {
                    reader4_complete = true;
                    reader4_triggered = false;
                }
                // Turn off ruler lights
                
            }
            
        }
    }
}

void resetPuzzle() {
    finished = false;
    reader1_complete = false;
    reader1_triggered = false;
    reader2_complete = false;
    reader2_triggered = false;
    reader3_complete = false;
    reader3_triggered = false;
    reader4_complete = false;
    reader4_triggered = false;
    // Turn off ruler lights handled in loop() section
}


 void dataPacket(int slaveID, byte data) {
 Wire.beginTransmission(slaveID);
 Wire.write(data);
 delay(100);
 Wire.endTransmission();
 }
 
 void receiveEvent(int howMany) {
 int inChar;
 while(Wire.available() > 0) {
 inChar = Wire.read();
 
 if(inChar == 299) {
 resetPuzzle();
 }
 
 Serial.println(inChar);
 }
 }
 
 void requestEvent() {
 if(reader1_complete and reader2_complete) {
 in_progress = false;
 finished = true;
 }
 // Just for show test
 if(reader1_triggered and reader2_triggered) {
 in_progress = false;
 finished = true;
 }
 // End test
 if(in_progress) {
 Serial.println(253);
 }
 if(finished) {
 Serial.println(251);
 }
 else {
 Serial.println(250);
 }
 delay(100);
