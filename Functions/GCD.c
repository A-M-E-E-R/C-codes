#include<stdio.h>
int GCD(int x,int y){
if (y>x){
    int c=y;
    y=x;
    x=c;
}
    while(y!=0){
        int r=x%y;
        x=y;
        y=r;
    }
return x;
}
int main(){
int x,y;
printf("Enter 2 numbers \n");
scanf("%d %d",&x,&y);
printf("GCD of %d and %d is %d",x,y,GCD(x,y));
}
