#include<stdio.h>
#include<string.h>
int main(){
char m[30];
printf("Enter a Sentence: ");
scanf("%[^\n]",m);
if(m[0]>=97 || m[0]<=122){
            m[0]=m[0]-32;
        }
for (int i=0;i<strlen(m);i++){
    if (m[i]==' '){
        i++;
        if(m[i]>=97 || m[i]<=122){
            m[i]=m[i]-32;
        }
        }
}
printf("%s",m);
}
