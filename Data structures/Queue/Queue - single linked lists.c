#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node*link;
}n;
n* f=NULL;
n* r=NULL ;
int isEmpty(){
    if(f==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(){
    n* t1=malloc(sizeof(n));
    if(t1==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
void enqueue(int d){
    if(isFull()){
        printf("\n\nThe Memory is Full...");
        return;
    }
    if(isEmpty()){
        f=malloc(sizeof(n));
        f->data=d;
        r=f;
        return ;
    }
    r->link=malloc(sizeof(n));
    r->link->data=d;
    r=r->link;
    r->link=NULL;
    return;
}
int dequeue(){
    int d=-999;
    if(isEmpty()){
        printf("Queue is Empty\n");
        return d;
    }
    n* t=f;
    d=f->data;
    f=f->link;
    free(t);
    t=NULL;
    return d;
}
void show(){
    if(isEmpty()){
        printf("Queue is Empty\n");
        return;
    }
    n* t=f;
    while(t){
        printf("%d\n",t->data);
        t=t->link;
    }
    return ;
}
int main(){
    while(1){
        printf("\n1.Enqueue \n2.Dequeue \n3.Show \n4.Exit \nEnter: ");
        int ch ,d;
        scanf("%d",&ch);
        switch(ch){
            case 1: {
                printf("\nEnter the Data: ");
                scanf("%d",&d);
                enqueue(d);
                break;
            }
            case 2: {
                printf("\n%d is Dequeued",dequeue());
                break;
            }
            case 3: {
                printf("\ndata: \n");
                show();
                break;
            }
            case 4: {
                printf("\nBye Bye...");
                exit(0 );
            }
            default : {
                printf("\nThe Entered choice is invalid...Try Again");
            }
        }
    }
}
