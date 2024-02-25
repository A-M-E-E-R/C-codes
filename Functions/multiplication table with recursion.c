#include<stdio.h>
int num=0;
void func(int n,int limit)
{
    if (num>limit)
        return;
    else {
        printf("%d x %d = %d \n",n,num,n*num);
        num++;
        return func(n,limit);
    }
}
int main()
{
    int n,g;
    printf("Enter the table \n");
    scanf("%d",&n);
    printf("Enter the limit \n");
    scanf("%d",&g);
    printf("Table of %d \n",n);
    func(n,g);
    return 0;
}
