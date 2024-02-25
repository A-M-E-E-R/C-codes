#include<stdio.h>
void swap(char *a,char *b){
    char temp = *a;
    *a=*b;
    *b=temp;
}
int main(){
int n;
printf("Enter the number of elements: ");
scanf("%d",&n);
char a[n];
printf("Enter the elements one by one: ");
for (int i=0;i<n;i++){
    printf("\n%dth element: ",i);
    getchar();
    scanf("%c",&a[i]);
}
int x,y;
printf("\nEnter the Positions to be swapped: ");
scanf("%d %d",&x,&y);
swap(&a[x],&a[y]);
for (int i=0;i<n;i++){
    printf("\n%dth element: ",i);
    printf("%c",a[i]);
}
}
