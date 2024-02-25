#include<stdio.h>
int main(){
int n;
printf("Enter the number of elements: ");
scanf("%d",&n);
int a[n];
printf("Enter the elements: ");
for (int i=0;i<n;i++){
    printf("\n%dth elements: ",i);
    scanf("%d",&a[i]);
}
int *p=a;
for (int i=0;i<n;i++){
    printf("\n%dth elements: ",i);
    printf("%d",*(p+i));
}
}
