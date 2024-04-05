#include<LPC214X.h>
void  delay(){
	
	unsigned int i=0;
	while(i<200000){
		i++;
	}
}
int main(){
	unsigned int x=00;
	//set the direction as output
	IODIR0 |=0x5555; 
	
	while(1){
	
		if(x){
		IOSET0 |=(0x01);
		
		}
		else{
		IOCLR0 |=(0x01);
			
		}
		
		if(x)
		IOSET0 |=(0x01<<2); 
		else
		IOCLR0 |=(0x01<<2);
		if(x)
		IOSET0 |=(0x01<<4);
		else
		IOCLR0 |=(0x01<<4);
		if(x)
		IOSET0 |=(0x01<<6);
		else
		IOCLR0 |=(0x01<<6);
		if(x)
		IOSET0 |=(0x01<<8);
		else
		IOCLR0 |=(0x01<<8);
		if(x)
		IOSET0 |=(0x01<<10);
		else
		IOCLR0 |=(0x01<<10);
		if(x)
		IOSET0 |=(0x01<<12);
		else
		IOCLR0 |=(0x01<<12);
		if(x)
		IOSET0 |=(0x01<<14);
		else
		IOCLR0 |=(0x01<<14);
		x^=1;
		delay();
	}
}