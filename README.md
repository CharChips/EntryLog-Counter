# EntryLog-Counter
### A simple Arduino based counter which counts the number of time a door has been opened.
### - by Charchit 
## Brief Description
An ultrasonic sensor and a seven segment display is interfaced with an arduino uno. The seven segment display diplays a value which initialized from zero and increments every time an object placed in front of the ultrasonic sensor is taken away from a certain specified distance from the sensor. This simple project can be used as a boilerplate template that can be used in other project as a counter circuit using distance sensor.
[Watch the sample video here](https://drive.google.com/file/d/1Zn_47Y1QejGaejkwp1mjF1is82TPK_4K/view?usp=drivesdk)

## Components Used:
- Arduino Uno
- Ultrasonic Distance Sensor (HC-SR04)
- Seven-Segment Display

## Basic user guide
- use the arduino code provided for Arduino IDE
- do the necessary pin connections as per the circuit diagram (preferably use a breadboard and jumper wires)
- upload the code to your arduino uno 

## Known Issues
-the counter resets to 0 after 8 

## future improvements
- *4-Digit Seven-Segment Display (WLG12-PA5)* can be used instead of a single digit segment display

## Applications
- It can be installed in front of a door , it will count the number of times the door has been opened, hence the name *EntryLog-Counter*
  
