#include<stdio.h>
int es(int n){
if(n==2)
    return 2;
if(n%2==1)
    n--;
return n+es(n-2);
}
int os(int n){
if(n==1)
    return 1;
if(n%2==0)
    n--;
return n+os(n-2);
}
int main(){
int n;
printf("Enter the limit: ");
scanf("%d",&n);
printf("\n1 -> find even sum \n2 -> find odd sum\nType: ");
int opt;
scanf("%d",&opt);
if(opt==1)
    printf("%d is even sum",es(n));
else if(opt==2)
    printf("%d is odd sum",os(n));
else
    printf("Invalid input");
}
