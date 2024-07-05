#ifndef ADAFURIT_FRAM_I2C_H
#define ADAFURIT_FRAM_I2C_H

/*-----------------------------------------------------------------------------
 * Including of Libary Dependencies
 * ----------------------------------------------------------------------------
*/
#include <stdint.h>

#define MB85RC_DEFAULT_ADDRESS (0x50)

#define _MaxSizeFRAM 32767 //Max Words in Fram --> 32767 words x 8 bits

class Adafruit_FRAM_I2C {
  public:
    Adafruit_FRAM_I2C(void);
    ~Adafruit_FRAM_I2C(void);

    bool begin(uint8_t addr = MB85RC_DEFAULT_ADDRESS);
    void getDeviceID(uint16_t *manufacturerID, uint16_t *productID);

    bool write(uint16_t framAddr, uint8_t value);
    bool write(uint16_t framAddr, uint8_t *buffer, uint16_t num);

    uint8_t read(uint16_t framAddr);
    bool read(uint16_t framAddr, uint8_t *buffer, uint16_t num);

    template <class T> uint16_t writeObject(uint16_t addr, const T &value) {
      const int8_t *p = (const int8_t *)(const void *)&value;
      uint16_t n;
      for (n = 0; n < sizeof(value); n++) {
        Adafruit_FRAM_I2C::write(addr++, *p++);
      }
      return n;
    }

    template <class T> uint16_t readObject(uint16_t addr, T &value) {
      int8_t *p = (int8_t *)(void *)&value;
      uint16_t n;
      for (n = 0; n < sizeof(value); n++) {
        *p++ = Adafruit_FRAM_I2C::read(addr++);
      }
      return n;
    }

  private:
    uint8_t virtualFRAMMemory[_MaxSizeFRAM];
};

void setReadValue(uint8_t value);
void setWriteReturnValue(bool value);
void setReadReturnValue(bool value);
void setFakeBeginFRAMI2C(bool value);
void setFakeDeviceID(uint16_t man_ID, uint16_t prod_ID);
bool getBeginFRAMI2C(void);
uint16_t getFRAMI2CAddress(void);
uint8_t getFRAMI2CreturnValue(void);

#endif // ADAFURIT_FRAM_I2C_H