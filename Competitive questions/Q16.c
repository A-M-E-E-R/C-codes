#include<stdio.h>
#include<string.h>
int main(){
    char str[25];
    gets(str);
    int L;
    scanf("%d",&L);
    int n=strlen(str);
    int i=0,count=0;
    while(i<n){
        int j=i,c=0;
        for(;i<j+L && i<n;i++){
            if(str[i]=='a')
                c++;
        }
        if(c>count){
            count=c;
        }
    }
    printf("%d",count);
}