#include<stdio.h>
int n;
void swap(int s,int a[],int);
int main(){
printf("Enter the number of elements: ");
scanf("%d",&n);
int a[n];
for (int i=0;i<n;i++){
        printf("Enter the Element for %d position: ",i+1);
    scanf("%d",&a[i]);
}
printf("The position upto which the elements shall be swapped: ");
int s;
scanf("%d",&s);
swap(s,a,n);
for (int i=s;i<n;i++){
    printf("%d",a[i]);
}
}
void swap(int s,int a[],int n){
int temp;
for (int j=s-1,i=0;i<=(s-1)/2;i++,j--){
    temp = a[i];
    a[i]=a[j];
    a[j]=temp;
}
for (int i=0;i<=(s-1);i++){
    printf("%d",a[i]);
}
}
