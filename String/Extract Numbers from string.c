#include<stdio.h>
#include<string.h>
int main(){
    char a[100];
    printf("Enter the String: ");
    scanf("%s",a);
    int b[strlen(a)],k=0,c=0;
    a[strlen(a)]='\0';
    for (int i=0;i<strlen(a);i++){
        if('0'<=a[i]&&a[i]<='9'){
            printf("%d ",a[i]-48);
        }
        }
}
