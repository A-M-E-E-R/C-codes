#include<LPC214x.h>
#include"UART.h"

int main(void){
	initUART();

	while(1)
	{
		printUART ("Welcome to Technologics");
		//sendUART (13); // carriage return
		//sendUART (10); // Line feed
		delayms(1000);
	}
}