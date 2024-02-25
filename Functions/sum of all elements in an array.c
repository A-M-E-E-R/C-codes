#include<stdio.h>
int sum(int a[],int n){
int s=0;
for (int i=0;i<n;i++){
    s=s+a[i];
}
return s;
}
int main(){
    int n;
printf("Enter the number of Elements: ");
scanf("%d",&n);
printf("Enter the Numbers: ");
int a[n];
for (int i=0;i<n;i++){
    printf("\n%d: ",i+1);
    scanf("%d",&a[i]);
}
printf("\n%d is the sum of all elements.",sum(a,n));
}
