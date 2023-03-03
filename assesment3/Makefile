#Makefile assesment number 3
#in this file we will generate the commands por especific file types
#and gcc bin utilities like: 
# objdump, nm, .map files and asm files

SRCS = main.c misc.c

# Architechture Specific Flags
 CPU = cortex-m0plus
 ARCH = thumb
 SPECS = nosys.specs

# Platform Specific Flags
 LINKER_FILE = msp432p401r.lds

# Compile Defines 
 CC = arm-none-eabi-gcc
 LD = arm-none-eabi-ld
 TARGET = main
 LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
 CFLAGS = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -Wall

 OBJS = $(SRCS:.c=.o)


%.o : %.c
	$(CC) -c $<

%.asm : %.c
	$(CC) $< $(CFLAGS) -S $@

.PHONY: map 
map: $(TARGET).out

$(TARGET): $(OBJS) 
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@

.PHONY: dump 
dump: $(OBJS)
	objdump -m msp432 -S -d $(OBJS)

.PHONY: clean 
clean:
	-rm -f $(OBJS) *.asm $(TARGET).map $(TARGET).out
