host_srcs = src/main.c \
	    src/memory.c \
	    src/data.c \
	    src/stats.c \
	    src/course1.c

msp_srcs = src/*.c


host_lib = common/

msp_lib = /include/CMSIS \
	  /include/common \
	  /include/msp432



#Conditional platform specific statement
ifeq ($(PLATFORM),HOST)

# Add your Source files to this variable
 SOURCES = $(host_srcs)
 INCLUDES = $(host_lib)

else ifeq ($(PLATFORM), MSP432)
 
 SOURCES =  $(msp_srcs)
 INCLUDES = $(msp_lib)

endif

