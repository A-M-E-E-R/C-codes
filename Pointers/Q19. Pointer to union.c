#include<stdio.h>
union p{
int a;
char b;
};
int main(){
union p x;
x.a=14;
union p *ptr=&x;
printf("%d ",ptr->a);
x.b='n';
printf("%c",ptr->b);
}
