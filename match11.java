/*
 * Author - Debag101
 * Purpose - Number Guesser game
 * Date - 26 - 5 - 2023
 */

//IO package classes for input
import java.io.BufferedReader;
import java.io.InputStreamReader;
//Random from util to generate random integer
import java.util.Random;

public class match11 {
    // Member variables
    int MAX_LIVES, MAX_RANGE, rand_num;
    // Status of game won or lost
    boolean game_won;

    match11() {
        // Intiliasing member varibles
        game_won = false;
        MAX_LIVES = 10;
        MAX_RANGE = 100;
        // Generating random number
        rand_num = generate_rand_num();
    }

    // Function to generate random number
    int generate_rand_num() {
        Random rand = new Random();
        return rand.nextInt(0, MAX_RANGE);
    }

    // Function to display context to user
    void display() {
        System.out.println("================RANDOM NUMBER GUESSER================\n");
        System.out.println(">> The number is within the range of 0 - 100");
        System.out.println(">> You have got 10 chances !\n");
    }

    // Gameplay starts
    void play() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int counter = 1; // Counts how many times user has guessed

        do {
            System.out.println("\n>> Lives left : " + (MAX_LIVES - counter + 1));
            System.out.println(">> Enter your guess => ");
            try { // try-catch to clean out string inputs
                int guess = Integer.parseInt(reader.readLine());
                if (guess == rand_num) {
                    game_won = true; // If user wins the game
                    break;
                } else if (guess < rand_num)
                    System.out.println("Number is higher than " + guess); // If user's guess is lower
                else
                    System.out.println("Number is lower than " + guess); // If user's guess is higher

                counter++; // Incrementing counter
            } catch (Exception NumberFormatException) {
                System.out.println("Invalid Input! One chance wasted!");
                counter++;
            }

        } while (counter <= MAX_LIVES);
    }

    // Display result based on boolean member variable `game_won`
    void display_result() {
        if (game_won)
            System.out.println("You have won the game !");
        else
            System.out.println("You have lost the game, the number was " + rand_num);
    }

    // Running the code
    public static void main(String[] args) {
        match11 obj = new match11();
        obj.display();
        obj.play();
        obj.display_result();
    }
}