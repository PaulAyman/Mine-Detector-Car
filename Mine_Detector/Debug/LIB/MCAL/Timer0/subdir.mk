################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LIB/MCAL/Timer0/Timer0.c 

OBJS += \
./LIB/MCAL/Timer0/Timer0.o 

C_DEPS += \
./LIB/MCAL/Timer0/Timer0.d 


# Each subdirectory must supply rules for building sources it contributes
LIB/MCAL/Timer0/%.o: ../LIB/MCAL/Timer0/%.c LIB/MCAL/Timer0/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


