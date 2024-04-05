#include<lpc214x.h>
#define CCLK 60000000   // Assuming CCLK is 60 MHz, adjust according to your system configuration

#define PCLK (CCLK / 4) // For UART0, the peripheral clock is one-fourth of the main clock

#define UART_BAUDRATE 9600

void UART0_Init() {
    // Enable UART0 power and set P0.0 (TXD0) and P0.1 (RXD0) as TXD and RXD pins
    PINSEL0 |= (1 << 0) | (1 << 2);

    // Enable FIFO, 8-bit data, 1 stop bit, no parity
    U0LCR = 0x83;

    // Set baud rate
    U0DLL = (unsigned char)(PCLK / (16 * UART_BAUDRATE)); // PCLK is the system clock
    U0DLM = 0;

    // Enable Receiver and Transmitter
    U0LCR = 0x03;
}

char UART0_Read() {
    while (!(U0LSR & 0x01)); // Wait until character received
    return U0RBR;
}

void UART0_Write(char data) {
    while (!(U0LSR & 0x20)); // Wait until Transmit Holding Register is empty
    U0THR = data;
}

int main() {
    char receivedData;

    UART0_Init();

    while (1) {
        // Read data from Bluetooth module
        receivedData = UART0_Read();

        // Process received data (you can perform any desired actions here)

        // Echo received data back to Bluetooth module
        UART0_Write(receivedData);
    }

    return 0;
}
