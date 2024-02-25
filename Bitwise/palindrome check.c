#include<stdio.h>
int main(){
    int n,a1,a2,c=4;
    printf("\nEnter the Number: ");
    scanf("%d",&n);
    for(int i=0;i<4;i++){
        a1=128>>i;
        a2=1<<i;
        if(!(!(n&a1))==!(!(n&a2))) c--;
    }
    printf("%d",c);
    if(c) printf("\nBits of %d is not palindrome",n);
    else printf("\nBits of %d is palindrome",n);
}
