#include<stdio.h>
int m=0,max,min;
void disp(int n,int a[]);
int main(){
printf("Enter the Number of elements ");
int n;

scanf("%d",&n);
printf("Enter the Elements of the array \n");
int a[n];
for(int i=0;i<n;i++){
        printf("%dth Element: ",i);
    scanf("%d",&a[i]);
}
min=a[0];
max=a[0];
disp(n,a);
}
void disp(int n,int a[]){
if (n==m){
printf("%d is minimum and %d is maximum",min,max);
return ;
}
if (min>a[m])
    min=a[m];

if (max<a[m])
    max=a[m];
m++;
return disp(n,a);
}
