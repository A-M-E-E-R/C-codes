#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct items{
    char name[20];
    float price;
    int quantity;
}item;
item menu[6] = {{"TEA",8.00,0},{"COFFEE",10.00,0},{"BOOST",12.00,0},{"PAZHAM-PORRI",15.00,0},{"UNDAM-PORRI",14.50,0},{"ULLANTHAPPAM",18.50,0}};
void add(){
    for(int i=0;i<6;i++){
        printf("%d)",i+1);
        puts(menu[i].name);
        printf("price : %.2f\n",menu[i].price);
    }
    int t;
nn:
    printf("\nEnter the item number to add to your order: ");
    scanf("%d",&t);
    if(t>6 || t<1){
        printf("Invalid number...");
        goto nn;
    }
    menu[t-1].quantity++;
    printf("\nEnter 0 to exit order window ");
    scanf("%d",&t);
    if(t==0) return;
    else goto nn;
}
void del(){ 
    int c;
pppp: 
    c=0;
    for(int i=0;i<6;i++){
        if(menu[i].quantity>0){
            printf("%d)",(c++)+1);
            puts(menu[i].name);
            printf("price : %.2f x %d qty\n",menu[i].price,menu[i].quantity);
        }   
    }
    if(c==0){
        printf("There are no items in the order.. ");
        return ;
    }
    printf("\nEnter the item number to delete the item: ");
    int q,n;
pp:
    scanf("%d",&n);
    if(n>c){
        printf("Invalid input... Try again: ");
        goto pp;
    }
    printf("Enter the number of qty of the item to be deleted: ");
ppp:
    scanf("%d",&q);
    if(q>menu[n-1].quantity){
        printf("Invalid input... Try again: ");
        goto ppp;
    }
    menu[n-1].quantity-=q;
    printf("Enter 0 to continue deleting: ");
    int o;
    scanf("%d",&o);
    if(o==0){
        goto pppp;
    }
    else return;
}
void disp_m(){
    for(int i=0;i<6;i++){
        printf("%d)",i+1);
        puts(menu[i].name);
        printf("price : %.2f\n",menu[i].price);
    }
    return ;
}
void disp_o(){
    int c=0;
    for(int i=0;i<6;i++){
        if(menu[i].quantity>0){
            printf("%d).",(c++)+1);
            puts(menu[i].name);
        }
    }
    return ;
}
void calc(){
    int c=0;
    float tot=0.0;
    for(int i=0;i<6;i++){
        if(menu[i].quantity>0){
            printf("%d).",(c++)+1);
            puts(menu[i].name);
            printf("price : %.2f\n",(menu[i].price * menu[i].quantity));
            tot+=menu[i].price*menu[i].quantity;
        }
    }
    if(c==0){
        printf("No orders yet...");
        return;
    }
    printf("\nThe total price = %.2f",tot);
    return;
}
void search(){
    char a[20];
    printf("Enter the item name in caps only: ");
    gets(a);
    for(int i=0;i<6;i++){
        if(strcmp(a,menu[i].name)==0){
            printf("%s is available with price %f",a,menu[i].price);
            return ;
        }
    }
    printf("\nThe entered item is not available...Sorry");
    return ;
}
void edit(){
    int i;
    while(1){
        printf("\nEnter:-  \n1. to add item \n2. to delete item \n3. to exit edit window");
        scanf("%d",&i);
        if(i==1){
            add();
        }
        else if(i==2){
            del();
        }
        else if(i==3){
            printf("Done");
            return ;
        }
        else{
            printf("\nInvalid option... Try again");
        }
    }
}
int main(){
    printf("Welcome to becauser Cafe ");
    printf("\nHere is the menu: \n");
    disp_m();
    int o;
    while(1){
        printf("\nEnter: \n1. to order \n2. to display order \n3. to edit order \n4. to display menu again \n5. to search for a specific item \
        \n6. to show the total amount \n7. to exit\n Enter here: ");
        scanf("%d",&o);
        switch(o){
            case 1: {
                add();
                break;
            }
            case 2: {
                disp_o();
                break;
            }
            case 3: {
                edit();
                break;
            }
            case 4: {
                disp_m();
                break;
            }
            case 5: {
                search();
                break;
            }
            case 6: {
                calc();
                break;
            }
            case 7: {
                printf("\nMuchas Gracias... ");
                exit(0);
            }
            default: {
                printf("Wrong input... please try again...");
            }
        }
    }
}