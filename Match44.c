/**
 * Author - Debag101
 * Purpose - Network analytics(noobie edition)
 * Date - 30 - 5- 2023
*/

#include <stdio.h>
#include <string.h>

#define MAX_BUFFER 128

// Function prototypes
void get_data();
void print_data();
void print_analytics();

// Structure to store engagement parameters
struct engagement_parameters {
    char name[MAX_BUFFER];
    int contacts;
    int posts;
} user;

int main(int argc, char const *argv[]) {
    get_data(); // Get user data
    print_data(); // Print user data
    print_analytics(); // Print analytics based on user data
    return 0;
}

// Function to get user data
void get_data() {
    printf("Enter your user id:\n");
    fgets(user.name, MAX_BUFFER, stdin);

    negative_contacts:
    printf("Enter your total contacts:\n");
    scanf("%d", &user.contacts);
    if (user.contacts < 0) {
        printf("Please enter a valid follower count!\n");
        goto negative_contacts; // If follower count is negative, prompt again
    }

    negative_posts:
    printf("Enter the number of posts you have made(This includes posts on any media form):\n");
    scanf("%d", &user.posts);
    if (user.posts < 0) {
        printf("Please enter a valid post count!\n");
        goto negative_posts; // If post count is negative, prompt again
    }

}

// Function to print user data
void print_data() {
    printf("Userid\t   contacts\tPosts\n");
    printf("%s\t\t%d\t\t%d", user.name, user.contacts, user.posts);
}

// Function to print analytics based on user data
void print_analytics() {
    float growth_rate, engagement;
    growth_rate = (float)user.contacts / user.posts; // Calculate the growth rate

    printf("\n\nYour contacts per post count is: %.2f ", growth_rate);
    if (growth_rate > 1000) {
        printf("\nGrowth rate is pretty high!");
    } else if (growth_rate > 500) {
        printf("\nGrowth rate is mediocre!");
    } else {
        printf("\nGrowth rate is slow but don't worry!");
    }

}
