#include<stdio.h>
int sort(int c[],int n){
int *a=c;
for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
    if(*(a+i)>*(a+j)){
        int t= *(a+i);
        *(a+i)=*(a+j);
        *(a+j)=t;
        }
}
}
}
int main(){
int n;
printf("Enter the Number of elements: ");
scanf("%d",&n);
int a[n];
printf("Enter the Numbers respectively: ");
for(int i=0;i<n;i++){
    printf("\n%dth element: ",i);
    scanf("%d",&a[i]);
}
sort(a,n);
int k;
printf("\nEnter the ordered position of the number to be printed: ");
scanf("%d",&k);
printf("\n%dth smallest element is: ",k);
printf("%d",a[k-1]);
}

