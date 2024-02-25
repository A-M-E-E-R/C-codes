#include<stdio.h>
struct p{
int a;
char b;
};
int main(){
struct p x;
x.a=14;
x.b='n';
struct p *ptr=&x;
printf("%d %c",ptr->a,ptr->b);
}
