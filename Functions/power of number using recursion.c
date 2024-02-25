#include<stdio.h>
int power(int n,int p){
if(p==0)
    return 1;
p--;
return n * power(n,p);
}
int main(){
int n,p;
printf("Enter the number: ");
scanf("%d",&n);
printf("Enter the power: ");
scanf("%d",&p);
printf("\n%d ",power(n,p));
}
