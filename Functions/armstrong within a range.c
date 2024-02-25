#include<stdio.h>
int arm(int x){
int temp=x,sum=0;
while(temp!=0){
    int r=temp%10;
    sum=sum+(r*r*r);
    temp=temp/10;
}
if (sum==x)
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
printf("The Armstrong Number within the range %d-%d: ",l,u);
for (int i=l;i<=u;i++){
    if(arm(i))
    printf("%d ",i);
}
}
