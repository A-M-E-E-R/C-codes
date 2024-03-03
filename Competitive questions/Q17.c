#include<stdio.h>
int main(){
    int n,a=1;
    scanf("%d",&n);
    n--;
    while(n){
        a*=n;
        n--;
    }
    printf("%d",a*2);
}