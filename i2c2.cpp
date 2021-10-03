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
#include <cstdint>
#include <math.h>
#include "app_error.h"
#include "nrf.h"
#include "MicroBitSystemTimer.h"


// Enable debugging: Debugging uses #ifdefs, so uncomment or comment out 
//#define DEBUG 1
// DEBUG uses ioPin P1 to indicate sampling of read (for timing calibration)
using namespace pxt;


#if MICROBIT_CODAL
// V2
#else
// V1
#endif


#ifdef DEBUG
#endif

namespace i2c2 { 

    MicroBitI2C *i2c2  = nullptr;
    // ************* Forward Decalarations
    // ************* Constants 
    // ************* State variables 
    // ************* Blocks 

    //%
    void setPins(PinName sda, PinName scl) {
        if(i2c2) delete i2c2;

        i2c2 = new MicroBitI2C(sda, scl);
    }


}