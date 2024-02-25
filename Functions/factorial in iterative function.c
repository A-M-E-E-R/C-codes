#include<stdio.h>
int factorial(int n){
int mul=1;
for (int i=1;i<=n;i++){
    mul=mul*i;
}
return mul;
}
int main(){
printf("Enter the Number: ");
int n;
scanf("%d",&n);
printf("\n%d!=%d",n,factorial(n));
}
