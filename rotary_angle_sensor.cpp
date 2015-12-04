#include <Arduino.h>
#include <Wire.h>
#include "rotary_angle_sensor.h"

int getDegree() {
	int sensor_value = analogRead(ROTARY_ANGLE_SENSOR);
	float voltage;
	voltage = (float)sensor_value*ADC_REF/1023;
	float degrees = (voltage*FULL_ANGLE)/GROVE_VCC;
	return degrees;
}
