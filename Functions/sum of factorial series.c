#include<stdio.h>
int fact (int x){
int f=1;
for (int i=1;i<=x;i++){
    f=f*i;
}
return f;
}
int main(){
printf("Enter the range to which sum shall be found: ");
int r,sum=0;
scanf("%d",&r);
for (int i=1;i<=r;i++){
    sum=sum+(fact(i)/i);
}
printf("The Sum of the series is: %d",sum);
}
