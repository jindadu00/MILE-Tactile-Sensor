# LED-control firmware

[MILE_LED/MILE_LED.ino](MILE_LED/MILE_LED.ino) provides constant RGB illumination using an ATtiny85 board and the [Adafruit NeoPixel library](https://github.com/adafruit/Adafruit_NeoPixel).

## Configuration

| Setting | Default | Description |
| --- | --- | --- |
| `LED_PIN` | `3` | Arduino digital-pin number; P3 / PB3 on the pictured ATtiny85 board |
| `LED_PATTERN` | `"RRRBBGGGBB"` | Color order from the signal-input end of the LED strip |
| `NUMPIXELS` | `10` | Calculated from the pattern length |
| `RED_LEVEL` | `15` | Red channel setting, 0–255 |
| `GREEN_LEVEL` | `15` | Green channel setting, 0–255 |
| `BLUE_LEVEL` | `15` | Blue channel setting, 0–255 |
| Pixel format | `NEO_GRB + NEO_KHZ800` | GRB byte order and 800 kHz signaling, retained from the supplied sketch |

The first eight color positions are `RRRBBGGG`. If the last two blue LEDs are omitted from the physical strip, the same sketch still supplies the correct colors to those first eight LEDs. This applies when LEDs are omitted from the **end of the signal chain**; omitting LEDs at its beginning or middle requires adjusting the pattern.

The brightness defaults are adjustable starting values, not recovered experimental calibration. Tune them with the assembled gel and camera at the intended exposure, checking for clipping and uneven illumination. The optional final two LEDs change the illumination distribution when fitted.

## Upload and check

1. Install Arduino IDE and the board package appropriate for the ATtiny85 controller. Select the actual board and CPU clock configuration. For board support, consult the [ATTinyCore documentation](https://github.com/SpenceKonde/ATTinyCore).
2. Install **Adafruit NeoPixel** through the Arduino Library Manager.
3. Open `MILE_LED/MILE_LED.ino`. Keep the sketch inside the folder named `MILE_LED`.
4. Match `LED_PIN` to the blue signal wire's board terminal. The supplied assembly uses P3 / PB3. Check the strip's input direction and pixel format.
5. Compile and upload using the selected board's supported upload method. On [Digispark-style boards](https://github.com/ArminJo/DigistumpArduino#pin-layout), P3 also carries USB data; disconnect the LED signal wire during USB programming and reconnect it afterward. Restore the [shared camera-board 5 V and ground connections](../docs/led-wiring.md) for operation.
6. Verify the color order before final assembly. Temporarily setting `LED_PATTERN` to `"R......."` lights only index 0 on an eight-position strip. `"G......."` and `"B......."` allow checking the other color channels; restore `"RRRBBGGGBB"` afterward.
7. Adjust `RED_LEVEL`, `GREEN_LEVEL`, and `BLUE_LEVEL` as needed, then check the assembled camera image.

The sketch sets all pixel colors in `setup()` and transmits one frame. `loop()` is empty because the LEDs retain the last transmitted colors for constant illumination.

## License

The sketch is adapted from the NeoPixel Ring simple example by Shae Erisson (2013) and retains its GPLv3 license notice. [MILE_LED/LICENSE.txt](MILE_LED/LICENSE.txt) contains the license text for this sketch.
