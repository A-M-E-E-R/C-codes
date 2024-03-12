#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t){
        int n,c=0;
        scanf("%d",&n);
        getchar();
        char a[n];
        for(int i=0;i<n;i++){
            a[i]=getchar();
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int k=i;
                while(k<=j){
                    if(a[k]=='1'){
                        c++;
                        k+=3;
                    }
                    else
                        k++;
                }
            }
        }
        printf("\n%d",c);
        t--;
    }
}
