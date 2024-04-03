#include<stdio.h>
#include"reservation.h"
int main(){
    room_numbering();
    checking();
    int opt;
    while(1){
        printf("\n1. to Reserve a room \n2. to Cancel reservation \n3. to check bookings and room availability \n4. to exit");
        printf("\nEnter: ");
        scanf("%d",&opt);
        switch (opt){
            case 1 :{
                printf("\nEnter the number of room to book: ");
                int c;
                scanf("%d",&c);
                room_booking(c);
                break;
            }
            case 2: {
                printf("\nEnter the room number to cancel: ");
                int c;
                scanf("%d",&c);
                cancellation(c);
                break;
            }
            case 3: {
                checking();
                break;
            }
            case 4 : {
                printf("\nThe Program Terminated... :)");
                exit (0);
            }
            default : {
                printf("\nThe Entered option is invalid... Try again");
            }
        }
    }
}
