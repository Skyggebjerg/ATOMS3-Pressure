#include <Arduino.h>

/**
 * @Hardwares: M5AtomS3
 * @Platform Version: Arduino M5Stack Board Manager v2.0.9
 * @Dependent Library:
 * M5GFX: https://github.com/m5stack/M5GFX
 * M5Unified: https://github.com/m5stack/M5Unified
 * M5AtomS3: https://github.com/m5stack/M5AtomS3
 */

#include "M5AtomS3.h"

int sensorPin = 1; // Sensor Pin on AtomS3

void setup() {
  Serial.begin(115200);
  auto cfg = M5.config();
  AtomS3.begin(cfg);
  pinMode(sensorPin, INPUT);  //Sets the specified pin to input mode.  设置指定引脚为输入模式

      AtomS3.Display.setTextColor(GREEN);
    //AtomS3.Display.setTextDatum(middle_center);
    AtomS3.Display.setFont(&fonts::Orbitron_Light_24);
    AtomS3.Display.setTextSize(1);
    AtomS3.Display.drawString("Click!", AtomS3.Display.width() / 2,
                              AtomS3.Display.height() / 2);
}

void loop() {
  float raw = analogRead(sensorPin);  // read the value from the sensor.  读取当前传感器的值
  float Vout = raw/4095*3.6; 
  float P = (Vout-0.1)/3.0*300.0-100.0;
  AtomS3.Display.clear();
  AtomS3.Display.drawString("P: ", 5, 5);
  AtomS3.Display.drawString(String(P), 40, 5);
  Serial.printf("pressure: %f.2 Kpa\r\n", P);
  delay(1000);
}