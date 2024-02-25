#include<stdio.h>
int m1,x,n2;
int mul(int a[m1][x],int b[x][n2]){
    int c[m1][n2];
    for(int i=0;i<m1;i++){
    for(int k=0;k<n2;k++){
            c[i][k]=0;
    }
}
    for (int i=0;i<m1;i++){
        for(int j=0;j<n2;j++){
            for(int k=0;k<x;k++){
                c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
            }
        }
    }
    for(int i=0;i<m1;i++){
        for(int j=0;j<n2;j++){
            printf("%2d",c[i][j]);
        }
    printf("\n");
    }
}
int main(){
    printf("Enter number of rows for first matrix: ");
    scanf("%d",&m1);
    printf("Enter number of columns for first matrix or number of rows of second matrix: ");
    scanf("%d",&x);
    printf("Enter number of columns for second matrix: ");
    scanf("%d",&n2);
    int a[m1][x],b[x][n2];
    printf("\nEnter the values for first matrix:");
    for (int i=0;i<m1;i++){
        for(int k=0;k<x;k++){
            printf("%d %d:",i,k);
            scanf("%d",&a[i][k]);
        }
    }
    printf("\nEnter the values for Second matrix:");
    for(int k=0;k<x;k++){
        for(int j=0;j<n2;j++){
            printf("%d %d:",k,j);
            scanf("%d",&b[k][j]);
        }
    }
    mul(a,b);
}
