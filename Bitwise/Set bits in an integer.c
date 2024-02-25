#include<stdio.h>
int main(){
    int n,a=1,c=0;
    printf("\nEnter the integer: ");
    scanf("%d",&n);
    while(a){
        if(a&n) c++;
        a<<=1;
    }
    printf("\nCount = %d",c);
}
