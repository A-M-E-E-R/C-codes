#include<lpc214x.h>
void pin_write(int pN, int pV);
	int main(){
		
		pin_write(0,0);
		pin_write(2,0);
	}
void pin_write(int pN, int pV){
	if(pN < 100){
		IODIR0 |= (0x01<< pN);
		if(pV){
			IOSET0 |= 0x01<<pN;
		}
		else{
			IOCLR0 |= 0x01<<pN;
		}
	}
	else{
		pN-=100;
		IODIR1 |= (0x01<< (pN));
		if(pV){
			IOSET1 |= 0x01<<pN;
		}
		else{
			IOCLR1 |= 0x01<<pN;
		}
	}	
}