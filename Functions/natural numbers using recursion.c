#include<stdio.h>
int nat(int n){
if(n==1){
return n;
}
printf("\n%d",n--);
return  nat(n);
}
int main(){
int n;
printf("Enter the number: ");
scanf("%d",&n);
printf("\n%d ",nat(n));
}
