#include<stdio.h>
void swap(int x,int y){
int swap=x;
x=y;
y=swap;
printf("X is %d and Y is %d now",x,y);
}
int main(){
int x,y;
printf("Enter the values for x and y respectively: ");
scanf("%d %d",&x,&y);
swap(x,y);
}
