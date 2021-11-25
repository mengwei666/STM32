TARGET=test
CC=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy
RM=rm -f
CORE=3
CPUFLAGS=-mthumb -mcpu=cortex-m$(CORE) --specs=nano.specs --specs=nosys.specs
LDFLAGS = -T stm32_flash.ld -Wl,-cref,-u,Reset_Handler -Wl,-Map=$(TARGET).map -Wl,--gc-sections -Wl,--defsym=malloc_getpagesize_P=0x80 -Wl,--start-group -lc -lm -Wl,--end-group
CFLAGS=$(INCFLAGS) -D STM32F10X_HD -D USE_STDPERIPH_DRIVER -Wall -g 

PWD=$(shell pwd)
INCFLAGS=-I $(PWD)/cmsis -I $(PWD)/libraries/inc -I $(PWD)/user
C_SRC=$(shell find ./ -name '*.c')
C_OBJ=$(C_SRC:%.c=%.o)

START_SRC=$(shell find ./ -name 'startup_stm32f10x_hd.s')
START_OBJ=$(START_SRC:%.s=%.o)


$(TARGET):$(START_OBJ) $(C_OBJ)
	$(CC) $^ $(CPUFLAGS) $(LDFLAGS) $(CFLAGS) -o $(TARGET).elf

$(START_OBJ):$(START_SRC)
	$(CC) -c $^ $(CPUFLAGS) $(CFLAGS) -o $@

$(C_OBJ):%.o:%.c
	$(CC) -c $^ $(CPUFLAGS) $(CFLAGS) -o $@

bin:
	$(OBJCOPY) $(TARGET).elf $(TARGET).bin -Obinary
hex:
	$(OBJCOPY) $(TARGET).elf $(TARGET).hex -Oihex
clean:
	$(RM) $(shell find ./ -name '*.o') $(TARGET).*

download:
	$(OBJCOPY) $(TARGET).elf $(TARGET).bin -Obinary
	st-flash write $(TARGET).bin 0x8000000
	$(RM) $(shell find ./ -name '*.o') $(TARGET).*
