#include<stdio.h>
#include<string.h>
int main(){
char a[100];
printf("Enter the string: ");
gets(a);
printf("\nThe words reversed order: \n\n");
for(int i=strlen(a);i>=0;i--){
    if(a[i--]=='\0'){
            int j=0;
           char b[10];
        while(*(a+i)!=' '){
            *(b+j)=*(a+i);
            if(i<0)
                break;
            i--;
            j++;
        }
        b[j]='\0';
        for(int k=strlen(b);k>=0;k--){
            printf("%c",*(b+k));
        }printf(" ");
    }
    a[i++]='\0';
}
printf("\n");
}
