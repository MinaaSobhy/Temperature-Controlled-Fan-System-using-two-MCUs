

#include "main1.h"


/* Interrupt 0 interrupt Service Routine */
ISR(INT0_vect)
{
	/* sending the special code when the button is pressed*/
	UART_sendByte(special_code);
}

/* Interrupt 0 initialization */
void INT0_Init(void)
{
	// set push button pin as input pin
	GPIO_setupPinDirection(BUTTON_PORT, BUTTON_PIN, PIN_INPUT);
	// set the interrupt with a raising edge triggering
	MCUCR |= (1<<ISC00) | (1<<ISC01);
	// Enable external interrupt pin INT0
	GICR  |= (1<<INT0);
	// Enable the Global Interrupt (I-bit)
	SREG |= (1<<7);
}


int main(void)
{
	/* UART Configuration */
	UART_ConfigType uart_type = {EIGHT_BIT, DISABLED, TWO_BIT, 9600};
	/* UART initialization */
	UART_init(&uart_type);

	/* ADC Configuration for temperature sensor*/
	ADC_ConfigType ADC_Config = {INTERNAL_VOLTAGE, F_CPU_8};
	/* ADC initialization*/
	ADC_init (&ADC_Config);


	/* Interrupt 0 Initialization */
	INT0_Init();
	/* DC motor - acting as a fan - initialization*/
	DCmotor_init();

	/* variable declaration */
	uint8 temp; //to store the reading of the temperature sensor
	uint8 speed; // to store the speed of the motor to turn the fan on

	while(1)
	{
		/* read the temperature from temperature sensor store it and
		 * send it to the second MCU */
		temp = get_Temp();
		UART_sendByte(temp);

		/* receive the speed from second MCU */
		speed = UART_recieveByte();

		/* check if the received speed is greater than 70 to turn on
		 * the fan */
		if (speed >= 70)
		{
			/* setting the fan to rotate with its maximum speed in ACW
			 * direction
			 */
			DCmotor_info(MAX,'F');
		}
		/* if the speed is less than 70 stop the fan */
		else
			DCmotor_info(STOP,'F');
	}
}
