#include<stdio.h>
void bubble(int arr[],int n){
    int m=n,z=0,y=0;
    for(int i=0;i<n;i++){
        int c=0,c1=0;
        if(c1!=0 && c==0){
            break;
            }
            c1++;
            y++;
            for(int j=0;j<m;j++){
                    z++;
                if(arr[j]>arr[j+1]){
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                    c++;
                }
            }
            m--;
        }
    return ;
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    bubble(a,n);
    printf("\n");
    for(int i=0;i<n;i++){
        printf(" %d",a[i]);
    }
}