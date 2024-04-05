#include"Timer.h"
#include<lpc214x.h>
void initUART(void);
void sendUART(unsigned char mydata);
void printUART(unsigned char mydata[]);
void initUART(void) {
    // Initialize PLL and pin select
    initPLL();
    PINSEL0 = 0x05; // Configure UART0 TXD0 pin (P0.0) as TXD0

    // Configure UART0
    U0LCR = 0x83; // DLAB=1, 8-bit UART
    U0DLL = 0x87; // 0x0187 for 9600 baud rate
    U0DLM = 0x01;
    U0LCR = 0x03; // DLAB=0, 8-bit UART
}

void sendUART(unsigned char mydata) {
    U0THR = mydata; // Load data into UART transmit holding register

    // Wait until THR is empty
    while (!(U0LSR & (0x01 << 5))); // THREmpty
}

void printUART(unsigned char mydata[])
{
int i=0;
while(mydata[i]!='\0')
{
sendUART(mydata[i]);
i++;
}
}