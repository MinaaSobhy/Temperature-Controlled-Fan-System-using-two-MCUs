################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DCmotor.c \
../adc.c \
../gpio.c \
../lm35.c \
../main1.c \
../pwm_timer0.c \
../uart.c 

OBJS += \
./DCmotor.o \
./adc.o \
./gpio.o \
./lm35.o \
./main1.o \
./pwm_timer0.o \
./uart.o 

C_DEPS += \
./DCmotor.d \
./adc.d \
./gpio.d \
./lm35.d \
./main1.d \
./pwm_timer0.d \
./uart.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


