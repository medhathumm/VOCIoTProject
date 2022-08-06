This is a [link](https://www.canva.com/design/DAFIZTETbGU/khlEG6ExhC2Ftb0q4DLnlg/view?utm_content=DAFIZTETbGU&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton) to a Canva presentation with less details but general information about the project.

# Background/Context
This is a beginner project focused on plotting Gas Resistance values (through the BME680 Environmental Sensor and Arduino Uno) in order to determine if Volatile Organic Compounds (VOCs) are present in a liquid, room/space, etc. 

However, this project focuses more toward Ethanol, which is a VOC commonly found in alcoholic bevarages, hand sanitizer, fuel, and more. Other aspects of Ethanol include:
- highly flammable
- clear, colorless liquid
- dissolves in water and other organic liquids
- pleasant odor, but burning taste
- room temperature
- also called ethyl alcohol

The reason that I had chosen to focus on Ethanol was due to an incident where a house in my neighborhood caught on fire. The fire initially started from the garage and moved to the entre backside and attic. Thankfully no one was in the house, but the potential that someone could have gotten harmed was huge. Firefighters at the scene concluded that the cause of the fire could have been a highly flammable leaked paint can, leaked gas tank, and other products. The house lacked a safety system or sensor, especially in the garage, with the ability to notify its resident of a potential VOC or leak. 

That is why I decided to focus on Ethanol and develop a device that searchs for VOCs and notifies the owner/user. This device is easy to use, effective in detecting VOCs, and (with further development) can be portable. 

Anyone can use this device. It's purpose is to be placed in locations with the most chemical household items or beverages (such as garages, bar rooms, cleaning supply cabinets, and more). The device is very different from common gas and ethanol detectors because these detectors/sensors are quite large and hard to interpret. The circuit and OLED is specifically coded to be easy-to-use and understand. 

Details of the project, circuit, and code are in the following sections. 

# Project and Circuit Layout
The circuit uses [Arduino Uno](https://www.sparkfun.com/products/15123) (or also known as the RedBoard Qwiic from SparkFun), [BME688 Sensor](https://www.sparkfun.com/products/19096) (similar to the BME680 Environmental Sensor and libraries work for both), [Micro OLED](https://www.sparkfun.com/products/14532), [Micro-B USB Cable](https://www.sparkfun.com/products/10215), and [Qwiic Cables](https://www.sparkfun.com/products/17259). All of these products are from SparkFun; therefore, the code is adjusted to work for these products and may need change for other products. 

Using these products, the circuit is set up as computer -> Arduino Uno -> BME680 -> OLED (where -> represents a cable connectivity). Please use the photos below for reference. 
- [Image #1 of circuit](https://drive.google.com/file/d/1y2ZjQC4EFqr70kspkzPAczW41k7UYcBL/view?usp=sharing)
- [Image #2 of circuit](https://drive.google.com/file/d/1-wZBbr4TrorwE3fzVAs2Vk3e0yQ8Z1Cd/view?usp=sharing)

There are 4 different tests and examples of code linked to this project: IOT_Project1, IOT_Project_Final_Gas_Resistance, plotData7.py, and plotData8.py. There are more specific details regarding the code and its uses in the later sections. 

In order for the project's success, there needs to be a timeline from June 23rd to August4th.
- June 23rd: Acquire necessary materials
- June 30th: Research and understand the applications of the materials and Arduino system.
- July 7th: Set up Arduino IDE, Anaconda, Python, and circuit system. Brainstorm project ideas.
- July 14th: Research project VOC, test sample codes, and debug issues.
- July 21st: Debug and test project data.
- July 28th: Add final details, confirm data, and complete final report.
- August 4th: Submit final report and project.

# Code
Lets first look at the IOT_Project1 code (also known as the BME680test found in the examples of the Adafruit BME680 Library in Arduino IDE). This code is used in Arduino IDE and I used it for the temperature data for my project. It starts with downloading and including all of the necessary libraries. Then, the Altitude is calculated (which is necessary to find the rest of the variables). Then the void setup() loop begins and the code checks to make sure that the BME680 works and is set up correctly. If not set up correctly, the serial monitor returns a printed statement that the BME680 could not be found. In this loop, the code also sets the original gas value, temperature sensor, humidity sensor, and pressure sensors. After all of these initial sensors have been approved, the code moves onto the void loop() section. In this section, there is an if loop so that the temperature, humidity, pressure and gas continue to get printed (does not have a maximum limit). I have commented out lines 61 and 62 for my own purposes, but those can be uncommented when needed or for reference. 

The data prints in the serial montior; however, in order to plot the data, the plotData7.py was used. I personally used Anaconda (also found as Anaconda Prompt (anaconda3) in windows) to download serials, program, and display the data points. Please look at the image below for reference. 
- [Anaconda](https://drive.google.com/file/d/1oZ2hNtqxkpdTYuP2XsTjegpOTbQln6Kr/view?usp=sharing)
(If you use this reference, please don't forget to put "python" before doing the python code of imports.)

The results for all of these codes are in the next section as well as their analysis.

The next set of codes used were the IOT_Project_Final_Gas_Resistance and plotData8.py. The IOT_Project_Final_Gas_Resistance prints the gas resistance values for the BME680 device. This program is uniquely modified to print an OLED display regarding whether a VOC was detected or not. The reason for the comparison between the gas resistance value to 60 KOhms is derived from the conclusions after initial tests (which can be found in the next section). The plotData.py is then used to specifically plot the data for the IOT_Project_Final_Gas_Resistance code. 

# Data Demo
Below is a YouTube link of me setting up the experiment and getting the data.
- [Demo Video](https://youtu.be/cKO28BpEptY)

# Data
Below are links to images for normal temperature and normal gas resistance values. 
- [Normal Temperature](https://drive.google.com/file/d/17dmyoQyN1IeyD_nPF6fFVl5ttMoqzJ8b/view?usp=sharing)
- [Normal Gas Resistance Values](https://drive.google.com/file/d/11k-O4UgHP3tjNVkNDljzhsUNMTi1_zHi/view?usp=sharing)

Below are links to images for the temperature and gas resistance values for an ethanol liquid: hand sanitizer. 
- [Hand Sanitizer Temperature](https://drive.google.com/file/d/1J7yUGIa3ZBozpbRaerjrmbbzxxzA4LOl/view?usp=sharing)
- [Hand Sanitizer Gas Resistance Values Set #1](https://drive.google.com/file/d/1LMJwbmRAD1JmhafOLZVdIoM9BkKcJor-/view?usp=sharing)
- [Hand Sanitizer Gas Resistance Values Set #2](https://drive.google.com/file/d/1XAjJBry_9vAsBFPNqhz_yI157iZbPauU/view?usp=sharing)

Below are the links to images for the temperature and gas resistance values for another ethanol liquid substance: whiskey.
- [Whiskey Temperature](https://drive.google.com/file/d/1CrSnhlJoFNHJgdjosE8aESBbPMaNI3L-/view?usp=sharing)
- [Whiskey Gas Resistance Values](https://drive.google.com/file/d/14P5wWUUnZXpSyQHasRk5xH7_9naAZqOd/view?usp=sharing)

# Data Analysis
As can clearly be seen, the normal temperature values are around 75-78 degrees Fahrenheit. The hand sanitizer temperature reading is around the same value as well. The whiskey temperature reading is slightly above, but can be considered equivalent due to small environmental factors that can cause the 2-5 degree Fahrenheit difference. Because the ethanol liquids have the same temperature as the normal temperature setting, the temperature factors and heat profiles will not be significant in determining if a VOC is present in the area. 

This is why the gas resistance value data is significant. The normal temperature is between 180 - 230 KOhms. Though this might seem like a big difference, if you look at the resistance values of the hand sanitizer and whiskey, it is evident when a VOC is detected. In other words, the Gas Resistance reading of the hand sanitizer is between 5 - 14 KOhms, which is a huge difference from 180 - 230 KOhms. This is the same situation for the whiskey, which has a gas resistance reading of between 8 - 10 KOhms. That is why the code in IOT_Project_Final_Gas_Resistance compares the Gas Resistance reading value to 60 KOhms (because the gas resistance value will for sure be above 60 KOhms in a non-VOC situation, but below 60 KOhms in a VOC situation).

The OLED clearly displays this, as shown in the demo. 

# Final Conclusions
The main purpose of this project is to show how such common household items can be flammable and dangerous when handled incorrectly and left open in a dangerous location. This is especially important to consider since hand sanitizer has 70% ethyl alcohol (which is also ethanol) and hand sanitizer is used greatly during the COVID pandemic. The other important conclusion from the experiment is the whiskey bottle. The bottle was empty (except for a few mL of alcohol left), but continued to have an alcoholic ordor. Despite being empty, the BME680 was able to pick up on VOCs. This shows that alcoholic beverages must be disposed of correctly in order to prevent harm and injuries. 

# Extra Resources
- [Using Python to Read a Sensor](https://problemsolvingwithpython.com/11-Python-and-External-Hardware/11.04-Reading-a-Sensor-with-Python/)
- Additional tests (such as HeaterProfileTest.ino and gasRead.py) are also linked for references. 












