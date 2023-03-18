
#ifndef POT_H_
#define POT_H_


#include "std_types.h"
#include "adc.h"
#include <util/delay.h>

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define SENSOR_CHANNEL_ID         0
#define SENSOR_MAX_VOLT_VALUE     2

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for calculate the resistance from the ADC digital value.
 */
uint8 get_Res(void);

#endif /* POT_H_ */
