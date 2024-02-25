#include<stdio.h>
int fact(int *x){
int f=1;
for (int i=1;i<=*x;i++){
    f=f*i;
}
return f;
}
int main(){
int x;
printf("Enter the number: ");
scanf("%d",&x);
printf("\n%d!=%d",x,fact(&x));
}
