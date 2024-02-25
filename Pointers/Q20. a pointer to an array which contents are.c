#include<stdio.h>
struct book{
char title[18];
char author[15];
int year;
};
int main(){
struct book s[5];
for(int i=0;i<5;i++){
    printf("Enter the title of Book %d: ",i+1);
    scanf("%s",s[i].title);
    printf("Enter the Author of the book %d: ",i+1);
    scanf("%s",s[i].author);
    printf("Enter the Year of Publication %d: ",i+1);
    scanf("%d",&s[i].year);
    printf("\n");
}
struct book *p=s;
printf("\nInformation of the books available are: \n");
for (int i=0;i<5;i++){
 printf("\n Book %d: \n Name: %s\n Author: %s\n Year of publication: %d",i+1,p->title,p->author,p->year);
 p++;
 printf("\n");
}
}
