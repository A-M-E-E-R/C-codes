#include<stdio.h>
int power(int *x,int *y){
int r=1;
for (int i=1;i<=*y;i++){
    r=r*(*x);
}
return r;
}
int main(){
int x,y;
printf("Enter the Number: ");
scanf("%d",&x);
printf("Enter the power: ");
scanf("%d",&y);
printf("\n\n%d powered by %d is %d",x,y,power(&x,&y));
}
