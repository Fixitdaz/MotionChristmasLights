# Motion-Activated Christmas Lights

**Arduino Uno project controlling WS2812B LEDs with a PIR motion sensor.**

This project creates an interactive holiday display. The lights remain in a dim, power-saving "Warm White" mode when the room is empty. When the PIR sensor detects movement, the strip triggers a bright, animated "Candy Cane" chase effect.

## Features
* **Idle Mode:** Low power, static warm white (Breathing effect optional).
* **Active Mode:** High brightness, moving Red/White stripes.
* **Timeout Logic:** Automatically reverts to idle 30 seconds after motion stops.

## Hardware Required
* Arduino Uno (or compatible)
* WS2812B Addressable LED Strip (NeoPixel)
* HC-SR501 PIR Motion Sensor
* 5V Power Supply (Amperage depends on strip length)
* 470Ω Resistor (Data line)
* 1000µF Capacitor (Power smoothing)

## Wiring

![Wiring Diagram]({https://github.com/Fixitdaz/MotionChristmasLights/blob/main/MotionChristmasLights/wiring_diagram.png})
| Component | Pin | Arduino Pin |
| :--- | :--- | :--- |
| **LED Strip** | Data (DIN) | Pin 6 |
| **PIR Sensor** | Signal (OUT) | Pin 2 |
| **Power** | 5V / GND | External PSU |

## Installation
1.  Open `MotionChristmasLights.ino` in Arduino IDE.
2.  Install the **FastLED** library by Daniel Garcia via Library Manager.
3.  Update `#define NUM_LEDS` to match your strip length.
4.  Upload to board.

## License
MIT License - Free to use and modify.
