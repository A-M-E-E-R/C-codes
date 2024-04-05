#include<lpc214x.h>
#include"C:\\Users\\IDEAPAD\\OneDrive\\Desktop\\projects\\Keil\\Project\\Calculator\\timer.h"
#include"C:\\Users\\IDEAPAD\\OneDrive\\Desktop\\projects\\Keil\\Header_Files\\lcd_4bit.h"
#include"C:\\Users\\IDEAPAD\\OneDrive\\Desktop\\projects\\Keil\\Header_Files\\Basic_Functions\\Functions.h"

void minute(void);
void seconds(short int);
void percent(void);
void s_chr(void);
void s_nil(void);
void s_chk(void);
void s_idle(void);
void all_clr(void);
short int m,s;
void seconds(short int x){
	initPLL();
	while(x>0){
		delayms(1000);
		x--;
	}
}
void minute(void){
	seconds(60);
}
void percent(void){
	dat('%');
}
void s_chr(void){
	show("||");
}
void s_nil(void){
	show("00");
}
void s_chk(void){
	show("**");
}
void s_idle(void){
	show("--");
}
void all_clr(void){
	cmd(0x01);
	cmd(0xc0);
	cmd(0xc1);
	s_nil();
	cmd(0xc5);
	s_nil();
	cmd(0xc9);
	s_nil();
	cmd(0xcd);
	s_nil();
}
