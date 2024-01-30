################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_Program.c \
../DIO_Program.c \
../EEPROM_Program.c \
../EXTINT_Program.c \
../GIE_Program.c \
../Seven_Seg_Program.c \
../TIMER0_Program.c \
../TWI_Program.c \
../Water_Heater_Program.c \
../main.c 

OBJS += \
./ADC_Program.o \
./DIO_Program.o \
./EEPROM_Program.o \
./EXTINT_Program.o \
./GIE_Program.o \
./Seven_Seg_Program.o \
./TIMER0_Program.o \
./TWI_Program.o \
./Water_Heater_Program.o \
./main.o 

C_DEPS += \
./ADC_Program.d \
./DIO_Program.d \
./EEPROM_Program.d \
./EXTINT_Program.d \
./GIE_Program.d \
./Seven_Seg_Program.d \
./TIMER0_Program.d \
./TWI_Program.d \
./Water_Heater_Program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


