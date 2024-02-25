#include<stdio.h>
int main(){
int *x=NULL,*y=NULL;
int a=10,b=20,sum;
x=&a;
y=&b;
sum = *x+*y;
printf("%d",sum);
}
