 #include<stdio.h>
 int main(){
    int a,n;
    printf("\nEnter 2 numbers: ");
    scanf("%d %d",&a,&n);
    a=a^n;
    n=a^n;
    a=a^n;
    printf("\n %d %d",a,n);
 }
