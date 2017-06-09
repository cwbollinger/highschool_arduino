################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/Users/chris/Documents/Arduino/libraries/NewPing/NewPing.cpp 

OBJS += \
./NewPing/NewPing.o 

CPP_DEPS += \
./NewPing/NewPing.d 


# Each subdirectory must supply rules for building sources it contributes
NewPing/NewPing.o: C:/Users/chris/Documents/Arduino/libraries/NewPing/NewPing.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"C:\arduino-1.0.4\hardware\arduino\cores\arduino" -I"C:\arduino-1.0.4\hardware\arduino\variants\standard" -I"C:\cygwin\home\chris\workspaces\arduino\ardu2013" -I"C:\Users\chris\Documents\Arduino\libraries\NewPing" -D__IN_ECLIPSE__=1 -DUSB_VID= -DUSB_PID= -DARDUINO=104 -Wall -Os -ffunction-sections -fdata-sections -fno-exceptions -g -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"  -c -o "$@" -x c++ "$<"
	@echo 'Finished building: $<'
	@echo ' '


