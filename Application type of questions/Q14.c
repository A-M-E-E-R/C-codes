#include<stdio.h>
int n=0,NUM=-1;
void swap(int *x,int *y){
    int t = *x;
    *x=*y;
    *y=t;
}
void by_3(int *a){
    for(int i=0;i<n;i++){
        int num=0,c=0;
        for(int j=0;j<n-i;j++){
            num*=10;
            num+=a[j];
            c++;
        }
        if(num%3==0){
            if(num>NUM){
                NUM=num;
                printf("\n%d",NUM);
            }
        }
    }
}
void permute(int *a,int l,int r){
    if(l==r){
        by_3(a);
    }
    for(int i=l;i<=r;i++){
        swap(&a[i],&a[l]);
        permute(a,l+1,r);
        swap(&a[i],&a[l]);
    }
}
int main(){
    int t;
    printf("Enter the number of test cases: ");
    scanf("%d",&t);
    while(t){
    printf("\nEnter the number of digits: ");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter the digits: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    permute(a,0,n-1);
    printf("\n Result = %d",NUM);
    t--;
    }
}
