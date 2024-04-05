#include<lpc214x.h>
#include<stdlib.h>
#include"charger.h"
#define power 15
#define c1 16
#define c2 17
#define c3 18
#define c4 19
#define r1 20
#define r2 21
#define r3 22
#define r4 23
typedef struct chargers{
	short int priority;
	short int completion;
} charger;
short int x,m,j;
charger slot[4];
void check(void);
void red_p(void);
int main(){
	IO0DIR|=0x00;;//input pins for checking
	IODIR0 |= 0xf00000;
	IOCLR0 |= 0xf00000;//clearing all values from output port connected to relay
	IO0DIR|=0x0FC;// LCD port
  lcd_init();
	initPLL();
	show("Welcome to smart");
	cmd(0xc1);
	show("CHARGER");
	delayms(500);
	all_clr();//clear screen with no connection sign for all
	while(1){
		check();
		ch:
		if(slot[0].priority==1){
			pin_write(r1,1);//relay 1 connect
			while(slot[0].priority && slot[0].priority!=10){
				cmd(0xc1);//address for 1
				s_chr();//charging sign
				minute();
				m++;
				slot[0].completion= (m*100)/480;//calculating percentage
				cmd(0x80);
				show_int(slot[0].completion);//LCD print
				percent();//% symbol
				if(slot[0].completion==100){//if completed the charging time 
					slot[0].priority=10;//idle priority value
					cmd(0xc1);//address for 1
					s_idle();//idle sign
					m=0;//minute flag reset
					slot[0].completion=0;//individual flag reset
				}
				check();
			}
			if(slot[0].priority!=10){//if the charging is not completed
				for(j=0;j<3;j++){
					seconds(10);
					cmd(0xc1);//address for 1
					s_chk();//checking sign
					if(pin_read(c1)){
						slot[0].priority=1;//retaking priority
						goto ch;
					}
				}
				cmd(0xc1);//address for 1
				s_nil();//disconnected sign
				m=0;//minute flag reset
				slot[0].completion=0;//individual flag reset
				red_p();//reduces every other priority value by 1
			}
			pin_write(r1,0);//relay 1 disconnect
			goto ch;
		}
		else if(slot[1].priority==1){
			pin_write(r2,1);//relay 2 connect
			while(slot[1].priority && slot[1].priority!=10){
				cmd(0xc5);//address for 2
				s_chr();//charging sign
				minute();
				m++;
				slot[1].completion= (m*100)/480;
				cmd(0x84);
				show_int(slot[1].completion);//LCD print
				percent();//% symbol
				if(slot[1].completion==100){//if completed the charging time 
					slot[1].priority=10;//idle priority value
					cmd(0xc5);//address for 2
					s_idle();//idle sign
					m=0;//minute flag reset
					slot[1].completion=0;//individual flag reset
				}
				check();
			}
			if(slot[1].priority!=10){//if the charging is not completed
				for(j=0;j<3;j++){
					seconds(10);
					cmd(0xc5);//address for 2
					s_chk();//checking sign
					if(pin_read(c2)){
						slot[1].priority=1;//retaking priority
						goto ch;
					}
				}
				cmd(0xc5);//address for 2
				s_nil();//disconnected sign
				m=0;//minute flag reset
				slot[1].completion=0;//individual flag reset
				red_p();//reduces every other priority value by 1
			}
			pin_write(r2,0);//relay 2 disconnect
			goto ch;
		}
		else if(slot[2].priority==1){
			pin_write(r3,1);//relay 3 connect
			while(slot[2].priority && slot[2].priority!=10){
				cmd(0xc9);//address for 3
				s_chr();//charging sign
				minute();
				m++;
				slot[2].completion= (m*100)/480;
				cmd(0x89);
				show_int(slot[2].completion);//LCD print
				percent();//% symbol
				if(slot[2].completion==100){//if completed the charging time 
					slot[2].priority=10;//idle priority value
					cmd(0xc9);//address for 3
					s_idle();//idle sign
					m=0;//minute flag reset
					slot[2].completion=0;//individual flag reset
				}
				check();
			}
			if(slot[2].priority!=10){//if the charging is not completed
				for(j=0;j<3;j++){
					seconds(10);
					cmd(0xc9);//address for 3
					s_chk();//checking sign
					if(pin_read(c3)){
						slot[2].priority=1;//retaking priority
						goto ch;
					}
				}
				cmd(0xc9);//address for 3
				s_nil();//disconnected sign
				m=0;//minute flag reset
				slot[2].completion=0;//individual flag reset
				red_p();//reduces every other priority value by 1
			}
			pin_write(r3,0);//relay 3 disconnect
			goto ch;
		}
		else if(slot[3].priority==1){
			pin_write(r4,1);//relay 4 connect
			while(slot[3].priority && slot[3].priority!=10){
				cmd(0xcd);//address for 4
				s_chr();//charging sign
				minute();
				m++;
				slot[3].completion= (m*100)/480;
				cmd(0x8d);
				show_int(slot[3].completion);//LCD print
				percent();//% symbol
				if(slot[3].completion==100){//if completed the charging time 
					slot[3].priority=10;//idle priority value
					cmd(0xcd);//address for 4
					s_idle();//idle sign
					m=0;//minute flag reset
					slot[3].completion=0;//individual flag reset
				}
				check();
			}
			if(slot[3].priority!=10){//if the charging is not completed
				for(j=0;j<3;j++){
					seconds(10);
					cmd(0xcd);//address for 4
					s_chk();//checking sign
					if(pin_read(c4)){
						slot[3].priority=1;//retaking priority
						goto ch;
					}
				}
				cmd(0xc4);//address for 4
				s_nil();//disconnected sign
				m=0;//minute flag reset
				slot[3].completion=0;//individual flag reset
				red_p();//reduces every other priority value by 1
			}
			pin_write(r4,0);//relay 4 disconnect
			goto ch;
		}
	}
}

void check(void){
	cc:
	if(pin_read(c1)&& slot[0].priority==0){
		x++;
		cmd(0xc1);
		s_idle();
		slot[0].priority=x;
	}
	if(pin_read(c1)==0 && slot[0].priority ){
		slot[0].priority=0;
		return ;
	}
	if(pin_read(c2)&& slot[1].priority==0){
		x++;
		cmd(0xc5);
		s_idle();
		slot[1].priority=x;
		goto cc;
	}
	if(pin_read(c2)==0 && slot[1].priority ){
		slot[1].priority=0;
		return ;
	}
	if(pin_read(c3)&& slot[2].priority==0){
		x++;
		cmd(0xc9);
		s_idle();
		slot[2].priority=x;
		goto cc;
	}
	if(pin_read(c3)==0 && slot[2].priority ){
		slot[2].priority=0;
		return ;
	}
	if(pin_read(c4)&& slot[3].priority==0){
		x++;
		cmd(0xcd);
		s_idle();
		slot[3].priority=x;
		goto cc;
	}
	if(pin_read(c4)==0 && slot[3].priority ){
		slot[3].priority=0;
		return ;
	}
}
void red_p(void){
	short int i;
	x--;
	for(i=0;i<4;i++)
		if(slot[i].priority!=0 && slot[i].priority!=10) slot[i].priority--; 
}
