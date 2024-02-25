#include<stdio.h>
#include<string.h>
int main(){
    int n=0,x=0;
char a[]="abccdxxxzyz",b[100];
for (int i=0;i<strlen(a);i++){
        int c=0;
    for (int j=0;j<x;j++){
        if(a[i]==b[j] && i!=j)
            c++;
    }
    if(c==0)
    b[x++]=a[i];
    }
printf("%s",b);
}

