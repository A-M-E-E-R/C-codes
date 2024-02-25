#include<stdio.h>
void prime(int x){
    int c=0;
for (int i=2;i<x;i++){
    int r=x%i;
    if (r==0){
        c++;
        break;
    }
}
if (c==0 && x!=1 && x!=0)
   printf("\n%d is prime number",x);
else
   printf("\n%d is not prime number",x);
}
void perfect(int x){
int sum=0;
for (int i=1;i<x;i++){
    if (x%i==0)
        sum=sum+i;
    }
if(sum==x)
    printf("\n%d is perfect number",x);
else
   printf("\n%d is not perfect number",x);
}
void arm(int x){
int temp=x,sum=0;
while(temp!=0){
    int r=temp%10;
    sum=sum+(r*r*r);
    temp=temp/10;
}
if (sum==x)
     printf("\n%d is Armstrong number",x);
else
   printf("\n%d is not Armstrong number",x);
}
int main(){
printf("Enter the number to check: ");
int n;
scanf("%d",&n);
prime(n);
arm(n);
perfect(n);
}
