#include<stdio.h>
int sum(int n){
if (n==1)
    return 1;
return n-- + sum(n);
}
int main(){
int n;
printf("Enter the limit: ");
scanf("%d",&n);
printf("%d",sum(n));
}
