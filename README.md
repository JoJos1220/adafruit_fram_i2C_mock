# Adafruit I2C FRAM MOCK Library

[![PlatformIO CI][build-shield]][build-url]
![License][license-url]
[![Contributors][contributors-shield]][contributors-url]
[![Release Version][realease-shield]][release-url]
[![PlatformIO Registry][PlatformIO-shield]][PlatformIO-url]
[![Release Date][releasedate-shield]][releasedate-url]
[![Last commit][lastcommit-shield]][lastcommit-url]

This is a simple MOCK-library for the Adafruit I2C FRAM sensor boards,
created for simple unity testing:
 
Check out the links above for our tutorials and wiring diagrams. This chip uses I2C to communicate.

To install, use the Arduino Library Manager and search for 'Adafruit FRAM i2c MOCK' and install the library.

Written by JoJo1220.
MIT license, all text above must be included in any redistribution

For usage, define a Build Flag in Native Environment for Unity Testing:

```cpp
build_flags = -D NATIVE_ENVIRONMENT
```

Add the following lines in your Original Code Section enables build in Native environment.
```cpp
#ifdef NATIVE_ENVIRONMENT
    #include <adafruit_fram_i2C_mock.h>
#else
    #include <Adafruit_FRAM_I2C.h>
#endif
```

Now, testing of the original Source code within the unity Environment can be done,
without changing the original source code:
 ```cpp
#include <unity.h>

#include <adafruit_fram_i2C_mock.h>

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_begin(void){
    Adafruit_FRAM_I2C mockFRAM;
    setFakeBeginFRAMI2C(true);
    bool begin = mockFRAM.begin();
    TEST_ASSERT_TRUE(begin);
}
void test_fram_class_read_and_write_operation(void){
    Adafruit_FRAM_I2C mockFRAM;
    uint16_t addr = 0x0000;
    uint8_t value = 0xAB;

    setFakeBeginFRAMI2C(true);
    TEST_ASSERT_TRUE(fram.begin(0x50));

    mockFRAM.write(addr, value);
    TEST_ASSERT_EQUAL_UINT16((uint16_t)addr, (uint16_t)getFRAMI2CAddress());
    TEST_ASSERT_EQUAL_UINT8((uint8_t)value, (uint8_t)getFRAMI2CreturnValue());
    
    uint8_t readvalue = mockFRAM.read(addr);
    TEST_ASSERT_EQUAL_UINT8(value, readvalue);
}

int main( int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_begin);
    RUN_TEST(test_fram_class_read_and_write_operation);
    UNITY_END();

    return 0;
}
 ```

  <!-- MARKDOWN LINKS & IMAGES -->
[PlatformIO-shield]: https://badges.registry.platformio.org/packages/jojos1220/library/adafruit_fram_i2c_mock.svg
[PlatformIO-url]: https://registry.platformio.org/libraries/jojos1220/adafruit_fram_i2c_mock
[build-shield]: https://github.com/JoJos1220/adafruit_fram_i2c_mock/actions/workflows/workflow.yml/badge.svg
[build-url]: https://github.com/JoJos1220/adafruit_fram_i2c_mock/actions/workflows/workflow.yml
[license-url]:https://img.shields.io/github/license/Jojos1220/adafruit_fram_i2c_mock?style=flat-square
[contributors-shield]: https://img.shields.io/github/contributors/JoJos1220/adafruit_fram_i2c_mock
[contributors-url]: https://github.com/JoJos1220/adafruit_fram_i2c_mock/graphs/contributors
[realease-shield]: https://img.shields.io/github/release/JoJos1220/adafruit_fram_i2c_mock.svg?style=plastic
[release-url]: https://github.com/JoJos1220/adafruit_fram_i2c_mock/releases/latest
[releasedate-shield]: https://img.shields.io/github/release-date/JoJos1220/adafruit_fram_i2c_mock.svg?style=plastic
[releasedate-url]: https://github.com/JoJos1220/adafruit_fram_i2c_mock/releases/latest/
[lastcommit-shield]: https://img.shields.io/github/last-commit/JoJos1220/adafruit_fram_i2c_mock?style=plastic
[lastcommit-url]: https://github.com/JoJos1220/adafruit_fram_i2c_mock/tree
