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
    printf("The Number %d is prime",x);
else
printf("%d is not prime",x);
}
int main(){
int x;
printf("Enter the Number to check: ");
scanf("%d",&x);
prime(x);
}
