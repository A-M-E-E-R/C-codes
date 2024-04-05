#include<lpc214x.h>
#include<stdint.h>
#include<string.h>
#include"lcd.h"
#include<stdio.h>

//#define MY_SLAVE_ID 7// Slave ID (you can assign a unique ID for each slave if needed)

void SPI_Init_Slave(void) {
    PINSEL0 = PINSEL0 | 0x00001500; // Select P0.4, P0.5, P0.6, P0.7 as SCK0, MISO0, MOSI0 and GPIO 
	S0SPCR = 0x0000; // SPI slave mode, 8-bit data, SPI0 mode 
	S0SPCCR = 0x10; // Even number, minimum value 8, pre scalar for SPI Clock 
}

unsigned char SPI_Slave_Receive(void) {
    while ( (S0SPSR & 0x80) == 0 ); // Wait until data received
    return S0SPDR; // Read received data from SPI data register
}

void SPI_Slave_Transmit(uint8_t data) {
    while ( (S0SPSR & 0x80) == 0 ); // Wait until previous transfer is complete
    S0SPDR = data; // Load data into SPI data register
}

int main(void) {
    SPI_Init_Slave();
    initLCD();
    while (1) {
        // Example: Receive data from master
        unsigned char received_data = SPI_Slave_Receive();
        
        // Example: Process received data
        if ((IOPIN0&(1<<7))==0) {
            LCDdata(received_data);// Do something when slave ID matches
        } else {
						LCDcommand(0x01);//clear display
            LCDstring("IDLE MODE");
        }
        
        // Example: Transmit data to master
        //SPI_Slave_Transmit(0xAA); // Example: Transmit data to master
    }

}
