import java.util.*;

public class match12 {
    //Creating Random object
    static Random rand = new Random();
    //Maximum number of tries
    static int tries = 10;

    //Method to print board
    public static void printBoard(int[][] board, int size) {
        // iterating through the array and printing it
        for (int i = 0; i < size; i++)
            System.out.println(Arrays.toString(board[i]));
    }
    //Method to create board
    public static int[][] BoardGenerator(int side) {
        // creating a new board and filling it all with 0s
        int[][] Board = new int[side][side];
        for (int i = 0; i < side; i++)
            Arrays.fill(Board[i], 0);

        return Board; // returning the board

    }
    //Method to generate bombed board
    public static int[][] bombPlacer(int side) {
        int[][] bombBoard = new int[side][side];
        // iterating through the board and filling random indexes with bomb
        for (int i = 0; i < side; i++) {
            for (int j = 0; j < side; j++) {
                if (rand.nextBoolean())
                    bombBoard[i][j] = -1;
            }
        }
      
        // returning the new board
        return bombBoard;
    }
    //Program execution starts from here
    public static void play(int[][] NB, int[][] BB, int size)  {
        // variables declared here
        Scanner rd = new Scanner(System.in);
      
        // looping until user has run out of tries
        for (int i = 0; i < tries; i++) {
            System.out.println("Current Board => ");
            printBoard(NB, size);
            
            // looping until proper input is provided
            while (true) {
                // asking for indexes of the row and coloumn user wants to put
                System.out.println(">> Enter the row index for the safe square");
                int row = rd.nextInt();
                System.out.println(">> Enter safe index for coloumn sqaure");
                int coloumns = rd.nextInt();
              
                // if the row or coloumn in invalid
                if (row >= size || row < 0 || coloumns >= size || coloumns < 0){
                    System.out.println("Invalid Sqaure");
                    continue; 
                }
              
                // if the selected row has a bomb in it
                if (BB[row][coloumns] == -1) {
                    System.out.println("You lost there was a bomb there !");
                    NB[row][coloumns] = -1;
                    printBoard(NB, size);
                    return;
                } 
              
                // if the selected row has no bomb in it
                else if (BB[row][coloumns] == 0) {
                    NB[row][coloumns] = 1;
                    System.out.println("You are safe !!");
                    break;
                } 
                
                // if the selected row was already selected by the user
                else if (BB[row][coloumns] == 1) {
                    System.out.println("Sqaure has already been pressed !");
                    break;
                }
            }
        }
      
        // running when the user has successfully survived for the given tries
        System.out.println(">> You have won !!!");
        rd.close();
    }

    //Main method
    public static void main(String[] args) {
        // variables declaration
        int boardSize = rand.nextInt(4, 11);
        int[][] Board, BombedBoard;
        Board = BoardGenerator(boardSize);
        BombedBoard = bombPlacer(boardSize);
      
        // playing the game
        play(Board, BombedBoard, boardSize);
    }
}
