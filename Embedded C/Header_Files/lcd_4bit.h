#include<lpc214x.h>
#include<stdlib.h>
#include<string.h>
#define bit(x) (1<<x)
 
void lcd_init(void);
void cmd(unsigned char a);
void dat(unsigned char b);
void show(unsigned char *s);
void lcd_delay(void);
 
#define delay for(i=0;i<55000;i++)
 
unsigned int range=0,i;
 
void lcd_init(void)
{
    cmd(0x02);//clear
    cmd(0x28);//4-bit mode
    cmd(0x0c);// turn on screen with no blinking cursor (cursor is hiddden) ;(0x0f) for both
    cmd(0x06);//entry mode (character after character)
    cmd(0x80);//first line, 0xc0 second line, 0x94 third line, 0xd4 fourth line
}
 
void cmd(unsigned char a)
{
    IO0PIN&=0xffffff03;
    IO0PIN|=(a & 0xf0) << 0;
    IO0CLR|=bit(2);                //rs=0
    IO0SET|=bit(3);                 //en=1
    lcd_delay();
    IO0CLR|=bit(3);                 //en=0
    
    IO0PIN&=0xffffff03;
    IO0PIN|=((a << 4)  & 0xf0) << 0;
    IO0CLR|=bit(2);                //rs=0
    IO0SET|=bit(3);                 //en=1
    lcd_delay();
    IO0CLR|=bit(3);                 //en=0
}
 
void dat(unsigned char b)
{
    IO0PIN&=0xffffff03;
    IO0PIN|=(b & 0xf0) << 0;
    IO0SET|=bit(2);                //rs=1
    IO0SET|=bit(3);            //en=1
    lcd_delay();
    IO0CLR|=bit(3);            //en=0
    
    IO0PIN&=0xffffff03;
    IO0PIN|=((b << 4)  & 0xf0) << 0;
    IO0SET|=bit(2);                //rs=1
    IO0SET|=bit(3);            //en=1
    lcd_delay();
    IO0CLR|=bit(3);            //en=0
}
 
void show(unsigned char *s)
{
    while(*s) {
        dat(*s++);
    }
}
 
void show_int(short int x)
{
	char a[4];
	sprintf(a,"%d",x);
	x = strlen(a);
	a[x]='\0';
	show((unsigned char *)a);
}
void lcd_delay(void)
    {
    unsigned int i;
    for(i=0;i<=1000;i++);
}
/*int main()
{
    VPBDIV=0x01;                 // PCLK = 60MHz
    IO0DIR|=0x0FC;
    lcd_init();
    cmd(0x89);
    show((unsigned char *)"Forward");
 
    while(1) {
        cmd(0x18);
        delay;
    }
}*/
