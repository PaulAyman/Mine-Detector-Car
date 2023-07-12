################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LIB/HAL/DCMOTOR/DCMOTOR.c 

OBJS += \
./LIB/HAL/DCMOTOR/DCMOTOR.o 

C_DEPS += \
./LIB/HAL/DCMOTOR/DCMOTOR.d 


# Each subdirectory must supply rules for building sources it contributes
LIB/HAL/DCMOTOR/%.o: ../LIB/HAL/DCMOTOR/%.c LIB/HAL/DCMOTOR/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


