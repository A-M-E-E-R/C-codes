#include"C:\\Users\\IDEAPAD\\OneDrive\\Desktop\\projects\\Keil\\Header_Files\\lcd_4bit.h"
int main()
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
}
