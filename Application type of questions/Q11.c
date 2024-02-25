#include<stdio.h>
#include<string.h>
int main(){
    int t;
    printf("Enter the number of test cases: ");
    scanf("%d",&t);
    while(t){
    char a[7];
    printf("\nEnter the string of digits: ");
    getchar();
    gets(a);
    int n=0,l=strlen(a);
    for(int i=0;i<l;i++){
        if((a[i+1]<=a[i] || (a[i+1]!=a[i]+1) && n )&& i+1!=l){
            n=0;
            break;
        }
        if(a[i+1]!=a[i]+1 && i+1!=l){
            n=a[i]+1;
        }
    }
    if(n){
        printf("\n%c",n);
    }
    else{
        printf("\nInvalid string...");
    }
    t--;
    }
}
