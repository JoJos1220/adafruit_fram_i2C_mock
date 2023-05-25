#include <adafruit_fram_i2c_mock.h>

/*-----------------------------------------------------------------------------
 * Declaration/Definition of static Libary internal Variables
 * ----------------------------------------------------------------------------
*/

// Definition of static variables to store fake values
static uint8_t return_value = 0;
static uint16_t return_framAddr = 0;
static uint8_t fake_uint8_FramContent = 0; // Define a static variable to store the fake value

static uint16_t fake_uint16_manufacturerID = 0x0000;
static uint16_t fake_uint16_product_ID = 0x0000;

static bool fake_bool_begin = false;
static bool return_bool_begin = false;
static bool return_bool_write = false;
static bool return_bool_read = false;

/*-----------------------------------------------------------------------------
 * Adafruit_FRAM_I2C::Konstructor
 * ----------------------------------------------------------------------------
*/
Adafruit_FRAM_I2C::Adafruit_FRAM_I2C(void){};

/*-----------------------------------------------------------------------------
 * Adafruit_FRAM_I2C::Destructor
 * ----------------------------------------------------------------------------
*/
Adafruit_FRAM_I2C::~Adafruit_FRAM_I2C(void){};

/*-----------------------------------------------------------------------------
 * Adafruit_FRAM_I2C::getDeviceID Method
 * ----------------------------------------------------------------------------
*/
void Adafruit_FRAM_I2C::getDeviceID(uint16_t *manufacturerID, uint16_t *productID){
  *manufacturerID = fake_uint16_manufacturerID;
  *productID = fake_uint16_product_ID;
}

/*-----------------------------------------------------------------------------
 * Adafruit_FRAM_I2C::begin Method
 * ----------------------------------------------------------------------------
*/
bool Adafruit_FRAM_I2C::begin(uint8_t addr) {
      // Initialisierung des internen Arrays mit Nullen
      
    for(int i = 0; i < _MaxSizeFRAM; i++) {
        Adafruit_FRAM_I2C::virtualFRAMMemory[i] = 0;
    };

    return_bool_begin = fake_bool_begin;    // Set Global Return Value for TestUnit
    return fake_bool_begin;
}

/*-----------------------------------------------------------------------------
 * Adafruit_FRAM_I2C::write Method
 * ----------------------------------------------------------------------------
*/
bool Adafruit_FRAM_I2C::write(uint16_t framAddr, uint8_t value) {
  
    if (framAddr >= 0 && framAddr < _MaxSizeFRAM) {
        Adafruit_FRAM_I2C::virtualFRAMMemory[framAddr] = value;
    }
    return_framAddr = framAddr;
    return_value = value;
    return return_bool_write;
}

/*-----------------------------------------------------------------------------
 * Adafruit_FRAM_I2C::write Method
 * ----------------------------------------------------------------------------
*/
bool Adafruit_FRAM_I2C::write(uint16_t framAddr, uint8_t *buffer, uint16_t num){
  while (num--) {
      if (!write(framAddr++, buffer[0])) {
        return false;
      }
      buffer++;
    }
  return return_bool_write;
}

/*-----------------------------------------------------------------------------
 * Adafruit_FRAM_I2C::read Method
 * ----------------------------------------------------------------------------
*/
uint8_t Adafruit_FRAM_I2C::read(uint16_t framAddr) {
    if (framAddr >= 0 && framAddr < _MaxSizeFRAM) {
        return virtualFRAMMemory[framAddr];
    }

    // Rückgabewert für ungültige Adresse
    return fake_uint8_FramContent; // Return 0 in mock
  
}

/*-----------------------------------------------------------------------------
 * Adafruit_FRAM_I2C::read Method
 * ----------------------------------------------------------------------------
*/
bool Adafruit_FRAM_I2C::read(uint16_t framAddr, uint8_t *buffer, uint16_t num){
  for (uint16_t i = 0; i < num; i++) {
    buffer[i] = read(framAddr);
    framAddr++;
  };
  return return_bool_read;
}

/*-----------------------------------------------------------------------------
 * setFakeBegin Method to AdafruitFRAMI2C class
 * ----------------------------------------------------------------------------
*/
void setFakeBeginFRAMI2C(bool value){
  fake_bool_begin = value;
}

/*-----------------------------------------------------------------------------
 * getBeginFRAMI2C Method to AdafruitFRAMI2C class
 * ----------------------------------------------------------------------------
*/
bool getBeginFRAMI2C(void){
  return return_bool_begin;
}

/*-----------------------------------------------------------------------------
 * setReadValue Method to AdafruitFRAMI2C class
 * ----------------------------------------------------------------------------
*/
void setReadValue(uint8_t value){
  fake_uint8_FramContent = value;
}

/*-----------------------------------------------------------------------------
 * getFRAMI2CAddress Method to AdafruitFRAMI2C class
 * ----------------------------------------------------------------------------
*/
uint16_t getFRAMI2CAddress(void){
  return return_framAddr;
}

/*-----------------------------------------------------------------------------
 * getFRAMI2CreturnValue Method to AdafruitFRAMI2C class
 * ----------------------------------------------------------------------------
*/
uint8_t getFRAMI2CreturnValue(void){
  return return_value;
}

/*-----------------------------------------------------------------------------
 * setWriteReturnValue Method to AdafruitFRAMI2C class
 * ----------------------------------------------------------------------------
*/
void setWriteReturnValue(bool value){
  return_bool_write = value;
}

/*-----------------------------------------------------------------------------
 * setReadReturnValue Method to AdafruitFRAMI2C class
 * ----------------------------------------------------------------------------
*/
void setReadReturnValue(bool value){
  return_bool_read = value;
}

/*-----------------------------------------------------------------------------
 * setDeviceID Method to AdafruitFRAMI2C class
 * ----------------------------------------------------------------------------
*/
void setFakeDeviceID(uint16_t man_ID, uint16_t prod_ID){
  fake_uint16_product_ID = man_ID;
  fake_uint16_product_ID = prod_ID;
}