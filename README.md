# OLED Turbo Button

Replace your IBM compatible's Turbo clock speed display with a sweet OLED panel that shows processor logos and screensavers!

![Turbo off, i8088 mode](https://joshuawoehlke.com/wp-content/uploads/2022/07/i8088-mode.jpg)

From the article [Ultimate Turbo Button Display](https://joshuawoehlke.com/ultimate-turbo-button-display/).

## Materials

- SSD1306 0.96" OLED panel
- Arduino Mega
- Spare molex connector (female)
- Pull-down resistor
- Jumper wires

You can adapt this project to use any Arduino and any compatible OLED panel. Don't think of this as prescriptive--you're supposed to find a panel that fits your computer, make bitmaps that match your processor, and generally make decisions that fit your machine. Think of this as inspiration, not a drop-in-ready reusable repo.

## Wiring

1. Connect your OLED panel to the Arduino according to the OLED's specific pinout (likely 4 wires: 5V, GND, SDA, and SCK)
2. Connect a [pull-down resistor](https://www.delftstack.com/howto/arduino/arduino-pull-down-resistor/) between a digital input of your choice and GND on the Arduino
3. Connect a jumper wire between your Turbo LED's positive lead and that same digital input
4. Solder a molex connector to the power leads on the Arduino so that it also powers up when the computer turns on

## Centering your display

You can use the included `displaycenter.ino` sketch to display a centering pattern on a 128x64 monochrome display. This should help you line it up perfectly.

## Adapting the sketch

You can load the sketch in this repo to your Arduino to test, but it almost certainly won't be right for your machine. My Turbo button runs native clock speed when it's on, which is backwards to most. Also, you're probably not running a Cyrix Cx486 DX2 80MHz, so the logo contained here won't match your machine.

To create your processor logos, make 128x64px monochrome bitmaps (or if using a different OLED panel, the appropriate size and format for it) in GIMP, Paint, or whatever. Use Jasper van Loenen's [image2cpp](http://javl.github.io/image2cpp/) to convert them to an array with "Horizontal, 1 bit per pixel" formatting (or again, what your OLED wants). Paste those arrays into the top of the included sketch.

![Starfield Simulation screen saver](https://joshuawoehlke.com/wp-content/uploads/2022/07/starfield-simulation.gif)

You may also want to use a different screensaver. It should be relatively straightforward to rip out and replace with something else. Adafruit's [GFX library](https://learn.adafruit.com/adafruit-gfx-graphics-library/overview) is called in this sketch, so it makes sense to build them with that.