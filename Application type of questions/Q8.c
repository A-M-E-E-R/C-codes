#include<stdio.h>
int main(){
    int t;
    printf("Enter the number of test cases: ");
    scanf("%d",&t);
    while(t){
    int n,a,digits=0,an=0;
    printf("\nEnter the number: ");
    scanf("%d",&n);
    a=n;
    while(a/10!=0){
         int t=a,x=0,d,dn;
         while(t){
            digits++;
            t/=10;
         }
         t=a;
         while(t){
            d=t%10;
            t/=10;
            if(t) dn=t%10;
            else dn=0;
            if(dn<=d) x++;
         }
         if(digits==x){
            an=a;
            break;
         }
         digits=0;
         a--;
    }
    if(a/10==0)
        printf("\n%d",a);
    else
        printf("\n%d",an);
    t--;
    }
}
