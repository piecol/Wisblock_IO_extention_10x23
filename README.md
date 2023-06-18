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
