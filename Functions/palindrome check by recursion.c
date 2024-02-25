#include<stdio.h>
 int sum=0;
int pal(int n){
if(n/10==0)
    return sum*10 + n%10;
sum=sum*10+n%10;
return pal(n/10);
}
int main(){
int n;
printf("Enter the Number: ");
scanf("%d",&n);
if(n==pal(n))
    printf("\n%d is a palindrome",n);
else
    printf("\n%d is not a palindrome",n);
}
