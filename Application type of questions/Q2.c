#include<stdio.h>
#include<string.h>
int main(){
    int t;
    printf("\nEnter the number of test cases: ");
    scanf("%d",&t);
    while(t){
    char tina[25];
    printf("\nEnter the string: ");
    scanf("%s",tina);
    int l=strlen(tina)-1,c=0;
    for(int i=0;i<=l/2;i++){
        while(tina[i]!=tina[l-i]){
            printf("\n%s",tina);
            if(tina[i]>tina[l-i]){
                tina[i]--;
                c++;
            }
            else{
                tina[l-i]--;
                c++;
            }
        }
    }
    printf("\nThe Palindrome = %s",tina);
    printf("\nThe total number of operations done : %d",c);
    t--;
}
}
