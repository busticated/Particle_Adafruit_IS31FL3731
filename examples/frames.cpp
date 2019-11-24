#include "Particle.h"
#include "Particle_Adafruit_IS31FL3731.h"

void setup();
void loop();

// If you're using the full breakout...
// Particle_Adafruit_IS31FL3731 ledmatrix = Particle_Adafruit_IS31FL3731();
// If you're using the FeatherWing version
Particle_Adafruit_IS31FL3731_Wing ledmatrix = Particle_Adafruit_IS31FL3731_Wing();

void setup(){
  Serial.begin(9600);
  Serial.println("ISSI manual animation test");
  
  // call .begin(address) to initialize the driver.
  // .begin() will return false if the matrix was not found, and true if initialization succeeded
  if (!ledmatrix.begin()){
    Serial.println("IS31 not found");
    while (1);
  }
  Serial.println("IS31 Found!");
  
  ledmatrix.setTextWrap(false);
  ledmatrix.setTextColor(64); // quarter brightness
  ledmatrix.setTextSize(1);

  // fill all 8 frames with some text
  for (uint8_t frame = 0; frame < 8; ++frame){
    ledmatrix.clear();
    ledmatrix.setFrame(frame);
    ledmatrix.setCursor(0, 0);
    ledmatrix.write('a' + frame * 3);
    ledmatrix.write('b' + frame * 3);
    ledmatrix.write('c' + frame * 3);
  }
}

int x = 0;

void loop(){
  // display each frame for 250 milliseconds
  for (uint8_t frame = 0; frame < 8; ++frame){
    ledmatrix.displayFrame(frame);
    delay(250);
  }
}
