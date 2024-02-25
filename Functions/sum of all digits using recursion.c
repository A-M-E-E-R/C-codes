#include<stdio.h>
int s;
int sum(int n){
if (n/10==0)
    return s+n%10;
s=s+n%10;
return sum(n/10);
}
int main(){
int n;
printf("Enter the Number: ");
scanf("%d",&n);
printf("%d is the sum",sum(n));
}
