#include<stdio.h>
#include<string.h>
int main(){
    char s[100],t[10];
    printf("\nEnter the main string: ");
    gets(s);
    fflush(stdin);
    printf("\nEnter the sub: ");
    gets(t);
    int ls=strlen(s),lt=strlen(t),c=0,j=0;
    for (int i = 0; i < ls; i++)
    {
        if(s[i]==t[j]){
            j++;
        }
        if(j==lt){
            j=0;
            c++;
        }
    }
    printf("%d",c);
}