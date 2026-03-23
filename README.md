# AngstromIO-devboard
<p align="center">
  <img width="130" height="200" alt="IOX-77 LOGO" src="IMG/AngstromIO logo.png" /> 
</p>

AngstromIO is one of the smallest devboards out there, barely longer than a USB-C connector, based on the Attiny1616 MCU. 2 GPIOs as well as I2C lines are broken out. 
I made a dual CH340 programming board too, both for UPDI programming and debugging (one way Serial Communication). 
I also designed a breadboard friendly, experimentation board for the CH32V003, with a 4 by 5 charlieplexed LED matrix.

While the AngstromIO is a tiny devboard, yet powerful, that could be embedded in any space constrained projects, the CH32 devboard is more an experimentation board, for me to learn how to program this awesome chip on the MounriverStudio programming and how to program a charlieplexed matrix. The Programmer is an all in one module, that will make debugging with the Serial monitor while programming easy: one board for both.

<br><br>
<p align="center">
  <img alt="Project Banner" src="https://github.com/user-attachments/assets/633cc341-a372-48ec-8386-ac6ccdab7370" width="73%" />
  <img alt="AIO demo gif" src="https://github.com/user-attachments/assets/e32076a6-1042-43d7-b61c-d9b781b1d239" width="22%"/>
</p>
<br><br>

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
- cheap 25cents CH32V003, Risc-V MCU, 16Kb flash
- USB-C for power, the CH32 runs at 3.3V but PC6 and PC5 are 5V tolerant
- On board 3.3V LDO
- 4x5 charlieplexed LED matrix
- SWIO programming, proper programmer required (WCH linkE)

# Pinout:


<img width="2545" height="1741" alt="PINOUT AIO no frame" src="https://github.com/user-attachments/assets/9437022b-7121-4267-9fcd-e5423e48c47e" />
<img width="2535" height="1742" alt="PINOUT CH32 no frame" src="https://github.com/user-attachments/assets/16de5c7e-309b-492c-a2a0-8896451d6b32" />
<img width="2533" height="1738" alt="PINOUT PGM no frame" src="https://github.com/user-attachments/assets/feef0b3e-9e65-4b93-9345-3e620c1adbbe" />


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

<img width="1763" alt="angstromIO 3d S3" src="https://github.com/user-attachments/assets/0f7962d5-38e1-4bd5-af0b-d7cd2c9fc207" />
<img width="1763" alt="angstromIO 3d S4" src="https://github.com/user-attachments/assets/a78e41e2-f0e4-4894-886c-536bf6179275" />
<img width="1763" alt="angstromIO 3d S6" src="https://github.com/user-attachments/assets/a9321e7a-7d50-47fc-a0c4-70c8fd251550" />

