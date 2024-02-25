#include<stdio.h>
int main(){
    int n,a=1,c=0;
    printf("\nEnter the integer: ");
    scanf("%d",&n);//input
    while(a){
        if(a&n) c++;//count increment if the result of the operation is 1
        a<<=1;//left shift by 1
    }
    if(c==1){//power of 2 only contains one bit set
        printf("%d is a power of 2",n);
    }
    else{
        printf("%d is not a power of 2",n);
    }
}
