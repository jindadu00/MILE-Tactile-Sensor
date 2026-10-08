# Illumination assembly and wiring

The photographs below show the sensor's LED strip seated inside the printed housing, the ATtiny85 controller board, and the camera board. The documented assembly uses **eight LEDs** for red, green, and blue illumination from three directions. The released firmware defines ten color positions, `RRRBBGGGBB`, with the final two blue LEDs optional. The camera uses a **120° fixed-focus lens**. The camera board provides a shared **5 V supply**, and the ATtiny85 board controls the LED strip.

## Assembly photographs

<img src="images/illumination-assembly-front.jpg" alt="LED strip inside the sensor housing, controller board front, and camera board connected by wires." width="420">

*Front view of the illumination assembly and connected boards. The LED strip follows the inner perimeter of the housing, and the wires leave through the housing opening.*

<img src="images/illumination-assembly-back.jpg" alt="Reverse view of the controller board with printed pin labels, the camera board, and the sensor housing." width="420">

## Soldering and assembly

1. Position the LED strip along the inner perimeter of the housing as shown in the photographs and assembly CAD. The documented eight-LED assembly uses the first eight positions, `RRRBBGGG`; two additional blue LEDs can occupy the end of the signal chain. Follow the strip's permitted bend and cut locations.
2. Identify the **5 V**, **ground**, and **signal-input** pads on the LED strip and the corresponding connections on the ATtiny85 board. Follow the terminal labels and the strip's input direction.
3. Route flexible wires through the housing opening. Leave sufficient length for assembly and servicing without pulling on the solder joints.
4. Connect the LED strip to the ATtiny85 board using **red for 5 V**, **black for ground**, and **blue for the LED control signal**. Connect the camera board to the ATtiny85 board using **red for 5 V** and **black for ground**, so the illumination assembly shares the camera board's 5 V supply. Keep solder joints compact and avoid bridges between adjacent pads.
5. Check continuity and ensure that supply and ground are not shorted before powering the assembly. Insulate exposed connections where needed and keep wires clear of the camera opening and acrylic seating surfaces.
6. Upload the [LED-control sketch](../Firmware/MILE_LED/MILE_LED.ino), power the camera board, and check the color order and illumination before fixing the acrylic support and bonding the gel. See [firmware setup](../Firmware/README.md).

## Connection roles

| Connection | Wire color | Function |
| --- | --- | --- |
| Camera board → ATtiny85 board | Red | Shared 5 V supply |
| Camera board → ATtiny85 board | Black | Common ground |
| ATtiny85 board → LED strip | Red | LED-strip 5 V supply |
| ATtiny85 board → LED strip | Black | LED-strip ground |
| ATtiny85 board → LED strip | Blue | LED control signal; default firmware output is digital pin 3 (P3 / PB3 on the pictured board) |

The camera board, ATtiny85 board, and LED strip share the same ground. The blue wire carries the control signal from the ATtiny85 board to the LED strip's signal input. `LED_PIN` is an Arduino digital-pin number; match it to the board's pin mapping and the actual signal-wire connection.

## LED color order

Count LEDs from the signal-input end, starting at index 0:

| LED index | Color |
| --- | --- |
| 0–2 | Red |
| 3–4 | Blue |
| 5–7 | Green |
| 8–9 | Blue (optional final LEDs) |

If the final two LEDs are physically absent, the first eight retain the same colors. Removing LEDs from the beginning or middle changes the index-to-position mapping. Brightness is configurable in the sketch; check the assembled camera image after changing the illumination.
