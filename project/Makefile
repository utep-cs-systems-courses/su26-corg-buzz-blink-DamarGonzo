CPU             = msp430g2553
CFLAGS          = -mmcu=msp430g2553 -I../h -I/opt/ti/msp430-gcc/include -I../demos/timerLib
LDFLAGS		= -L/opt/ti/msp430-gcc/include

CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: toy.elf

toy.elf: main.o led.o switches.o buzzer.o stateMachines.o toy.o p2_handler.o wdt_handler.o ../demos/timerLib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: toy.elf
	mspdebug rf2500 "prog toy.elf"

clean:
	rm -f *.o *.elf
