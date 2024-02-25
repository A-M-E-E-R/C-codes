#include<string.h>
#include<stdio.h>
int main(){
    int t;
    printf("\nEnter the number of test cases to be run: ");
    scanf("%d",&t);
    while(t){
        char a[25];
        printf("\nEnter the string: ");
        getchar();
        gets(a);
        int n=strlen(a),l=0,c=0;
        char an[n];
        an[0]=a[0];
        int k=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                if(an[j]!=a[i]){
                    l++;
                }
            }
            if(k==l){
                an[k]=a[i];
                k++;
                if(c<=l){
                    c=l+1;
                }
            }
            else{
                k=1;
                an[0]=a[i];
            }
            l=0;
        }
        printf("\n%d is the longest unique substring...",c);
        t--;
    }
}
