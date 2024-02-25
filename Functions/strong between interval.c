#include<stdio.h>
int strong(int l,int n){
int i,original,sum,factorial;
for (i=1;i<=n;i++){
        original=i;
        int temp=i;
        sum=0;
        while (temp!=0){
        int k=temp%10;
        temp=temp/10;
        factorial = 1;
        for (int f=1;f<=k;f++){
        factorial = factorial *f;
        }
        sum = sum + factorial;
        }
if (sum==original){
printf("%d \n",sum);
}
}
}
int main(){
int l,u;
printf("Enter the starting number: ");
scanf("%d",&l);
printf("Enter the ending number: ");
scanf("%d",&u);
printf("The prime Numbers within the range %d-%d: ",l,u);
    strong(l,u);
}
