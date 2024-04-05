#define c1 128
#define c2 129
#define c3 130
#define c4 131
#define KeyPort 13
/*C1 C2 C3 C4 R1 R2 R3 R4
	1  1  1  1  0  1  1   1 = 0x F7
	1  1  1  1  1  0  1   1 = 0x FB
	1  1  1  1  1  1  0   1 = 0x FD
	1  1  1  1  1  1  1   0 = 0x FE*/
 #include<lpc214x.h>
#include"C:\\Users\\IDEAPAD\\OneDrive\\Desktop\\projects\\Keil\\Header_Files\\Basic_Functions\\Functions.h"
 unsigned char getKeypad(void);
 unsigned char getKeypad(void)
{
	unsigned char key = 'x';
	int mydata;
	delay();
	while(key=='x')//while loop should terminate when the user presses the key
	{
		port_write(KeyPort,0xF7);
		mydata = pin_read(c1);
		if (mydata==0)
		{
			key = '.';
			break;
		}
		mydata = pin_read(c2);
		if (mydata==0)
		{
			key = '0';
			break;
		}
		mydata = pin_read(c3);
		if (mydata==0)
		{
			key = '=';
			break;
		}
		mydata = pin_read(c4);
		if (mydata==0)
		{
			key = '+';
			break;
		}
		port_write(KeyPort,0xFB);
		mydata = pin_read(c1);
		if (mydata==0)
		{
			key = '1';
			break;
		}
		mydata = pin_read(c2);
		if (mydata==0)
		{
			key = '2';
			break;
		}
		mydata = pin_read(c3);
		if (mydata==0)
		{
			key = '3';
			break;
		}
		mydata = pin_read(c4);
		if (mydata==0)
		{
			key = '-';
			break;
		}
		port_write(KeyPort,0xFD);
		mydata = pin_read(c1);
		if (mydata==0)
		{
			key = '4';
			break;
		}
		mydata = pin_read(c2);
		if (mydata==0)
		{
			key = '5';
			break;
		}
		mydata = pin_read(c3);
		if (mydata==0)
		{
			key = '6';
			break;
		}
		mydata = pin_read(c4);
		if (mydata==0)
		{
			key = '*';
			break;
		}
		port_write(KeyPort,0xFE);
		mydata = pin_read(c1);
		if (mydata==0)
		{
			key = '7';
			break;
		}
		mydata = pin_read(c2);
		if (mydata==0)
		{
			key = '8';
			break;
		}
		mydata = pin_read(c3);
		if (mydata==0)
		{
			key = '9';
			break;
		}
		mydata = pin_read(c4);
		if (mydata==0)
		{
			key = '/';
			break;
		}
	}
	return key;
}



