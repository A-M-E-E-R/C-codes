
#include<lpc214x.h>
#include"C:\\Users\\IDEAPAD\\OneDrive\\Desktop\\projects\\Keil\\Project\\Calculator\\timer.h"
#include"C:\\Users\\IDEAPAD\\OneDrive\\Desktop\\projects\\Keil\\Header_Files\\Basic_Functions\\Functions.h"
#define RS 0 //rs=>p0.3
#define RW 1//rw=>p0.1
#define EN 2//en=>p0.2
//function declarations
short int i=0;
void LCDcommand(unsigned char mycmd);
void LCDprint(unsigned char mydata[]);
void LCDdata(unsigned char mydata);
void initLCD(void);

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
