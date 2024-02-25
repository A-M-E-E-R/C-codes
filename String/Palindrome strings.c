#include<stdio.h>
#include<string.h>
int main(){
char a[100];
printf("Enter the Word: ");
scanf("%s",a);
int c=strlen(a)-1,d=0;
for (int i=0;i<strlen(a)/2;i++){
    if(a[c]!=a[i]){
        d++;
        break;}
        c--;
}
if(d==0)
    printf("1");
else
    printf("0");
}
