#include<stdio.h>
int main(){
    int N;
    scanf("%d",&N);
    char a[N];
    fflush(stdin);
    gets(a);
    int c=0,count=0;
    char x=a[0];
    int B=0,E=0;
    for(int i=0;i<N;i++){
        if(x!=a[i]){
            B=i;
            break;
        }
    }
    for(int i=N-1;i>=0;i--){
        if(a[N-1]!=a[i]){
            E=i;
            break;
        }
    }
    x=a[B];
    for(int i=B;i<=E;i++){
        if(x==a[i]){
            c++;
        }
        else{
            x=a[i];
            c=1;
        } 
        if(c>count){
            count=c;
        }
    }
    printf("\n%d",count);
}