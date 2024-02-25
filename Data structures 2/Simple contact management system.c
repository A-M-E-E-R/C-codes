#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct contact s;
struct contact
{
    char name[15];
    char Ph_no[12];
    s* link;
};
s* head=NULL;
s* add_contact()//the function adds new data to the linked list
{
    if(head==NULL)
    {
        head=malloc(sizeof(s));
        printf("Enter the Name of the contact: ");
        fflush(stdin);
        gets(head->name);
        printf("\nEnter the phone number of the contact: ");
        fflush(stdin);
        gets(head->Ph_no);
        head->link=NULL;
        printf("\ncontact details saved successfully...");
        return head;
    }
    s* t=head;
    while(t->link!=NULL)
    {
        t=t->link;
    }
    t->link=malloc(sizeof(s));
    t=t->link;
    printf("Enter the Name of the contact: ");
    fflush(stdin);
    gets(t->name);
    printf("\nEnter the phone number of the contact: ");
    fflush(stdin);
    gets(t->Ph_no);
    t->link=NULL;
    printf("Contact details saved successfully...");
    return head;
}
void delete_contact(char *r)//function to delete a node with the corresponding data
{
    if(strcmp(head->name,r)==0)
    {
        s* t=head;
        head=head->link;
        free(t);
        t=NULL;
        printf("\nDELETED successfully...");
        return ;
    }
    s* t=head;
    do
    {
        if(strcmp(t->link->name,r)==0){
            s* temp= t->link;
            t->link=temp->link;
            free(temp);
            temp=NULL;
            return ;
        }
        t=t->link;
    }
    while(t->link!=NULL);
    if(strcmp(t->name,r)==0){
        free(t);
        t=NULL;
        printf("\nDELETED successfully...");
        return;
    }
    else printf("\nThe Contact with %s doesn't exist...",r);
    return ;
}
void view_details(char *r)//function to view a data inside a node corresponding to a given data
{
    s* t=head;
    while(t!=NULL){
        if(strcmp(t->name,r)==0){
            printf("\nName: ");
            puts(t->name);
            printf("Phone no. : %s",t->Ph_no);
            return;
        }
        t=t->link;
    }
    printf("\nThe Contact with %s doesn't exist...",r);;
    return ;
}
void view_all(){//function to view all data
    s* t=head;
    int c=1;
    while(t!=NULL){
        printf("\n\n%d.Name: ",c++);
        puts(t->name);
        printf("Phone no. : %s",t->Ph_no);
        t=t->link;
    }
    return ;
}
int main(){
    int o;
    while(1){
        printf("\n1. to add contact \n2. delete contact \n3. to view details of a contact \n4. to view all \n5. to exit");
        printf("\nEnter the option: ");
        scanf("%d",&o);//for switch case
        switch(o){
            case 1: {
                head=add_contact();
                break;
            }
            case 2: {
                if(head==NULL){
                    printf("\nEmpty list");
                    break;
                }
                char r[25];
                printf("\nEnter the Contact name to delete: ");
                scanf("%s",r);
                delete_contact(r);
                break;
            }
            case 3: {
                if(head==NULL){
                    printf("\nEmpty list");
                    break;
                }
                char r[25];
                printf("\nEnter the Contact name to view: ");
                scanf("%s",r);
                view_details(r);
                break;
            }
            case 4: {
                view_all();
                break;
            }
            case 5: {
                printf("\nMuchas Gracias...");
                exit(0);
            }
            default : {
                printf("\nInvalid option... Try again...");
            }
        }
    }
}
