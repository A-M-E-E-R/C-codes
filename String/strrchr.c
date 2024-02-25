#include<stdio.h>
#include<string.h>
int main(){
char a[100],c;
printf("Enter the string: ");
gets(a);
printf("Enter the character: ");
c=getchar();
int n=strlen(a),i=-1;
for(int j=0;j<n;j++){
        if(a[n-j]==c){
        i=n-j+1;
        break;
        }
}
if(i==-1)
    printf("\nThere is no occurrence for %c",c);
else
    printf("\nThe occurrence of %c is at %d",c,i);
}

