#include<lpc214x.h>
void delay();
int main(){
	unsigned int x;
	IODIR0 |= ((0x01<<1)|(0x01<<6)|(0x01<<11)|(0x01<<15)|(0x01<<20));
	IODIR1 = 0;
	while(1){
		if((IOPIN1 &(0x01<<16))==0){
			IOCLR0 |= ((0x01<<1)|(0x01<<20));
			IOSET0 |= ((0x01<<11)|(0x01<<15));
			x=10;
			while(x>0){
				delay();
				x--;
			}
			IOCLR0 |= 0x01<<11;
			IOSET0 |= 0x01<<6;
			x=2;
			while(x>0){
				delay();
				x--;
			}
			IOCLR0 |= 0x01<<6;
		}
		else if((IOPIN1 &(0x01<<21))==0){
			IOCLR0 |= ((0x01<<11)|(0x01<<15));
			IOSET0 |= ((0x01<<1)|(0x01<<20));
			x=16;
			while(x>0){
				delay();
				x--;
			}
			x=3;
			while(x>0){
				IOCLR0 |= 0x01<<20;
				delay();
				IOSET0 |= 0x01<<20;
				delay();
				x--;
			}
			IOCLR0 |= 0x01<<20;
		}
		else{
			IOCLR0 |= 0x00ffffff;
		}
	}
}
void delay(){
	unsigned int x=205000;
	while(x>0){
		x--;
	}
}
