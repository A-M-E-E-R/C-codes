#include<stdio.h>
int minmax[2];
int minmax1(int x[],int n){
int large = x[0],small=x[0];
for (int i=1;i<n;i++){
    if(large<x[i])
        large=x[i];
}
for (int i=1;i<n;i++){
    if(small>x[i])
        small=x[i];
}
minmax[0]=small;
minmax[1]=large;
return *minmax;
}
int main(){
    int n;
printf("Enter the Number of Elements: ");
scanf("%d",&n);
int x[n];
printf("Enter the Elements: ");
for (int i=0;i<n;i++){
    printf("\n %dth :",i+1);
    scanf("%d",&x[i]);
}
minmax1(x,n);
printf("%d is minimum and %d is maximum",minmax[0],minmax[1]);
}
