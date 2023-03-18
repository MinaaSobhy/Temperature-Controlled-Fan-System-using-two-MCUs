
#ifndef MAIN2_H_
#define MAIN2_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "adc.h"
#include "common_macros.h"
#include "DCmotor.h"
#include "gpio.h"
#include "pot.h"
#include "pwm_timer0.h"
#include "std_types.h"
#include "uart.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

//Define LED ports
#define LEDR_PORT PORTC_ID
#define LEDY_PORT PORTC_ID
#define LEDG_PORT PORTC_ID
//Define LED pins
#define LEDR_PIN PIN0_ID
#define LEDY_PIN PIN1_ID
#define LEDG_PIN PIN2_ID


#endif /* MAIN2_H_ */
