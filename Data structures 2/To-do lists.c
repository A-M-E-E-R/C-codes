#include<stdio.h>
#include<stdlib.h>
typedef struct to_do{
    char task[25];//string upto 24 characters
    int done_or_empty;//if empty , will store 1 or if done it will store a higher value than 1
}test_struct;
test_struct a[10];//10 up to_do tasks
void add_task(){//function to add task
    int i;
nn:
    printf("\nEnter the numbered task position: ");//task serial number
    scanf(" %d",&i);
    fflush(stdin);//to clear the buffer carry
    if(i>10 || i<1){
        printf("\nInvalid number... try with 1 - 10");
        goto nn;
    }
    if(a[i-1].done_or_empty){//checking if the number is free
        printf("\nEnter the task to be added: ");
        scanf("%[^\n]s",a[i-1].task);
        a[i-1].done_or_empty=0;
    }
    else{
        printf("\nTask already exists at this number");
    }
   return ;
}
void view_task(){//function to view the tasks
    printf("\nTo-do List: ");
    for(int i=0;i<10;i++){
        if(a[i].done_or_empty==1){
            printf("\n%d. ",i+1);
        }
        else if(a[i].done_or_empty>1){
            printf("\n%d. ",i+1);
            puts(a[i].task);
            printf("    - done");
        }
        else{
            printf("\n%d. ",i+1);
            printf("%s",a[i].task);
        }
    }
    return ;
}
void done(){
aa:
    printf("\nEnter the task number: ");
    int i;
    scanf("%d",&i);
        if(i>10 || i<1){
            printf("\nInvalid number... try with 1 - 10");
            goto aa;
        }
        if(a[i-1].done_or_empty==1){
            printf("\n Empty number...");
        }
        else if(a[i-1].done_or_empty>1){
            printf("\n The task is marked done already...");
        }
        else{
            a[i-1].done_or_empty=2;
            printf("\nMarked Done...");
        }
    return;
}
void delete_task(){
aa:
    printf("\nEnter the task number: ");
    int i;
    scanf("%d",&i);
        if(i>10 || i<1){
            printf("\nInvalid number... try with 1 - 10");
            goto aa;
        }
        if(a[i-1].done_or_empty==1){
            printf("\n Already Empty number...");
        }
        else if(a[i-1].done_or_empty>1){
            printf("\n The task was marked done...");
            a[i-1].done_or_empty=1;
        }
        else{
            printf("\n%d. ",i+1);
            puts(a[i-1].task);
            printf("\nwill be erased...");
            a[i-1].done_or_empty=1;
            printf("\nDone");
        }
    return;
}
void reset(){
    for(int i=0;i<10;i++){
        a[i].done_or_empty=1;
    }
}
int main(){
    reset();
    int an;
    while(1){
    printf("\n1. to add task \n2. to view \n3. to mark done \n4. to delete task \n5. to exit \nEnter the option:");
    scanf("%d",&an);
    switch(an){
        case 1: {
            add_task();
            break;
        }
        case 2: {
            view_task();
            break;
        }
        case 3: {
            done();
            break;
        }
        case 4: {
            delete_task();
            break;
        }
        case 5: {
            printf("\nMuchas gracias... :)");
            exit(0);
        }
        default : {
            printf("\nWrong input for option... \nTry again...");
        }
    }
    }
}
