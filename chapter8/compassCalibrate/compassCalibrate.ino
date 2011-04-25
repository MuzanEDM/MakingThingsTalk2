#include <Wire.h>
#include <LSM303DLH.h>

LSM303DLH compass;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  compass.enable();

  // calibrate for the first ten seconds after startup:
  while (millis() < 10000) {
    compass.calibrate(); 
  }
}

void loop() {
  compass.read();
  int heading = compass.heading();
  Serial.println(heading);
  delay(100);
}





