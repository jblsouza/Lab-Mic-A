// João Souza 414298 e Alexandre Rocha 321451

#include <Wire.h>
#include "rgb_lcd.h"
#include <Stepper.h>
#include "rotary_angle_sensor.h"

//rotary angle sensor
int angle;
int mappedRPM;
#define pinCooler A6


//cooler variables
//int pinCooler = 7; //output pin of the cooler
int coolerPot; //potency of the cooler, it's going to be decided based on the temperature
int del_t=1000; //duration between temperature readings
int minPot = 3; //minimum potency acquired by testing
int maxPot = 5; //maximum potency acquired by testing

//motor variables
const int stepsPerRevolution = 200; //steps per revolution, specified by the motor type
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11); //creation of object that's going to represent our motor, pins 8,9,10,11 are going to be responsible for the control of the steps
int motorSpeed = 3; //motor speed represents qtty of revolutions per minute
int stepQ = 100; //represents the qtty of steps to be used
int minRPM = 1;
int maxRPM = 6;

//temperature sensor variables
int pinSensorTemp = 0; //input pin to get the temperature sensor
int a; //value that's going to acquire the value from analogRead of the sensor
float temperature; //temperature acquired by the sensor
int B=3975; //B value of the thermistor, it's acquired by the type of the sensor
float resistance; //resistance acquired by the measures of the sensor, it's going to be used to calculate the temperature
int minTemp = 29; //minimum temperature measured by the sensor 
int maxTemp = 32; //maximum temperature measured by the sensor

//lcd
rgb_lcd lcd; // I2C port of Arduino's Shield
const int colorR = 255; //red value of the background color of the LCD
const int colorG = 0; //green value of the background color of the LCD
const int colorB = 0; ////blue value of the background color of the LCD


void setup()
{
  //LCD setup
  lcd.begin(16, 2); // set up the LCD's number of columns and rows
  lcd.setRGB(colorR, colorG, colorB); // set lcd background color
  lcd.print("Temperature: "); //Prints message
  delay(del_t); //delay to set up the lcd

  //Motor setup
  myStepper.setSpeed(motorSpeed); //set motor speed to 60 revolution per minute, 1 revolution per second
}

void loop()
{
  //temperature control
  a=analogRead(pinSensorTemp); //reads output value of the sensor
  resistance=(float)(1023-a)*10000/a; //calculates the resistance of the temperature sensor
  temperature=1/(log(resistance/10000)/B+1/298.15)-273.15; //uses the calculated resistance to acquire the temperature value
  if (temperature < minTemp) //if a read temperature is lower then the minimum, then 
	  minTemp = temperature; //updates minTemp
  if (temperature > maxTemp) //if a read temperature is higher then the maximum, then 
	  maxTemp = temperature; //updates maxTemp
  
  //cooler control
  coolerPot = map(temperature, minTemp, maxTemp, minPot, maxPot); //maps the temperature into the cooler's potency
  coolerPot = map(coolerPot, minPot, maxPot, 200, 254);
  analogWrite(pinCooler, coolerPot); //write the potency in the cooler

  //LCD control
  lcd.setCursor(0, 1); // set the cursor to column 0, line 1 (note: line 1 is the second row, since counting begins with 0)
  lcd.print(temperature); //print temperature in the lcd
    
  //rotary angle
  angle = getDegree(); //returns the angle diference between the mark and the origin
  mappedRPM = map(angle, 0, FULL_ANGLE, minRPM, maxRPM); // It's going to map 0 to 300 degrees into 1 to 6 rpm, this means from 30s 1/2 revolution to 5s 1/2 revolution
	
  //motor control using rotary sensor
  myStepper.setSpeed(mappedRPM);
  delay(del_t);
  myStepper.step(stepQ); //the motor is going to make 1/2 of a revolution revolution, then changes direction
  stepQ = -stepQ; //changes rotation direction
}
