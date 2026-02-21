#include <Wire.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp;


const int SOLENOID_PIN = x;
const int SOLENOID_PULSE_MS = 300;


float altitude1, altitude2; 
float GroundPressure;
bool fired = false;
bool armed = false;

void setup() {
  Serial.begin(9600);
  delay(1000);

  pinMode(SOLENOID_PIN, OUTPUT);
  digitalWrite(SOLENOID_PIN, LOW);
  if (!bmp.begin(0x76)) {
    while (1);
  }

  GroundPressure = bmp.readPressure() / 100.0;
}

void loop() {
altitude1 = bmp.readAltitude(groundPressure);
delay(500)
altitude2 = bmp.readAltitude(groundPressure);

  if (!armed && altitude1 > 5.0)
  {
    armed = true;
  }

  if (armed && !fired && (altitude2 - altitude1) <= 1) {
    fireSolenoid();
    fired = true;
  }

  delay(50);
}

void fireSolenoid() {
  digitalWrite(SOLENOID_PIN, HIGH);
  delay(SOLENOID_PULSE_MS);
  digitalWrite(SOLENOID_PIN, LOW);
}
