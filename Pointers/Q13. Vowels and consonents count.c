#include<stdio.h>
int main(){
char a[100];
printf("Enter the sentence: ");
scanf("%[^\n]",a);
char *p=a;
int v=0,c=0,s=0;
while(*p!='\0'){
    if(*p=='a'||*p=='A'||*p=='e'||*p=='E'||*p=='i'||*p=='I'||*p=='o'||*p=='O'||*p=='u'||*p=='U'){
        p++;
        v++;
    }
    else if(*p>='0'&&*p<='9'){
        p++;
        continue;
    }
    else if(*p==' '||*p=='.'||*p==','||*p=='"'||*p=='!'){
        p++;
        continue;
    }
    else{
        p++;
        c++;
    }
}
printf("\nThere are %d of Vowels and %d of Consonants",v,c);
}
