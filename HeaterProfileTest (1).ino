/***************************************************************************
  This is a library for the BME680 gas, humidity, temperature & pressure sensor

  Designed specifically to work with the Adafruit BME680 Breakout
  ----> http://www.adafruit.com/products/3660

  These sensors use I2C or SPI to communicate, 2 or 4 pins are required
  to interface.

  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing products
  from Adafruit!

  Written by Limor Fried & Kevin Townsend for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ***************************************************************************/

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_BME680.h"

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME680 bme; // I2C

int Step1;
int Step2;
int Step3;
int Step4;
int Step5;
int Step6;
int Step7;
int Step8;
int Step9;
int Step10;

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println(F("BME680 test"));

  if (!bme.begin()) {
    Serial.println("Could not find a valid BME680 sensor, check wiring!");
    while (1);
  }

  // Set up oversampling and filter initialization
  bme.setTemperatureOversampling(BME680_OS_8X);
  bme.setHumidityOversampling(BME680_OS_2X);
  bme.setPressureOversampling(BME680_OS_4X);
  bme.setIIRFilterSize(BME680_FILTER_SIZE_3);
  delay(180);
}

void loop() {
  if (! bme.performReading()) {
    Serial.println("Failed to perform reading :(");
    return;
  }

  //Equivalent to HP-354
  bme.setGasHeater(320, 60);
  bme.performReading();
  Step1 = (bme.gas_resistance)/1000;
  
  bme.setGasHeater(320, 120);
  bme.performReading();
  Step2 = (bme.gas_resistance)/1000;
  
  bme.setGasHeater(320, 180);
  bme.performReading();
  Step3 = (bme.gas_resistance)/1000;
  
  bme.setGasHeater(320, 240);
  bme.performReading();
  Step4 = (bme.gas_resistance)/1000;;
  
  bme.setGasHeater(320, 300);
  bme.performReading();
  Step5 = (bme.gas_resistance)/1000;
  
  bme.setGasHeater(320, 360);
  bme.performReading();
  Step6 = (bme.gas_resistance)/1000;
  
  bme.setGasHeater(320, 420);
  bme.performReading();
  Step7 = (bme.gas_resistance)/1000;;
  
  bme.setGasHeater(320, 480);
  bme.performReading();
  Step8 = (bme.gas_resistance)/1000;
  
  bme.setGasHeater(320, 540);
  bme.performReading();
  Step9 = (bme.gas_resistance)/1000;
  
  bme.setGasHeater(320, 600);
  bme.performReading();
  Step10 = (bme.gas_resistance)/1000;
  Serial.print("Step 1:");
  Serial.println(Step1);
  Serial.print("Step 2:");
  Serial.println(Step2);
  Serial.print("Step 3:");
  Serial.println(Step3);
  Serial.print("Step 4:");
  Serial.println(Step4);
  Serial.print("Step 5:");
  Serial.println(Step5);
  Serial.print("Step 6:");
  Serial.println(Step6);
  Serial.print("Step 7:");
  Serial.println(Step7);
  Serial.print("Step 8:");
  Serial.println(Step8);
  Serial.print("Step 9:");
  Serial.println(Step9);
  Serial.print("Step 10:");
  Serial.println(Step10);
 // Serial.println("\n");
  delay(2000);
}
