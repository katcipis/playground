LD=avr-ld
CXX=avr-g++
OBJCP=avr-objcopy
#LIBS=-lgcc -lm -lgcc -lc -lgcc
MCU=atmega128
SRCS=./src/main.cc ./src/GPS.cc ./src/GSM.cc ./src/ATMega128UART.cc ./src/System.cc

all: main

main: main
	$(CXX) -g -O0 -mmcu=$(MCU) -o main $(SRCS) -I./include

prog:	main
	$(OBJCP) -O ihex main main.hex
	avrdude -V -P /dev/ttyUSB0 -c avrispv2 -p m128 -U flash:w:main.hex
	#avrdude -P /dev/ttyUSB0 -c stk500v2 -p m128 -U flash:w:main.hex
	
clean:
	rm -rf *.o *.s *.hex main
