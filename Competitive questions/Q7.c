#include<stdio.h>
int main(){
    int N;
    scanf("%d",&N);
    int a[N];
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    printf("\n");
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(a[i]%2 && a[j]%2==0){
                int t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    for(int i=0;i<N;i++){
        printf(" %d",a[i]);
    }
}