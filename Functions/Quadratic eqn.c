#include<stdio.h>
#include<math.h>
void qdrtc(int a,int b,int c){
double x1,x2;
double B=b;
if((pow(B,2)-(4*a*c))>=0){
x2=(-b-sqrt(pow(B,2)-(4*a*c)))/(2*a);
x1=(-b+sqrt(pow(B,2)-(4*a*c)))/(2*a);
printf(" %lf, %lf",x1,x2);
}
else{
x2=(-b-sqrt((pow(B,2)-(4*a*c))*-1))/(2*a);
x1=(-b+sqrt((pow(B,2)-(4*a*c))*-1))/(2*a);
printf(" %lf+i, %lf-i",x1,x2);
}
}
int main(){
    int a,b,c;
printf("Enter the values for a,b,c for the equation (ax^2+bx+c=0)\n");
printf("\na=");
scanf("%d",&a);
printf("\nb=");
scanf("%d",&b);
printf("\nc=");
scanf("%d",&c);
printf("\nthe solutions for (%dx^2 + %dx + %d = 0) are ",a,b,c);
qdrtc(a,b,c);
}
