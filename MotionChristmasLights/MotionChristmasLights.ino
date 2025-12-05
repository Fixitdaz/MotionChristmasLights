#include <FastLED.h>

// --- Hardware Configuration ---
#define LED_PIN     6       // Data Pin
#define PIR_PIN     2       // Sensor Signal Pin
#define NUM_LEDS    60      // LED Count
#define BRIGHTNESS  255     // Max Brightness
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];

// --- Timer Variables ---
unsigned long lastMotionTime = 0;
const unsigned long motionTimeout = 30000; // 30 seconds

void setup() {
  delay(3000); // Safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
  pinMode(PIR_PIN, INPUT);
}

void loop() {
  int pirState = digitalRead(PIR_PIN);

  if (pirState == HIGH) {
    lastMotionTime = millis();
  }

  if (millis() - lastMotionTime < motionTimeout) {
    candyCaneEffect();
  } else {
    warmIdle();
  }
}

// Active Pattern
void candyCaneEffect() {
  FastLED.setBrightness(255);
  static uint8_t startIndex = 0;
  startIndex++;
  for( int i = 0; i < NUM_LEDS; i++) {
    int pixelPos = i + startIndex;
    if (pixelPos % 4 < 2) {
      leds[i] = CRGB::Red;
    } else {
      leds[i] = CRGB::White;
    }
  }
  FastLED.show();
  delay(100);
}

// Idle Pattern
void warmIdle() {
  FastLED.setBrightness(50);
  fill_solid(leds, NUM_LEDS, CRGB(255, 147, 41));
  FastLED.show();
  delay(500);
}