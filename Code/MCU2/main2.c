
#include "main2.h"

/* Ports and Pins of LEDs and the channel of the ADC */
#define SENSOR_CHANNEL_ID 0



int main(void)
{
	/* ADC Configuration for potentiometer sensor*/
	ADC_ConfigType ADC_Config = {INTERNAL_VOLTAGE, F_CPU_8};
	/* ADC initialization*/
	ADC_init (&ADC_Config);

	/* UART Configuration */
	UART_ConfigType uart_type = {EIGHT_BIT, DISABLED, TWO_BIT, 9600};
	/* UART initialization */
	UART_init(&uart_type);

	//DC motor Initialization
	DCmotor_init();

	//LED initialization
	GPIO_setupPinDirection(LEDR_PORT,LEDR_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection(LEDY_PORT,LEDY_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection(LEDG_PORT,LEDG_PIN, PIN_OUTPUT);

	/* Set the three bits to turn off the LEDs at the beginning */
	GPIO_writePin(LEDR_PORT,LEDR_PIN, LOGIC_HIGH);
	GPIO_writePin(LEDY_PORT,LEDY_PIN, LOGIC_HIGH);
	GPIO_writePin(LEDG_PORT,LEDG_PIN, LOGIC_HIGH);

	/* variables declaration */
	uint8 speed; // to store the current motor speed
	uint8 temp; // to store the current temperature
	uint8 i; // to store the loop number till stop the motor

	while(1)
	{
		/* receiving the temperature from the first MCU */
		temp = UART_recieveByte();


		if (temp < 200)
		{
			/* calculate motor speed from the potentiometer */
			speed=get_Res();

			/* send the motor speed percentage to the first MCU */
			UART_sendByte(speed);

			/* move the motor with the required speed according to the
			 * reading of the potentiometer and rotate it ACW */
			DCmotor_info(speed,'F');

		}
		/* slow down the motor if the temperature is more than or equal 200 */
		else
		{

			for (i = speed; i > 0; i--)
			{
				DCmotor_info(i , 'F');
				_delay_ms(30);
			}


		}


		/*lighting the lEDs */
		if ( temp < 20)
		{
			/* if the temperature is below 20 the green led
			 * will lighten up*/
			GPIO_writePin(LEDR_PORT,LEDR_PIN, LOGIC_HIGH);
			GPIO_writePin(LEDY_PORT,LEDY_PIN, LOGIC_HIGH);
			GPIO_writePin(LEDG_PORT,LEDG_PIN, LOGIC_LOW);


		}
		else if ( temp <= 40)
		{
			/* if the temperature is between 20 and 40
			 * the yellow led will lighten up */
			GPIO_writePin(LEDR_PORT,LEDR_PIN, LOGIC_HIGH);
			GPIO_writePin(LEDY_PORT,LEDY_PIN, LOGIC_LOW);
			GPIO_writePin(LEDG_PORT,LEDG_PIN, LOGIC_HIGH);


		}
		else
		{
			/* if the temperature is between more than 40
			 * the red led will lighten up */
			GPIO_writePin(LEDR_PORT,LEDR_PIN, LOGIC_LOW);
			GPIO_writePin(LEDY_PORT,LEDY_PIN, LOGIC_HIGH);
			GPIO_writePin(LEDG_PORT,LEDG_PIN, LOGIC_HIGH);
		}
	}
}

