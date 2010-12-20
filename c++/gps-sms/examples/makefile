LD=avr-elf-ld
CXX=avr-elf-g++
OBJCP=avr-elf-objcopy
LIBS=-lgcc -lm -lgcc -lc -lgcc
MCU=at90s8515
OBJS=main.o handler.o vector.o my_handler.o system.o keyboard.o timer.o

all: main

main: $(OBJS)
	$(LD) -m avr2 -L`avr-elf-gcc --print-file-name=` -o main $(OBJS) $(LIBS)

main.o: main.cc
	$(CXX) -O0 -mmcu=$(MCU) -c $<

handler.o: handler.cc
	$(CXX) -O0 -mmcu=$(MCU) -fomit-frame-pointer -c $<

vector.o: vector.cc
	$(CXX) -O0 -mmcu=$(MCU) -fomit-frame-pointer -c $<		

my_handler.o: my_handler.cc
	$(CXX) -O0 -mmcu=$(MCU) -fomit-frame-pointer -c $<

system.o: system.cc
	$(CXX) -O0 -mmcu=$(MCU) -c $<

keyboard.o: keyboard.cc
	$(CXX) -O0 -mmcu=$(MCU) -c $<

timer.o: timer.cc
	$(CXX) -O0 -mmcu=$(MCU) -c $<

prog:	main
	$(OBJCP) -O ihex main main.hex		
	uisp -dprog=stk500 -dpart=at90s8515 -dserial=/dev/ttyS0 \
	--erase --upload --verify if=main.hex
	
clean:
	rm -rf *.o *.s *.hex main
