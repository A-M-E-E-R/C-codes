#include<stdio.h>
int max(int *a,int *b){
if(*a>*b)
return *a;
else
    return *b;
}
int main(){
int a,b;
printf("Enter two numbers: ");
scanf("%d %d",&a,&b);
printf("%d is the maximum\n",max(&a,&b));
}
