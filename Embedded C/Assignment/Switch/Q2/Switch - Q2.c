#include<lpc214x.h>
int main(){

IODIR0 |= 0x0084;
IODIR1 = 0;

	if((IOPIN1 & 0x10000)==0){
		IOSET0 |= 0x04;
	}
	else
		IOCLR0 |= 0x04;
	
	if((IOPIN1 & 0x100000)==0){
		IOSET0 |= 0x80;
	}
	else
		IOCLR0 |= 0x80;
	
}