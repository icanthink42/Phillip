#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_PN532.h>
 
#define PN532_IRQ   (2)
#define PN532_RESET (3)  // Not connected by default on the NFC Shield
 
Adafruit_PN532 nfc(PN532_IRQ, PN532_RESET);
 
void setup(void) 
{
  analogWrite(A3, HIGH);
  Serial.begin(115200);
  while (!Serial) delay(10);
  Serial.println("Finding NFC scanner...");
 
  if (!nfc.begin()) {
    Serial.print("Begin Failed");
    while (1); // halt!
  }
  Serial.println("NFC object init'd!");
 
  uint32_t versiondata = nfc.getFirmwareVersion();
  if (! versiondata) 
  {
    Serial.print("Didn't find PN53x board");
    while (1); // halt
  }
  
  Serial.print("Found chip PN5"); 
  Serial.println((versiondata>>24) & 0xFF, HEX); 
  Serial.print("Firmware ver. "); 
  Serial.print((versiondata>>16) & 0xFF, DEC); 
  Serial.print('.'); Serial.println((versiondata>>8) & 0xFF, DEC);
 
  nfc.setPassiveActivationRetries(0xFF);

  nfc.SAMConfig();
}
 
void loop(void) 
{
  boolean success;
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };
  uint8_t uidLength;  
 
  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, &uid[0], &uidLength);
  
  if (success) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
 
    delay(1000);

    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);

  }
  else
  {
    Serial.println("Timed out waiting for a card");
  }
}
