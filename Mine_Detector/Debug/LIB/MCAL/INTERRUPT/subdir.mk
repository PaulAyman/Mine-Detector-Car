################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LIB/MCAL/INTERRUPT/INTERRUPT.c 

OBJS += \
./LIB/MCAL/INTERRUPT/INTERRUPT.o 

C_DEPS += \
./LIB/MCAL/INTERRUPT/INTERRUPT.d 


# Each subdirectory must supply rules for building sources it contributes
LIB/MCAL/INTERRUPT/%.o: ../LIB/MCAL/INTERRUPT/%.c LIB/MCAL/INTERRUPT/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


