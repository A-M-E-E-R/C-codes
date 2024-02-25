#include<stdio.h>
#include<stdlib.h>
typedef struct employee s;
struct employee
{
    char name[15];
    int id;
    int wage_per_hour;
    int hours_worked;
    int total_wage;
    s* link;
};
s* head=NULL;
s* add_employee()//the function adds new data to the linked list
{
    if(head==NULL)
    {
        head=malloc(sizeof(s));
        printf("Enter the Name of the Employee: ");
        fflush(stdin);
        gets(head->name);
        printf("\nEnter the id: ");
        scanf("%d",&head->id);
        printf("\nEnter the wage/hr: ");
        scanf("%d",&head->wage_per_hour);
        printf("\nEnter the total hrs worked: ");
        scanf("%d",&head->hours_worked);
        head->total_wage=head->hours_worked * head->wage_per_hour;
        printf("\nThe total wage of the employee is %d",head->total_wage);
        head->link=NULL;
        printf("\nEmployee details saved successfully...");
        return head;
    }
    s* t=head;
    while(t->link!=NULL)
    {
        t=t->link;
    }
    t->link=malloc(sizeof(s));
    t=t->link;
    printf("Enter the Name of the Employee: ");
    fflush(stdin);
    gets(t->name);
    printf("\nEnter the id: ");
    scanf("%d",&t->id);
    printf("\nEnter the wage/hr: ");
    scanf("%d",&t->wage_per_hour);
    printf("\nEnter the total hrs worked: ");
    scanf("%d",&t->hours_worked);
    t->total_wage=t->hours_worked * t->wage_per_hour;
    printf("\nThe total wage of the employee is %d",t->total_wage);
    head->link=NULL;
    printf("\nEmployee details saved successfully...");
    return head;
}
void delete_employee(int r)//function to delete a node with the corresponding data
{
    if(head->id==r)
    {
        s* t=head;
        head=head->link;
        free(t);
        t=NULL;
        printf("\nDELETED successfully...");
        return ;
    }
    int c=1;
    s* t=head;
    do
    {
        if(t->link->id==r){
            s* temp= t->link;
            t->link=temp->link;
            free(temp);
            temp=NULL;
            return ;
        }
        t=t->link;
    }
    while(t->link!=NULL);
    if(t->id==r){
        free(t);
        t=NULL;
        printf("\nDELETED successfully...");
        return;
    }
    else printf("\nThe Employee with ID %d doesn't exist...",r);
    return ;
}
void view_details(int r)//function to view a data inside a node corresponding to a given data
{
    s* t=head;
    while(t!=NULL){
        if(t->id==r){
            printf("\nName: ");
            puts(t->name);
            printf("\nID. : %d",r);
            printf("\nWage per Hour: %d",t->wage_per_hour);
            printf("\nTotal Hours worked: %d",t->hours_worked);
            printf("\nTotal Wage: %d",t->total_wage);
            return;
        }
        t=t->link;
    }
    printf("\nThe Employee with ID %d doesn't exist...",r);
    return ;
}
int main(){
    int o;
    while(1){
        printf("\n1. to add an Employee \n2. delete an Employee \n3. to view details of an Employee \n4. to exit");
        printf("\nEnter the option: ");
        scanf("%d",&o);//for switch case
        switch(o){
            case 1: {
                head=add_employee();
                break;
            }
            case 2: {
                if(head==NULL){
                    printf("\nEmpty list");
                    break;
                }
                int r;
                printf("\nEnter the ID number to delete: ");
                scanf("%d",&r);
                delete_employee(r);
                break;
            }
            case 3: {
                if(head==NULL){
                    printf("\nEmpty list");
                    break;
                }
                int r;
                printf("\nEnter the ID number to view: ");
                scanf("%d",&r);
                view_details(r);
                break;
            }
            case 4: {
                printf("\nMuchas Gracias...");
                exit(0);
            }
            default : {
                printf("\nInvalid option... Try again...");
            }
        }
    }
}

