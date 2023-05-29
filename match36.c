/**
 * Author - Debag101
 * Purpose - Workout Tracker
 * Date - 29-5-2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int steps; // Number of steps taken
    int calories_burned; // Total calories burned
    char routine[100][50]; // Array to store workout routines
    int workouts_done; // Number of workouts done
} FitnessTracker;

void initializeTracker(FitnessTracker *tracker) {
    tracker->steps = 0;
    tracker->calories_burned = 0;
    tracker->workouts_done = 0;
}

void trackSteps(FitnessTracker *tracker, int num_steps) {
    tracker->steps += num_steps; // Increment the total steps
}

void trackCalories(FitnessTracker *tracker, int num_calories) {
    tracker->calories_burned += num_calories; // Increment the total calories burned
}

void trackWorkout(FitnessTracker *tracker, char *workout) {
    // Check if the number of workouts done is within the limit
    if (tracker->workouts_done < 100) {
        // Copy the workout name to the routine array
        strcpy(tracker->routine[tracker->workouts_done], workout);
        // Increment the number of workouts done
        tracker->workouts_done++;
    }
}

void displaySummary(FitnessTracker *tracker) {
    printf("Fitness Tracker Summary\n");
    printf("-----------------------\n");
    printf("Total Steps: %d\n", tracker->steps);
    printf("Total Calories Burned: %d\n", tracker->calories_burned);
    printf("Workout History:\n");
    for (int i = 0; i < tracker->workouts_done; i++) {
        printf("Workout %d: %s\n", i + 1, tracker->routine[i]);
    }
}

int main() {
    FitnessTracker tracker;
    initializeTracker(&tracker);

    // Tracking data
    trackSteps(&tracker, 2500); // Track 2500 steps
    trackCalories(&tracker, 150); // Track 150 calories burned
    trackWorkout(&tracker, "Running"); // Track a workout routine "Running"
    trackSteps(&tracker, 3000); // Track additional 3000 steps
    trackCalories(&tracker, 200); // Track additional 200 calories burned
    trackWorkout(&tracker, "Cycling"); // Track another workout routine "Cycling"

    // Displaying summary
    displaySummary(&tracker);

    return 0;
}
