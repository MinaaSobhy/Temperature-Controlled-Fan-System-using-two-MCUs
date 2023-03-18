
#include "pot.h"



/*
 * Description :
 * Calculate the resistance from the ADC digital value and return it to the user.
 */
uint8 get_Res(void)
{
	uint8 res = 0;

	uint16 adc = 0;

	/* Read ADC channel where the potentiometer is connected */

	adc = ADC_read(SENSOR_CHANNEL_ID);
	_delay_ms(5);
	/* Calculate the resistance from the ADC value*/
	res = (uint8)((uint16)(((float)adc*ADC_REF_VOLT_VALUE/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE))*100));

	return res;
}
