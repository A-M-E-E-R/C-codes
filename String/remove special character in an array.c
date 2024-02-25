#include<stdio.h>
#include<string.h>
int main(){
char a[50];
printf("Enter the string: ");
gets(a);
int n=strlen(a);
for(int i=0;i<n;i++){
    if(a[i]>='0' && a[i]<='9')
        continue;
    else if(a[i]>='A' && a[i]<='Z')
        continue;
    else if(a[i]>='a' && a[i]<='z')
        continue;
    else{
        int j=i;
        while(i<n){
            a[i]=a[i+1];
            i++;
        }
        i=j;
}
}
printf("\n%s",a);
}
