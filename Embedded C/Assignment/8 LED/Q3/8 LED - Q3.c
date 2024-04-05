#include<LPC214X.h>
void  delay(){
	
	unsigned int i=0;
	while(i<200000){
		i++;
	}
}
int main(){
	unsigned int x=0;
	//set the direction as output
	IODIR0 |=0x5555; 
												
	
	while(1){
	
		if(x & 0x01){
		IOSET0 |=(0x01);
		}
		else{
		IOCLR0 |=(0x01);
		}
		
		if(x & 0x01<<1){
			IOSET0 |=(0x01<<2); 
		}
		else{
			IOCLR0 |=(0x01<<2);
		}
		if(x & 0x01<<2)
		{
			IOSET0 |=(0x01<<4);
		}
		else{
			IOCLR0 |=(0x01<<4);
		}
		if(x & 0x01<<3){
			IOSET0 |=(0x01<<6);
		}
		else{
			IOCLR0 |=(0x01<<6);
		}
		x++;
		if(x & 0x01<<4){
			x=0;
		}
		delay();
	}
}