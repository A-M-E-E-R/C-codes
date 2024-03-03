#include<stdio.h>
#include<string.h>
int main(){
     int N,r,i=0;
     printf("N= ");
     scanf("%d",&N);
     int  k;
     printf("\nEnter the base: ");
     scanf("%d",&k);
     char a[16];
     while(N){
        r=N%k;
        if(r>=0 && r<=9){
            a[i++]=48+r;
        }else{
            a[i++]=55+r;
        }
        N/=k;
     }
     a[i]='\0';
     int l= strlen(a);
     for(int i=l-1;i>=0;i--){
        printf("%c",a[i]);
     }
}