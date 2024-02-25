#include<stdio.h>
int perfect(int x){
int sum=0;
for (int i=1;i<x;i++){
    if (x%i==0)
        sum=sum+i;
    }
if(sum==x)
    return 1;
else
    return 0;
}
int main(){
int start,end;
printf("Enter the Starting number: ");
scanf("%d",&start);
printf("Enter the Ending number: ");
scanf("%d",&end);
for (int i=start;i<=end;i++){
 if(perfect(i)==1)
        printf("%d ",i);
}
}
