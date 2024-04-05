// Functions.h
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include<lpc214x.h>

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
int pin_read(int pN){
	int value;
	if(pN<100){
		IODIR0 = IODIR0 & (~(0x01 << pN));
		value = IOPIN0 & (1<<pN);
	}
	else{
		pN-=100;
		IODIR1 = IODIR1 & (~(0x01 << pN));
		value = IOPIN1 & (1<<pN);
	}
	return value;
}

void port_write(int pB, int pV){
	if(pB < 10){
		IODIR0 |= (0xff<< pB*8);
		IOSET0 |= pV<<(pB*8);
		IOCLR0 |= (~(pV))<<(pB*8);
	}
	else{
		pB-=10;
		IODIR1 |= (0xff<< pB*8);
		IOSET1 |= pV<<(pB*8);
		IOCLR1 |= ~(pV)<<(pB*8);
	}	
}


#endif /* FUNCTIONS_H */
