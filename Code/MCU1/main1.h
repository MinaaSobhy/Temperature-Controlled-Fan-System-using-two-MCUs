

#ifndef MAIN1_H_
#define MAIN1_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include "adc.h"
#include "common_macros.h"
#include "DCmotor.h"
#include "gpio.h"
#include "lm35.h"
#include "pwm_timer0.h"
#include "std_types.h"
#include "uart.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/* Define button port */
#define BUTTON_PORT PORTD_ID
/* Define button pin */
#define BUTTON_PIN PIN2_ID

/* Defining special code to be send when the button is pressed */
#define special_code 200

/* Defining DC motor speeds */
#define MAX 100
#define STOP 0

#endif /* MAIN1_H_ */
