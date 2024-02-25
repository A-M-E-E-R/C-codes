#include<stdio.h>
#include<stdlib.h>
struct marks//structure to enter the marks of different subjects
{
    float science;
    float maths;
    float social_science;
    float art;
};
typedef struct student s;
struct student
{
    char name[15];
    int roll_no;
    struct marks m;//nested structure to enter the marks
    float total_marks;
    s* link;
};
s* head=NULL;
s* add_student()//the function adds new data to the linked list
{
    if(head==NULL)
    {
        head=malloc(sizeof(s));
        printf("Enter the Name of the student: ");
        fflush(stdin);
        gets(head->name);
        printf("\nEnter the roll number of the student: ");
        scanf("%d",&head->roll_no);
        printf("\nEnter the marks for science, maths, social_science and art: ");
        scanf("%f %f %f %f",&head->m.science,&head->m.maths,&head->m.social_science,&head->m.art);
        head->total_marks=head->m.science+head->m.maths+head->m.social_science+head->m.art;
        printf("\nThe total marks is %.2f",head->total_marks);
        head->link=NULL;
        printf("\nStudent details saved successfully...");
        return head;
    }
    s* t=head;
    while(t->link!=NULL)
    {
        t=t->link;
    }
    t->link=malloc(sizeof(s));
    t=t->link;
    printf("Enter the Name of the student: ");
    fflush(stdin);
    gets(t->name);
    printf("\nEnter the roll number of the student: ");
    scanf("%d",&t->roll_no);
    printf("\nEnter the marks for science, maths, social_science and art: ");
    scanf("%f %f %f %f",&t->m.science,&t->m.maths,&t->m.social_science,&t->m.art);
    t->total_marks=t->m.science+t->m.maths+t->m.social_science+t->m.art;
    printf("\nThe total marks is %.2f",t->total_marks);
    t->link=NULL;
    printf("Student details saved successfully...");
    return head;
}
void delete_student(int r)//function to delete a node with the corresponding data
{
    if(head->roll_no==r)
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
        if(t->link->roll_no==r){
            s* temp= t->link;
            t->link=temp->link;
            free(temp);
            temp=NULL;
            return ;
        }
        t=t->link;
    }
    while(t->link!=NULL);
    if(t->roll_no==r){
        free(t);
        t=NULL;
        printf("\nDELETED successfully...");
        return;
    }
    else printf("\nThe student with Roll No. %d doesn't exist...",r);
    return ;
}
void view_details(int r)//function to view a data inside a node corresponding to a given data
{
    s* t=head;
    while(t!=NULL){
        if(t->roll_no==r){
            printf("\nName: ");
            puts(t->name);
            printf("\nRoll no. : %d",r);
            printf("\nThe marks of the student: ");
            printf("Science: %.2f\tMaths: %.2f\tSocial studies: %.2f\tArt: %.2f",t->m.science,t->m.maths,t->m.social_science,t->m.art);
            printf("\nTotal Marks = %.2f",t->total_marks);
            return;
        }
        t=t->link;
    }
    printf("\nThe student with Roll No. %d doesn't exist...",r);
    return ;
}
int main(){
    int o;
    while(1){
        printf("\n1. to add student \n2. delete student \n3. to view details of a student \n4. to exit");
        printf("\nEnter the option: ");
        scanf("%d",&o);//for switch case
        switch(o){
            case 1: {
                head=add_student();
                break;
            }
            case 2: {
                if(head==NULL){
                    printf("\nEmpty list");
                    break;
                }
                int r;
                printf("\nEnter the student's roll number to delete: ");
                scanf("%d",&r);
                delete_student(r);
                break;
            }
            case 3: {
                if(head==NULL){
                    printf("\nEmpty list");
                    break;
                }
                int r;
                printf("\nEnter the student's roll number to view: ");
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
