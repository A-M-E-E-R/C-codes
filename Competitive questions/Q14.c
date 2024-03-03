#include<stdio.h>
int main(){
    int N;
    scanf("%d",&N);
    int a[N];
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    int c=1;
    for(int i=1;i<N;i++){
        if(a[i-1]<a[i])
            c++;
    }
    printf("%d",c);
}