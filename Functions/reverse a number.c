#include<stdio.h>
int reverse(int a){
int n=0;
while (a>0){
    n=n+(a%10);
    a=a/10;
    if (a!=0)
    n=n*10;
}
return n;
}
int main(){
int a;
printf("Enter the values");
scanf("%d",&a);
printf("%d",reverse(a));
}
