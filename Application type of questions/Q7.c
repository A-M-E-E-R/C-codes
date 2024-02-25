#include<stdio.h>
#include<string.h>
int main(){
    int t;
    printf("Enter the number of test cases: ");
    scanf("%d",&t);
    while(t){
    char s[20],t[20];
    printf("\nEnter the string S: ");
    getchar();
    gets(s);
    printf("\nEnter the string t: ");
    gets(t);
    int l1=strlen(s),l2=strlen(t),c1=0,c2=0,j=0;
    for(int i=0;i<l1;i++){
        if(s[i]=='+'){
            if(t[j]=='+'){
                c2++;
                c1++;
                j++;
            }
            else if(t[j]=='-' && t[j+1]=='-'){
                c2+=2;
                c1++;
                j+=2;
            }
        }
        else if(s[i]=='-'){
            if(t[j]=='-'){
                c2++;
                c1++;
                j++;
            }
        }
    }
jj:
    if(c1==l1 && c2==l2){
        printf("\nYes");
    }
    else{
        printf("\nN0");
    }
    t--;
    }
}
