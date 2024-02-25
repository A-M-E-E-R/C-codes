#ifndef CIRCULAR_DOUBLE_LINKED_LIST_H_INCLUDED
#define CIRCULAR_DOUBLE_LINKED_LIST_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
struct node* rlink;
int data;
struct node* flink;
} n;
n* createnode(){
    n* t=malloc(sizeof(n));
    if(t==NULL){
        printf("\nThe memory was not allocated...");
        exit(1);
    }
    t->rlink=t;
    printf("\nEnter the data for the new node: ");
    int d;
    scanf("%d",&d);
    t->data=d;
    t->flink=t;
    return t;
}
void addatend(n* head){
n* t1=head;
while(t1->flink!=head){
    t1=t1->flink;
}
n* t2=createnode();
t1->flink=t2;
t2->rlink=t1;
t2->flink=head;
head->rlink=t2;
return;
}
n* addatbeg(n* head){
    n* t1=head;
    n* t2=createnode();
    t2->flink=head;
    t2->rlink=t1->rlink;
    t1->rlink=t2;
    t2->rlink->flink=t2;
    return t2;
}
n* addatpos(n* head,int pos){
    n*  t1=head;
    n* temp=head;
    int c=1;
    while(temp->flink!=head){
        c++;
        temp=temp->flink;
    }
    if(pos==1){
        head=addatbeg(head);
        return head;
    }
    else if(pos<1 || pos>c+1){
        printf("\nInvalid position...");
        return head;
    }
    else if(pos==c+1){
        addatend(head);
        return head;
    }
    else{
        for(int i=0;i<pos-1;i++){
            t1=t1->flink;
        }
        n* t2=createnode();
        n* t3=t1->rlink;
        t2->rlink=t3;
        t2->flink=t1;
        t1->rlink=t2;
        t3->flink=t2;
    }
    return head;
}
n* create_list(n* head){
    int c=0,N;
    printf("Enter the number of nodes to be created: ");
    scanf("%d",&N);
    if(head==NULL){
        head=createnode();
        c++;
    }
    while(N-c){
        addatend(head);
        N--;
    }
    return head;
}
n* delatbeg(n* head){
    n* t1=head;
    if(head->flink==head){
        free(head);
        head=NULL;
        return NULL;
    }
    head=head->flink;
    head->rlink=head->rlink->rlink;
    head->rlink->flink=head;
    free(t1);
    t1=NULL;
    return head;
}
n* delatend(n* head){
    n* t1=head;
    while(t1->flink!=head){
        t1=t1->flink;
    }
    n* t2=t1->rlink;
    free(t1);
    t1=NULL;
    t2->flink=head;
    head->rlink=t2;
    return head;
}
n* delatpos(n* head,int pos){
    int c=1;
    n* temp=head;
    while(temp->flink!=head){
        temp=temp->flink;
        c++;
    }
    if(pos==1){
        head=delatbeg(head);
        return head;
    }
    else if(pos>c||pos<1){
        printf("\nThe entered position is invalid");
        return head;
    }
    else if(pos==c){
        head=delatend(head);
        return head;
    }
    temp=head;
    for(int i=1;i<pos;i++){
        temp=temp->flink;
    }
    n* t1=temp->rlink;
    n* t2=temp->flink;
    free(temp);
    temp=NULL;
    t1->flink=t2;
    t2->rlink=t1;
    return head;
}
int datacheck(n* head){
    int c=1,y=0,data;
    printf("\nEnter the data: ");
    scanf("%d",&data);
    n* temp=head;
    while(temp->flink!=head){
        if(temp->data==data){
            y++;
            break;
        }
        temp=temp->flink;
        c++;
        if(temp->data==data){
            y++;
            break;
        }
    }
    if(y!=0){
        return c;
    }
    else{
        return 0;
    }
}
n* datadelete(n* head){
    int pos=datacheck(head);
    if(pos==0){
        printf("\nThe entered data doesn't exist...");
        return head;
    }
    else{
        head=delatpos(head,pos);
        return head;
    }
}
n* reverselist(n* head){
    n* t1=head;
    while(t1->flink!=head){
        n* t2=t1->rlink;
        t1->rlink=t1->flink;
        t1->flink=t2;
        t1=t1->rlink;
    }
    n* t2=t1->rlink;
    t1->rlink=t1->flink;
    t1->flink=t2;
    return t1;
}
void show(n* head){
    n* t=head;
    if(head==NULL){
        printf("\nThe list is empty...");
        return ;
    }
    int c=1;
    do{
        printf("\n%d) %d-->%d-->%d",c++,t->rlink,t->data,t->flink);
        t=t->flink;
    }while(t!=head);
    return;
}
n* deletelist(n* head){
    n* temp= head;
    int  c=1;
    while(temp!=head){
        delatend(temp);
        show(temp);
        printf("\t%d\n",c++);
        if(temp->flink==head){
            head=delatbeg(head);
            break;
        }
    }
    if(head==NULL){
        printf("\nEmpty list achieved... ");
        return NULL;
    }
    free(temp);
    temp=NULL;
    printf("\n\nDeletion completed...");
    return temp;
}
void sort_list(n* head){
    n* t1=head;
    n* t2=t1->flink;
    while(t1->flink!=head){
        t2=t1->flink;
        while(t2!=head){
            if(t2->data<t1->data){
                int d=t1->data;
                t1->data=t2->data;
                t2->data=d;
            }
            t2=t2->flink;
        }
        t1=t1->flink;
    }
    return;
}
void   sorted_data_input(n* head){
    addatend(head);
    sort_list(head);
    return ;
}
#endif // CIRCULAR_DOUBLE_LINKED_LIST_H_INCLUDED
