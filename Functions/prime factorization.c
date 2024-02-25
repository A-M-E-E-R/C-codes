#include<stdio.h>
int prime(int x){
    int c=0;
for (int i=2;i<x;i++){
    int r=x%i;
    if (r==0){
        c++;
        break;
    }
}
if (c==0 && x!=1 && x!=0)
   return x;
else
    return 0;
}
void factrz(int x){
for (int i=1;i<=x;i++){
    if(x%i==0){
        if(prime(i))
        printf(" %d",i);
    }
}
}
int main(){
int x;
printf("Enter the Number: ");
scanf("%d",&x);
factrz(x);
}
