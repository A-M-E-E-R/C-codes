#include<stdio.h>
void inter(int a[],int b[],int n,int m){
    int *x=a,*y=b,k=0;
    if(n>m){
        int o=n;
        n=m;
        m=o;
    }
   for(int i=0;i<n;i++){
    if(*(a+i)==*(b+i)){
        printf("%d",*(a+i));
        break;
    }
    }
}
int main(){
int n;
printf("Enter the number of elements for 1st array: ");
scanf("%d",&n);
int a[n];
printf("\nEnter the elements of the array: \n");
for(int i=0;i<n;i++){
    printf("\n%dth element: ",i);
    scanf("%d",&a[i]);
}
int m;
printf("Enter the number of elements for 2nd array: ");
scanf("%d",&m);
int b[m];
printf("\nEnter the elements of the array: \n");
for(int i=0;i<m;i++){
    printf("\n%dth element: ",i);
    scanf("%d",&b[i]);
}
printf("\n\nThe intersection of the 2 arrays is: ");
inter(a,b,n,m);
}
