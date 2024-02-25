#include<stdio.h>
int hcf(int,int);
int main(){
int n1,n2;
printf("Enter 2 Numbers: ");
scanf("%d %d",&n1,&n2);
printf("%d is the HCF of %d and %d",hcf(n1,n2),n1,n2);
}
int hcf(int x,int y){
if (y==0)
    return x;
int r=x%y;
x=y;
y=r;
return hcf(x,y);
}
