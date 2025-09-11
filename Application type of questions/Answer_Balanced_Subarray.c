#include <stdio.h>
#include<stdlib.h>

int odd(int n){
    if(n%2) return 1;
    else return 0;
}

int main() {
    int n,streak=0,temp_streak=0,current,esum,osum,end_mark;
    int *arr = NULL;
    while(1){
        printf("Enter the number of elements to be entered: ");
        scanf("%d",&n);
        if (n>0)break;
        printf("Nice try...\n\n");
    }
    arr = (int*) malloc(n*sizeof(int));
    printf("Enter the numbers: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        current = esum = osum = 0;
        for(int j=i;j<n;j++){
            current++;
            if(odd(arr[j])) osum+=arr[j];
            else esum += arr[j];
            if (osum==esum){
                temp_streak = current;
                if(temp_streak>streak)end_mark = j;
            }
        }
        if(temp_streak>streak)streak=temp_streak;
    }
    
    if(streak){
        printf("The longest Balanced subarray array length is %d",streak);
        printf("\nThe Subarray: ");
        for (int i = end_mark-streak+1; i <= end_mark; i++)
        {
            printf("%d ",arr[i]);
        }
    }
    else printf("\n\nThere is no Balanced Subarray");

    free(arr);
    arr = NULL;
    
    return 0;
}
