//
//    FILE: ADS_read.ino
//  AUTHOR: Rob.Tillaart
// PURPOSE: read analog inputs - straightforward.
//     URL: https://github.com/RobTillaart/ADS1X15

//  test
//  connect 1 potmeter per port.
//
//  GND ---[   x   ]------ 5V
//             |
//
//  measure at x (connect to AIN0).
//
// MODIFIED BY: Pierluigi Colangeli
//     PURPOSE: read analog inputs - example for RAK3172 and custo min IO board.
//         URL: https://github.com/piecol/Wisblock_IO_extention_10x23

#include <Arduino.h>
#include <Wire.h>
#ifdef _VARIANT_RAK4630_
#include <Adafruit_TinyUSB.h>
#endif
#include "ADS1X15.h"


#define VSS_PIN WB_IO2
#define PWR_ON  HIGH


ADS1115 ADS(0x48);


void setup() 
{ 
  pinMode(VSS_PIN, OUTPUT);
  digitalWrite(VSS_PIN, PWR_ON);
  
  delay(500);
  Serial.begin(115200);
  delay(2000);
  Serial.println(__FILE__);
  Serial.print("ADS1X15_LIB_VERSION: ");
  Serial.println(ADS1X15_LIB_VERSION);

  ADS.begin();
}


void loop() 
{
  ADS.setGain(1);

  int16_t val_0 = ADS.readADC(0);  
  int16_t val_1 = ADS.readADC(1);  
 
  float f = ADS.toVoltage(1);  // voltage factor

  Serial.print("\tAnalog0: ");   Serial.println(val_0 * f, 6);
  Serial.print("\tAnalog1: ");   Serial.println(val_1 * f, 6);
  Serial.println();

  delay(1000);
}
