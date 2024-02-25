#include<stdio.h>
#include<string.h>
int z=1;
int itob(int x){//itob means integer to binary
int b=0,j=1,r;
while(x>0){
    r=x%2;
    b=b+(j*r);
    j=j*10;
    x=x/2;
}
return b;
}
/*float ftob(float x){//float to binary
    if(x==0.0) return 0.0;
    float f=0.0,i=1.0;
    while (x<1){
        i=i/10;
        z=z*10;
        x=x*2;
    }
    if(x>=1.0000)
        return 1.0*i;
}*/
float dtob(float x){
int y=x;
x=x-y;
return (itob(y));
}
int main(){
float x;
printf("Enter the Value: ");
scanf("%f",&x);
int n=dtob(x);
printf("%d\n",n);
int n1=n,c=0;
while(n1)
{
    c++;
    n1/=10;
}
char res[c];
for(int i=0;i<c;i++){
    int j=(n%10);
    res[i]=(char)j;
    n=n/10;
}
printf("%c",res[1]);
    for(int i=c-1;i>=0;i--){
        printf("%d",*(res+i));
    }
}
