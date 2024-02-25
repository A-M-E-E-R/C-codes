#include<stdio.h>
#include<string.h>
int main(){
    int t;
    printf("Enter the number of test cases: ");
    scanf("%d",&t);
    while(t){
    char a[25];
    printf("\nEnter the string: ");
    getchar();
    gets(a);
    int n=strlen(a),x=0,y=0,z=0,c=0;
    for(int i=0;i<n;i++){
        if(a[i]=='a'){
            x++;
        }
        else if(a[i]=='b'){
            y++;
        }
        else if(a[i]=='c'){
            z++;
        }
        if(x&&y&&z){
            x=0;
            y=0;
            z=0;
            c++;
        }
    }
    printf("\n%d substrings...",c);
    t--;
    }
}
