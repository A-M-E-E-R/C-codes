#include<stdio.h>
#include<string.h>
int main(){
char str[25];
printf("Enter the Sentence: ");
scanf("%[^\n]",str);
str[strlen(str)]='\0';
int i=0,v=0,c=0;
while (str[i]!='\0' || str[i]==' '){
        if(str[i]==' ')
            i++;
    if (str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
    v++;
    else
     c++;
     i++;
}
printf("\n %d is the count of Vowels in the String and %d is the count of Consonants",v,c);
}

