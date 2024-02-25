#include<stdio.h>
#include<string.h>
int main(){
    printf("Enter the string: ");
    char a[100];
    gets(a);
    a[strlen(a)]='\0';
char b[strlen(a)];
int c=strlen(a)-1;
for (int i=0;i<strlen(a);i++){
        b[c]=a[i];
        c--;
}
b[strlen(a)]='\0';
printf("%s",b);
}
