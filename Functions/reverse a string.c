#include<stdio.h>
#include<string.h>
void rev(char a[]){
char b[strlen(a)+1];
int c=strlen(a)-1;
for (int i=0;i<=strlen(a);i++){
        b[c]=a[i];
        c--;
}
b[strlen(a)]='\0';
printf("%s",b);
}
int main(){
    printf("Enter the string: ");
    char a[100];
    scanf("%s",a);
    a[strlen(a)]='\0';
rev(a);
}
