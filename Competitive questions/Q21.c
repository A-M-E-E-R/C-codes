#include<stdio.h>
int main(){
    int N;
    scanf("%d",&N);
    int a[N];
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    int c;
    for(int i=0;i<N;i++){
        if(a[i]==322)
            continue;
        printf("\n%d occurs ",a[i]);
        c=1;
        for(int j=i+1;j<N;j++){
            if(a[i]==a[j]){
                a[j]=322;
                c++;
            }
        }
        printf("%d times",c);
    }
}