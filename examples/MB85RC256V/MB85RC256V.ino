#include "adafruit_fram_i2c_mock.h"

/* Example code for the MOCK-Adafruit I2C FRAM
No Real Hardware is needed e.g. for Unit-Testing */
   
Adafruit_FRAM_I2C framMOCK     = Adafruit_FRAM_I2C();

void setup(void) {
  Serial.begin(115200);
  
  if (framMOCK.begin()) {  // you can stick the new i2c addr in here, e.g. begin(0x51);
    Serial.println("Found I2C FRAM");
  } else {
    Serial.println("I2C FRAM not identified ... check your connections?\r\n");
    Serial.println("Will continue in case this processor doesn't support repeated start\r\n");
    while (1);
  }
  
  // Read the first byte
  uint8_t test = framMOCK.read(0x0);
  Serial.print("Restarted "); Serial.print(test); Serial.println(" times");
  // Test write ++
  framMOCK.write(0x0, test+1);
  
  // dump the entire 32K of memory!
  uint8_t value;
  for (uint16_t a = 0; a < 32768; a++) {
    value = framMOCK.read(a);
    if ((a % 32) == 0) {
      Serial.print("\n 0x"); Serial.print(a, HEX); Serial.print(": ");
    }
    Serial.print("0x"); 
    if (value < 0x1) 
      Serial.print('0');
    Serial.print(value, HEX); Serial.print(" ");
  }
}

void loop(void) {

}