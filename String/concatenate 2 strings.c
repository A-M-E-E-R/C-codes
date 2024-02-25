#include<stdio.h>
#include<string.h>
char s1[10],s2[25];
void conct();
int main(){
printf("Enter the First string: ");
gets(s1);
printf("Enter the Second string: ");
gets(s2);
printf("\nThe concatenated string is: ");
conct();
}
void conct(){
    int c=sizeof(s1)-strlen(s1)-1,d=strlen(s1);
for (int i=0;i<c;i++){
    s1[d+i]=s2[i];
}
printf("%s",s1);
}
