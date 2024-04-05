#include<lpc214x.h>
void delay(){
	unsigned int x = 150000;
	while(x>0){
		x--;
	}
}
int main(){
	unsigned int x =0,n=1;
	IODIR0 = 0x00ffffff;
	IODIR1 = 0;
	while(1){
		if(x==1){
			IOCLR0 = 0x00ffffff;
			IOSET0 = 0X0018;
			delay();
		}
	  if(x==2){
			IOCLR0 = 0x00ffffff;
			IOSET0 = 0X016C;
			delay();
		}
		if(x==3){
			IOCLR0 = 0x00ffffff;
			IOSET0 = 0X013C;
			delay();
		}
		if(x==4){
			IOCLR0 = 0x00ffffff;
			IOSET0 = 0X0198;
			delay();
		}
		if(x==5){
			IOCLR0 = 0x00ffffff;
			IOSET0 = 0X01B4;
			delay();
		}
		if(x==6){
			IOCLR0 = 0x00ffffff;
			IOSET0 = 0X01F4;
			delay();
		}
		if(x==7){
			IOCLR0 = 0x00ffffff;
			IOSET0 = 0X001C;
			delay();
		}
		if(x==8){
			IOSET0 = 0X01FF;
			delay();
		}
		if(x==9){
			IOCLR0 = 0x00ffffff;
			IOSET0 = 0X01BC;
			delay();
			if(n==1) x=0;
		}
		if(x==0){
			IOCLR0 = 0x00ffffff;
			IOSET0 = 0X00FC;
			delay();
			if(n==-1) x=10;
		}
		if((IOPIN1 & 0x01<<26)==0) n*=-1;
		x+=n;
	}
}