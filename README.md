# Wisblock_IO_extention_10x23
Mini version of the RAK5804 IO module built for a 10x23mm sensor slot.

It maintains the option to choose between VDD and +3V3_S to power up peripherals.

The block exposes the following pins:

- 2 GPIOs (1-2 or 3-4)
- I2C
- TX/RX
- 2 ANALOG input

GND and +3V3 are redundant on each SMD connector.
All IOs are protected with ESD bidirectional diodes.
The analog inputs are provided by the ADS1115 chip mounted on the bottom of the board.
The pins can be wired through SH 1.0mm pitch horizontal connectors.

![IO_MOSAIC](https://github.com/piecol/Wisblock_IO_extention_10x23/assets/29545872/d94824b2-ea09-4e53-92ed-dce951a62d62)

Main point was to allow analog measuements on RAK19003 mini WisBlock base that has no IO slot. 
Having a dedicated ADC also makes it possible to measure either 2 single-ended channel or one in differential mode. 

![test_RAK v1](https://github.com/piecol/Wisblock_IO_extention_10x23/assets/29545872/fa6455f0-08eb-4e42-8286-08541ba00e5f)

***Read sensor ADS1115***
##### ADS1115  
 ```c
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
```

Arduino serial prints:

```c
Analog0: 0.220006
Analog1: 0.392011

Analog0: 0.240007
Analog1: 0.268008

Analog0: 0.286008
Analog1: 0.356010

Analog0: 0.306009
Analog1: 0.372011
```
