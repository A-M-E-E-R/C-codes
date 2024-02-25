#include<stdio.h>
int main(){
    int a,n=0;
    printf("\nEnter the number: ");
    scanf("%d",&a);
    int c=0,x;
    while(c!=8){
        if(a&(1<<c)) n|=(1<<(7-c));
        c++;
    }
    printf("\n%d",n);
}

