# Background/Context
This is a beginner project focused on plotting Gas Resistance values (through the BME680 Environmental Sensor and Arduino Uno) in order to determine if Volatile Organic Compounds (VOCs) are present in a liquid, room/space, etc. 

However, this project focuses more toward Ethanol, which is a VOC commonly found in alcoholic bevarages, hand sanitizer, fuel, and more. Other aspects of Ethanol include:
- also called ethyl alcohol
- highly flammable
- clear, colorless liquid
- dissolves in water and other organic liquids
- pleasant odor, but burning taste
- room temperature

The reason that I had chosen to focus on Ethanol due to an incident where a house in my neighborhood caught on fire. The fire initially started from the garage and moved to the entre backside and attic. Thankfully no one was in the house, but the potential that someone could have gotten harmed was huge. Firefighters at the scene concluded that the cause of the fire could have been a highly flammable leaked paint can, leaked gas tank, and other products. The house lacked a safety system or sensor, especially in the garage, with the ability to notify its resident of a potential VOC or leak. 

That is why I decided to focus on Ethanol and develop a device that searchs for VOCs and notifies the owner/user. This device is easy to use, effective in detecting VOCs, and (with further development) can be portable. 

Anyone can use this device. It's purpose is to be placed in locations with the most chemical household items or beverages (such as garages, bar rooms, cleaning supply cabinets, and more). The device is very different from common gas and ethanol detectors because these detectors/sensors are quite large and hard to interpret. The circuit and OLED is specifically coded to be easy-to-use and understand. 

Details ofthe project, cirucit, and code are in the following sections. 

# Project and Circuit Layout
The circuit uses [Arduino Uno](https://www.sparkfun.com/products/15123) (or also known as the RedBoard Qwiic from SparkFun), [BME688 Sensor](https://www.sparkfun.com/products/19096) (similar to the BME680 Environmental Sensor and libraries work for both), [Micro OLED](https://www.sparkfun.com/products/14532), [Micro-B USB Cable](https://www.sparkfun.com/products/10215), and [Qwiic Cables](https://www.sparkfun.com/products/17259). All of these products are from SparkFun; therefore, the code is adjusted to work for these products and may need change for other products. 

Using these products, the circuit is set up as computer -> Arduino Uno -> BME680 -> OLED (where -> represents a cable connectivity). Please use the photos below for reference. 
[Image #1 of circuit](https://drive.google.com/file/d/1y2ZjQC4EFqr70kspkzPAczW41k7UYcBL/view?usp=sharing)
[Image #2 of circuit](https://drive.google.com/file/d/1-wZBbr4TrorwE3fzVAs2Vk3e0yQ8Z1Cd/view?usp=sharing)


There are 4 different tests and examples of code linked to this project: IOT_Project1, IOT_Project_Final_Gas_Resistance, plotData7.py, and plotData8.py. There are more specific details regarding the code and its uses in the later sections. 

In order for the project's success, there needs to be a timeline from June 23rd to August4th.
- June 23rd: 








