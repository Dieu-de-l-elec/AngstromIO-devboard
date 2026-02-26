# AngstromIO-devboard
<p align="center">
  <img width="130" height="200" alt="IOX-77 LOGO" src="IMG/AngstromIO logo.png" /> 
</p>

AngstromIO is one of the smallest devboards out there, barely longer than a USB-C connector, based on the Attiny1616 MCU. 2 GPIOs as well as I2C lines are broken out. 
I made a dual CH340 programming board too, both for UPDI programming and debugging (one way Serial Communication). 
I also designed a breadboard friendly, experimentation board for the CH32V003, with a 4 by 5 charlieplexed LED matrix.

While the AngstromIO is a tiny devboard, yet powerful, that could be embbeded in any space constrained projects, the CH32 devboard is more an experimentation board, for me to learn how to program this awesome chip on the MounriverStudio programming and how to program a charlieplexed matrix. The Programmer is an all in one module, that will make debugging with the Serial monitor whil programming easy: one board for both.

![Global](https://github.com/user-attachments/assets/642b73ac-d4aa-4dd5-9208-d3b9f72aa41b)


# Key features:
### AngstromIO Key features:
- One of the smallest devboards: 8.9mm by 9mm, USB-C included
- Attiny1616 MCU, 16Kb flash, low power, arduino compatible (for basic libraries at least)
- USB-C for power, runs at 5V
- 2x RGB addressable LEDs (SK6805-EC15)
- Pins broken out: SCL, SDA, PB2 (TX), PA3, +5V, GND, and UPDI for programming

### Programmer Key features:
- Dual CH340E setup:
    - One for programming (set as SerialUPDI programmer),
    - One for debugging (Serial Communication, USB to UART)
- 2 USB-C for data transfer, only the USB-C for Serial provides 5V to the board
- On board 3.3V LDO
- 3.3V/5V operating voltage selection

### CH32 devboard Key features:
- Breadboard friendly devboard
- cheap 25cents CH32V003, Risc-V MCU, 26Kb flash
- USB-C for power, the CH32 runs at 3.3V but PC6 and PC5 are 5V tolerant
- On board 3.3V LDO
- 4x5 charlieplexed LED matrix
- SWIO programming, proper programmer required (WCH linkE)

# Pinout:
🚧 coming soon...

# Software:
### AngstromIO Software:
Arduino compatible, some libraries may not work, but some have been arranged/made by SpenceKonde like Wire (I2C) and tinyNeoPixel (for more information, see: https://github.com/SpenceKonde/megaTinyCore/tree/master/megaavr/libraries)

### CH32 devboard Software:
Programmed on the Mounriver studio IDE

# PCB design:
PCB designed in EasyEDA Pro, 2 layers, 1.0mm thick, Purple soldermask
All 3 designs panelized into one PCB.

# Schematic:
<img src="AIO schematic.svg" alt="SCHEMATIC" width="2300"/>

# PCB Layout:

<img width="1386" height="1139" alt="angstromIO 3d S3" src="https://github.com/user-attachments/assets/0f7962d5-38e1-4bd5-af0b-d7cd2c9fc207" />

<img width="1502" height="1182" alt="angstromIO 3d S4" src="https://github.com/user-attachments/assets/a78e41e2-f0e4-4894-886c-536bf6179275" />

<img width="1221" height="1088" alt="angstromIO 3d S6" src="https://github.com/user-attachments/assets/a9321e7a-7d50-47fc-a0c4-70c8fd251550" />

<img width="1822" height="1589" alt="Layout top panel" src="https://github.com/user-attachments/assets/4b67eaeb-947d-4ba3-9d8d-20ee2b3913c5" />


<img width="1678" height="1717" alt="Layout bottom panel" src="https://github.com/user-attachments/assets/d983fcb7-f020-4338-9049-abf60f8b3ea7" />



# Renders:
🚧 coming soon...

# BOM:
### AngstromIO BOM:
🚧 coming soon...

### Programmer BOM:
🚧 coming soon...

### CH32 devboard BOM:
🚧 coming soon...






