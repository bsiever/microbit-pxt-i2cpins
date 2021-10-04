/**
* Bill Siever
* 2021-10-02 Initial Version
*
* Development environment specifics:
* Written in Microsoft PXT
*
* This code is released under the [MIT License](http://opensource.org/licenses/MIT).
* Please review the LICENSE.md file included with this example. If you have any questions 
* or concerns with licensing, please contact techsupport@sparkfun.com.
* Distributed as-is; no warranty is given.
*/

#include "pxt.h"


// Enable debugging: Debugging uses #ifdefs, so uncomment or comment out 
//#define DEBUG 1
// DEBUG uses ioPin P1 to indicate sampling of read (for timing calibration)
using namespace pxt;


// #if MICROBIT_CODAL
// // V2
// #else
// // V1
// #endif


// #ifdef DEBUG
// #endif

namespace pins { 



    // MicroBitI2C *i2c2  = nullptr;
    // // ************* Forward Decalarations
    // // ************* Constants 
    // // ************* State variables 
    // // ************* Blocks 

    //%
    void setI2CPins(PinName sda, PinName scl) {
        // https://stackoverflow.com/questions/2166099/calling-a-constructor-to-re-initialize-object
        uBit.i2c.~MicroBitI2C(); // destruct 
        new(&uBit.i2c) MicroBitI2C(sda, scl);
    }

    // //%
    // int setFrequency(uint32_t frequency) {
    //      if(!i2c2) return -1;
    //      return i2c2->setFrequency(frequency);
    //  }

    // //%
    // int write(uint16_t address, uint8_t *data, int len, bool repeated = false) {
    //      if(!i2c2) return -1;
    //      return i2c2->write(address, data, len, repeated);        
    // }

    // //%
    // int read(uint16_t address, uint8_t *data, int len, bool repeated = false) {
    //      if(!i2c2) return -1;
    //      return i2c2->read(address, data, len, repeated);        

    // }
    
    // //%
    // int readRegister(uint16_t address, uint8_t reg, uint8_t *data, int length, bool repeated = true) {
    //      if(!i2c2) return -1;
    //      return i2c2->readRegister(address, reg, data, length, repeated);        
    // }

    // //%
    // void clearBus() {
    //      if(!i2c2) return;
    //      i2c2->clearBus();       
    // }

    // //%
    // int setBusIdlePeriod(int period) {
    //     if(!i2c2) return -1;
    //     return i2c2->setBusIdlePeriod(period);
    // }

    // //%
    // int i2cWriteBuffer(int address, Buffer buf, bool repeat = false)
    // {
    //     // From https://github.com/microsoft/pxt-microbit/blob/d80514bda223f729d452c1e51047f3272a2317fb/libs/core/pins.cpp
    //     if(!i2c2) return -1;
    //     return i2c2->write(address << 1, (BUFFER_TYPE)buf->data, buf->length, repeat);
    // }
    // /**
    //  * Read `size` bytes from a 7-bit I2C `address`.
    //  */
    // //%
    // Buffer i2cReadBuffer(int address, int size, bool repeat = false)
    // {
    //   // From https://github.com/microsoft/pxt-microbit/blob/d80514bda223f729d452c1e51047f3272a2317fb/libs/core/pins.cpp
    //   Buffer buf = createBuffer(size);
    //   i2c2->read(address << 1, (BUFFER_TYPE)buf->data, size, repeat);
    //   return buf;
    // }
}