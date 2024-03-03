#include<stdio.h>
int main(){
    int x,y,sum=0,n,r;
    scanf("%d",&x);
    scanf("%d",&y);
    for(int i=x;i<=y;i++){
        n=2;
        r=0;
        while(n<i){
            if(i%n==0){
                r++;
                break;
            }
            n++;
        }
        if(r==0){
            sum+=i;
        }
    }
    printf("%d",sum);
}