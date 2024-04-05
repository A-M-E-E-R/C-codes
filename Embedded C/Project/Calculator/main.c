 #include<stdlib.h>
 #include<stdio.h>
 #include"timer.h"
 #include<string.h>
 #include"C:\\Users\\IDEAPAD\\OneDrive\\Desktop\\projects\\Keil\\Project\\Calculator\\arith_math.h"
 #include<lpc214x.h>
 #include"C:\\Users\\IDEAPAD\\OneDrive\\Desktop\\projects\\Keil\\Header_Files\\Basic_Functions\\Functions.h"
 #include"keypad_math.h"
 #include"C:\\Users\\IDEAPAD\\OneDrive\\Desktop\\projects\\Keil\\Header_Files\\lcd.h"
int main(){
	unsigned char mykey,sign;  
	short int i=0,c=0,f=0;
	unsigned int X,Y,R;
	unsigned char x[15], y[15],r[16];
	initLCD();
	while(1){
		mykey=getKeypad();
		if(mykey=='.'){
			LCDcommand(0x0c);
			LCDdata('W');
			LCDdata('E');
			LCDdata('L');
			LCDdata('C');
			LCDdata('O');
			LCDdata('M');
			LCDdata('E');
			
			goto jjj;
		}
	}
	while(1)
	{
jjj:
	mykey=getKeypad();
	if(mykey!='x')
		{
		if(mykey=='=') goto jj;
		if(mykey=='.') goto jump;
		if((mykey=='+'||mykey=='-'||mykey=='*'||mykey=='/')&&f==1) continue;
		LCDdata(mykey);
jj:
		if(mykey!='+'&&mykey!='-'&&mykey!='*'&&mykey!='/'&&mykey!='='&&c==0){
			*(x+i)=mykey;
			i++;
		}
		else if(mykey=='+'||mykey=='-'||mykey=='*'||mykey=='/'){
			c=1;
			f=1;
			x[i]='\0';
			i=0;
			sign=mykey;
			LCDcommand(0xC0); 
		}
		else if(mykey!='+'&&mykey!='-'&&mykey!='*'&&mykey!='/'&&mykey!='='&&c==1){
			*(y+i)=mykey;
			i++;
		}
		else if(mykey=='='){
			y[i]='\0';
			X = atoi(x);
			Y = atoi(y);
			if(sign=='+'){
				R=add(X,Y);
			}
			else if(sign=='-'){
				R=sub(X,Y);
			}
			else if(sign=='*'){
				R=mul(X,Y);
			}
			else if(sign=='/'){
				R=Div(X,Y);
			}
			if(sign!='+'&&sign!='-'&&sign!='*'&&sign!='/'){
				R=X;
			}
			break;
		}
		delayms(20);
		}
	}
	sprintf(r,"%d",R);
	LCDdata('.');//clear
	LCDcommand(0xC0);//second line
	for(c=0;c<16;c++){
		LCDdata(r[c]);
	}
	while(1){
		mykey=getKeypad();
		if(mykey=='.'){
jump:
			LCDdata('.');
			i=0;
			c=0;
			f=0;
			sign = '\0';
			memset(x, '\0', sizeof(x));
			memset(y, '\0', sizeof(y));
			memset(r, '\0', sizeof(r));
			goto jjj;
		}
	}
}