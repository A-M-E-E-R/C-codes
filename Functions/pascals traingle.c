#include<stdio.h>
int fact(int n){
    int mul=1;
    for (int i=1;i<=n;i++){
        mul=mul*i;
    }
    return mul;
}
void pscls(int n){
    int m;
    m=n;
    for(int i=0;i<n;i++){
        for (int j=0;j<=m;j++){
            printf("  ");//2 spaces
        }
        for(int j=0;j<=i;j++){
            printf("%3d ",fact(i)/(fact(j)*fact(i-j)));
        }
        printf("\n");
        m--;
    }
}
int main(){
    int n;
    printf("Enter the Number of Rows for the Triangle \n");
    scanf("%d",&n);
    pscls(n);
}
