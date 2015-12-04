#define ROTARY_ANGLE_SENSOR A1 //Input Pin of the rotary angle sensor
#define ADC_REF 5//reference voltage of ADC is 5v.If the Vcc switch on the seeeduino
				 //board switches to 3V3, the ADC_REF should be 3.3
#define GROVE_VCC 5//VCC of the grove interface is normally 5v
#define FULL_ANGLE 300//full value of the rotary angle is 300 degrees

int getDegree();
