 #include<stdio.h>
int main(){
int n;
printf("Enter the Number of inputs: ");
scanf("%d",&n);
int p[n],w[n];
printf("\nEnter %d profit: ",n);
for(int i=0;i<n;i++){
    scanf("%d",&p[i]);
}
printf("\nEnter %d weights: ",n);
for(int i=0;i<n;i++){
    scanf("%d",&w[i]);
}
int W;
printf("Enter the Weight of the items: ");
scanf("%d",&W);
int c[n];
for(int i=0;i<n;){
    if(W>=w[i]){
        c[i]=p[i];
    }
    c[++i]=0;
}
int profit=0;
for(int i=0;i<n;i++){
    if(profit<c[i]){
        profit=c[i];
    }
}
printf("%d is the profit",profit);
}
