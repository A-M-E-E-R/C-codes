#include<stdio.h>
#include<string.h>
int main(){
char a[100];
printf("Enter the String: ");
gets(a);
int n=strlen(a);
for(int i=0;i<n;i++){
     if(a[i-1]==' ' || i==0){
        printf("%c",a[i]);
     }
}
}
