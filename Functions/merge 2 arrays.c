#include<stdio.h>
int sort(int a[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                int swap=a[i];
                a[i]=a[j];
                a[j]=swap;
            }
        }
    }
return *a;
}
int merge(int a[],int b[],int n,int m){
int merge[n+m];
int j=0;
for (int i=0;i<n;i++){
    merge[j++]=a[i];
}
for (int i=0;i<m;i++){
    merge[j++]=b[i];
}
sort(merge,m+n);
for (int i=0;i<m+n;i++){
    printf("%d ",merge[i]);
}
}
int main(){
int n,m;
printf("Enter the number of elements of first array: ");
scanf("%d  %d",&n,&m);
int a[n],b[m];
for (int i=0;i<n;i++){
    printf("%dth: ",i+1);
    scanf("%d",&a[i]);
}
sort(a,n);
printf("\n Enter the number of elements of second array: ");
for (int i=0;i<m;i++){
    printf("%dth: ",i+1);
    scanf("%d",&b[i]);
}
sort(b,m);
printf("\n");
merge(a,b,n,m);
}
