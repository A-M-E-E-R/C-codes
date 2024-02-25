#include<stdio.h>
int m=0;
int disp(int n,int a[]);
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
printf("%d is the sum",disp(n,a));
}
int disp(int n,int a[]){
if (n-1==m){
        return a[m];
}
m++;
return a[m-1]+disp(n,a);
}
