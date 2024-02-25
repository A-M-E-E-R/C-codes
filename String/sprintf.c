#include<stdio.h>
#include<string.h>
int main(){
int x=5;
char y;
char *z=&y;
sprintf(z,"%d",x);
printf("%c",y);
}
