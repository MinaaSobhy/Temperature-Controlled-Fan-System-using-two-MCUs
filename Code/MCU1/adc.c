

#include "avr/io.h"
#include <avr/interrupt.h>
#include "adc.h"
#include "common_macros.h"



/*******************************************************************************
 *                          Functions Definitions                              *
 *******************************************************************************/

void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	/* ADMUX Register Bits Description:
	 * REFS1:0 = 11 to choose to use the internal 2.56 Volt reference voltage
	 * ADLAR   = 0 right adjusted
	 */
	ADMUX = ( ADMUX & (0x3F) ) | ( (Config_Ptr->ref_volt)<<6 );

	/* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 * ADATE   = 0 Disable Auto Trigger
	 * ADPS2:0 = 011 to choose ADC_Clock=F_CPU/8=1Mhz/8=125Khz --> ADC must operate in range 50-200Khz
	 * depending on what the user will choose
	 */
	ADCSRA |= (1<<ADEN) ;
	ADCSRA = (ADCSRA & (0xF8)) | (Config_Ptr->prescaler);
}

uint16 ADC_read(uint8 channel)
{
	    channel &= 0x07; /* Input channel number must be from 0 --> 7 */
		ADMUX &= 0xE0; /* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
		ADMUX = ADMUX | channel; /* Choose the correct channel by setting the channel number in MUX4:0 bits */
		SET_BIT(ADCSRA,ADSC); /* Start conversion write '1' to ADSC */
		while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Wait for conversion to complete, ADIF becomes '1' */
		SET_BIT(ADCSRA,ADIF); /* Clear ADIF by write '1' to it :) */
		return ADC; /* Read the digital value from the data register */

}