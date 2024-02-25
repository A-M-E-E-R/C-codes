#include<stdio.h>
int sum(int x,int y){
return x+y;
}
int dif(int x,int y){
return x-y;
}
int mul(int x,int y){
return x*y;
}
int div(int x,int y){
return x/y;
}
int main(){
int x,y;
ss:
printf("\nEnter two numbers: ");
scanf("%d %d",&x,&y);
int n;
printf("\nEnter 1 for doing Addition,2 for doing Subtraction,3 for doing Multiplication,4 for doing Division and anything other to Exit");
scanf("%d",&n);
if (n==1){
    printf("%d is sum",sum(x,y));
    goto ss;
}
if (n==2){
    printf("%d is difference",dif(x,y));
    goto ss;
}
if (n==3){
    printf("%d is product",mul(x,y));
    goto ss;
}
if (n==4){
    printf("%d is quotient",div(x,y));
    goto ss;
}
else{
    printf("bye bye...");
}
}
