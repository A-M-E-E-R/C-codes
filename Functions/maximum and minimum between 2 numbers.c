#include<stdio.h>
void maxmin(int *a,int *b){
if(*a>*b)
    printf("%d is Maximum and %d is Minimum",*a,*b);
else
    printf("%d is Maximum and %d is Minimum",*b,*a);
}
int main(){
printf("Enter 2 numbers: ");
int x,y;
scanf("%d %d",&x,&y);
maxmin(&x,&y);
}
