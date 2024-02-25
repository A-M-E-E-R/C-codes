#include<stdio.h>
int main(){
 int i = 111;
    char *c = (char*)&i;
    printf("\n%d",*c);
    if (*c)
        printf("Little endian");
    else
        printf("Big endian");
    return 0;
}
