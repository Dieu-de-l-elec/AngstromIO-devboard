# AngstromIO-devboard
AngstromIO, one of the smallest devboards out there, barely longer than a USB C connector, based on the Attiny1616 MCU. 2 GPIOs as well as I2C lines are broken out. 
I made a dual CH340 programming board too, both for UPDI programming and debugging (one way Serial Communication). 
I also designed a breadboard friendly, experimentation board for the CH32V003, with a 4 by 5 charlieplexed LED matrix.

<p align="center">
  <img width="130" height="200" alt="IOX-77 LOGO" src="assets/AngstromIO logo far away.png" />
</p>

# AngstromIO Key features:
- One of the smallest devboards: 8.9mm by 9mm, USB-C included
- Attiny1616 MCU, 16Kb flash, low power, arduino compatible (for basic libraries at least)
- USB-C for power, runs at 5V
- 2x RGB addressable LEDs (SK6805-EC15)
- Pins broken out: SCL, SDA, PB2 (TX), PA3, +5V, GND, and UPDI for programming

# Programmer Key features:
- Dual CH340E setup:
    - One for programming (set as SerialUPDI programmer),
    - One for debugging (Serial Communication, USB to UART)
- 2 USB-C for data transfer, only the USB-C for Serial provides 5V to the board
- On board 3.3V LDO
- 3.3V/5V operating voltage selection

# CH32 devboard Key features:
- Breadboard friendly devboard
- cheap 25cents CH32V003, Risc-V MCU, 26Kb flash
- USB-C for power, the CH32 runs at 3.3V but PC6 and PC5 are 5V tolerant
- On board 3.3V LDO
- 4x5 charlieplexed LED matrix
- SWIO programming, proper programmer required (WCH linkE)




