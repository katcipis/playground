#include <ic.h>
#include <uart.h>
#include <machine.h>
#include <../app/tsg/include/errors.h>

#ifndef __tsg_serial_interface_h
#define __tsg_serial_interface_h

#define RX_BUFFER_SIZE 256  //!< _rx_buffer size
#define TX_BUFFER_SIZE 256  //!< _tx_buffer size

#define RX_BUFFER_MASK 255  //!< _rx_buffer size
#define TX_BUFFER_MASK 255  //!< _tx_buffer size

__USING_SYS

class TSG_serial_interface
{
private:
    static volatile int _rx_i,              //!< _rx_buffer read index
                        _rx_wr_i,           //!< _rx_buffer write index
                        _tx_i,
                        _tx_wr_i;

    static volatile bool _rx_overflow,      //!< flag indicates overflow
                         _tx_overflow;

    static unsigned char _rx_buffer[];      //!< receive buffer
    static unsigned char _tx_buffer[];      //!< receive buffer

    static UART _uart;                      //!< uart used in communication

public:
    TSG_serial_interface(int baud = 9600) {

        Machine::int_vector(Machine::irq2int(IC::IRQ_USART0_RXC), _uart_rx_handler);
        Machine::int_vector(Machine::irq2int(IC::IRQ_USART0_UDRE), _uart_tx_handler);

        _rx_on();
        _tx_on();
    }

    /*! \brief Reset the rx buffer
    *
    *  \param    void
    *
    *  \retval   void
    */
    void reset_rcv_buffer() {
        _rx_i = 0; _rx_wr_i = 0; _rx_overflow = false;
    }

    /*! \brief Returns the number of bytes in rx_buffer
    *
    *  \param    void
    *
    *  \retval   int
    */
    volatile int rcv_buffer_size() {

        if (_rx_wr_i == _rx_i)
            return 0;
        else
            return (_rx_wr_i > _rx_i) ? (_rx_wr_i - _rx_i) : RX_BUFFER_SIZE - (_rx_i - _rx_wr_i);
    }

    /*! \brief Returns true if the transmit buffer full
    *
    *   \param  void
    *
    *   \retval bool
    */
    volatile bool send_buffer_full() {
        int tmp = _tx_wr_i + 1;

        if ( tmp >= TX_BUFFER_SIZE )
            tmp = 0;

        if ( tmp == _tx_i )
            return true;
        else
            return false;
    }

    /*! \brief Reset communication buffers and flags
    *
    *  \param    void
    *
    *  \retval   void
    */
    void reset_serial();

    /*! \brief Moves the uart receive buffer to char* b and resets it.
    *
    *  \param    output char*   a pointer to the new buffer location
    *
    *  \retval   char       error code ou SUCCESS
    */
    char get_rcv_buffer(char * b);

    /*! \brief Sends a char to uart
    *
    *  \param    input     char
    *
    *  \retval   char      error code ou SUCCESS
    */
    char put_c(char c);

    /*! \brief Sends a null terminated string to uart
    *
    *  \param    input     char* string
    *
    *  \retval   char      error code ou SUCCESS
    */
    char put_s(const char * s);

    /*! \brief Sends a null terminated string located in program memory to uart
    *
    *  \param    input     char* string
    *
    *  \retval   char      error code ou SUCCESS
    */
    char put_s_P(const char * s);

    /*! \brief Returns the first char of rx buffer
    *
    *  \param    void
    *
    *  \retval   char      The rx_buffer character
    */
    char get_c() {

        while ( _rx_i == _rx_wr_i );

        char ret = _rx_buffer[_rx_i];

        _rx_i = (_rx_i + 1) & RX_BUFFER_MASK;

        return ret;
    }

private:
    static void _uart_tx_handler(unsigned int);
    static void _uart_rx_handler(unsigned int);

    static void _rx_off() { IC::disable(IC::IRQ_USART0_RXC); }
    static void _rx_on() { IC::enable(IC::IRQ_USART0_RXC); }
    static void _tx_off() { IC::disable(IC::IRQ_USART0_UDRE); }
    static void _tx_on() { IC::enable(IC::IRQ_USART0_UDRE); }
};

#endif
