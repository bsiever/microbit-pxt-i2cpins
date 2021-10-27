serial.writeLine("starting...")
// serial.writeLine("Press A to show temperature")
// serial.writeLine("If sensor is connected it should show the temperature")
// serial.writeLine("If sensor is NOT connected it should show -Infinity (for temp) and an error message")
input.onButtonPressed(Button.A, function () {
  //  pins.setI2CPins(DigitalPin.P0, DigitalPin.P1)
    pins.setI2CPins(DigitalPin.P1, DigitalPin.P2)
    pins.i2cWriteNumber(
    104,
    107,
    NumberFormat.UInt8LE,
    true
    )
    pins.i2cWriteNumber(
    104,
    0,
    NumberFormat.UInt8LE,
    false
    )
})
input.onButtonPressed(Button.B, function () {
    pins.i2cWriteNumber(
    104,
    59,
    NumberFormat.UInt8LE,
    false
    )
    pins.i2cWriteNumber(
    104,
    14,
    NumberFormat.UInt8LE,
    true
    )
    serial.writeValue("x", pins.i2cReadNumber(104, NumberFormat.UInt16BE, true))
    serial.writeValue("y", pins.i2cReadNumber(104, NumberFormat.UInt8BE, true))
    serial.writeValue("z", pins.i2cReadNumber(104, NumberFormat.UInt8BE, true))
    serial.writeValue("t", pins.i2cReadNumber(104, NumberFormat.UInt8BE, false))
})

// input.onButtonPressed(Button.A, function () {
//     serial.writeString("temp = ")
//     serial.writeNumber(dstemp.celsius(DigitalPin.P0))
//     serial.writeString("\n")
// //      basic.showNumber(dstemp.celsius(DigitalPin.P0))
// })

// dstemp.sensorError(function (errorMessage, errorCode, port) {
//     serial.writeString("\n");
//     serial.writeString(errorMessage);
//     serial.writeString(" code=");
//     serial.writeNumber(errorCode);
//     serial.writeString(" port=");
//     serial.writeNumber(port);
//     serial.writeString("\n");
// //    basic.showString("err")
// //    basic.showNumber(ErrorCode)
// })

