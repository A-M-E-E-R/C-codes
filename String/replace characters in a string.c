#include<stdio.h>
#include<string.h>
int main(){
char str[25],w,rplc;
printf("Enter the String: ");
scanf("%[^\n]",str);
getchar();
printf("\n Enter the Character in the sentence to be replaced: ");
w=getchar();
getchar();
printf("\n Enter the Character to be replaced with: ");
rplc=getchar();
getchar();
str[strlen(str)]='\0';
int i=0;
while (str[i]!='\0'){
    if(str[i]==w)
        str[i]=rplc;
    i++;
}
printf("\n %s is the new string",str);
}
