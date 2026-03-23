/*  AngstromIO mini devboard demo code | Clem, #Dieu-de-l'elec | https://github.com/Dieu-de-l-elec/AngstromIO-devboard/tree/main
 *  Based on megaTinyCore library by SpenceKonde
 *  
 *  The devboard can be programmed using the Serial UPDI programmer, 
 *    To set up the Attiny1616 in the arduino IDE, the board package has to be installed first (paste http://drazzy.com/package_drazzy.com_index.json in File>Preferences>Additional Board manager URL) 
 *    Then the Attiny1616 can be selected, with "SerialUPDI - 230400" as programmer
 *  The programmer and AIO should be connected to the same USB Host (the AIO has to share ground with the programmer, so all three USB-C connected to the computer)
 *  And when downloading the sketch, a wire (UPDI) would be pressed against the UPDI pad on the AIO (a pogopin would be suited here, but it work without)
 *  
 *  Have fun! :D
 */

#include <tinyNeoPixel.h>
#define PIN            2
#define NUMPIXELS      2

int waitTime = 1000;
int count = 0;
tinyNeoPixel LED = tinyNeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  LED.begin();
  LED.setBrightness(37);
  Serial.begin(9600);
  delay (2000);
}
void loop() {
  Serial.println ("Hi! I'm AngstromIO!");
  LEDTest();
  count += 1;
  Serial.print ("I've been running ");
  Serial.print (count);
  Serial.println (" loops!");
}
void LEDTest () {
  // pixels.Color takes RGB values from 0,0,0 up to 255,255,255
  LED.setPixelColor(0, LED.Color(255, 0, 0)); // RED
  LED.setPixelColor(1, LED.Color(0, 255, 0)); // GREEN
  LED.show();
  delay(waitTime);
  LED.setPixelColor(0, LED.Color(0, 255, 0)); // GREEN
  LED.setPixelColor(1, LED.Color(0, 0, 255)); // BLUE
  LED.show();
  delay(waitTime);
  LED.setPixelColor(0, LED.Color(0, 0, 255)); // BLUE
  LED.setPixelColor(1, LED.Color(255, 0, 0)); // RED
  LED.show();
  delay(waitTime);
  LED.setPixelColor(0, LED.Color(255, 0, 255)); // MAGENTA
  LED.setPixelColor(1, LED.Color(255, 0, 255)); // MAGENTA
  LED.show();
  delay(waitTime);
  LED.setPixelColor(0, LED.Color(255, 255, 0)); // YELLOW
  LED.setPixelColor(1, LED.Color(255, 255, 0)); // YELLOW
  LED.show();
  delay(waitTime);
  LED.setPixelColor(0, LED.Color(0, 255, 255)); // CYAN
  LED.setPixelColor(1, LED.Color(0, 255, 255)); // CYAN
  LED.show();
  delay(waitTime);
  LED.setPixelColor(0, LED.Color(255, 255, 255)); // WHITE
  LED.setPixelColor(1, LED.Color(255, 255, 255)); // WHITE
  LED.show();
  delay(waitTime);
}
