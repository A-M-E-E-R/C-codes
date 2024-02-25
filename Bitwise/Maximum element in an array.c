#include<stdio.h>
int main(){
    int n=1<<7,a[7];//setting 8th bit
    printf("\nEnter the numbers: ");
    for(int i=0;i<7;i++){//taking input for the array
        printf("\n%dth: ",i+1);
        scanf("%d",&a[i]);
    }
    while(n){
        for(int i=0;i<7;i++){
            if(n&a[i]){//checking for bits at different position
                for(int j=0;j<7;j++){
                    if(a[j]&n || a[j]>n) continue;
                    a[j]=0;
                }
            }
        }
    n=n>>1;
    }
    for(int i=0;i<7;i++){
        if(a[i]) printf("\n%d",a[i]);
    }
}
