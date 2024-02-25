#include<stdio.h>
int main(){
    int a,n,c=1;
    printf("\nEnter the number: ");
    scanf("%d",&a);//input for number
    printf("\nEnter the position: ");
    scanf("%d",&n);//input for position
    for(int i=1;i<n;i++){//setting all bits upto n
        c=c<<1;
        c|=1;
    }
    c=c&a;//copying upto n
    a=a>>n;//deleting upto n
    c=c<<(8-n);
    a=a|c;//making the result by adding
    printf("\n%d",a);
}
