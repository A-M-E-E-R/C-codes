#ifndef SINGLELINKEDLISTS_H_INCLUDED
#define SINGLELINKEDLISTS_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node*link;
} n;
n* addatend(n *temp,int i,int a)
{
    scanf("%d",&temp->data);
    if(i==a-1)
    {
        temp->link=NULL;
        return temp;
    }
    temp->link=malloc(sizeof(n));
    temp=temp->link;
    return temp;
}
n* addatbeg(n *temp,int i)
{
    n* t=malloc(sizeof(n));
    t->data=i;
    t->link=temp;
    return t;
}
n* delatbeg(n *head)
{
    if(head==NULL)
    {
        printf("Empty list.");
        exit(1);
    }
    else
    {
        n* temp = head;
        head = head->link;
        free(temp);
        temp=NULL;
    }
    return head;
}
void delast(n* head)
{
    n* temp =head;
    n* temp1 = NULL;
    while(temp->link!=NULL)
    {
        temp1=temp;
        temp = temp->link;
    }
    temp1->link=NULL;
    free(temp);
    temp=NULL;
    return;
}
n* addatmid(n *temp,int i)
{
    n* t=malloc(sizeof(n));
    t->data=i;
    t->link=temp->link;
    temp->link=t;
    return t;
}
void delatmid(n *temp, n* temp1)
{
    temp->link=temp1->link;
    free(temp1);
    temp1=NULL;
    return;
}
int datacheck(n* head,int data)
{
    n* temp = head;
    int c=1;
    while(temp!=NULL)
    {
        if(temp->data==data)
        {
            printf("The data is present at node %d",c);
            return c;
        }
        temp=temp->link;
        c++;
    }
    printf("\nThe data is not present.");
    return 0;
}
int show(n* head)
{
    if(head==NULL)
    {
        printf("\nEmpty list...");
        return 0;
    }
    n* temp=head;
    int c=1;
    while(temp!=NULL)
    {
        printf("Node %d) %d->%d\n",c++,temp,temp->data);
        temp=temp->link;
    }
    return c-1;
}
n* deletelist(n* head)
{
    n* temp= head;
    int    c=1;
    while(temp!=NULL)
    {
        temp=delatbeg(temp);
        c=(show(temp));
        printf("\n%d",c++);
    }
    head=temp;
    printf("\nDeletion completed...");
    return head;
}
n* sorted_entry(n* head,int data)
{
    n* temp=head;
    if(head->data>data)
    {
        head=addatbeg(head,data);
        return head;
    }
    while(temp->link!=NULL)
    {
        if(temp->link->data>data)
        {
            temp=addatmid(temp,data);
            return head;
        }
        temp=temp->link;
    }
    n* temp1=malloc(sizeof(n));
    temp1->data=data;
    temp1->link=NULL;
    temp->link=temp1;
    return head;
}
n* reverselist(n* head)
{
    n* t2= head;
    n* t3=t2->link;
    n* t1=NULL;
    while(t3!=NULL)
    {
        t2->link=t1;
        t1=t2;
        t2=t3;
        t3=t2->link;
        if(t3==NULL)
        {
            t2->link=t1;
        }
    }
    return t2;
}
n* rev_list(n* head)
{
    n* p1=NULL;
    n* p2=NULL;
    while(head!=NULL)
    {
        p2=head->link;
        head->link=p1;
        p1=head;
        head=p2;
    }
    head=p1;
    return head;
}
n* datadelete(n* head,int data)
{
    int c=datacheck(head,data);
    if(c==0)
    {
        return head;
    }
    n* temp=head;
    n* temp1=temp->link;
    for(int i=1; i<=c; i++)
    {
        if(c==1)
        {
            head=delatbeg(head);
            return head;
        }
        if(i==c-1)
        {
            delatmid(temp,temp1);
            break;
        }
        temp=temp->link;
        temp1=temp->link;
    }
    return head;
}
void crt_node(int a)
{
    int N=0;
    n *head=malloc(sizeof(n));
    if(head==NULL)
    {
        printf("Memory not allocated");
        exit(1);
    }
    n *temp=head;
    for(int i=0; i<a; i++)
    {
        printf("Enter the data for node %d: ",i+1);
        temp=addatend(temp,i,a);
    }
    {
        printf("\n Enter 'y' to add a node in the beginning of the list: ");
        char y;
        getchar();
        y=getchar();
        if(y=='y')
        {
ss:
            printf("\nEnter the data for the new node: ");
            int d;
            scanf("%d",&d);
            head=addatbeg(head,d);
            {
                char x;
                printf("\nEnter 'y' to add one more node in the beginning: ");
                getchar();
                x=getchar();
                if (x=='y')
                {
                    goto ss;
                }
            }
        }
    }
    {
        char y;
        printf("\nEnter 'y' to add a node in between nodes: ");
        getchar();
        y=getchar();
        if (y=='y')
        {
aa:
            printf("Enter the node position to be added: ");
            int m;
            scanf("%d",&m);
            if(m>a || m<=0)
            {
                printf("\nThe entered position is invalid. Enter a new position.");
                goto aa;
            }
            temp=head;
            for(int i=1; i<=m; i++)
            {
                if(i==m)
                {
                    int d;
                    printf("\nEnter the data for the new node: ");
                    scanf("%d",&d);
                    temp=addatmid(temp,d);
                    break;
                }
                temp=temp->link;
            }
            char x;
            printf("Enter 'y' to add another node at desired position: ");
            getchar();
            x=getchar();
            if(x=='y')
            {
                goto aa;
            }
        }
    }
    temp=head;
    int c=1;
    printf("\n");
    c=(show(head));
    {
        printf("Enter the 'y' to delete the first node: ");
        char y;
        getchar();
        y=getchar();
        if(y=='y')
        {
            head=delatbeg(head);
            printf("\nDeletion successfully done.");
            N++;
        }
    }
    {
        printf("Enter the 'y' to delete the last node: ");
        char y;
        getchar();
        y=getchar();
        if(y=='y')
        {
            delast(head);
            printf("\nDeletion successfully done.");
            N++;
        }
    }
    {
        char y;
        printf("\nEnter 'y' to delete a node at any position  : ");
        getchar();
        y=getchar();
        if (y=='y')
        {
qq:
            printf("Enter the node position to be deleted: ");
            int m;
            scanf("%d",&m);
            if(m>c-1 || m<=0)
            {
                printf("\nThe entered position is invalid. Enter a new position.");
                goto qq;
            }
            temp=head;
            n* temp1=temp->link;
            for(int i=1; i<=m; i++)
            {
                if(m==1)
                {
                    head=delatbeg(head);
                }
                if(i==m-1)
                {
                    delatmid(temp,temp1);
                    break;
                }
                temp=temp->link;
                temp1=temp->link;
            }
            printf("\nDeletion successfully done.");
            N++;
        }
    }
    temp=head;
    printf("\n");
    if(N!=0)
        c=(show(head));
    else
        printf("The list are unchanged.");
    char y='\0';
    if(N!=0)
    {
        printf("Enter 'y' to delete a node again: ");
        getchar();
        y=getchar();
    }
    if(y=='y')
    {
        goto qq;
    }
    else
        printf("\nEnter a data to be checked in the list: ");
    int data;
    scanf("%d",&data);
    c=datacheck(head,data);
    printf("\nEnter new data to enter in sorted list: ");
    scanf("%d",&data);
    head=sorted_entry(head,data);
    c=show(head);
    {
        printf("\nEnter 'd' to delete a node corresponding to a data list: ");
        getchar();
        y=getchar();
        if(y=='d')
            printf("\nEnter the data to delete: ");
        scanf("%d",&data);
        head=datadelete(head,data);
    }
    {
        printf("\nEnter 'r' to reverse the whole list: ");
        getchar();
        y=getchar();
        if(y=='r')
            head=reverselist(head);
    }
    c=show(head);
    {
        printf("\nEnter 'x' to delete the whole list: ");
        getchar();
        y=getchar();
        if(y=='x')
            head=deletelist(head);
    }
    printf("\nThe program ended successfully.");
    return ;
}

#endif // SINGLELINKEDLISTS_H_INCLUDED
