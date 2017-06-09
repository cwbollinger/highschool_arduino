################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Diagnostics.cpp \
../NXTAnalog.cpp \
../NXTDigital.cpp \
../NXTI2C.cpp \
../NXTPing.cpp \
../ardu2013.cpp \
../twi4nxt.cpp 

OBJS += \
./Diagnostics.o \
./NXTAnalog.o \
./NXTDigital.o \
./NXTI2C.o \
./NXTPing.o \
./ardu2013.o \
./twi4nxt.o 

CPP_DEPS += \
./Diagnostics.d \
./NXTAnalog.d \
./NXTDigital.d \
./NXTI2C.d \
./NXTPing.d \
./ardu2013.d \
./twi4nxt.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"C:\arduino-1.0.4\hardware\arduino\cores\arduino" -I"C:\arduino-1.0.4\hardware\arduino\variants\standard" -I"C:\cygwin\home\chris\workspaces\arduino\ardu2013" -I"C:\Users\chris\Documents\Arduino\libraries\NewPing" -D__IN_ECLIPSE__=1 -DUSB_VID= -DUSB_PID= -DARDUINO=104 -Wall -Os -ffunction-sections -fdata-sections -fno-exceptions -g -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"  -c -o "$@" -x c++ "$<"
	@echo 'Finished building: $<'
	@echo ' '


