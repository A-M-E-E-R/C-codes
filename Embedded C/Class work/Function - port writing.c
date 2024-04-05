#include<lpc214x.h>
void pin_write(int pB, int pV);
	int main(){
		
		pin_write(0,0);
		pin_write(1,0);
	}
void pin_write(int pB, int pV){
	if(pB < 10){
		IODIR0 |= (pV<< pB*8);
		if(pV){
			IOSET0 |= pV<<pB*8;
		}
		else{
			IOCLR0 |= 0xff<<pB*8;
		}
	}
	else{
		pB-=10;
		if(pB>1){
		IODIR1 |= (pV<< (pB*8));
		if(pV){
			IOSET1 |= pV<<pB*8;
		}
		else{
			IOCLR1 |= 0xff<<pB*8;
		}
	}	}
}