#include<stdio.h>
#include<stdlib.h>
typedef struct hotel{
    int booking;
    int room_num;
    char name[25];
}t;
t rooms[100];
int booked;
void room_numbering(){
    for(int i=0;i<100;i++){
        rooms[i].booking=0;
        rooms[i].room_num=i+1;
    }
    return;
}
int booking(int n){
    if(n<=0 || n>100){
        printf("\nThe entered Room number is Invalid");
        return 1;
    }
    else if(rooms[n-1].booking!=0){
        printf("\nThe entered Room is already booked...");
        return 1;
    }
    rooms[n-1].booking=1;
    printf("\nEnter the Name of booker: ");
    getchar();
    gets(rooms[n-1].name);
    booked++;
    return 0;
}
void room_booking(int num){
    if(num>100-booked  || num<1){
        printf("\nThe Entered number of Room are not available...");
        return;
    }
    while(num){
        int n;
nn:
        printf("Enter the Room number: ");
        scanf("%d",&n);
        if(booking(n)){
            goto nn;
        }
        num--;
    }
    return;
}
void checking(){
    if(booked==100){
        printf("\nAll the Room are booked...");
        return ;
    }
    printf("\n%d Rooms are booked",booked);
    printf("\n%d Rooms are available",100-booked);
    printf("\nAvailable rooms are:   \n");
    int c=0;
    for(int i=0;i<100;i++){
        if(rooms[i].booking){
            printf(" B   ");
            c++;
            continue;
        }
        printf("%2d   ",rooms[i].room_num);
        c++;
        if(c==10){
            printf("\n");
            c=0;
        }
    }
    return;
}
void cancellation(int n){
    if(rooms[n-1].booking){
        rooms[n-1].booking=0;
        booked--;
        printf("\nRoom booked by %s is being cancelated...\n...........\n.......\n...\n",rooms[n-1].name);
        printf("\nCancellation completed...");
    }
    else{
        printf("\nRoom number %d is not booked...",n);
    }
    return ;
}
