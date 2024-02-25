#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack_array[MAX];
int top=-1;
int isEmpty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(){
    if(top==MAX-1){
        return 1;
    }
    else{
        return 0;
    }
}
void Push(int d){
    if(isFull()){
        printf("\nStack overflow");
        exit(1);
    }
    top++;
    stack_array[top]=d;
    return ;
}
int Pop(){
    if(isEmpty()){
        printf("\nStack underflow");
        exit(1);
    }
    int d;
    d=stack_array[top];
    top--;
    return d;
}
int Top(){
    if(isEmpty()){
        printf("\nStack underflow");
        exit (1);
    }
    return stack_array[top];
}
void show(){
    if(isEmpty()){
        printf("\nStack underflow");
        exit (1);
    }
    for(int i=top;i>=0;i--){
        printf("%d\n",stack_array[i]);
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
