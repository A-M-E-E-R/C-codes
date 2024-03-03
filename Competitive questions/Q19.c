#include<stdio.h>
int main(){
    int N;
    scanf("%d",&N);
    int a[N];
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    int d;
    scanf("%d",&d);
    int X,x,fine=0;
    scanf("%d",&X);
    if(d%2) x=0;
    else x=1;
    for(int i=0;i<N;i++){
        if(a[i]%2==x)
            fine+=X;
    }
    printf("%d",fine);
}