void initUART(int baud);

void transmitByte(uint8_t ch);

uint8_t receiveByte(void);

void printString(const char myString[]);

// Prints a byte as a 3-digit number over Serial
void printByte(uint8_t ch);

