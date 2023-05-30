/**
 * Author - Debag101
 * Purpose - Movie Adviser/ Referencer
 * Date - 30 05 2023
*/

// Including necessary header files
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>


// Displays header of console print
void display_header() {
    printf("==================WELCOME TO MOVIE REFERENCER==================\n");
}

// Displays context and movie preference choices
void display_context() {
    printf("1.Horror Movies\n2.Action Movies\n3.Philosphical Movies\n4.Fantasy Movies\n5.Miscellaneous\nEnter your choice => ");
}


// Displays 5 horror movies
void Horror() {
    printf("We would like to suggest the following :\n The Conjuring\nHalloween\nThe Exorcist\nA Nightmare on Elm Street\nThe Shining");
}


// Displays 5 action movies
void Action() {
    printf("We would like to suggest the following : \nDie Hard\nThe Dark Knight\nMad Max: Fury Road\nJohn Wick\nMission: Impossible - Fallout");
}


// Displays 5 philosphical movies
void Philosophical() {
    printf("We would like to suggest the following : \nThe Matrix\nEternal Sunshine of the Spotless Mind\nBlade Runner\nInception\nFight Club");
}


// Displays 5 fantasy movies
void Fantasy() {
    printf("We would like to suggest : \nThe Lord of the Rings\ntrilogy\nHarry Potter series\nPan's Labyrinth\nThe Chronicles of Narnia series\nAvatar");
}


// Displays 5 Miscellaneous movies
void Miscellaneous() {
    printf("We would like to suggest : \nPulp Fiction\nThe Shawshank Redemption\nThe Grand Budapest Hotel\nHer\nThe Social Network");
}


// Main execution starts
int main(int argc, char const *argv[])
{
    // Displaying header
    display_header();

    // while(true) for invalid input| breaks for valid input
    while(true) {
        int choice;

        display_context();
        scanf("%d", &choice); // Getting users choice

        if(choice < 0 || choice > 5) 
            printf("Invalid option !\n");  // Invalid choice condition
        else if(choice == 1) {
            Horror(); // Horror movie
            break;
        }
        else if(choice == 2){
            Action(); // Action movie
            break;
        }
        else if(choice == 3){
            Philosophical(); // Philosophical movies
            break;
        }
        else if(choice == 4){
            Fantasy(); // Fantasy movies
            break;
        }
        else {
            Miscellaneous(); // Miscellaneous movies
            break;
        }
    }   

    // Exit code functionality
    printf("\n\nEnter any key to exit..........\n");
    getch();
    system("cls");
    return 0;
}
