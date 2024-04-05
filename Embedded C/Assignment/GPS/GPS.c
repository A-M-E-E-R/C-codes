#include <lpc214x.h>
#include <stdio.h>
#include <string.h>

// Define UART baud rate and buffer size
#define UART_BAUDRATE 9600
#define BUFFER_SIZE 256

// Function to initialize UART
void UART_Init() {
    // Enable UART1 power and set P0.8 (TXD1) and P0.9 (RXD1) as TXD and RXD pins
    PINSEL0 |= (1 << 17) | (1 << 18);

    // Enable FIFO, 8-bit data, 1 stop bit, no parity
    U1LCR = 0x83;

    // Set baud rate
    U1DLL = (unsigned char)(15000000 / (16 * UART_BAUDRATE)); // Assuming PCLK is 15 MHz
    U1DLM = 0;

    // Enable Receiver and Transmitter
    U1LCR = 0x03;
}

// Function to send a character via UART
void UART_SendChar(char ch) {
    while (!(U1LSR & (1 << 5))); // Wait until Transmitter Holding Register (THRE) is empty
    U1THR = ch; // Send character
}

// Function to send a string via UART
void UART_SendString(const char* str) {
    while (*str != '\0') {
        UART_SendChar(*str++);
    }
}

// Function to receive a character via UART
char UART_ReceiveChar() {
    while (!(U1LSR & 0x01)); // Wait for character to be received
    return U1RBR; // Return received character
}

// Function to receive a string via UART
void UART_ReceiveString(char* buffer) {
    char ch;
    int i = 0;
    do {
        ch = UART_ReceiveChar();
        buffer[i++] = ch;
    } while (ch != '\n' && i < BUFFER_SIZE - 1);
    buffer[i] = '\0'; // Null-terminate the string
}

int main() {
    char buffer[BUFFER_SIZE];

    // Initialize UART
    UART_Init();

    // Send initialization commands to GPS module
    UART_SendString("AT+CGPSPWR=1\r\n"); // Power on the GPS module
    UART_SendString("AT+CGPSRST=0\r\n"); // Reset the GPS module
    UART_SendString("AT+CGPSINF=0\r\n"); // Request GPS information

    while (1) {
        // Receive GPS data
        UART_ReceiveString(buffer);

        // Process GPS data (e.g., extract latitude and longitude)
        // Example: Parse received GPS data and extract latitude and longitude
        // ...

        // Print GPS data to UART or do further processing
        UART_SendString(buffer);
    }

    return 0;
}
