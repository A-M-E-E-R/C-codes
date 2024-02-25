#include<stdio.h>
#include<string.h>
char ms[20];
void subS();
int main(){
printf("Enter the Sentence: ");
gets(ms);
ms[strlen(ms)]='\0';
subS();
}
void subS(){
    int c=0;
printf("Enter the string: ");
char s[10];
gets(s);
s[strlen(s)]='\0';
for (int i=0;i<strlen(s);i++){
    int j=0;
    c=0;
    while (s[i]!=ms[j])
        j++;
    while(s[i]==ms[j]){
        i++;
        j++;
        c++;
    }
        if (c==strlen(s)){
            printf("The Sub string is present");
            c=100;
            break;
        }
        else {
            i=i-c;
            c=0;
        }
}
if (c!=100)
    printf("Substring not present");
}
