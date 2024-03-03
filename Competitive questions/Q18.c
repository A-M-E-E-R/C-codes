#include<stdio.h>
int main(){
    int n,a,s;
    scanf("%d",&n);
    scanf("%d",&a);
    n*=a;
an:
    s=0;
    while(n){
        s+=n%10;
        n/=10;
    }
    if(s/10){
        n=s;
        goto an;
    }
    printf("%d",s);
}