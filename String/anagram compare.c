#include<stdio.h>
#include<string.h>
char str[25],astr[25];
void anagrm();
int main(){
printf("Enter the String: ");
scanf("%s",str);
printf("Enter the String: ");
scanf("%s",astr);
str[strlen(str)]='\0';
astr[strlen(astr)]='\0';
if(strlen(str)==strlen(astr))
    anagrm();
else
    printf("Enter a valid input");
}
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
        printf("The 2 strings are not Anagram of each other");
    if(same==c)
        printf("The entered strings are anagram of each other.");
}
