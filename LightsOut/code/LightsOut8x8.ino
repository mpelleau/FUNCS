/*************************************************** 
  This is an implementation of the game Lights Out for 4 Trellises
  Press a key to turn on/off the adjacent buttons, try to turn all
  the LEDs off!

  Designed specifically to work with the Adafruit Trellis 
  ----> https://www.adafruit.com/products/1616
  ----> https://www.adafruit.com/products/1611

  These displays use I2C to communicate, 2 pins are required to  
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Tony Sherwood for Adafruit Industries.  
  MIT license, all text above must be included in any redistribution

  Based on https://github.com/adafruit/Adafruit_Trellis_Library/tree/master/examples/TrellisLightsOut
 ****************************************************/

#include <Wire.h>
#include "Adafruit_Trellis.h"

Adafruit_Trellis matrix0 = Adafruit_Trellis();
Adafruit_Trellis matrix1 = Adafruit_Trellis();
Adafruit_Trellis matrix2 = Adafruit_Trellis();
Adafruit_Trellis matrix3 = Adafruit_Trellis();

Adafruit_TrellisSet trellis =  Adafruit_TrellisSet(&matrix0, &matrix1, &matrix2, &matrix3);

#define NUMTRELLIS 4

#define numKeys (NUMTRELLIS * 16)

#define n 8
#define nbMoves numKeys/2

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

/*
  In order for this layout to work, you will have to have soldered your 4 boards
  together in the same order that I did.  Below is the top view of the circuit, with
  each board's address, and lines indicating which boards are connected to each other.
  If you soldered your boards together differently, you will need to edit the chessboard
  array below until the LED wipe when you start up your sketch turns on all of the LEDs
  in order.
             [0x73]--[0x72]
                       |
  [ARDUINO]--[0x70]--[0x71]
 
*/

int chessboard[n][n] = {
  {60, 56, 52, 48, 44, 40, 36, 32}, 
  {61, 57, 53, 49, 45, 41, 37, 33},
  {62, 58, 54, 50, 46, 42, 38, 34},
  {63, 59, 55, 51, 47, 43, 39, 35},
  {12, 8, 4, 0, 28, 24, 20, 16},
  {13, 9, 5, 1, 29, 25, 21, 17},
  {14, 10, 6, 2, 30, 26, 22, 18},
  {15, 11, 7, 3, 31, 27, 23, 19}
};


// Connect Trellis Vin to 5V and Ground to ground.
// Connect the INT wire to pin #5 (can change later
#define INTPIN 5
// Connect I2C SDA pin to your Arduino SDA line
// Connect I2C SCL pin to your Arduino SCL line


void setup() {
  Serial.begin(9600);
  Serial.println("Trellis Lights Out");

  // INT pin requires a pullup
  pinMode(INTPIN, INPUT);
  digitalWrite(INTPIN, HIGH);

  trellis.begin(0x71, 0x72, 0x73, 0x70);

  // Turn on all the leds at the beginining
  for (uint8_t i = 0; i < n; i++) {
    for (uint8_t j = 0; j < n; j++) {
      trellis.setLED(chessboard[i][j]);
      trellis.writeDisplay();
      delay(50);
    }
  }  

  // Turn off all the leds
  for (uint8_t i = 0; i < numKeys; i++) {
    trellis.clrLED(i);
  }
  trellis.writeDisplay();
  
  // Set up a random board
  makeRandomBoard();
}


void toggle(int placeVal) {
 if(placeVal != -1) {
  
 if (trellis.isLED(placeVal))
    trellis.clrLED(placeVal);
  else
    trellis.setLED(placeVal);
 }
}


/* Directions are ordered clockwise starting with 0 = NORTH */
int getNeighbor(int placeVal, int neighbor) {
  int px = 0;
  int py = 0;
  int x = 0;
  int y = 0;
  
  getPosition(placeVal, &px, &py);
  switch (neighbor) {
    case NORTH:
      x = px;
      y = py - 1;
      break;
    case SOUTH:
      x = px;
      y = py + 1;
      break;
    case EAST:
      x = px + 1;
      y = py;
      break;
    case WEST:
      x = px - 1;
      y = py;
      break;
    default:
      x = 0;
      y = 0;
  }

  if(x >= 0 && x <= n-1 && y >= 0 && y <= n-1) return chessboard[x][y];
  else return -1;
}


int getPosition(int pv, int *tx, int *ty) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (chessboard[i][j] == pv) {
        *tx = i;
        *ty = j;
        return 1;  
      }
    }
  }
  return -1;
}


void makeRandomBoard() {
  int x = 0;
  int y = 0;
  for (int i = 0; i < nbMoves; i++) {
    x = random(0, n-1);
    y = random(0, n-1);
    makeYourMove(chessboard[x][y]);
  }
  trellis.writeDisplay();
  delay(100);
}


void makeYourMove(int placeVal) {
  // First, flip this light
  toggle(placeVal);
    
  // Then, flip the lights to the N,S,E,W of this light
  toggle(getNeighbor(placeVal, NORTH)); // North
  toggle(getNeighbor(placeVal, EAST)); // East
  toggle(getNeighbor(placeVal, SOUTH)); // South
  toggle(getNeighbor(placeVal, WEST)); // West 
}


void loop() {
  delay(30); // 30ms delay is required, dont remove me!
    // If a button was just pressed or released...
    if (trellis.readSwitches()) {
      // go through every button
      for (uint8_t i = 0; i < numKeys; i++) {
	      // if it was pressed, make your move
        if (trellis.justPressed(i)) {
          makeYourMove(i);
        }
      }
      // tell the trellis to set the LEDs we requested
      trellis.writeDisplay();
    }
}
