#include<stdio.h>
#include"C:\\Users\\IDEAPAD\\OneDrive\\Desktop\\projects\\Keil\\Header_Files\\lcd_4bit.h"
unsigned int get_value();
int main(){
	unsigned int x;
	PINSEL0 = 0x00;
	PINSEL1 = 0x00001000;
	AD1CR = 0;//clean up
	AD1CR |= 0x01<<7;//channel number is 7 (AD1.7)
	AD1CR |= 13<<8; //CLKDIV for adc
	AD1CR |= 0x01 << 16; //busrt
	AD1CR |= (1 << 21); //power down (PDN = 1)
	while(1){
		x = get_value();
		show_int(x);
	}
}
unsigned int get_value(){
	unsigned int x;
	AD1CR |= (1 << 21); //power down (PDN = 1)
	AD1CR |= 0x01 << 24; //start conversion 
	while((AD1GDR &(0x01<<31))==0);//if the 3st bit becomes 1, the conversion is done.
	x = AD1GDR;
	x = (x>>6)& 0x000003ff; //extracting values from 15 to 6 bits of the AD1GDR
	return x;
}
