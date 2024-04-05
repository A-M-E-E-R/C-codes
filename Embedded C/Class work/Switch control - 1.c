#include<lpc214x.h>

int main(){
	IODIR0 |= (0xffffffffff);
	IODIR1 &= ~((0x01<<16)|(0x01<<31));
	if((IOPIN1 & 0x01<<16)==0){
		IOSET0 |= 0x01<<9;
	}
	else{
		IOCLR0 |= 0x01<<9;       
	}
	if((IOPIN1 & 0x01<<31)==0){
		IOSET0 |= 0x01<<16;
	}
	else{
		IOCLR0 |= 0x01<<16;
	}
}