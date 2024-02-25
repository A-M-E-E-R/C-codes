#include<stdio.h>
int arm(int x){
int temp=x,sum=0;
while(temp!=0){
    int r=temp%10;
    sum=sum+(r*r*r);
    temp=temp/10;
}
if (sum==x)
    return 1;
else
    return 0;
}
int perfect(int x){
int sum=0;
for (int i=1;i<x;i++){
    if (x%i==0)
        sum=sum+i;
    }
if(sum==x)
    return 1;
else
    return 0;
}
int main(){
int x;
printf("Enter the Number to check: ");
scanf("%d",&x);
if(arm(x)==1 && perfect(x)==1)
    printf("\n%d is both perfect and Armstrong number.",x);
else if((arm(x)==1 && perfect(x)!=1))
    printf("\n%d is not perfect and it is Armstrong number.",x);
else if((arm(x)!=1 && perfect(x)==1))
    printf("\n%d is perfect and not Armstrong number.",x);
else
    printf("%d is neither perfect nor Armstrong.",x);
}
