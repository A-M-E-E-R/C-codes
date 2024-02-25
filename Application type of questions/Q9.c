#include<stdio.h>
#include<string.h>
char str[25],astr[25];
int main(){
    int t;
    printf("Enter the number of test cases: ");
    scanf("%d",&t);
    while(t){
    int x=0,c=0;
    printf("Enter the String S: ");
    scanf("%s",str);
    printf("Enter the String T: ");
    scanf("%s",astr);
    str[strlen(str)]='\0';
    astr[strlen(astr)]='\0';
    int lt=strlen(astr);
    for(int i=0;i<lt;i++){
        for(int j=0;j<lt;j++){
            if(astr[i]==str[j]){
                str[i]='*';
                x=4;
                break;
            }
        }
        if(x!=4){
            astr[i]='#';
        }
        x=0;
    }
    for(int i=0;i<lt;i++){
        for(int j=0;j<lt;j++){
            if(astr[i]=='#' && str[j]!='*'){
               c++;
               astr[i]=str[j];
            }
        }
    }
    printf("\n%d",c);
    t--;
    }
}

