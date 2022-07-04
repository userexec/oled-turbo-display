/**************************************************************************
Display Center

Shows a static display centering pattern on 128x64px monochrome
SSD1306 displays. Use this to help line up your display when
affixing it.
 **************************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// 'displaycenter', 128x64px
const unsigned char displaycenter [] PROGMEM = {
	0xfe, 0xf7, 0xdf, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0xfb, 0xef, 0x7f, 
	0xbe, 0xf7, 0xdf, 0x7f, 0xff, 0xdf, 0xff, 0xfe, 0x7f, 0xff, 0xfb, 0xff, 0xfe, 0xfb, 0xef, 0x7d, 
	0xfe, 0xf7, 0xdf, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0xfb, 0xef, 0x7f, 
	0xe6, 0xf7, 0xdf, 0x7f, 0xff, 0x9f, 0xff, 0xfe, 0x7f, 0xff, 0xf9, 0xff, 0xfe, 0xfb, 0xef, 0x67, 
	0xe6, 0xf7, 0xdf, 0x7f, 0xff, 0x9f, 0xff, 0xfe, 0x7f, 0xff, 0xf9, 0xff, 0xfe, 0xfb, 0xef, 0x67, 
	0xff, 0xf7, 0xdf, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0xfb, 0xef, 0xff, 
	0xfc, 0x77, 0xdf, 0x7f, 0xff, 0x1f, 0xff, 0xfe, 0x7f, 0xff, 0xf8, 0xff, 0xfe, 0xfb, 0xee, 0x3f, 
	0x05, 0x77, 0xdf, 0x7f, 0xff, 0x5f, 0xff, 0xfe, 0x7f, 0xff, 0xfa, 0xff, 0xfe, 0xfb, 0xee, 0xa0, 
	0xfc, 0x77, 0xdf, 0x7f, 0xff, 0x1f, 0xff, 0xfe, 0x7f, 0xff, 0xf8, 0xff, 0xfe, 0xfb, 0xee, 0x3f, 
	0xff, 0xff, 0xdf, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0xfb, 0xff, 0xff, 
	0xff, 0xc1, 0xdf, 0x7f, 0xfe, 0x0f, 0xff, 0xfe, 0x7f, 0xff, 0xf0, 0x7f, 0xfe, 0xfb, 0x83, 0xff, 
	0xff, 0xdd, 0xdf, 0x7f, 0xfe, 0xef, 0xff, 0xfe, 0x7f, 0xff, 0xf7, 0x7f, 0xfe, 0xfb, 0xbb, 0xff, 
	0x00, 0x5d, 0xdf, 0x7f, 0xfe, 0xef, 0xff, 0xfe, 0x7f, 0xff, 0xf7, 0x7f, 0xfe, 0xfb, 0xba, 0x00, 
	0xff, 0xdd, 0xdf, 0x7f, 0xfe, 0xef, 0xff, 0xfe, 0x7f, 0xff, 0xf7, 0x7f, 0xfe, 0xfb, 0xbb, 0xff, 
	0xff, 0xc1, 0xdf, 0x7f, 0xfe, 0x0f, 0xff, 0xfe, 0x7f, 0xff, 0xf0, 0x7f, 0xfe, 0xfb, 0x83, 0xff, 
	0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0x07, 0x7f, 0xfe, 0x0f, 0xff, 0xfe, 0x7f, 0xff, 0xf0, 0x7f, 0xfe, 0xe0, 0xff, 0xff, 
	0xff, 0xff, 0x77, 0x7f, 0xfe, 0xef, 0xff, 0xfe, 0x7f, 0xff, 0xf7, 0x7f, 0xfe, 0xee, 0xff, 0xff, 
	0x00, 0x01, 0x07, 0x7f, 0xfe, 0x0f, 0xff, 0xfe, 0x7f, 0xff, 0xf0, 0x7f, 0xfe, 0xe0, 0x80, 0x00, 
	0xff, 0xff, 0x77, 0x7f, 0xfe, 0xef, 0xff, 0xfe, 0x7f, 0xff, 0xf7, 0x7f, 0xfe, 0xee, 0xff, 0xff, 
	0xff, 0xff, 0x07, 0x7f, 0xfe, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x7f, 0xfe, 0xe0, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xc1, 0x8c, 0x6f, 0x8d, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xfc, 0x1f, 0xfe, 0x0a, 0xf7, 0x75, 0xaf, 0xae, 0xb0, 0x7f, 0xf8, 0x3f, 0xff, 0xff, 
	0xff, 0xff, 0xfd, 0x5f, 0xfe, 0xab, 0x77, 0x7d, 0xaf, 0x76, 0xb5, 0x7f, 0xfa, 0xbf, 0xff, 0xff, 
	0x00, 0x00, 0x04, 0x1f, 0xfe, 0x0b, 0x77, 0x8c, 0x6f, 0x07, 0x70, 0x7f, 0xf8, 0x20, 0x00, 0x00, 
	0xff, 0xff, 0xfd, 0x5f, 0xfe, 0xab, 0x77, 0xf5, 0xef, 0x77, 0x75, 0x7f, 0xfa, 0xbf, 0xff, 0xff, 
	0xff, 0xff, 0xfc, 0x1f, 0xfe, 0x0a, 0xf7, 0x75, 0xef, 0x77, 0x70, 0x7f, 0xf8, 0x3f, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xc1, 0x8d, 0xe1, 0x77, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0xff, 
	0x00, 0x00, 0x00, 0x09, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x90, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x09, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x90, 0x00, 0x00, 0x00, 
	0xff, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xcc, 0x2e, 0x82, 0x11, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xfc, 0x1f, 0xfe, 0x0f, 0xb5, 0xe6, 0xee, 0xf6, 0xf0, 0x7f, 0xf8, 0x3f, 0xff, 0xff, 
	0xff, 0xff, 0xfd, 0x5f, 0xfe, 0xaf, 0x7d, 0xea, 0xee, 0xf6, 0xf5, 0x7f, 0xfa, 0xbf, 0xff, 0xff, 
	0x00, 0x00, 0x04, 0x1f, 0xfe, 0x0f, 0x7c, 0x6a, 0xee, 0x31, 0xf0, 0x7f, 0xf8, 0x20, 0x00, 0x00, 
	0xff, 0xff, 0xfd, 0x5f, 0xfe, 0xaf, 0x7d, 0xec, 0xee, 0xf5, 0xf5, 0x7f, 0xfa, 0xbf, 0xff, 0xff, 
	0xff, 0xff, 0xfc, 0x1f, 0xfe, 0x0f, 0xb5, 0xec, 0xee, 0xf6, 0xf0, 0x7f, 0xf8, 0x3f, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xcc, 0x2e, 0xee, 0x16, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0x07, 0x7f, 0xfe, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x7f, 0xfe, 0xe0, 0xff, 0xff, 
	0xff, 0xff, 0x77, 0x7f, 0xfe, 0xef, 0xff, 0xfe, 0x7f, 0xff, 0xf7, 0x7f, 0xfe, 0xee, 0xff, 0xff, 
	0x00, 0x01, 0x07, 0x7f, 0xfe, 0x0f, 0xff, 0xfe, 0x7f, 0xff, 0xf0, 0x7f, 0xfe, 0xe0, 0x80, 0x00, 
	0xff, 0xff, 0x77, 0x7f, 0xfe, 0xef, 0xff, 0xfe, 0x7f, 0xff, 0xf7, 0x7f, 0xfe, 0xee, 0xff, 0xff, 
	0xff, 0xff, 0x07, 0x7f, 0xfe, 0x0f, 0xff, 0xfe, 0x7f, 0xff, 0xf0, 0x7f, 0xfe, 0xe0, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 
	0xff, 0xc1, 0xdf, 0x7f, 0xfe, 0x0f, 0xff, 0xfe, 0x7f, 0xff, 0xf0, 0x7f, 0xfe, 0xfb, 0x83, 0xff, 
	0xff, 0xdd, 0xdf, 0x7f, 0xfe, 0xef, 0xff, 0xfe, 0x7f, 0xff, 0xf7, 0x7f, 0xfe, 0xfb, 0xbb, 0xff, 
	0x00, 0x5d, 0xdf, 0x7f, 0xfe, 0xef, 0xff, 0xfe, 0x7f, 0xff, 0xf7, 0x7f, 0xfe, 0xfb, 0xba, 0x00, 
	0xff, 0xdd, 0xdf, 0x7f, 0xfe, 0xef, 0xff, 0xfe, 0x7f, 0xff, 0xf7, 0x7f, 0xfe, 0xfb, 0xbb, 0xff, 
	0xff, 0xc1, 0xdf, 0x7f, 0xfe, 0x0f, 0xff, 0xfe, 0x7f, 0xff, 0xf0, 0x7f, 0xfe, 0xfb, 0x83, 0xff, 
	0xff, 0xff, 0xdf, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0xfb, 0xff, 0xff, 
	0xfc, 0x77, 0xdf, 0x7f, 0xff, 0x1f, 0xff, 0xfe, 0x7f, 0xff, 0xf8, 0xff, 0xfe, 0xfb, 0xee, 0x3f, 
	0x05, 0x77, 0xdf, 0x7f, 0xff, 0x5f, 0xff, 0xfe, 0x7f, 0xff, 0xfa, 0xff, 0xfe, 0xfb, 0xee, 0xa0, 
	0xfc, 0x77, 0xdf, 0x7f, 0xff, 0x1f, 0xff, 0xfe, 0x7f, 0xff, 0xf8, 0xff, 0xfe, 0xfb, 0xee, 0x3f, 
	0xff, 0xf7, 0xdf, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0xfb, 0xef, 0xff, 
	0xe6, 0xf7, 0xdf, 0x7f, 0xff, 0x9f, 0xff, 0xfe, 0x7f, 0xff, 0xf9, 0xff, 0xfe, 0xfb, 0xef, 0x67, 
	0xe6, 0xf7, 0xdf, 0x7f, 0xff, 0x9f, 0xff, 0xfe, 0x7f, 0xff, 0xf9, 0xff, 0xfe, 0xfb, 0xef, 0x67, 
	0xfe, 0xf7, 0xdf, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0xfb, 0xef, 0x7f, 
	0xbe, 0xf7, 0xdf, 0x7f, 0xff, 0xdf, 0xff, 0xfe, 0x7f, 0xff, 0xfb, 0xff, 0xfe, 0xfb, 0xef, 0x7d, 
	0xfe, 0xf7, 0xdf, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0xfb, 0xef, 0x7f
};


void setup() {
   Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  display.clearDisplay();
  display.drawBitmap(0, 0, displaycenter, 128, 64, 1);
  display.display();
}

void loop() {}