![panel front](https://github.com/user-attachments/assets/ba18e137-6d20-45a5-81c4-ce5c13919953)

![panel back](https://github.com/user-attachments/assets/92759a96-98f8-4d33-9d98-7eebe01363e5)

![Programmer PCB 2D](https://github.com/user-attachments/assets/02ac54df-69c2-4aa1-8e9f-59df2b894ee8)
<img width="1763" alt="CH32 Devboard top" src="https://github.com/user-attachments/assets/a90795da-a8e0-4654-8a1d-1cdb60842c4a" />
<img width="1763" alt="CH32 Devboard btm" src="https://github.com/user-attachments/assets/74f7cf1a-6db9-4b80-9b06-d0b3a5bb8b01" />


<img width="1763" alt="Layout top panel" src="https://github.com/user-attachments/assets/4b67eaeb-947d-4ba3-9d8d-20ee2b3913c5" />
<img width="1763" alt="Layout bottom panel" src="https://github.com/user-attachments/assets/d983fcb7-f020-4338-9049-abf60f8b3ea7" />



# Renders:

<img width="1763" alt="Render AngstromIO devboard Top" src="https://github.com/user-attachments/assets/379e2b7b-ba40-40fe-8885-09695af9f56a" />

<img width="1763" alt="Render AngstromIO devboard Bottom" src="https://github.com/user-attachments/assets/655bb147-956b-44bc-b298-71a2ca5763eb" />

<img width="1763" alt="Render programmer 1" src="IMG/RENDERS/PROGRAMMER/PGM 001.png" />
<img width="1763" alt="Render programmer 2" src="IMG/RENDERS/PROGRAMMER/PGM 002.png" />
<img width="1763" alt="Render programmer 3" src="IMG/RENDERS/PROGRAMMER/PGM 003.png" />
<img width="1763" alt="Render programmer 4" src="IMG/RENDERS/PROGRAMMER/PGM 004.png" />

<img width="1763" alt="Render CH32 devboard 1" src="IMG/RENDERS/CH32 devboard/CH32 001.png" />
<img width="1763" alt="Render CH32 devboard 2" src="IMG/RENDERS/CH32 devboard/CH32 002.png" />
<img width="1763" alt="Render CH32 devboard 3" src="IMG/RENDERS/CH32 devboard/CH32 003.png" />
<img width="1763" alt="Render CH32 devboard 4" src="IMG/RENDERS/CH32 devboard/CH32 004.png" />
<img width="1763" alt="Render CH32 devboard 5" src="IMG/RENDERS/CH32 devboard/CH32 005.png" />

# BUILD:

<img width="1763" alt="Render CH32 devboard 5" src="IMG/BUILD/All three (1).jpg" />
<img width="1763" alt="Render CH32 devboard 5" src="IMG/BUILD/All three (2).jpg" />

<img width="1763" alt="Render CH32 devboard 5" src="IMG/BUILD/AIO (7).jpg" />
<img width="1763" alt="Render CH32 devboard 5" src="IMG/BUILD/AIO (6).jpg" />
<img width="1763" alt="Render CH32 devboard 5" src="IMG/BUILD/AIO (1).jpg" />
<img width="1763" alt="Render CH32 devboard 5" src="IMG/BUILD/AIO (2).jpg" />
<img width="1763" alt="Render CH32 devboard 5" src="IMG/BUILD/AIO (3).jpg" />
<img width="1763" alt="Render CH32 devboard 5" src="IMG/BUILD/AIO (4).jpg" />
<img width="1763" alt="Render CH32 devboard 5" src="IMG/BUILD/AIO (5).jpg" />

<img width="1763" alt="Render CH32 devboard 5" src="IMG/BUILD/CH32 devboard (1).jpg" />
<img width="1763" alt="Render CH32 devboard 5" src="IMG/BUILD/CH32 devboard (4).jpg" />
<img width="1763" alt="Render CH32 devboard 5" src="IMG/BUILD/CH32 devboard (6).jpg" />
<img width="1763" alt="Render CH32 devboard 5" src="IMG/BUILD/CH32 devboard (7).jpg" />
<img width="1763" alt="Render CH32 devboard 5" src="IMG/BUILD/CH32 devboard (8).jpg" />

<img width="1763" alt="Render CH32 devboard 5" src="IMG/BUILD/CH32 devboard White bg (1).jpg" />
<img width="1763" alt="Render CH32 devboard 5" src="IMG/BUILD/CH32 devboard White bg (2).jpg" />
<img width="1763" alt="Render CH32 devboard 5" src="IMG/BUILD/CH32 devboard White bg (3).jpg" />
<img width="1763" alt="Render CH32 devboard 5" src="IMG/BUILD/CH32 devboard White bg (4).jpg" />
<img width="1763" alt="Render CH32 devboard 5" src="IMG/BUILD/CH32 devboard White bg (5).jpg" />

<img width="1763" alt="Render CH32 devboard 5" src="IMG/BUILD/PGM (1).jpg" />
<img width="1763" alt="Render CH32 devboard 5" src="IMG/BUILD/PGM (2).jpg" />
<img width="1763" alt="Render CH32 devboard 5" src="IMG/BUILD/PGM (3).jpg" />
<img width="1763" alt="Render CH32 devboard 5" src="IMG/BUILD/PGM (5).jpg" />
<img width="1763" alt="Render CH32 devboard 5" src="IMG/BUILD/PGM (4).jpg" />









# BOM:






### AngstromIO BOM:
Qty| Part| Value| LCSC Part Number| Link
--- | --- | --- | --- | ---
 1| ATTINY1616-MNR| | C507118| https://www.lcsc.com/product-detail/C507118.html
 2| Resistor 0402| 5.1kΩ| C473460| https://www.lcsc.com/product-detail/C473460.html
 1| USB TYPE-C| 6P| C668623| https://www.lcsc.com/product-detail/C668623.html
 2| RGB addressable LED SK6805-EC15| | C2890035| https://www.lcsc.com/product-detail/C2890035.html
 1| MLCC Ceramic capacitor 0402| 100nF| C1525| https://www.lcsc.com/product-detail/C1525.html
 1| MLCC Ceramic capacitor 0402| 10µF| C315248| https://www.lcsc.com/product-detail/C315248.html
 1| TVS diode| | C5199850| https://www.lcsc.com/product-detail/C5199850.html
 1| | + Custom PCB Panel | | I used JLCPCB services https://jlcpcb.com

### Programmer BOM:
Qty| Part| Value| LCSC Part Number| Link
--- | --- | --- | --- | ---
 2| CH340E| | C99652|  https://www.lcsc.com/product-detail/C99652.html
 1| TLV75733PDBVR 3V3 LDO| | C485517| https://www.lcsc.com/product-detail/C485517.html
 1| Slide switch MK-12C02-G015| | C2911519| https://www.lcsc.com/product-detail/C2911519.html
 6| RED LED 0402| | C25503345| https://www.lcsc.com/product-detail/C25503345.html
 7| Resistor 0402| 5.1kΩ| C473460| https://www.lcsc.com/product-detail/C473460.html
 6| Resistor 0402| 1kΩ| C2906864| https://www.lcsc.com/product-detail/C2906864.html
 2| MLCC Ceramic capacitor 0805| 10µF| C15850| https://www.lcsc.com/product-detail/C15850.html
 4| MLCC Ceramic capacitor 0603| 100nF| C66501| https://www.lcsc.com/product-detail/C66501.html
 2| USB TYPE-C| 16P| C2765186| https://www.lcsc.com/product-detail/C2765186.html
 1| 2.54 Dupont headers| 6P| C492414| https://www.lcsc.com/product-detail/C492414.html
 1| | + Custom PCB Panel | | I used JLCPCB services https://jlcpcb.com
 
### CH32 devboard BOM:
Qty| Part| Value| LCSC Part Number| Link
--- | --- | --- | --- | ---
 1| USB TYPE-C| 6P| C668623| https://www.lcsc.com/product-detail/C668623.html
 2| Resistor 0402| 5.1kΩ| C473460| https://www.lcsc.com/product-detail/C473460.html
 1| Resistor 0402| 1kΩ| C2906864| https://www.lcsc.com/product-detail/C2906864.html
 2| Resistor 0402| 10kΩ| C2906861| https://www.lcsc.com/product-detail/C2906861.html
 5| Resistor 0402| 680Ω| C2909378| https://www.lcsc.com/product-detail/C2909378.html
 2| MLCC Ceramic capacitor 0805| 10µF| C15850| https://www.lcsc.com/product-detail/C15850.html
 3| MLCC Ceramic capacitor 0603| 100nF| C66501| https://www.lcsc.com/product-detail/C66501.html
 1| TVS diode|| C5199850| https://www.lcsc.com/product-detail/C5199850.html
 20| RED LED 0402| | C25503345| https://www.lcsc.com/product-detail/C25503345.html
 2| tactile switch| | C492872| https://www.lcsc.com/product-detail/C492872.html
 1| Orange LED 0603| | C965800| https://www.lcsc.com/product-detail/C965800.html
 1| CH32V003F4U6| | C5299908| https://www.lcsc.com/product-detail/C5299908.html
 1| AP2127K-3.3TRG1 3V3 LDO| | C156285| https://www.lcsc.com/product-detail/C156285.html
 1| 2.54 Dupont headers| 5P| C42431794| https://www.lcsc.com/product-detail/C42431794.html
 1| 2.54 Dupont headers| 6P| C42431807| https://www.lcsc.com/product-detail/C42431807.html
 1| | + Custom PCB Panel|  | I used JLCPCB services https://jlcpcb.com






