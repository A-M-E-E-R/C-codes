#include<lpc214x.h>
void delay(){
	unsigned int x = 150000;
	while(x>0){
		x--;
	}
}
int main(){
	unsigned int x =0,n=1;
	IODIR0 = 0xffffffff;
	IODIR1 = (1<<27)|(1<<28)|(1<<29)|(1<<30);
	while(1){
			if(x%10==1){
				IOSET0 = 0X0018;
			}
			if(x%10==2){
				IOSET0 = 0X016C;
			}
			if(x%10==3){
				IOSET0 = 0X013C;
			}
			if(x%10==4){
				IOSET0 = 0X0198;
			}
			if(x%10==5){
				IOSET0 = 0X01B4;
			}
			if(x%10==6){
				IOSET0 = 0X01F4;
			}
			if(x%10==7){
				IOSET0 = 0X001C;
			}
			if(x%10==8){
				IOSET0 = 0X01FF;
			}
			if(x%10==9){
				IOSET0 = 0X01BC;
			}
			if(x%10==0){
				IOSET0 = 0X00FC;
			}
			if((x/10)%10==0){
				IOSET0 |= (1<<10)|(1<<11)|(1<<12)|(1<<13)|(1<<14)|(1<<15);
			}
			if((x/10)%10==1){
				IOSET0 |= (1<<11)|(1<<12);
			}
			if((x/10)%10==2){
				IOSET0 |= (1<<10)|(1<<11)|(1<<16)|(1<<14)|(1<<13);
			}
			if((x/10)%10==3){
				IOSET0 |= (1<<10)|(1<<11)|(1<<12)|(1<<13)|(1<<16);
			}
			if((x/10)%10==4){
				IOSET0 |= (1<<16)|(1<<11)|(1<<12)|(1<<15);
			}
			if((x/10)%10==5){
				IOSET0 |= (1<<10)|(1<<16)|(1<<12)|(1<<13)|(1<<15);
			}
			if((x/10)%10==6){
				IOSET0 |= (1<<10)|(1<<16)|(1<<12)|(1<<13)|(1<<14)|(1<<15);
			}
			if((x/10)%10==7){
				IOSET0 |= (1<<10)|(1<<11)|(1<<12);
			}
			if((x/10)%10==8){
				IOSET0 |= (1<<10)|(1<<11)|(1<<16)|(1<<12)|(1<<13)|(1<<14)|(1<<15);
			}
			if((x/10)%10==9){
				IOSET0 |= (1<<10)|(1<<11)|(1<<12)|(1<<13)|(1<<16)|(1<<15);
			}
			if((x/100)%10==0){
				IOSET0 |= (1<<17)|(1<<18)|(1<<19)|(1<<20)|(1<<21)|(1<<22);
			}
			if((x/100)%10==1){
				IOSET0 |= (1<<18)|(1<<19);
			}
			if((x/100)%10==2){
				IOSET0 |= (1<<17)|(1<<18)|(1<<23)|(1<<21)|(1<<20);
			}
			if((x/100)%10==3){
				IOSET0 |= (1<<20)|(1<<23)|(1<<19)|(1<<18)|(1<<17);
			}
			if((x/100)%10==4){
				IOSET0 |= (1<<22)|(1<<23)|(1<<18)|(1<<19);
			}
			if((x/100)%10==5){
				IOSET0 |= (1<<17)|(1<<23)|(1<<22)|(1<<20)|(1<<19);
			}
			if((x/100)%10==6){
				IOSET0 |= (1<<17)|(1<<19)|(1<<22)|(1<<23)|(1<<20)|(1<<21);
			}
			if((x/100)%10==7){
				IOSET0 |= (1<<17)|(1<<18)|(1<<19);
			}
			if((x/100)%10==8){
				IOSET0 |= (1<<17)|(1<<18)|(1<<19)|(1<<20)|(1<<21)|(1<<22)|(1<<23);
			}
			if((x/100)%10==9){
				IOSET0 |= (1<<17)|(1<<18)|(1<<19)|(1<<20)|(1<<22)|(1<<23);
			}
			if((x/1000)%10==0){
				IOSET0 |= (1<<25)|(1<<26);
				IOSET1 |= (1<<27)|(1<<28)|(1<<29)|(1<<30);
			}
			if((x/1000)%10==1){
				IOSET1 |= (1<<27);
				IOSET0 |= (1<<26);
			}
			if((x/1000)%10==2){
				IOSET1 |= (1<<28)|(1<<29);
				IOSET0 |= (1<<25)|(1<<26)|(1<<31);
			}
			if((x/1000)%10==3){
				IOSET1 |= (1<<27)|(1<<28);
				IOSET0 |= (1<<25)|(1<<26)|(1<<31);
			}
			if((x/1000)%10==4){
				IOSET1 |= (1<<27)|(1<<30);
				IOSET0 |= (1<<26)|(1<<31);
			}
			if((x/1000)%10==5){
				IOSET1 |= (1<<27)|(1<<28)|(1<<30);
				IOSET0 |= (1<<25)|(1<<31);
			}
			if((x/1000)%10==6){
				IOSET1 |= (1<<27)|(1<<28)|(1<<29)|(1<<30);
				IOSET0 |= (1<<25)|(1<<31);
			}
			if((x/1000)%10==7){
				IOSET1 |= (1<<27);
				IOSET0 |= (1<<25)|(1<<26);
			}
			if((x/1000)%10==8){
				IOSET1 |= (1<<27)|(1<<28)|(1<<29)|(1<<30);
				IOSET0 |= (1<<25)|(1<<26)|(1<<31);
			}
			if((x/1000)%10==9){
				IOSET1 |= (1<<27)|(1<<28)|(1<<30);
				IOSET0 |= (1<<25)|(1<<26)|(1<<31);
			}
			if((IOPIN1 & 1<<18)==0){
				x++;
				if(x==10000) x=0;
			}
			if((IOPIN1 & 1<<22)==0){
				if(x==0) x=10000;
				x--;	
			}			
			delay();
			IOCLR0 = 0xffffffff;
			IOCLR1 = (1<<27)|(1<<28)|(1<<29)|(1<<30);
		}
}