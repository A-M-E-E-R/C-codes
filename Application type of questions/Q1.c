#include<stdio.h>
#include<string.h>
int main(){
    int t;
    printf("Enter the number of test cases: ");
    scanf("%d",&t);
    getchar();
    while(t){
    char tina[25];
    printf("\nEnter the string: ");
    gets(tina);
    int l=strlen(tina),c=0;
    for(int i=0;i<l;i++){
        if(tina[i]=='a' || tina[i]=='A'){
            c++;
        }
    }
    int i=0;
    while(c<=(l/2)){
        if(tina[i]!='a' || tina[i]!='A'){
            tina[i]=tina[i+1];
            l--;
        }
        i++;
    }
    printf("\nThe length of the good string is %d",l);
    t--;
    }
}
