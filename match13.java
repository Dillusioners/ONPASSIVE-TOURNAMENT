
/*Author - Debag101
 * purpose - connect 4
 * date - 26 - 5 - 2023
 */
import java.util.Arrays;
import java.util.Scanner;

public class match13 {
    final int MAX_ROWS, MAX_COLS;
    char[][] board;
    char player1, player2;

    // generating player symbols and board
    match13() {
        player1 = 'O';
        player2 = 'X';
        MAX_ROWS = 6;
        MAX_COLS = 7;
        board = new char[MAX_ROWS][MAX_COLS];
        fillBoard();
    }

    // FIlling board
    void fillBoard() {
        for (int i = 0; i < MAX_ROWS; i++) {
            Arrays.fill(board[i], '_');
        }
    }

    // Displaying board
    void displayBoard() {
        for (int i = 0; i < MAX_ROWS; i++)
            System.out.println(Arrays.toString(board[i]));
    }

    // context for user

    void displayContext() {
        System.out.println("Player 1 gets 'O' & player 2 gets 'X !");
    }

    // CHecking who won based on symbol
    boolean hasWon(char sym) {
        // vertical
        for (int i = 0; i < MAX_ROWS; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == sym && board[i][j + 1] == sym && board[i][j + 2] == sym && board[i][j + 3] == sym)
                    return true;
            }
        }
        // horizontal
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < MAX_COLS; j++) {
                if (board[i][j] == sym && board[i + 1][j] == sym && board[i + 2][j] == sym && board[i + 3][j] == sym)
                    return true;
            }
        }

        // down diagonal
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (board[i][j] == sym && board[i + 1][j + 1] == sym && board[i + 2][j + 2] == sym
                        && board[i + 3][j + 3] == sym)
                    return true;
            }
        }

        // up diagonal
        for (int k = MAX_ROWS - 1; k > 2; k--) {
            for (int j = 0; j < 2; j++) {
                if (board[k][j] == sym && board[k - 1][j + 1] == sym && board[k - 2][j + 2] == sym
                        && board[k - 3][j + 3] == sym)
                    return true;

            }
        }

        return false;
    }

    // Placing symbols
    void place(char symbol, int col) {
        for (int i = MAX_ROWS - 1; i >= 0; i--) {
            if (board[i][col - 1] == '_') {
                board[i][col - 1] = symbol;
                return;
            }
        }
        System.out.println(">> Slot is already occupied!");
    }

    // Gameplay starts
    void play() {
        Scanner sc = new Scanner(System.in);
        int counter = 0;
        displayContext();
        while (counter < 42) {
            displayBoard();
            System.out.println("Which coloumn do you choose ? ");
            int col_choice = sc.nextInt();
            if (col_choice < 0 || col_choice > 7)
                System.out.println("Invalid choice !");
            else {
                if (counter % 2 == 0) {
                    place(player1, col_choice);
                    if (hasWon(player1)) {
                        System.out.println("PLayer 1 has won");
                        break;
                    }
                } else {
                    place(player2, col_choice);
                    if (hasWon(player2)) {
                        System.out.println("Player two has won");
                        break;
                    }
                }
            }
            counter++;
        }
        sc.close();
    }

    // Main method
    public static void main(String[] args) {
        match13 obj = new match13();
        obj.play();
        obj.displayBoard();
    }
}
