#include<stdio.h>
#include<string.h>
int main(){
    int t;
    printf("\nEnter the number of test cases: ");
    scanf("%d",&t);
    getchar();
    while(t){
    char prep[20];
    printf("\nEnter the String: ");
    gets(prep);
    int l=strlen(prep),x=0;
    for(int i=0;i<l;i++){
        int y=0;
        if(prep[i]=='*') continue;
        for(int j=i+1;j<l;j++){
            if(prep[i]==prep[j]){
                y++;
                prep[j]='*';
            }
        }
        if(y==0 && prep[i]!='*'){
            printf("\nThe index is %d",i);
            x=999;
            break;
        }
    }
    if(x==0){
        printf("\n-1");
    }
    t--;
    }
}
