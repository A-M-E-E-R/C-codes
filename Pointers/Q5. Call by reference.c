#include<stdio.h>
int sum(int *a,int *b){
int s=*a + *b;
return s;
}
int main(){
int a=5,b=6;
printf("%d is the sum\n",sum(&a,&b));
}
