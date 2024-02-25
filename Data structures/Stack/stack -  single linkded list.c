#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node*link;
}n;
n* top=NULL;
int isEmpty(){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
void Push(int i){
    n* t=malloc(sizeof(n));
    t->data=i;
    t->link=top;
    top=t;
}
int Pop(){
    if(isEmpty()){
        printf("Stack Underflow\n");
        exit(1);
    }
    n* t=top;
    int d;
    top=top->link;
    free(t);
    t=NULL;
    return d;
}
int Top(){
    if(isEmpty()){
        printf("Stack Underflow\n");
        exit(1);
    }
    return top->data;
}
void show(){
    if(isEmpty()){
        printf("Stack Underflow\n");
        exit(1);
    }
    n* t=top;
    while(t){
        printf("%d\n",t->data);
        t=t->link;
    }
    return ;
}
int main(){
    while(1){
        printf("\n1.push \n2.pop \n3.view top element \n4. view all elements \n5. Exit \nEnter:  ");
        int d,ch;
        scanf("%d",&ch);
        switch (ch){
            case 1: {
                printf("Enter element to be pushed: ");
                scanf("%d",&d);
                Push(d);
                break;
            }
            case 2: {
                d=Pop();
                printf("%d is popped out of stack\n",d);
                break;
            }
            case 3: {
                d=Top();
                printf("%d is the top element.",d);
                break;
            }
            case 4: {
                printf("The elements of stack\n");
                show();
                break;
            }
            case 5: {
                printf("Bye Bye...");
                exit(0);
            }
            default:{
                printf("Wrong choice\n");
            }
        }
    }
}
