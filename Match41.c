/**
 * Author - Debag101
 * Purpose - Destination Optimiser
 * Date - 30 05 2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MaxBuffer 128

// Displays context to user
void display() {
    printf("==========DESTINATION OPTIMISER==========\n");
}


// Execution starts
int main(int argc, char const *argv[]) {

    int count_destinations;

    display(); // Displaying context to user

    printf("How many destinations do you have => \n");
    scanf("%d", &count_destinations);// Getting the number of destinations

    if(count_destinations < 0) // No negative destinations available
        printf("Not a valid number of destinations !");
    else {
        float distanceof_destinations[count_destinations]; // Creating the set/list of distances

        for(int i = 0; i < count_destinations; i++) { // Looping over

            negative_distance:
            printf("Enter distance of destination %d in kms => \n", (i+1));
            scanf("%f", &distanceof_destinations[i]); // Gets the distances one by one

            if(distanceof_destinations[i] < 0) { //No negative distance
                printf("Please enter valid distance !\n");
                goto negative_distance; // Simple and efficient use of goto
            } else if(distanceof_destinations[i] >= 10000) 
                printf("Deliver through sea or aerial routes !\n");
            else if(distanceof_destinations[i] >= 5000) 
                printf("Deliver through sea or land routes!\n");
            else 
                printf("Deliver through land routes!\n");
        }
    }

    printf("Enter any key to exit..........\n");
    getch();
    system("cls");
    return 0;
}