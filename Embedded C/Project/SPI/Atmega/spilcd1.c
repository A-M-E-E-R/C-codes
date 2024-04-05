/*
  ATmega16 as slave for SPI communication
  http://www.electronicwings.com/arm7/lpc2148-spi-serial-peripheral-interface
*/ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#define MOSI PB5
#define MISO PB6
#define SCK PB7
#define SS PB4
#define LCD_PORT PORTD
#define LCD_DATA_PORT_DIRECTION DDRD
#define LCD_COMMAND_PORT PORTC
#define LCD_COMMAND_PORT_DIRECTION DDRC
#define RS PC0
#define RW PC1
#define EN PC2

void LCD_CMD(char command)
{
	LCD_PORT = command;
	LCD_COMMAND_PORT = (0<<RS)|(0<<RW)|(1<<EN);	/* EN = 1, RS = 0, RW = 0 */
	_delay_ms(2);
	LCD_COMMAND_PORT = (0<<RS)|(0<<RW)|(0<<EN);	/* EN = 0, RS = 0, RW = 0 */
	_delay_ms(5);
}

void LCD_INIT(void)
{
	LCD_DATA_PORT_DIRECTION = 0xFF;
	LCD_COMMAND_PORT_DIRECTION = 0xFF;
	_delay_ms(20);
	LCD_CMD(0x38);  /* Initialize lcd */
	LCD_CMD(0x0C);   /* Display on cursor off */
	LCD_CMD(0x06);  /* Auto increment cursor */
	LCD_CMD(0x01);   /* Display clear */
	LCD_CMD(0x80);  /* First line first position */
}

void LCD_STRING (char* msg)
{
	int i=0;
	while(msg[i]!=0)
	{
		LCD_PORT = msg[i];
		LCD_COMMAND_PORT = (1<<RS)|(0<<RW)|(1<<EN);	/* EN = 1, RS = 1, RW = 0 */
		_delay_ms(2);
		LCD_COMMAND_PORT = (1<<RS)|(0<<RW)|(0<<EN);	/* EN = 0, RS = 1, RW = 0 */
		_delay_ms(5);
		i++;
	}
}

void LCD_CHAR (char msg)
{
	LCD_PORT = msg;
	LCD_COMMAND_PORT = (1<<RS)|(0<<RW)|(1<<EN);	/* EN = 1, RS = 1, RW = 0 */
	_delay_ms(2);
	LCD_COMMAND_PORT = (1<<RS)|(0<<RW)|(0<<EN);	/* EN = 0, RS = 1, RW = 0 */
	_delay_ms(5);
}


void SPI0_INIT( void )
{ 
		DDRB = DDRB | (1<<MISO); /* Make MISO output */													 
		DDRB &= ~( (1<<MOSI) | (1<<SCK) | (1<<SS) ); /* Make MOSI, SCK and SS pins as inputs. */	 																						
		SPCR = (1<<SPE); /* Enable SPI */
}

unsigned char SPI_SLAVE_READ_CHAR()
{
	while(!(SPSR & (1<<SPIF))); /* Wait till data reception is completed */
	return SPDR; /* Return the data received */
}

void SPI_SLAVE_WRITE_CHAR(char ch)
{
	char flush;
	SPDR = ch; /* Load data to be written into the data register */
	while(!(SPSR & (1<<SPIF))); /* Wait till data transmission is completed */
	flush = SPDR;
}


int main(void)
{
	int i = 0;
	int j = 0;
	int k = 0;
	unsigned char receive[7], rx;
	SPI0_INIT();
	LCD_INIT();
	LCD_STRING("Slave receive");
	memset(receive,0,7);	
	while(SPI_SLAVE_READ_CHAR() != 0x01);
	do 
	{
		do
		{
			receive[j] = SPI_SLAVE_READ_CHAR();
			rx = receive[j];
			j++;
		} while (rx != 0);
		LCD_CMD(0xC0);
		for(i=0;i<j-1;i++)
		LCD_CHAR(receive[i]);
		memset(receive,0,7);
		j = 0;
	} while (k != 16);
	return 0;
}