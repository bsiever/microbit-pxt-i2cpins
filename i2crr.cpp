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

using namespace pxt;

namespace i2crr { 
    
    //%
    void setI2CPins(int sdaPin, int sclPin) {
#if MICROBIT_CODAL
        // V2

        // destruct at old location
        uBit.i2c.~MicroBitI2C(); 
        // Free associated peripherals
        // Peripherals are allocated starting from Max index (in allocate_peripheral in codal-nrf52's peripheral_alloc.cpp)
        // _i2c is initialized first, so it'll get NRF_SPIM1, leaving NRF_SPIM0 for i2c (external))
        free_alloc_peri(NRF_SPIM0);
        // Get the pins to use
        MicroBitPin *sda = getPin(sdaPin);
        MicroBitPin *scl = getPin(sclPin);
        // https://stackoverflow.com/questions/2166099/calling-a-constructor-to-re-initialize-object
       new (&uBit.i2c) MicroBitI2C(*sda, *scl);
#else
        // V1
        // Only 1 TWI / I2C port.  Mutually exclusive with on-board periphs: Accelrometer/Magnetometer (compass)
        // destruct at old location
        uBit.i2c.~MicroBitI2C(); 
        // Get the pins to use
        MicroBitPin *sda = getPin(sdaPin);
        MicroBitPin *scl = getPin(sclPin);
        // https://stackoverflow.com/questions/2166099/calling-a-constructor-to-re-initialize-object
       new (&uBit.i2c) MicroBitI2C(sda->name, scl->name);
#endif
    }
}