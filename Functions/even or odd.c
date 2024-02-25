#include<stdio.h>
void evod(int x){
if(x%2==0)
    printf("%d is Even.",x);
else
    printf("%d is Odd.",x);
}
int main(){
int x;
printf("Enter the Number: ");
scanf("%d",&x);
evod(x);
}
