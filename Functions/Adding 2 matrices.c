#include<stdio.h>
void add(int a[3][3],int b[3][3]);
int main(){
int a[3][3],b[3][3];
printf("Enter the Values for 1st \n");
for (int i=0;i<3;i++){
    for (int j=0;j<3;j++){
        scanf("%d",&a[i][j]);
    }
}
printf("Enter the Values for 2nd\n");
for (int i=0;i<3;i++){
    for (int j=0;j<3;j++){
        scanf("%d",&b[i][j]);
    }
}
add(a,b);
}
void add(int a[3][3],int b[3][3]){
int sum[3][3];
for (int i=0;i<3;i++){
    for (int j=0;j<3;j++){
        sum[i][j]=a[i][j]+b[i][j];
            printf("%d ",sum[i][j]);
    }
    printf("\n");
}
}
