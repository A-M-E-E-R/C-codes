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
    return 1;
else
    return 0;
}
int main(){
int l,u;
printf("Enter the starting number: ");
scanf("%d",&l);
printf("Enter the ending number: ");
scanf("%d",&u);
printf("The prime Numbers within the range %d-%d: ",l,u);
for (int i=l;i<=u;i++){
    if(prime(i))
    printf("%d ",i);
}
}
