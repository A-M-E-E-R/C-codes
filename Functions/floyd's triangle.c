#include<stdio.h>
void floyd(int n){
    int cnt=1;
    for (int i=1;i<=n;i++){
            int j=i;
        while(j!=0){
            printf("%d ",cnt++);
            j--;
        }
        printf("\n");
    }
}
int main(){
printf("Enter the number of Rows required to print: ");
int n;
scanf("%d",&n);
floyd(n);
return 0;
}
