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
//All libraries needed for this code
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_BME680.h"
#include <SparkFun_Qwiic_OLED.h> //http://librarymanager/All#SparkFun_Qwiic_Graphic_OLED

//defines necessary sea level pressure for gas resistance calculations, pressure, and more
#define SEALEVELPRESSURE_HPA (1033.47)

//objects being used (including the Arduino BME680 sensor and an OLED)
Adafruit_BME680 bme; // I2C
QwiicMicroOLED myOLED;

//initialize step variables
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
  //testing if BME680 functions
  Serial.begin(115200);
  while (!Serial);
  Serial.println(F("BME680 test"));

  if (!bme.begin(0x76)) {
    Serial.println("Could not find a valid BME680 sensor, check wiring!");
    while (1);
  }

  // Set up oversampling and filter initialization
  bme.setTemperatureOversampling(BME680_OS_8X); 
  bme.setHumidityOversampling(BME680_OS_2X); 
  bme.setPressureOversampling(BME680_OS_4X); 
  bme.setIIRFilterSize(BME680_FILTER_SIZE_3); 
  delay(180);

  Serial.begin(115200);
    //Serial.println("Running OLED example");

    Wire.begin();

    // Initalize the OLED device and related graphics system
    if (myOLED.begin() == false)
    {
        Serial.println("Device begin failed. Freezing...");
        while (true)
            ;
    }

    //Displays initial pop-up message on OLED Device
    myOLED.setCursor(0,10); 
    myOLED.println("Checking for VOCs");
    myOLED.display();
    delay(300);

}

void loop() {
  //checks to see if bme680 works
  if (! bme.performReading()) {
    Serial.println("Failed to perform reading :(");
    return;
  }

  //Multiple sections of step variables being assigned gas resistance values
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

  //prints all gas resistance and step values
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

  // if and else if loops to determine whether to display caution message based on gas resistance value in any of the step variables (concluded based on trials)
  if (Step1 <= 60) {
     myOLED.erase();
     myOLED.setCursor(0,10);
     myOLED.println("Caution: VOC Detected");
     myOLED.display();
  }
  else if (Step2 <= 60) {
     myOLED.erase();
     myOLED.setCursor(0,10);
     myOLED.println("Caution: VOC Detected");
     myOLED.display();
  }
  else if (Step3 <= 60) {
     myOLED.erase();
     myOLED.setCursor(0,10);
     myOLED.println("Caution: VOC Detected");
     myOLED.display();
  }
  else if (Step4 <= 60) {
     myOLED.erase();
     myOLED.setCursor(0,10);
     myOLED.println("Caution: VOC Detected");
     myOLED.display();
  }
  else if (Step5 <= 60) {
     myOLED.erase();
     myOLED.setCursor(0,10);
     myOLED.println("Caution: VOC Detected");
     myOLED.display();
  }
  else if (Step6 <= 60) {
     myOLED.erase();
     myOLED.setCursor(0,10);
     myOLED.println("Caution: VOC Detected");
     myOLED.display();
  }
  else if (Step7 <= 60) {
     myOLED.erase();
     myOLED.setCursor(0,10);
     myOLED.println("Caution: VOC Detected");
     myOLED.display();
  }
  else if (Step8 <= 60) {
     myOLED.erase();
     myOLED.setCursor(0,10);
     myOLED.println("Caution: VOC Detected");
     myOLED.display();
  }
  else if (Step9 <= 60) {
     myOLED.erase();
     myOLED.setCursor(0,10);
     myOLED.println("Caution: VOC Detected");
     myOLED.display();
  }
  else if (Step10 <= 60) {
     myOLED.erase();
     myOLED.setCursor(0,10);
     myOLED.println("Caution: VOC Detected");
     myOLED.display();
  }
  else {
     myOLED.erase();
     myOLED.setCursor(0,10);
     myOLED.println("No VOC Detected");
     myOLED.display();
  }
 
  
}
