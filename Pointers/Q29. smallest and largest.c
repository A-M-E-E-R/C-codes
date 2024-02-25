#include<stdio.h>
int main(){
int n;
printf("Enter the number of elements: ");
scanf("%d",&n);
int a[n];
printf("\nEnter the elements: ");
for(int i=0;i<n;i++){
    printf("\n%dth element: ",i);
    scanf("%d",(a+i));
}
for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
    if(*(a+i)>*(a+j)){
        int t= *(a+i);
        *(a+i)=*(a+j);
        *(a+j)=t;
        }
}
}
printf("\n%d is the smallest element in the array.",a[0]);
printf("\n\n%d is the largest element in the array.",a[n-1]);
}
