#include<stdio.h>
int odev(int n,int m){
if(n==m){
    if(m%2==0){
        printf("\n%d is even",m);
        }
    else{
        printf("\n%d is odd",m);
        }
        return 0;
}
if(n%2==0){
    printf("\n%d is even",n);
}
else if(n%2==1){
    printf("\n%d is odd",n);
}
n++;
return odev(n,m);
}
int main(){
int n,m;
printf("Enter the lower limit and upper limit: ");
scanf("%d  %d",&n,&m);
odev(n,m);
}
