# Particle_Adafruit_IS31FL3731

A Particle library for the Adafruit IS31FL3731 Charlieplex LED driver and CharliePlex FeatherWing. Forked from [adafruit/Adafruit_IS31FL3731](https://github.com/adafruit/Adafruit_IS31FL3731)


## Usage

Start by creating a new matrix object with something like:

```
#include "Adafruit_IS31FL3731.h"

// If you're using the full breakout...
// Adafruit_IS31FL3731 ledmatrix = Adafruit_IS31FL3731();
// If you're using the FeatherWing version
Adafruit_IS31FL3731_Wing ledmatrix = Adafruit_IS31FL3731_Wing();
```

Then in your setup, call `.begin(<address>)` to initialize the driver. `.begin()` will return false if the matrix was not found, and `true`  if initialization succeeded.

```
void setup(){
  if (!ledmatrix.begin()){
    Serial.println("IS31 not found");
    while (1);
  }
  Serial.println("IS31 found!");
}
```

You can then draw to the display. Note that since we write directly to the driver RAM, any pixels 'drawn' will appear immediately.

You can start with `drawPixel(x, y, brightness)` where `x` ranges between `0` and `14` inclusive, and `y` ranges between `0` and `7` inclusive. Brightness is the PWM of the LED, `0` is off, and `255` is all the way on.

This loop will light up every LED in increasing brightness:

```
int i = 0;
for (uint8_t x = 0; x < 15; ++x) {
  for (uint8_t y = 0; y < 7; ++y) {
    ledmatrix.drawPixel(x, y, ++i]);
  }
}
```

See the [examples](examples) folder for more details.