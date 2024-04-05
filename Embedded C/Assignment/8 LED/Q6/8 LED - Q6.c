#include<LPC214X.h>
void  delay(){
	
	unsigned int i=0;
	while(i<200000){
		i++;
	}
}
int main(){
	unsigned int x=0xff;
	//set the direction as output
	IODIR0 |=0x5555; 
	
	while(1){
	
		if(x & 0x01){
		IOSET0 |=(0x01);
		
		}
		else{
		IOCLR0 |=(0x01);
			
		}
		
		if(x & 0x01<<1)
		IOSET0 |=(0x01<<2); 
		else
		IOCLR0 |=(0x01<<2);
		if(x & 0x01<<2)
		IOSET0 |=(0x01<<4);
		else
		IOCLR0 |=(0x01<<4);
		if(x & 0x01<<3)
		IOSET0 |=(0x01<<6);
		else
		IOCLR0 |=(0x01<<6);
		if(x & 0x01<<4)
		IOSET0 |=(0x01<<8);
		else
		IOCLR0 |=(0x01<<8);
		if(x & 0x01<<5)
		IOSET0 |=(0x01<<10);
		else
		IOCLR0 |=(0x01<<10);
		if(x & 0x01<<6)
		IOSET0 |=(0x01<<12);
		else
		IOCLR0 |=(0x01<<12);
		if(x & 0x01<<7)
		IOSET0 |=(0x01<<14);
		else
		IOCLR0 |=(0x01<<14);
		x--;
		delay();
		if(x==0)
			x=0xff;
	}
}