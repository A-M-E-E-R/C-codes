#include<stdio.h>
#include<string.h>
int main(){
char a[100];
printf("Enter the string: ");
gets(a);
int n=strlen(a);
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(a[i]>a[j]){
            int temp = a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
}
printf("%s",a);
}
