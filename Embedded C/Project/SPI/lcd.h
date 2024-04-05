#include<lpc214x.h>
#include"C:\\Users\\IDEAPAD\\OneDrive\\Desktop\\projects\\Keil\\Header_Files\\Basic_Functions\\Functions.h"
#include"C:\\Users\\IDEAPAD\\OneDrive\\Desktop\\projects\\Keil\\Project\\Calculator\\timer.h"
#define RS 16 //rs=>p0.0
#define RW 17//rw=>p0.1
#define EN 18//en=>p0.2
//function declarations
void LCDcommand(unsigned char mycmd);
void LCDdata(unsigned char mydata);
void initLCD(void);
//Defining the function
void LCDcommand(unsigned char mycmd)
{
pin_write(RS,0);// RS will be selected for command mode
pin_write(RW,0);//will be selected for write
port_write(1,mycmd);
pin_write(EN,1);
delayus(25);
pin_write(EN,0);
}
void LCDdata(unsigned char mydata)
{
	if(mydata=='.'){
		LCDcommand(0x01);
		return ;
	}
	if(mydata=='*') mydata = 'x';
	pin_write(RS,1);
	pin_write(RW,0); 
	port_write(1,mydata);
	pin_write(EN,1);
	delayus(25);
	pin_write(EN,0);
}
void LCDstring(unsigned char *s)
{
    while(*s) {
        LCDdata(*s++);
    }
}
void initLCD(void)
{
LCDcommand(0x38);//16*2 lcd
LCDcommand(0x08);//cursor off display off
LCDcommand(0x06);//entry mode
LCDcommand(0x01);//clear display
LCDcommand(0x80);//to start from 1st row
}