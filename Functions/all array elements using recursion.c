#include<stdio.h>
int m;
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
printf("%d ",disp(n,a));
}
int disp(int n,int a[]){
if (n-1==m){
        return a[m];
}
printf("%d ",a[m++]);
return disp(n,a);
}
