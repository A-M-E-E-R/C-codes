#include<stdio.h>
int prime(int *n){
int rem;
for(int i=2;i<=*n;i++){
 rem=*n%i;
    if(rem==0&&i!=*n){
    printf("\n%d is not a prime Number",*n);
    break;
    }
    else if(rem==0&&i==*n){
    printf("\n%d is a prime Number",*n);
    }
}
}
int main(){
int n;
printf("Enter the number to check if it is prime: ");
scanf("%d",&n);
prime(&n);
}
