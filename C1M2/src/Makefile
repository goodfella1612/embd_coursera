#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------


ifeq ($(strip $(PLATFORM)),)
PLATFORM := HOST
endif

include sources.mk

# print-platform:
# 	@echo PLATFORM is $(PLATFORM)

LINKER_FILE = -T ../msp432p401r.lds
CPU = -mcpu=cortex-m4 -mfpu=fpv4-sp-d16
ARCH = -march=armv7e-m
SPECS = --specs=nosys.specs
ARCH_FLAG = $(CPU) $(ARCH) $(SPECS) -mthumb -mfloat-abi=hard
GEN_FLAG = -Wall -Werror -g -O0 -std=c99
ifeq ($(PLATFORM),HOST)
	CC = gcc
	LDFLAGS = -Wl,-Map=c1m2.map
	CFLAGS = $(GEN_FLAG)
	CPPFLAGs = -DHOST
	SIZE = size
else ifeq ($(PLATFORM),MSP432)
	CC = arm-none-eabi-gcc
	LDFLAGS = $(LINKER_FILE) -Wl,-Map=c1m2.map $(ARCH_FLAG)
	CFLAGS = $(GEN_FLAG) $(ARCH_FLAG)
	CPPFLAGs = -DMSP432
	SIZE = arm-none-eabi-size
else

endif
# Compiler Flags and Defines
OBJECTS = $(SOURCES:.c=.o)

.PHONY : all
all : build

.PHONY : build

build : c1m2.out
	@echo "\n Code Size report"
	@$(SIZE) $<

.PHONY : compile-all
compile-all : $(OBJECTS)

.PHONY : clean
clean : 
	rm -rf c1m2.out *.o *.i *.d *.map *.asm 

c1m2.out : $(OBJECTS)
	$(CC) $(LDFLAGS) $(INCLUDES) $^ -o $@

%.o : %.c 
	$(CC) $(CPPFLAGs) $(CFLAGS) $(INCLUDES) -MD -c $< -o $@

%.i : %.C
	$(CC) $(CPPFLAGs) $(CFLAGS) $(INCLUDES) -E -c $< -o $@	

%.asm: %.c
	$(CC) $(CPPFLAGs) $(CFLAGS) $(INCLUDES) -S $< -o $@
	objdump -d c1m2.out > c1m2.asm
.PHONY : print-objects
# print-objects:
# 	@echo OBJECTS = $(OBJECTS)
