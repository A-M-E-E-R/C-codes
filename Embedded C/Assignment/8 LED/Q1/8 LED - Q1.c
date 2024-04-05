#include<LPC214X.h>
void  delay(){
	
	unsigned int i=0;
	while(i<20000){
		i++;
	}
}
int main(){
	
	//set the direction as output
	IODIR0 |=(0x01);
	
	while(1){
	//turn on led
	
		IOSET0 |=(0x01);
		delay();
	
	//turn off led
	IOCLR0 |=(0x01);
		delay();
	}
}