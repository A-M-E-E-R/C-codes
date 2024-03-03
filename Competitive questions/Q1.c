#include<stdio.h>
int main(){
    int v,w;
    printf("\nEnter the total number of vehicles: ");
    scanf("%d",&v);
    printf("\nEnter the total number of wheels: ");
    scanf("%d",&w);
    int f,t;
    if(v%2) f=(v/2)+1,t=v/2;
    else f=v/2,t=v/2;
    if(w>=2 && w%2==0 && v<w){
        while(((f*4)+(t*2)!= w)){
            if(((f*4)+(t*2)) > w){
                f--;
                t++;
            }
            else if(((f*4)+(t*2)) < w){
                f++;
                t--;
            }
        }
        printf("\n Two wheelers = %d and Four wheelers = %d",t,f);
    }
    else
        printf("\nINVALID INPUT");
}
