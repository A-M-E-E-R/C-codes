#include<stdio.h>
int main(){
int n;
printf("Enter the number of inputs: ");
scanf("%d",&n);
int val[n];
printf("Enter the Values: ");
for(int i=0;i<n;i++){
    scanf("%d",&val[i]);
}
int wt[n],W;
printf("Enter the Weights: ");
for(int i=0;i<n;i++){
    scanf("%d",&wt[i]);
}
printf("Enter the Weight limit: ");
scanf("%d",&W);
for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
    if(wt[i]<wt[j]){
        {int temp = wt[i];
        wt[i]=wt[j];
        wt[j]=temp;
    }
     {int temp = val[i];
        val[i]=val[j];
        val[j]=temp;
    }
    }}
}
int sum=sum1=0;
for(int i=0;i<n;i++){
    if(W>=sum+wt[i]){
     sum=sum + wt[i];
      printf("%d ",wt[i]);
        sum1=sum1+val[i];
    }
}
printf("\n%d",sum1);
}
