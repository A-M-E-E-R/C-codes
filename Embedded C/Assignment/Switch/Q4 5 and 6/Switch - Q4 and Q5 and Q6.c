#include<lpc214x.h>
void  delay(){
	
	unsigned int i=0;
	while(i<200000){
		i++;
	}
}
int main(){
	unsigned int x;
	//set the direction as output
	IODIR0 |=0x0fffff00; 
	IODIR1 &= 00;
	while(1){			
		if((IOPIN1 & 0X01<<24)==0){
			x=0;
			while(1){
			
				if(x & 0x01){
				IOSET0 |=(0x01<<12);
				}
				else{
				IOCLR0 |=(0x01<<12);
				}
				
				if(x & 0x01<<1){
					IOSET0 |=(0x01<<16); 
				}
				else{
					IOCLR0 |=(0x01<<16);
				}
				if(x & 0x01<<2)
				{
					IOSET0 |=(0x01<<21);
				}
				else{
					IOCLR0 |=(0x01<<21);
				}
				if(x & 0x01<<3){
					IOSET0 |=(0x01<<26);
				}
				else{
					IOCLR0 |=(0x01<<26);
				}
				x++;
				if(x & 0x01<<4){
					x=0;
				}
				if(((IOPIN1 & 0X01<<28)==0))
					break;
				delay();
			}
		}
		if(((IOPIN1 & 0X01<<28)==0)){
			x=15;
			while(1){
		
				if(x & 0x01){
				IOSET0 |=(0x01<<12);
				}
				else{
				IOCLR0 |=(0x01<<12);
				}
				
				if(x & 0x01<<1){
					IOSET0 |=(0x01<<16); 
				}
				else{
					IOCLR0 |=(0x01<<16);
				}
				if(x & 0x01<<2)
				{
					IOSET0 |=(0x01<<21);
				}
				else{
					IOCLR0 |=(0x01<<21);
				}
				if(x & 0x01<<3){
					IOSET0 |=(0x01<<26);
				}
				else{
					IOCLR0 |=(0x01<<26);
				}
				x--;
				delay();
				if((IOPIN1 & 0X01<<24)==0)
					break;
				if(x==0)
					x=15;
			}
		}
	}
}