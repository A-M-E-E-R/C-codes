#include<lpc214x.h>
#include<stdint.h>
#include<string.h>
#include"lcd.h"
#include<stdio.h>

#define SLAVE1_SS_PIN  (1 << 7) // Example SS pin for slave 1
#define SLAVE2_SS_PIN  (1 << 3) // Example SS pin for slave 2

void SPI_Init() {
    PINSEL0 = PINSEL0 | 0x00001500; // Select P0.4, P0.5, P0.6, P0.7 as SCK0, MISO0, MOSI0 and GPIO 
	S0SPCR = 0x0020; // SPI Master mode, 8-bit data, SPI0 mode 
	S0SPCCR = 0x10; // Even number, minimum value 8, pre scalar for SPI Clock 
}

void SPI_Write(char data)
{
	char flush;
	IO0CLR = (1<<7);  // SSEL = 0, enable SPI communication with slave 
	S0SPDR = data;  // Load data to be written into the data register 
	while ( (S0SPSR & 0x80) == 0 );  // Wait till data transmission is completed 
	flush = S0SPDR;
	IO0SET = (1<<7);  // SSEL = 1, disable SPI communication with slave 
}

char SPI_Read()
{
	IO0CLR = (1<<7);  // SSEL = 0, enable SPI communication with slave 
	S0SPDR = 0xFF;  // Transmit Flush byte 
	while ( (S0SPSR & 0x80) == 0 );  // Wait till data transmission is completed 
	IO0SET = (1<<7);  // SSEL = 1, disable SPI communication with slave 
	return S0SPDR;  // Return the data received 
}
void select_slave(short int slave) {
    switch (slave) {
        case 1:
            IO0CLR = SLAVE1_SS_PIN; // Select slave 1
            break;
        case 2:
            IO0CLR = SLAVE2_SS_PIN; // Select slave 2
            break;
        // Add cases for additional slaves as needed
    }
}
void deselect_all_slaves(void) {
    IO0SET = SLAVE1_SS_PIN | SLAVE2_SS_PIN; // Deselect all slaves
    // Add code to deselect additional slaves as needed
}

int main(void)
{
	short int i,j;
	unsigned char rx1;
	char receive, transmit[7];
	i = 0;
	j = 0;
	
	memset(transmit,0,7);
	initLCD();
	SPI_Init();
	LCDstring("Master send");
	SPI_Write(0x01);
	for(i=0;i<16;i++)
	{
		select_slave((i%2)+1);
		sprintf(transmit,"i = %d",i);		
		while(transmit[j] != 0)
		{			
			SPI_Write(transmit[j]);
			delayms(100);
			j++;
		}
		SPI_Write('\0');
		LCDcommand(0xC0);
		LCDstring((unsigned char *)transmit);	
		memset(transmit,0,7);
		j = 0;
	}
	return 0;
}

