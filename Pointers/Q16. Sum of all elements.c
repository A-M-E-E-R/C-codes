#include<stdio.h>
int sum(int c[],int n){
int *a=c,sum=0;
for(int i=0;i<n;i++){
    sum=sum+*a;
    a++;
}
return sum;
}
int main(){
int n;
printf("Enter the Number of elements: ");
scanf("%d",&n);
int a[n];
printf("Enter the Numbers respectively: ");
for(int i=0;i<n;i++){
    printf("\n%dth element: ",i);
    scanf("%d",&a[i]);
}
printf("\n%d is the sum of all elements in the array",sum(a,n));
}
