/**
 * Author - Debag101
 * Purpose - Social Media analytics(noobie edition)
 * Date - 28 - 5- 2023
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
    char user_id[MAX_BUFFER];
    int followers;
    int posts;
    int total_likes;
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
    fgets(user.user_id, MAX_BUFFER, stdin);

    negative_followers:
    printf("Enter your total followers:\n");
    scanf("%d", &user.followers);
    if (user.followers < 0) {
        printf("Please enter a valid follower count!\n");
        goto negative_followers; // If follower count is negative, prompt again
    }

    negative_posts:
    printf("Enter the number of posts you have made:\n");
    scanf("%d", &user.posts);
    if (user.posts < 0) {
        printf("Please enter a valid post count!\n");
        goto negative_posts; // If post count is negative, prompt again
    }

    negative_likes_per_post:
    printf("Enter the total count of likes you have received: ");
    scanf("%d", &user.total_likes);
    if (user.total_likes < 0) {
        printf("Please enter a valid average likes per post: ");
        goto negative_likes_per_post; // If like count is negative, prompt again
    }
}

// Function to print user data
void print_data() {
    printf("User id\tFollowers\tPosts\tAverage Likes\n");
    printf("%s\t\t%d\t\t%d\t\t%d", user.user_id, user.followers, user.posts, user.total_likes);
}

// Function to print analytics based on user data
void print_analytics() {
    float growth_rate, engagement;
    growth_rate = (float)user.followers / user.posts; // Calculate the growth rate
    engagement = (float)user.total_likes / user.posts; // Calculate the engagement rate

    printf("\n\nYour followers per post count is: %.2f ", growth_rate);
    if (growth_rate > 1000) {
        printf("\nGrowth rate is pretty high!");
    } else if (growth_rate > 500) {
        printf("\nGrowth rate is mediocre!");
    } else {
        printf("\nGrowth rate is slow but don't worry!");
    }

    printf("\n\nYou garner about %.2f likes per post!", engagement);
    if (engagement > 10000) {
        printf("\nEngagement seems to be very high!");
    } else if (engagement > 5000) {
        printf("\nEngagement is good enough!");
    } else {
        printf("\nTry making better content!");
    }
}
