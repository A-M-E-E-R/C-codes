#include<stdio.h>
int main(){
int n;
printf("Enter the number of elements: ");
scanf("%d",&n);
int a[n];
printf("Enter the Numbers respectively: ");
for(int i=0;i<n;i++){
    printf("\n%dth element: ",i);
    scanf("%d",&a[i]);
}
printf("\nThe elements in reverse order are: ");
int *w=a;
for(int i=1;i<=n;i++){
    printf("%d ",*(w+n-i));
}
}
