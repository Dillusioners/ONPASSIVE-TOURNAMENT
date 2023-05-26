# include <iostream>
# include <random>

// defining the colors
# define white 1
# define black 2

// the game board
int board[8][8];

// loading the board
void load(){
    // filling the entire board with 0s
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            board[i][j] = 0;
        }
    }

    // initializing the starting positions
    board[3][3] = white;
    board[3][4] = white;
    board[4][3] = black;
    board[4][4] = black;
}

void printBoard(){
    // the gap between two rows
    std::string equals = "========================================";

    // printing each element of the board as W or B or blank space
    std::cout << equals << '\n';
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            std::cout << "| ";

            // if board index is white, print W, else print B, else print a blank
            if(board[i][j] == white) std::cout << 'W';
            else if(board[i][j] == black) std::cout << 'B';
            else std::cout << ' ';

            std::cout << " |";
        }
        std::cout << std::endl << equals << std::endl;
    }
}

// function to update the given row and coloumn
void update(int row, int col, bool user){
    // switch case based on the board value in row and coloumn
    switch(board[row][col]){
        case white: { // white
            // if it is the user, rejecting to place there
            // if it the bot, replace the index with black
            if(user) std::cout << "You cannot place your piece there.";
            else board[row][col] = black;
            break;
        }

        case black: { // black
            // if it the user, replace a black piece and place a white piece
            if(user){
                std::cout << "Successfully replaced my black piece with your white piece.\n";
                board[row][col] = white;
            }
            break;
        }

        case 0: { // empty
            // if it the user, place a white piece, else place a black piece
            if(user){
                std::cout << "Placed your white piece on a new square.\n";
                board[row][col] = white;
            }
            else board[row][col] = black;
            break;
        }
    }
}

// function to check if the user is winning or not
bool userWins(){
    // the total count of white and black pieces on the board
    int whites = 0, blacks = 0;

    // iterating through the board
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            // if the current index is white, the total white count increases. same for the black.
            whites += (board[i][j] == white);
            blacks += (board[i][j] == black);
        }
    }

    // returning whether the white pieces count is more than the blacks
    return (whites > blacks);
}

// program execution starts from here
int main(int argc, char** argv){
    // loading the board and declaring variables
    load();
    std::random_device rd;
    std::mt19937 mt(rd());
    int row = 0, col = 0;

    // prologue text
    std::cout << "WELCOME TO DILLUSIONERS Reversi/Othello.\n\n";
    std::cout << "You will be representing the white pieces and I will be representing the black pieces.\n";
    std::cout << "After 15 moves, the one with the most colored pieces wins the game.\n";

    // iterating 15 times
    for(int i = 0; i < 15; i++, row = 0, col = 0){
        // printing the board and asking user for the row and coloumn count
        std::cout << std::endl;
        printBoard();
        std::cout << "\nEnter the row number: ";
        std::cin >> row;
        std::cout << "Enter coloumn number: ";
        std::cin >> col;
        std::cout << std::endl;

        // decreasing by 1 as array indexing starts from 0 in c++
        row--, col--;

        // if the row and coloumn count provided is invalid
        if(row < 0 || row > 7 || col < 0 || col > 7) continue;

        update(row, col, true); // updating the board on user input
        update(mt() % 8, mt() % 8, false); // updating the board on bot input
        std::cout << std::endl;        
    }

    // ending text and printing who has won the game
    std::cout << "15 moves are over.\n";
    if(userWins()) std::cout << "You have won.\n";
    else std::cout << "I have won.\n";

    return 0;
}
