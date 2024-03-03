#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n],min_legth;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&min_legth);
    int c=0,sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(c){
            c++;
        }
        if(sum>=min_legth){
            c++;
            sum=0;
        }
    }
    if(c==n-1) printf("\npossible");
    else printf("\nImPossible");
}