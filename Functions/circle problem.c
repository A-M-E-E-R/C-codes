#include<stdio.h>
#define pi 3.14159
int dia(int r){
return r*2;
}
float circumfrn(int r){
return 2*pi*r;
}
float area(int r){
return pi*r*r;
}
int main(){
int r;
printf("Enter the Radius of the Circle: ");
scanf("%d",&r);
printf("\nDiameter=%d \nCircumference=%f \nArea=%f",dia(r),circumfrn(r),area(r));
}
