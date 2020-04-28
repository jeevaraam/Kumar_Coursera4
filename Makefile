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
#  @Author Jeevaraam Kumar
#  @Date April 16 2020
#------------------------------------------------------------------------------
# Makefile to Compile executable for Two different platforms using Command Line Argument Input
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      %.i - Produce C Preprocessor Expanded File 
#	   %.d - Produce Dependency File for given input file
#	   %.asm - Produce Assembly code for the given input file
#	   %.o - Produce Compiled object file but not linked for given input file
#	   compile-all - Compiles all the Source files given in Sources input variable
#	   build - Compiles and links all files and produce a single output file (Dependency files, object files and Memory map files are generated)
#      clean - Deletes all the files that are produced as a result of one or more above operations
#
# Platform Overrides:
#      HOST - The operations are automatically selected for producing host specific outputs
#	   MSP432  - The operations are automatically selected for producing ARM CORTEX-M4 specific outputs
#    
#      Note - If no platform override is mentioned HOST is taken as default
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM ?= HOST

# Architectures Specific Flags

LINKER_FILE = msp432p401r.lds
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs

#Common Flags
TARGET = c1m2
CPPFLAGS = -D$(PLATFORM)
FLAGS = -Wall -Werror -g -O0 -std=c99

# Compiler Flags and Defines
ifeq ($(PLATFORM),MSP432)
    # FLAGS for MSP432 
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	CFLAGS = $(CPPFLAGS) -mcpu=$(CPU) -m$(ARCH) -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=$(SPECS) $(FLAGS)
	DMP = arm-none-eabi-objdump -d
else
	#FLAGS for HOST
	CC = gcc
	LD = ld
	LDFLAGS = -Wl,-Map=$(TARGET).map
	CFLAGS = $(CPPFLAGS) $(FLAGS)
	DMP = objdump -d
endif

#Flies collection for .o Files
OBJS = $(SOURCES:.c=.o)

#Files collection for Dependency Files
DEBS = $(SOURCES:.c=.d)

#Compiles all files but not linked
.PHONY: compile-all
compile-all:$(OBJS)

#Produces object file for given input file
%.o : %.c
	$(CC) $(INCLUDES) -c $< $(CFLAGS) -o $@

#Produces Assembly file for given input file
%.asm : %.c
	$(CC) $(INCLUDES) -S $< $(CFLAGS) -o $@

#Produces Preprocessor expanded file for given input file
%.i : %.c
	$(CC) $(INCLUDES) -E $< $(CFLAGS) -o $@

#Generates Dependency File for given input file
%.d : %.c
	$(CC) $(INCLUDES) -M $< $(CFLAGS) -o $@

#Compiles and links all the files to single executable file
.PHONY: build
build: $(DEBS) $(TARGET).out

$(TARGET).out:$(OBJS) 
	$(CC) $(INCLUDES) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@
	$(DMP) $(TARGET).out
	size $(TARGET).out 
	
#Cleans the compiler generated files in the folder
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET).out $(TARGET).map $(SOURCES:.c=.i) $(SOURCES:.c=.asm) $(SOURCES:.c=.d)
