#include<stdio.h>
int main(){
    int n,a=1<<7,c=0;// input variable, iteration variable and count variable
    printf("\nEnter the Number: ");
    scanf("%d",&n);
    while(a>0){//loop iterates till 0 (8 times maximum)
        if(n&a) break;
        else {
            c++; //count taken
            a>>=1;
        }
    }
    printf("\nCount = %d",c); // output printed on the screen
}
