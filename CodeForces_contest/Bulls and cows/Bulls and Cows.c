#include<stdio.h>
int main(){
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    int x=4,r,R,bulls=0,cows=0,M=m,N=n;
    while(x){
        r=N%10;
        N/=10;
        R=M%10;
        M/=10;
        if(r==R) bulls++;
        x--;
    }
    for(int i=0;i<4;i++){
        r=n%10;
        n/=10;
        M=m;
        for(int j=0;j<4;j++){
            R=M%10;
            M/=10;
            if(r==R){
                cows++;
                break;
            }
        }
    }
    cows-=bulls;
    printf("%d %d",bulls,cows);
}