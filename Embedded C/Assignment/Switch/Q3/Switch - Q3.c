#include<lpc214x.h>
int main(){
	int x = 0;
	IODIR0 = 0x01<<30;
	IODIR1 = 0x00;
	while(1){
		if((IOPIN1 & 0x01<<30)==0)
			x^=1;
		if(x)
			IOSET0 |= 0x01<<30;
		else
			IOCLR0 |= 0x01<<30;
	}
}