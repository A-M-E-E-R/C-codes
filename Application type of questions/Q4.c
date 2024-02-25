#include<stdio.h>
#include<string.h>
int main(){
    int t;
    printf("Enter the number of test cases: ");
    scanf("%d",&t);
    getchar();
    while(t){
    char ms[20];
    printf("Enter the main String: ");
    gets(ms);
    ms[strlen(ms)]='\0';
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
            printf("YES... ");
            c=999;
            break;
        }
        else {
            i=i-c;
            c=0;
        }
    }
    if (c!=999)
        printf("NO... ");
    t--;
    }
}
