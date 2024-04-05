// lcd.h
#ifndef LCD_H
#define LCD_H
#include<lpc214x.h>
#include"C:\\Users\\IDEAPAD\\OneDrive\\Desktop\\projects\\Keil\\Project\\Calculator\\timer.h"
#include"C:\\Users\\IDEAPAD\\OneDrive\\Desktop\\projects\\Keil\\Header_Files\\Basic_Functions\\Functions.h"
#define RS 0 //rs=>p0.0
#define RW 1//rw=>p0.1
#define EN 2//en=>p0.2
//function declarations
short int i=0;
void LCDcommand(unsigned char mycmd);
void LCDprint(unsigned char mydata[]);
void LCDdata(unsigned char mydata);
void initLCD(void);
void enter(void);
void enter_id(void);
void wrong_id(void);
void change(void);
void granted(void);
void denied(void);
void clear(void);
void TRY(void);
void okay(void);
//Defining the function
void LCDcommand(unsigned char mycmd)
{
pin_write(RS,0);// RS will be selected for command mode
pin_write(RW,0);//will be selected for write
pin_write(EN,1);
port_write(1,mycmd);
delayus(100);
pin_write(EN,0);
}
void LCDdata(unsigned char mydata)
{
	pin_write(RS,1);
	pin_write(RW,0);
	pin_write(EN,1);
	port_write(1,(int)mydata);
	delayms(20);
	pin_write(EN,0);
}
void initLCD(void)
{
LCDcommand(0x38);//16*2 lcd
LCDcommand(0x0c);//cursor off display off
LCDcommand(0x06);//entry mode
LCDcommand(0x01);//clear display
LCDcommand(0x80);//to start from 1st row
}
void clear(void){
	LCDcommand(0x01);
}
void LCDprint(unsigned char mydata[])
	{
	int i=0;
	while(mydata[i]!='\0')
		{
		LCDdata(mydata[i]);
			i++;
		}
}
void enter(void){
			LCDprint("ENTER");
			LCDcommand(0xc0);
			LCDdata('P');
			LCDdata('A');
			LCDdata('S');
			LCDdata('S');
			LCDdata('W');
			LCDdata('O');
			LCDdata('R');
			LCDdata('D');
			delayms(50);
			clear();
}
void change(void){
			LCDdata('C');
			delayus(10);
			LCDdata('H');
			delayus(10);
			LCDdata('A');
			delayus(10);
			LCDdata('N');
			delayus(10);
			LCDdata('G');
			delayus(10);
			LCDdata('E');
			LCDcommand(0xc0);
			LCDdata('P');
			LCDdata('A');
			LCDdata('S');
			LCDdata('S');
			LCDdata('W');
			LCDdata('O');
			LCDdata('R');
			LCDdata('D');
			delayms(10);
			clear();
}
void okay(void){
			LCDdata('P');
			LCDdata('R');
			LCDdata('E');
			LCDdata('S');
			LCDdata('S');
			LCDdata(' ');
			LCDdata('=');
			LCDcommand(0xc0);
			LCDdata('C');
			LCDdata('O');
			LCDdata('N');
			LCDdata('T');
			LCDdata('I');
			LCDdata('N');
			LCDdata('U');
			LCDdata('E');
			delayms(100);
			clear();
}
void wrong_id(void){
			LCDdata('W');
			LCDdata('R');
			LCDdata('O');
			LCDdata('N');
			LCDdata('G');
			LCDdata(' ');
			LCDdata('I');
			LCDdata('D');
			LCDcommand(0xc0);
			LCDdata('T');
			LCDdata('R');
			LCDdata('Y');
			LCDdata(' ');
			LCDdata('A');
			LCDdata('G');
			LCDdata('A');
			LCDdata('I');
			LCDdata('N');
			delayms(100);
			clear();
}
void granted(void){
			LCDdata('A');
			LCDdata('C');
			LCDdata('C');
			LCDdata('E');
			LCDdata('S');
			LCDdata('S');
			LCDcommand(0xc0);
			LCDdata('G');
			LCDdata('R');
			LCDdata('A');
			LCDdata('N');
			LCDdata('T');
			LCDdata('E');
			LCDdata('D');
			pin_write(116,1);//Green light
			delayms(100);
			pin_write(116,0);
	clear();
}
void denied(void){
			LCDdata('A');
			LCDdata('C');
			LCDdata('C');
			LCDdata('E');
			LCDdata('S');
			LCDdata('S');
			LCDcommand(0xc0);
			LCDdata('D');
			LCDdata('E');
			LCDdata('N');
			LCDdata('I');
			LCDdata('E');
			LCDdata('D');
	delayms(10);
	for(i=0;i<10;i++){
			pin_write(118,1);//Red light
			delayms(50);
			pin_write(118,0);
			delayms(45);
	}
	clear();
}
void TRY(void){
			LCDdata('T');
			LCDdata('R');
			LCDdata('Y');
			LCDcommand(0xc0);
			LCDdata('A');
			LCDdata('G');
			LCDdata('A');
			LCDdata('I');
			LCDdata('N');
			delayms(100);
	clear();
}
void enter_id(void){
			LCDdata('E');
			LCDdata('N');
			LCDdata('T');
			LCDdata('E');
			LCDdata('R');
			LCDcommand(0xc0);
			LCDdata('T');
			LCDdata('H');
			LCDdata('E');
			LCDdata(' ');
			LCDdata('I');
			LCDdata('D');
			delayms(100);
	clear();
}
#endif /* lcd_H */
