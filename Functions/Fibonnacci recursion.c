#include<stdio.h>
int count=1,x=0,y=1;
int fbncci(int);
int main(){
    int pos;
    printf("The position of the number to be printed in Fibonacci Series: ");
    scanf("%d",&pos);
    printf("%dth Number is %d",pos,fbncci(pos));
}
int fbncci(int pos){
    int s=x+y;
    if (pos==0)
        return x;
    if (pos==1)
        return y;
    count++;
    x=y;
    y=s;
    if (count==pos)
        return y;
    return fbncci(pos);
}
