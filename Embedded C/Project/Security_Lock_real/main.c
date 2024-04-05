#include<lpc214x.h>
#include<string.h> 
#include"C:\\Users\\IDEAPAD\\OneDrive\\Desktop\\projects\\Keil\\Project\\Calculator\\keypad_math.h"
#include"C:\\Users\\IDEAPAD\\OneDrive\\Desktop\\projects\\Keil\\Header_Files\\Basic_Functions\\Functions.h"
#include"lcd.h"
int main(){
	unsigned char mykey,password[5]={"7536"},pass[5],ID1[4]={'+','+','+'},ID2[4]={'-','*','-'},ID3[4]={'/','*','/'},ID[4];
	short int i,c=3;
	initLCD();
Try:
		clear();
	i=0;
	enter(); //display enter password
	memset(pass, '\0', sizeof(pass));
	while(1){
		mykey=getKeypad();
		if(mykey!='x'){
			if(mykey=='.'){// (ON/C) to reset
				enter_id();
				c=3;
				memset(ID, '\0', sizeof(ID));
				while(1){
					mykey=getKeypad();
					if(mykey!='x'){
						LCDdata(mykey);
						ID[i]=mykey;
						i++;
						if(i>2){
re:
							i=0;
							if(strncmp((const char *)&ID,(const char *)&ID1,3)==0||strncmp((const char *)&ID,(const char *)&ID2,3)==0||strncmp((const char *)&ID,(const char *)&ID3,3)==0){//id check
							delayms(10);
							clear();	
							change();
								c=3;
								while(1){//password changer
									mykey=getKeypad();
										if(mykey!='x'){
											if(mykey!='.'&&mykey!='-'&&mykey!='+'&&mykey!='*'&&mykey!='/'&&mykey!='='){
												LCDdata(mykey);
												password[i++]=mykey;
												if(i>3){
													delayms(10);
													clear();
													okay();
													while(1){
														mykey=getKeypad();
														if(mykey!='x'){//confirm reset
															if(mykey=='=') {
																clear();
																LCDprint("RESET");
																LCDcommand(0xc0);
																LCDprint("SUCCESSFUL");
																goto Try;
															}
															else goto re;// Re enter the new password
														}
													}
												}
											}
										}
									}
								}
								else{
										wrong_id();
										goto Try;
								}
							}
						}
					}
				}
				else if(mykey!='.'&&mykey!='-'&&mykey!='+'&&mykey!='*'&&mykey!='/'&&mykey!='='){
					LCDdata('*');//password covered display
					pass[i]=mykey;//entered password stored in pass to compare
					i++;
				}
				if(i>3){
					delayms(10);
					clear();
					i=0;
					if(strncmp((const char *)&pass,(const char *)&password,4)==0){//password comparison
						granted();
						c=3;
						goto Try;
					}
					else {
						c--;
						if(c>0) {//try 3 times
							TRY();
							goto Try;
						}
						else{//access denied
							denied();
							c=3;
							goto Try;
						}
					}
				}
			}
		}
}

