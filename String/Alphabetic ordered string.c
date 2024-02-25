#include<stdio.h>
#include<string.h>
int main(){
char a[100];
printf("Enter the String: ");
gets(a);
int n=strlen(a);
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(a[i]>a[j]){
            char t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
}
printf("%s",a);
}
