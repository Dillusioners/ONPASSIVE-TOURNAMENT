/*
 * Author - Debag101
 * Purpose
 */
import java.util.Scanner;

public class Match6 {
    //Score variable to store user's score
    int score;
    //Questions and answers storage using arrays
    String[] Questions;
    char[] Answers;

    Match6() {
        //Initialising vars
        score = 0;
        Questions = new String[3];
        Answers = new char[3];
        //Adding questions and answers to the arrays respectively
        AddQnA();
    }

    void AddQnA() {
        //Manually adding questions
        Questions[0] = "When did India gain Independence ?\na.1945\nb.1934\nc.1947\nd.1971\n";
        Questions[1] = "Who was the first person to walk on the moon ?\na.Neil Armstrong \nb.Ram Das \nc.Sunil Chatterjee \nd.NigerBoi sams";
        Questions[2] = "What is the smallest plannet of our solar system ?\na.Venus \nb.Earth \nc.Mercury \nd.Pluto";

        //Manually adding answers
        Answers[0] = 'c';
        Answers[1] = 'a';
        Answers[2] = 'c';
    }

    //Method that starts the game
    void play() {
        //scanner obj for input
        Scanner sc = new Scanner(System.in);
        //counter to store rounds
        int counter = 0;
        do {
            //Prints question
            System.out.printf("\nQuestion no. %d\n%s",counter + 1, Questions[counter]);
            //Prompts for answer
            System.out.println("\nEnter your answer : ");

            //Gets user input
            char answer = sc.next().charAt(0);
            answer = Character.toLowerCase(answer);

            //Checks the answer
            if(answer != 'a' && answer != 'b' && answer != 'c' && answer != 'd') {
                System.out.println("Invalid answer : ");
            } else if(answer == Answers[counter]) {
                System.out.println("Correct answer !");
                counter++;
                score++;
            } else {
                System.out.println("Wrong answer correct answer was " + Answers[counter] + "!");
                counter++;
            }
        }
        while(counter < 3);
        //closing the obj
        sc.close();
    }

    //Prints user's score
    void printResult() {
        System.out.println("\n================Result================\n");
        System.out.println("You got " + score  + "/3 correct !");
    }
    //Main starts
    public static void main(String[] args) {
        Match6 obj = new Match6();
        obj.play();
        obj.printResult();
    }
}