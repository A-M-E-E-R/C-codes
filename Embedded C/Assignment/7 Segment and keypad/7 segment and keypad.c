#include<lpc214x.h>
void delay(){
	unsigned int x = 150000;
	while(x>0){
		x--;
	}
}
int main(){
	IODIR0 = 0x00ffffff;
	IODIR1 = 0xffff0000;
	while(1){
		if((IOPIN0 & 1<<29)==(IOPIN1 & 1<< 18)){
			IOCLR0 = 0x00ffffff;
			IOSET0 = 0X0018;
			delay();
		}
	  if((IOPIN0 & 1<<27)==(IOPIN1 & 1<< 18)){
			IOCLR0 = 0x00ffffff;
			IOSET0 = 0X016C;
			delay();
		}
		if((IOPIN0 & 1<<25)==(IOPIN1 & 1<< 18)){
			IOCLR0 = 0x00ffffff;
			IOSET0 = 0X013C;
			delay();
		}
		if((IOPIN0 & 1<<29)==(IOPIN1 & 1<< 22)){
			IOCLR0 = 0x00ffffff;
			IOSET0 = 0X0198;
			delay();
		}
		if((IOPIN0 & 1<<27)==(IOPIN1 & 1<< 22)){
			IOCLR0 = 0x00ffffff;
			IOSET0 = 0X01B4;
			delay();
		}
		if((IOPIN0 & 1<<25)==(IOPIN1 & 1<< 22)){
			IOCLR0 = 0x00ffffff;
			IOSET0 = 0X01F4;
			delay();
		}
		if((IOPIN0 & 1<<29)==(IOPIN1 & 1<< 26)){
			IOCLR0 = 0x00ffffff;
			IOSET0 = 0X001C;
			delay();
		}
		if((IOPIN0 & 1<<27)==(IOPIN1 & 1<< 26)){
			IOSET0 = 0X01FF;
			delay();
		}
		if((IOPIN0 & 1<<29)==(IOPIN1 & 1<< 18)){
			IOCLR0 = 0x00ffffff;
			IOSET0 = 0X01BC;
			delay();
		}
		if((IOPIN0 & 1<<29)==(IOPIN1 & 1<< 18)){
			IOCLR0 = 0x00ffffff;
			IOSET0 = 0X00FC;
			delay();
		}
	}
}