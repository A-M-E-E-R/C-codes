#include<stdio.h>
int main(){
    int N;
    scanf("%d",&N);
    int price=1;
    while(N){
        price*=N%10;
        N/=10;
    }
    printf("%d",price);
}