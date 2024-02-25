#include<stdio.h>
int expo(int y){
int r=1;
for (int i=1;i<=y;i++){
    r=r*2;
}
return r;
}
int btod(int n){
    int c=0,d=0;
    while(n!=0){
        int r=n%10;
        d=d+r*expo(c++);
        n=n/10;
    }
    return d;
}
int main(){
int n;
printf("Enter the Binary Value: ");
scanf("%d",&n);
printf("%d is decimal value of %d",btod(n),n);
}
