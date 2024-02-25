#include<stdio.h>
int main(){
    int t;
    printf("Enter the number of test cases: ");
    scanf("%d",&t);
    while(t){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int total=0,c=0;
    for(int i=0;i<n;i++){
        if(a[i]==1) c++;
        else c=0;
        if(c>total) total=c;
    }
    printf("\n%d",total);
    t--;
    }
}
