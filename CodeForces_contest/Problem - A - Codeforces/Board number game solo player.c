#include<stdio.h>
int min(int x,int y){
    if(x<y) return x;
    else return y;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t){
        int n;
        //printf("\nEnter the value of n: ");
        scanf("%d",&n);
        int a[2*n];
        for(int i=0;i<2*n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=0;i<2*n;i++){
            for(int j=i+1;j<2*n;j++){
                if(a[i]>a[j]){
                    int t=a[i];
                    a[i]=a[j];
                    a[j]=t;
                }
            }
        }
        int sum=0;
        for(int i=0;i<2*n;i+=2){
            sum+=min(a[i],a[i+1]);
        }
        printf("%d",sum);
        t--;
    }
}
