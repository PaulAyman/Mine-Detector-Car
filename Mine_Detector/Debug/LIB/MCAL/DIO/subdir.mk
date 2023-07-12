################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LIB/MCAL/DIO/DIO.c 

OBJS += \
./LIB/MCAL/DIO/DIO.o 

C_DEPS += \
./LIB/MCAL/DIO/DIO.d 


# Each subdirectory must supply rules for building sources it contributes
LIB/MCAL/DIO/%.o: ../LIB/MCAL/DIO/%.c LIB/MCAL/DIO/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


