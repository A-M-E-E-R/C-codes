#include<string.h>
#include<stdio.h>
int main(){
    char a[30];
    printf("\nEnter the string: ");
    gets(a);
    int l=strlen(a),c=0;
    for(int i=0;i<l;i++){
        for(int j=i+1;j<l;j++){
            if(a[i]==a[j] && a[i]!='$'){
                c++;
                a[j]='$';
            }
        }
        if(c==0 && a[i]!='$'){
            printf("%d\t",i+1);
        }
        c=0;
    }
}
