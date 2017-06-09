################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
ardu2013_robo.lss \

FLASH_IMAGE += \
ardu2013_robo.hex \

EEPROM_IMAGE += \
ardu2013_robo.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: ardu2013_robo.elf secondary-outputs

# Tool invocations
ardu2013_robo.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C++ Linker'
	avr-gcc -Os -Wl,--gc-sections  -L"C:\cygwin\home\chris\workspaces\arduino\Arduino_Duemilanove_w__ATmega328/Release" -mmcu=atmega328p  -o"ardu2013_robo.elf" $(OBJS) $(USER_OBJS) $(LIBS) -lm
	@echo 'Finished building target: $@'
	@echo ' '

ardu2013_robo.lss: ardu2013_robo.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ardu2013_robo.elf  >"ardu2013_robo.lss"
	@echo 'Finished building: $@'
	@echo ' '

ardu2013_robo.hex: ardu2013_robo.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex ardu2013_robo.elf  "ardu2013_robo.hex"
	@echo 'Finished building: $@'
	@echo ' '

ardu2013_robo.eep: ardu2013_robo.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex ardu2013_robo.elf  "ardu2013_robo.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ardu2013_robo.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p ardu2013_robo.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(CXX_DEPS)$(S_UPPER_DEPS)$(C++_DEPS)$(ASM_DEPS)$(CC_DEPS)$(CPP_DEPS)$(C_UPPER_DEPS)$(SIZEDUMMY) ardu2013_robo.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
