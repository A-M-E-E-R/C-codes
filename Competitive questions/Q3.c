#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int m1,p1,m2,p2;
    scanf("%d %d",&m1,&p1);
    scanf("%d %d",&m2,&p2);
    int s1= 0,s2= 0;
    int x=  0;
    int an=0;
    while(x!=n){
        if(an==0){
            s1=(n/m1)+1;
            x=s1*m1;
            an++;
        }
        if(x>n){
            x-=m1;
            s1--;
        }
        if(x<n){
            x+=m2;
            s2++;
        }
    }
    printf("\n%d",(s1*p1)+(s2*p2));
}