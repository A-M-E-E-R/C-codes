#include<stdio.h>
#include<string.h>
int main(){
char str[25];
printf("Enter the String: ");
scanf("%[^\n]",str);
str[strlen(str)]='\0';
char copy[strlen(str)];
for (int i=0;i<strlen(str);i++){
    copy[i]=str[i];
}
printf("\n \"%s\" is the copy of the string",copy);
}
