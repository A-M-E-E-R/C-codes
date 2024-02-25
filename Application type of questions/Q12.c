#include<string.h>
#include<stdio.h>
int main(){
    int t;
    printf("\nEnter the number of test cases: ");
    scanf("%d",&t);
    while(t){
    printf("\nEnter the main String: ");
    char a[25];
    getchar();
    gets(a);
    printf("\nEnter the number of queries: ");
    int n,l=strlen(a);
    scanf("%d",&n);
    char q[n][10];
    int c[n],index[n][8];
    for(int i=0;i<n;i++){
        printf("\nEnter the %dth query: ",i+1);
        scanf("%s",q[i]);
        c[i]=0;
    }
    for(int i=0;i<n;i++){
        int ql=strlen(q[i]);
        for(int j=0;j<l;j++){
            int qp=0,p=0;
            while(q[i][p]==a[j]){
                p++;
                qp++;
                j++;
            }
            if(qp==ql){
                c[i]++;
                index[i][c[i]-1]=j-ql;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("\nRepetition: %d",c[i]);
        int j=0;
        if(c[i]) printf(" Indexes: ");
        while(j!=c[i]){
            printf("  %d",index[i][j]);
            j++;
        }
    }
    t--;
    }
}
