#include<stdio.h>
int main(){
    int c=0;
    char a[100];
    printf("Enter the string: ");
    scanf("%[^\n]",a);
    char *p=a;
    while(*p!='\0'){
        c++;
        p++;
    }
    printf("String length = %d",c);
}
