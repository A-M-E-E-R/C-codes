#include<stdio.h>
#define SIZE 5
int f=-1,r=-1;
int q_arr[SIZE];
int isEmpty(){
    if(f==r){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(){
    if(r==SIZE-1){
        return 1;
    }
    else{
        return 0;
    }
}
void enqueue(int d){
    if(isFull()){
        printf("The Queue is full");
        return;
    }
    r++;
    q_arr[r]=d;
    return ;
}
int dequeue(){
    int d=-999;
    if(isEmpty()){
        printf("The Queue is Empty");
        return d;
    }
    f++;
    return q_arr[f];
}
void show(){
    if(isEmpty()){
        printf("The Queue is Empty");
        return ;
    }
    for(int i=f+1;i<=r;i++){
        printf("\n%d",q_arr[i]);
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
            printf("\nThe data are: ");
            show();
            break;
        }
        case 4: {
            printf("\nBye Bye...");
            return 0;
        }
        default : {
            printf("\nThe Entered choice is invalid...Try Again");
        }
    }
}


}
