#include<stdio.h>
#include<string.h>
char str[25],astr[25];
void anagrm(){
    int c=strlen(str),same=0;
    for (int i=0;i<strlen(str);i++){
        for (int k=0;k<strlen(str);k++){
            if(astr[k]!= '$'){
                if (str[i]==astr[k]){
                    astr[k]='$';
                    str[i]='@';
                    same++;
                }
            }
        }
    }
    if(same!=c)
        printf("\nThe 2 strings are not Anagram of each other");
    if(same==c)
        printf("\nThe entered strings are anagram of each other.");
}
int main(){
    int t;
    printf("\nEnter the number of test cases: ");
    scanf("%d",&t);
    while(t){
    printf("\nEnter the String of prepBuddy: ");
    scanf("%s",str);
    printf("\nEnter the String of Tina: ");
    scanf("%s",astr);
    str[strlen(str)]='\0';
    astr[strlen(astr)]='\0';
    if(strlen(str)==strlen(astr))
        anagrm();
    else
        printf("\nThe Entered strings are not Anagram...");
    t--;
    }
}
