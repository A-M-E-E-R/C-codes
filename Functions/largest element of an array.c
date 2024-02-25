#include<stdio.h>
void large(int x[],int n){
int large = x[0];
for (int i=1;i<n;i++){
    if(large<x[i])
        large=x[i];
}
printf("%d is the Largest",large);
}
int main(){
    int n;
printf("Enter the number of elements of the array: ");
scanf("%d",&n);
int a[n];
printf("\n Now enter the elements\n");
for (int i=0;i<n;i++){
    printf("%dth element: ",i+1);
    scanf("%d",&a[i]);
}
large(a,n);
}
