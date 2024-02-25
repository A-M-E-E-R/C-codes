#include<stdio.h>
int main(){
    int n,a=1,c=0;;// variable :- input variable, operation variable and count
    printf("\nEnter the number: ");
    scanf("%d",&n);
    while(a<=128){// loops goes till 1000 0000
        if(n&a)break;
        else{
            c++;
            a<<=1;
        }
    }
    printf("Count = %d ",c);//the count is printed on screen
}
