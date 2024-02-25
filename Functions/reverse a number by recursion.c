#include<stdio.h>
int rev(int n){
if(n/10==0)
    return n%10;
printf("%d",n%10);
return rev(n/10);
}
int main(){
int n;
printf("Enter the Number: ");
scanf("%d",&n);
printf("%d",rev(n));
}
