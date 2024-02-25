#include<stdio.h>
int main(){
int n,d,c=0;
printf("Enter the Number of elements of array : ");
scanf("%d",&n);
int a[n];
printf("Enter %d Elements: ",n);
for (int i=0;i<n;i++){
    printf("\n%dth element: ",i);
    scanf("%d",&a[i]);
}
printf("\nEnter the position of the element to be deleted: ");
scanf("%d",&d);
for (int i=0;i<n;i++){
    if(*(a+i)==d){
        c++;
    }
}
int f[n-c],k=0;
for(int i=0;i<n;i++){
    if(*(a+i)!=d){
        f[k]=*(a+i);
        k++;
    }
}
printf("\n\nThe array without the occurrence of %d are ",d);
for(int i=0;i<(n-c);i++){
    printf("%d ",f[i]);
}
}
