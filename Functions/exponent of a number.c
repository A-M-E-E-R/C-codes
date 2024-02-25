#include<stdio.h>
int exponent(int x,int y){
int r=1;
for (int i=1;i<=y;i++){
    r=r*x;
}
return r;
}
int main(){
int x,y;
printf("Enter the Number: ");
scanf("%d",&x);
printf("Enter the power: ");
scanf("%d",&y);
printf("The exponent = %d",exponent(x,y));
}
