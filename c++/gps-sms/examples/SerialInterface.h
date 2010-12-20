/*
 * SerialInterface.h
 *
 *  Created on: 15/10/2008
 *      Author: tiago
 */

#include <uart.h>
#include <cpu.h>
#include <machine.h>
#include <alarm.h>
#include <../app/tsg/include/gsm_modem.h>
#include <../app/tsg/include/tsg_serial_interface.h>

#ifndef SERIALINTERFACE_H_
#define SERIALINTERFACE_H_

__USING_SYS

class SerialInterface{
	
private:
	GSM_modem *modem_uart; 
	TSG_serial_interface *debug_uart; 
	static const bool debug_mode = true;

public:
	SerialInterface(GSM_modem *p_modem_uart, TSG_serial_interface *p_debug_uart){
		modem_uart = p_modem_uart;
		debug_uart = p_debug_uart;
	}

	int getLine(char* buffer, int bufferSize){
			
		char lastChar = 0;
		int count = 0;
	
		for(; count < bufferSize; ++count) buffer[count] = 0;
		count = 0;
	
		while((lastChar != '\n') && (count < bufferSize)){
			while(!modem_uart->get_rx_buffer_size());		
			lastChar = modem_uart->get_rx_buffer_c();
			buffer[count++] = lastChar;
		}
		buffer[count++] = 0;
	
		if(debug_mode){
			debug_uart->put_c('$');
			debug_uart->put_c('R');
			debug_uart->put_c('X');
			debug_uart->put_c('=');
			for(int i = 0; buffer[i] != 0;++i) debug_uart->put_c(buffer[i]);
			debug_uart->put_c('\n');  
		}
		return count;
	}


	int putLine(char* buffer){

		int i = 0;
		while(buffer[i] != 0) modem_uart->put_c_send_buffer(buffer[i++]);
		modem_uart->put_c_send_buffer('\r');
		modem_uart->put_c_send_buffer('\n');
	
		if(debug_mode){
			debug_uart->put_c('$');
			debug_uart->put_c('T');
			debug_uart->put_c('X');
			debug_uart->put_c('=');
			for(int i = 0; buffer[i] != 0;++i) debug_uart->put_c(buffer[i]);
			debug_uart->put_c('\n');  
		}	
	
		return i+2;
	}

	int put(char* buffer){
	
		int i = 0;
		while(buffer[i] != 0) modem_uart->put_c_send_buffer(buffer[i++]);
	
		if(debug_mode){
			debug_uart->put_c('$');
			debug_uart->put_c('T');
			debug_uart->put_c('X');
			debug_uart->put_c('=');
			for(int i = 0; buffer[i] != 0;++i) debug_uart->put_c(buffer[i]);
			debug_uart->put_c('\n');
		}

		return i;
	}

	


};

#endif /* SERIALINTERFACE_H_ */



