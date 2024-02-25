#include<stdio.h>
#include<string.h>
int main(){
    char puz[5][5]={'B','O','O','K','D','I','W','H','T','I','T','L','O','H','M','E','N','D','I','E','S','C','A','R','E'};
    for (int i=0;i<5;i++){
        for (int j=0;j<5;j++){
            printf("%c  ",puz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    char w[7];
    ss:
    printf("\n Enter a word from the puzzle or Enter 'EXIT' to quit: ");
    scanf("%s",w);
    w[strlen(w)]='\0';
    if (strcmp(w,"BOOK")==0){
        printf("Good One...\n");
        goto ss;
    }
    if (strcmp(w,"DIME")==0){
        printf("Excellent...\n");
        goto ss;
    }
    if (strcmp(w,"BITES")==0){
        printf("Great...\n");
        goto ss;
    }
    if (strcmp(w,"SCARE")==0){
        printf("Woow...\n");
        goto ss;
    }
    if (strcmp(w,"OHM")==0){
        printf("Nice...\n");
        goto ss;
    }
    if (strcmp(w,"END")==0){
        printf("Good...\n");
        goto ss;
    }
    if (strcmp(w,"DIE")==0){
        printf("Fine try...\n");
        goto ss;
    }
    if (strcmp(w,"OWL")==0){
        printf("Super...\n");
        goto ss;
    }
    if (strcmp(w,"EXIT")==0){
        printf("Bye Bye...\n");
    }
    else {
        printf("Invalid entry... Check and try again...\n");
        goto ss;
    }
}
