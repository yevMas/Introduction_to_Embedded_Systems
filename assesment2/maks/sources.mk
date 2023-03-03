#Variables for platform specific sources
host_srcs = main.c\
memory.c

msp_srcs = interrupts_msp432p401r_gcc.c\
startup_msp432p401r_gcc.c\
system_msp432p401rr.c

#Libs platform specific
host_lib = /home/yev/Documents/Mascarenas_Coursera/assesment2/m2/include/common

msp_lib = /home/yev/Documents/Mascarenas_Coursera/assesment2/m2/include/pHeaders

#Conditional platform specific statement
ifeq ($(PLATFORM),HOST)
# Add your Source files to this variable
 SOURCES = $(host_srcs)
 INCLUDES = $(host_lib)
else ifeq ($(PLATFORM), MSP432)
 SOURCES = $(host_srcs) $(msp_srcs)
 INCLUDES = $(host_lib)\
 $(msp_lib)
endif

