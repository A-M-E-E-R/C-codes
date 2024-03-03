#include<stdio.h>
int n;
int rat(int r,int unit,int arr[])
{
    int c=r*unit;
    if(n==0)
    {
        return -1;
    }
    int total_food=0,count=0;
    for(int i=0; i<n; i++)
    {
        total_food+=arr[i];
        count++;
        if(c<=total_food) break;
    }
    if(total_food-c>=0)
    {
        return count;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int r,unit;
    printf("\nr: ");
    scanf("%d",&r);
    printf("\nUnit: ");
    scanf("%d",&unit);
    printf("\nn: ");
    scanf("%d",&n);
    int arr[n];
    printf("\narr: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("%d",rat(r,unit,arr));
}
