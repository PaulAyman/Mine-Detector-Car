################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LIB/HAL/LCD_DRIVER/LCD.c 

OBJS += \
./LIB/HAL/LCD_DRIVER/LCD.o 

C_DEPS += \
./LIB/HAL/LCD_DRIVER/LCD.d 


# Each subdirectory must supply rules for building sources it contributes
LIB/HAL/LCD_DRIVER/%.o: ../LIB/HAL/LCD_DRIVER/%.c LIB/HAL/LCD_DRIVER/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


