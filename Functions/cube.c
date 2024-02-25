#include<stdio.h>
int cube(int n){
    int cube=n*n*n;
    return cube;
}
int main(){
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);
    printf("\nCube of %d is %d",n,cube(n));
}
