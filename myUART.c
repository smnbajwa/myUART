#include <avr/io.h>
#include "myUART.h"


// Initialization
void initUART(int baud) {
	// Calculate UBBR
	uint16_t baud_setting = (F_CPU / 16 / baud) - 1;

	// Set BAUD
	UBRR0H = baud_setting >> 8;
	UBRR0L = baud_setting;

	// Set Transmitter/Receiver enable
	UCSR0B |= (1 << TXEN0) | (1 << RXEN0);
	
	// Set 8 data bits and 1 stop bit
	UCSR0C |= (1 << UCSZ00) | (1 << UCSZ01);
}


// Transmitting functions
void transmitByte(uint8_t ch) {
    while (!(UCSR0A & (1 << UDRE0)));

    UDR0 = ch;
}


// Receiving functions
uint8_t receiveByte(void) {
	while (!(UCSR0A & (1 << RXC0)));

	return UDR0;
}


// Printing functions
void printString(const char myString[]) {
    for (int i = 0; myString[i]; i++)
    {
        transmitByte(myString[i]);
    }
}


void printByte(uint8_t ch) {
	transmitByte('0' + (ch / 100));
	transmitByte('0' + ((ch / 10) % 10));
	transmitByte('0' + (ch % 10));
}
