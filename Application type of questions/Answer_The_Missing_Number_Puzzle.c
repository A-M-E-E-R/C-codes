#include <stdio.h>
#include <stdlib.h>

int main() {
 int n;
 int *arr = NULL;
 
 printf("Enter the number of elements to be taken: ");
 scanf("%d",&n);
 
 arr = (int*) malloc(n * sizeof(int));
 printf("Enter your inputs: \n");
 for(int i=0;i<n;i++){
     scanf("%d",&arr[i]);
 }
 int max=arr[0],min=arr[0];
  for(int i=1;i<n;i++){
      if (max<arr[i]) max = arr[i];
      if (min>arr[i]) min = arr[i];
 }
 int something=0;
 for(int j = min;j<max;j++){
     int count=0;
     for(int i=0;i<n;i++){
         if(j==arr[i]) break;
         count++;
     }
     if(count==n){
        if (!something) printf("\n\nThe missing numbers are: ");
        if(something) printf(", ");
        something++;
        if(j==7){
            printf("SUUII...");
            continue;
        }
        printf("%d",j);
     }
    }
    if(!something) printf("\n\nThere are no missing numbers.");
    
    free(arr);
    return 0;
}
