#include<stdio.h>
#include<string.h>
int main(){
    char a[4];
nn: 
    fflush(stdin);
    gets(a);
    int n,r;
    scanf("%d",&n);
    if(strcmp(a,"mon")==0) r=6;
    else if(strcmp(a,"tue")==0) r=5;
    else if(strcmp(a,"wed")==0) r=4;
    else if(strcmp(a,"thu")==0) r=3;
    else if(strcmp(a,"fri")==0) r=2;
    else if(strcmp(a,"sat")==0) r=1;
    else if(strcmp(a,"sun")==0) r=0;
    else{
        printf("Invalid.\
        do type:\
        sun, mon, tue, wed, thu, fri or sat");
        goto nn;
    }
    int c=0;
    if(n>r){
        c++;
        n-=r;
    }
    n/=7;
    c+=n;
    printf("\n%d",c);
}