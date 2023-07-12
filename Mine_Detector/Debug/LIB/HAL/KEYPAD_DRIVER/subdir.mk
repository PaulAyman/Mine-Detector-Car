################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LIB/HAL/KEYPAD_DRIVER/KEYPAD.c 

OBJS += \
./LIB/HAL/KEYPAD_DRIVER/KEYPAD.o 

C_DEPS += \
./LIB/HAL/KEYPAD_DRIVER/KEYPAD.d 


# Each subdirectory must supply rules for building sources it contributes
LIB/HAL/KEYPAD_DRIVER/%.o: ../LIB/HAL/KEYPAD_DRIVER/%.c LIB/HAL/KEYPAD_DRIVER/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


