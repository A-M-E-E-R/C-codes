#include<stdio.h>
int main(){
    char a[6];
    gets(a);
    int n=0;
    while(a[0]!=a[4]||a[1]!=a[3]){
        a[4]++;
        n++;
        if(a[3]=='5'&&a[4]==':'){
            a[1]++;
            a[3]='0';
            a[4]='0';
        }
        if(a[4]==':'){
            a[3]++;
            a[4]='0';
        }
        if(a[1]==':'){
            a[1]='0';
            a[0]++;
        }
        if(a[1]=='5'&&a[0]=='2'){
            a[1]='0';
            a[0]='0';
        }
    }
    printf("%d ",n);
}