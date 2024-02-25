#include<stdio.h>
int sqr(int x);
int main(){
int x;
printf("Enter the Number: ");
scanf("%d",&x);
printf("\nThe square of %d is %d",x,sqr(x));
}
int sqr(int x){
return x*x;
}
