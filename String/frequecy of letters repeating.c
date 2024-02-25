#include<stdio.h>
#include<string.h>
int main(){
char s[30];
printf("Enter the String: ");
scanf("%[^\n]",s);
s[strlen(s)]='\0';
for (int i=0;i<strlen(s);i++){
    int c=1;
    for(int j=i+1;j<strlen(s);j++){
        if(s[i]!='$'){
            if(s[i]==s[j]){
                c++;
                s[j]='$';
                }
            }
            }
    if(s[i]!='$'){
            printf("%c prints %d times\n",s[i],c);
        }
    }
}
