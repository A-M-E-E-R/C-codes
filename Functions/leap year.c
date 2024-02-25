#include<stdio.h>
void leap(int n){
    if(n%4==0){
        printf("%d is a leap year\n",n);
    }
    else if(n%100==0){
        printf("%d is a leap year\n",n);
    }
    else if(n%400==0){
        printf("%d is a leap year\n",n);
    }
    else
        printf("%d is not a leap year\n",n);
}
int main(){
int n;
printf("Enter the year to check: ");
scanf("%d",&n);
leap(n);
}
