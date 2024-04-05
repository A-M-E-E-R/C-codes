#include<lpc214x.h>
#include<stdio.h>
#include<stdlib.h>
#include"C:\\Users\\IDEAPAD\\OneDrive\\Desktop\\projects\\Keil\\Project\\Calculator\\timer.h"
#include"C:\\Users\\IDEAPAD\\OneDrive\\Desktop\\projects\\Keil\\Header_Files\\Basic_Functions\\Functions.h"
#include"pwm.h"
void forward(void);
void reverse(void);
void stop(void);
int main() {
	pwm_init();
    while (1) {
        // Set low speed
        
				forward();
			delayms(100);
        // Set high speed
			reverse(); 
        delayms(100);
			
    }
}
void stop(void){
	pin_write(116,0);
}
void forward(void){
	pin_write(116,1);
	set_motor_speed(900);
	pin_write(122,1);
	pin_write(123,0);
}
void reverse(void){
	pin_write(116,1);
	set_motor_speed(10);
	pin_write(122,0);
	pin_write(123,1);
}
