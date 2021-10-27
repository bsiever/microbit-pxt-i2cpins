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
#include "MicroBitI2C.h"
#include "MicroBit.h"

#if MICROBIT_CODAL
#include "peripheral_alloc.h"
#endif 
// Enable debugging: Debugging uses #ifdefs, so uncomment or comment out 
//#define DEBUG 1
// DEBUG uses ioPin P1 to indicate sampling of read (for timing calibration)
using namespace pxt;

#define DEBUG 1

#ifdef DEBUG
    /**
     * 
     */
// https://www.forward.com.au/pfod/microbit/gettingStarted.html
    void loopUntilSent(ManagedString str) {
    int rtn = uBit.serial.send(str);
    while(rtn == MICROBIT_SERIAL_IN_USE) {
       uBit.sleep(0); // let other tasks run
       rtn = uBit.serial.send(str); 
    }
}
    void loopUntilSent(int str) {
    int rtn = uBit.serial.send(str);
    while(rtn == MICROBIT_SERIAL_IN_USE) {
       uBit.sleep(0); // let other tasks run
       rtn = uBit.serial.send(str); 
    }
}

#endif 



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
#if MICROBIT_CODAL
// V2

        //uBit.i2c.~MicroBitI2C(); // destruct : No Crash
        // Free it:
        loopUntilSent("freeing\n");
        // Peripherals are allocated starting from Max index (in allocate_peripheral in codal-nrf52's peripheral_alloc.cpp)
        // _i2c is initialized first, so it'll get NRF_SPIM1)
        free_alloc_peri(NRF_SPIM0);

        loopUntilSent("allocing\n");

//        new (&uBit.i2c) MicroBitI2C(sda, scl);
       //new (&uBit.i2c) MicroBitI2C(uBit.io.P20, uBit.io.P19);
        // Creating a new object causes the crash....
        // NOTE: Hard coded, not   The below are "NRF52Pin" objects
//      MicroBitI2C *i2c2 = new MicroBitI2C(sda, scl);
      MicroBitI2C *i2c2 = new MicroBitI2C(uBit.io.P1, uBit.io.P2);
      
         loopUntilSent("write\n");

//      i2c2->write(12,(uint8_t*)"hi world", 8);
        // The above doesn't crash...But the below _does_.  Are passed sda/scl not the same?

     //MicroBitI2C *i2c2 = new MicroBitI2C(sda, scl);
        loopUntilSent("done\n");

    memcpy(&uBit.i2c, i2c2, sizeof(MicroBitI2C));
        loopUntilSent("copied\n");

#else
// V1
        // MicroBitI2C *i2c2 = new MicroBitI2C(uBit.io.P20, uBit.io.P19);
        // uBit.i2c.~MicroBitI2C(); // destruct 
        // memcpy(&uBit.i2c, i2c2, sizeof(MicroBitI2C));
#endif
        // https://stackoverflow.com/questions/2166099/calling-a-constructor-to-re-initialize-object
     //   uBit.i2c.~MicroBitI2C(); // destruct 
       // new (&uBit.i2c) MicroBitI2C(sda, scl);
      
      
        //memcpy(&uBit.i2c, i2c2, sizeof(MicroBitI2C));
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