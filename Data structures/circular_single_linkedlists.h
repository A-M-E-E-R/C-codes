#ifndef CIRCULAR_SINGLE_LINKEDLISTS_H_INCLUDED
#define CIRCULAR_SINGLE_LINKEDLISTS_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
int data;
struct node* link;
}n;
n* createnode(){
    n* t=malloc(sizeof(n));
    printf("\nEnter the data: ");
    scanf("%d",&t->data);
    t->link=t;
    return t;
}
void addatend(n* head){
    n* t=head;
    n* temp=createnode();
    do{
        t=t->link;
    }while(t->link!=head);
    t->link=temp;
    temp->link=head;
    return ;
}
n* addatbeg(n* head){
    n* t=head;
    n* NEW=createnode();
    do{
        t=t->link;
    }while(t->link!=head);
    t->link=NEW;
    NEW->link=head;
    return NEW;
}
void addNnodes(n* head,int d){
    while(d){
        addatend(head);
        d--;
    }
    return ;
}
n* addatpos(n* head,int pos){
    n* t=head;
    if(pos==1){
        head=addatbeg(head);
        return head;
    }
    int c=1;
    do{
        t=t->link;
        c++;
    }while(t!=head);
    if(pos<1 || pos>c){
        printf("Invalid position...");
        return head;
    }
    else if(pos==c){
        addatend(head);
        return head;
    }
    else{
        n* temp=t;
        while(pos){
            temp=t;
            t=t->link;
            pos--;
        }
        temp->link=createnode();
        temp->link->link=t;
        return head;
    }
}
n* deletehead(n* head){
    n* t=head;
    do{
        t=t->link;
    }while(t->link!=head);
    t->link=head->link;
    free(head);
    head=NULL;
    return t->link;
}
void delatend(n* head){
    n* t=head;
    n* temp=head->link;
    while(t->link!=head){
        temp=t;
        t=t->link;
    }
    temp->link=t->link;
    free(t);
    t=NULL;
    return ;
}
n* delatpos(n* head,int pos){
    n* t=head;
    if(pos==1){
        head=deletehead(head);
        return head;
    }
    int c=0;
    do{
        t=t->link;
        c++;
    }while(t!=head);
    if(pos<1 || pos>c){
        printf("Invalid position...");
        return head;
    }
    else if(pos==c){
        delatend(head);
        return head;
    }
    else{
        n* temp=head;
        while(pos-1){
            temp=t;
            t=t->link;
            pos--;
        }
        temp->link=t->link;
        free(t);
        t=NULL;
        return head;
    }
}
int datacheck(n* head,int d){
    n* t=head;
    int c=0,pos=1;
    while(t->link!=head){
        if(t->data==d){
            c++;
            break;
        }
        pos++;
        t=t->link;
    }
    if(c==0){
        printf("\nData is not present...");
        return 0;
    }
    else{
        return pos;
    }
}
n* deletedata(n* head,int d){
    int c=datacheck(head,d);
    if(c){
        head=delatpos(head,c);
        return head;
    }
    return head;
}
n* delete_list(n* head){
    n* t=head;
    while(t->link!=head){
        delatend(head);
    }
    free(t);
    t=NULL;
    return t;
}
void sort_list(n* head){
    n* t1=head;
    n* t2=t1->link;
    while(t1->link!=head){
        t2=t1->link;
        while(t2!=head){
            if(t2->data<t1->data){
                int d=t1->data;
                t1->data=t2->data;
                t2->data=d;
            }
            t2=t2->link;
        }
        t1=t1->link;
    }
    return;
}
void   sorted_data_input(n* head){
    addatend(head);
    sort_list(head);
    return ;
}
n* reverselist(n* head){
    n* t1= head;
    n* t2= t1->link;
    n* t3= t2->link;
    do{
        t2->link=t1;
        t1=t2;
        t2=t3;
        t3=t3->link;
    }while(t2!=head);
    t2->link=t1;
    return t1;
}
int show(n* head){
    n* t=head;
    int n=1;
    do{
        printf("\n%d) %d-->%d",n++,t->data,t->link);
        t=t->link;
    }while(t!=head);
    return n-1;
}

#endif // CIRCULAR_SINGLE_LINKEDLISTS_H_INCLUDED
