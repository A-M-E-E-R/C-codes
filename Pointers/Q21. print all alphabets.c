#include<stdio.h>
int main(){
int x=65;
int *p=&x;
do{
    printf("%c ",*p);
    x++;
}while(*p<=90);
}
