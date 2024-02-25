/*write a program to print numbers from 1 to 10 in
such a way that when number is odd add 1 and when number
is even substract 1*/
#include<stdio.h>
void odd (int n){
if (n>10)
    return;
printf("%d ",n+1);
even(n+1);
}
void even (int n){
if (n>10)
    return;
printf("%d ",n-1);
odd(n+1);
}
int main(){
odd(1);
}
