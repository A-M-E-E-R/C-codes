#include<stdio.h>
#include<string.h>
int main(){
char a[100],b[100],*p=NULL;
printf("Enter the string: ");
gets(a);
printf("Enter the sub-string to be checked: ");
gets(b);
int n=strlen(a),m=strlen(b),o=0;
    for(int i=0;i<n;i++){
        int j=0;
            while(a[i]==b[j] && i<n){
                o++;
                i++;
                j++;
            }
            if(o==m){
                p=&a[i-m];
                printf("%s",p);
                break;
            }
            else
                o=0;
        }
if(o==0){
    printf("it won't work bro!!");
}
}

