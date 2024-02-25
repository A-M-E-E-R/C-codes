#include<stdio.h>
int H,L;
int odd(int);
int even(int);
int main(){
//ss:
printf("Enter 1 for Odd sum and 2 for Even sum");
int o;
scanf("%d",&o);
/*if (o!=1 && o!=2){
    printf("Enter a Valid input");
    goto ss;
}*/
printf("Enter the Range \n");
printf("Enter the Number to which the sum shall be found");
scanf("%d",&H);
printf("Enter the Number from which the sum shall be found");
scanf("%d",&L);
if (o==1)
    printf("%d is the sum",odd(L));
//if (o==2)
  //  printf("%d is the sum",even(L));
}
int odd(int n){
if (L%2!=0){
     n=L;}
else
    n=L+1;
if (n==H || n==(H-1)){
    return n;
}
printf("%d",n);
return n + odd(n+2);
}
/*int even(int n){
if (L%2==0)
     n=L;
else
     n=L+1;
if (n==H || n==(H-1)){
    return n;
}
return n + even(n+2);
}
*/
