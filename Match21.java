/*
 * Author - Debag101
 * Purpose - Palindrome checker
 * Date - 27 - 5 - 2023
 */

import java.util.Scanner;

public class Match21 {
    // Member variable to store the string
    String input;

    Match21() {
        // displays context
        display_context();
        // gets the string
        getString();
    }

    void getString() {
        // Initialises scanner obj to take input
        Scanner sc = new Scanner(System.in);
        // Getting string from user
        System.out.println("Enter your input : ");
        input = sc.nextLine(); // Gets the input

        sc.close(); // Closes scanner obj to prevent memory leak
    }

    // Tells the user about the code
    void display_context() {
        System.out.println("\n==================PALINDROME CHECKER==================");
        System.out.println("NB :- Program is case sensitive !");
    }

    // Checks if string is palindrome
    void checkPalindrome() {
        if (input == "" || input.length() == 1) {// Empty strings are always palindrom
            System.out.printf("\n%s is a Palindrome !", input);
            return;
        } else {
            int midPoint = input.length() / 2;// Finding the midpoint index
            for (int i = 0; i <= midPoint; i++) {
                if (input.charAt(i) != input.charAt(input.length() - i - 1)) {
                    System.out.printf("\n%s is not a Palindrome !", input);// if we find any instance of not equals
                                                                           // we print that string is not a palindrome

                }
            }
        }

        System.out.printf("\n%s is a Palindrome !", input);
    }

    // Code execution starts
    public static void main(String[] args) {
        Match21 obj = new Match21();
        obj.checkPalindrome();
    }
}
