#include <../app/tsg/include/tsg_serial_interface.h>
#include <avr/pgmspace.h>

__USING_SYS

volatile int TSG_serial_interface::_rx_i = 0,
             TSG_serial_interface::_rx_wr_i = 0,
             TSG_serial_interface::_tx_i = 0,
             TSG_serial_interface::_tx_wr_i = 0;

volatile bool TSG_serial_interface::_rx_overflow = false,
              TSG_serial_interface::_tx_overflow = false;

unsigned char TSG_serial_interface::_rx_buffer[RX_BUFFER_SIZE];
unsigned char TSG_serial_interface::_tx_buffer[TX_BUFFER_SIZE];

UART TSG_serial_interface::_uart = UART(0);

void TSG_serial_interface::reset_serial() {

    _rx_off();
    _rx_i = _rx_wr_i = 0;
    _tx_i = _tx_wr_i = 0;
    _rx_overflow = false;
    _tx_overflow = false;
    _rx_on();
}

char TSG_serial_interface::get_rcv_buffer(char * b) {
    char * tmp_p = b;
    // test if buffer has data
    if (_rx_i == _rx_wr_i)
        return NO_DATA_AT_BUFFER;

    while (_rx_i != _rx_wr_i) {

        *tmp_p = _rx_buffer[_rx_i];

        _rx_i = (_rx_i + 1) & RX_BUFFER_MASK;

        tmp_p++;
    }
    *tmp_p = '\0';
    reset_rcv_buffer();

    return SUCCESS;
}

char TSG_serial_interface::put_c(char c) {

    if ( _tx_i == ( (_tx_wr_i + 1) & TX_BUFFER_MASK ) ) {

        return FAILED;
    } else {

        _tx_buffer[_tx_wr_i] = c;

        _tx_wr_i = (_tx_wr_i + 1) & TX_BUFFER_MASK;

        _tx_on();

        return SUCCESS;
    }
}

char TSG_serial_interface::put_s(const char * s) {
    const char * _s = s;

    while ( *_s ) {

        if ( put_c(*_s) != SUCCESS )
            return FAILED;

        _s++;
    }
    return SUCCESS;
}

char TSG_serial_interface::put_s_P(const char * s) {
    char c;
    const char * s_tmp = s;

    for ( c = pgm_read_byte(s_tmp); c; ++s_tmp, c = pgm_read_byte(s_tmp) ) {

        if ( put_c(c) != SUCCESS )
            return FAILED;
    }
}

void TSG_serial_interface::_uart_rx_handler(unsigned int) {

    _rx_buffer[_rx_wr_i] = _uart.rxd();

    _rx_wr_i = (_rx_wr_i + 1) & RX_BUFFER_MASK;

//     if ( _rx_wr_i == _rx_i )
//         IC::disable(IC::IRQ_USART0_RXC);
}

void TSG_serial_interface::_uart_tx_handler(unsigned int) {

    if (_tx_i == _tx_wr_i) {

//         IC::disable(IC::IRQ_USART0_UDRE);
        _tx_off();
    } else {

        _uart.txd(_tx_buffer[_tx_i]); // EPOS prevents nested interrupts

        _tx_i = (_tx_i + 1) & TX_BUFFER_MASK;
    }
}
