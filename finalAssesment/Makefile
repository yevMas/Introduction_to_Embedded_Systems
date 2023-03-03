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
# Makefile for a multiplatform  build system
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE>.i - Generates the preprocessed output of all c-files (-E flag)
#      <FILE>.asm - Generates assembly output of c-files and the executable 
#      		   (-S flag and objdump utility)
#      <FILE>.o - Generates the object file for all c-files (but do not link)
#      	         by specifying the object file you want to compile
#      compile-all - Compile all objetc files, but DO NOT link
#      build - Compile all object files and link into a final executable
#      clean - Removes all compiled objects, preprocessed outputs, assembly 
#      	      outputs, executable files and build output files.
#
# Platform Overrides:
#	-HOST:
#       CC - C COMPILER 
#       TARGET - HOST MACHINE
#
#       -MSP432
#       CC - EMBEDDED C COMPILER
#       TARGET - EMBEDDED TARGET DEVICE 
#       CPU - ARM Cortex Architecture (cortex-m4, cortex-m0plus)
#       ARCH - ARM Architecture (thumb, arm)
#       SPECS - Specs dile to give the linker(nosys.specs, nano.specs)
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
OUTPF = course1

# More Variables Declared
OBJS = $(SOURCES:.c=.o)
OUTS = $(SOURCES:.c=.out)

# Architecture Specific Flags, Compiler Flags and Defines
ifeq ($(PLATFORM),HOST)	
	#Compile defines
	CC = gcc
	TARGET = HOST
	LDFLAGS = -Wl,-Map=$(OUTPF).map -lm
	CFLAGS = -Wall -g -std=c99 -O0
	CPPFLAGs = -D$(TARGET) -I$(INCLUDES)

else	
#Architecture specific flags
	CPU = cortex-m4
	ARCH = thumb
	SPECS = nos1 -cys.specs

#Platform specific flags
	LINKER_FILE = msp432p401r.lds

#Compile defines
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	TARGET = MSP432
	LDFLAGS = -Wl,-Map=$(OUTPF).map -T$(LINKER_FILE) -lm
	CFLAGS = -D$(TARGET) -I$(INCLUDES) -Wall -Werror -g -std=c99\
		 -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -O0\
		 -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 
	CPPFLAGs = -MD 

endif

ifeq ($(COURSE1), TRUE)
	CFLAGS += -DCOURSE1
endif

#Rules
#Generate the preprocessed output of a c-program
#make main.i
%.i : %.c
	$(CC) -E $< $(CFLAGS) $(CPPFLAGs) $(LDFLAGS) -o $@ 

#Generate assembly output of c-program impelementationfiles
#and the final output executable
#make main.s
%.asm : %.c
	$(CC) -S $< $(CFLAGS) $(CPPGLAGs) $(LDFLAGS) -o $@

#Generate the object file for all c-source files (but do not link) by 
#specifying the object file you want to compile 
#make main.o
%.o : %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGs) -o $@


#Rules
.PHONY: compile-all
compile-all:$(OBJS)

.PHONY: build
build: $(OUTPF).out

$(OUTPF).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPGLAGs) $(LDFLAGS) -o $@

.PHONY: clean
clean: 
	rm -f *.i *.d *.map *.s *.out *.o




