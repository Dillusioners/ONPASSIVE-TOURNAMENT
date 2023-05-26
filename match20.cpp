# include <iostream>
# include <random>
# include <thread>
# include <chrono>

// some constant values declared for easier code readability
# define size 10
# define player 1
# define enemy 2
# define killed 3

// the board which will contain the battleships
int board[size][size];


// method to slowly print a text
inline void slowPrint(std::string text, int delay = 40){
   // iterating through the string
   for(auto t : text){
   	// printing a character and flushing the stream
   	std::cout << t << std::flush;
   	// sleeping the program
   	std::this_thread::sleep_for(std::chrono::milliseconds(delay));
   }
}

// loading the board
void loadBoard(){
    // variable declaration here
    std::random_device rd;
    std::mt19937 mt(rd());
    int row, col, i, j;

    // filling the entire board with 0s
    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            board[i][j] = 0;
        }
    }

    // looping 10 times to generate 10 battleships
    for(i = 0; i < size; i++){
        // generating random ship location
        row = mt() % size;
        col = mt() % size;

        // if there is already a ship in that place, skip this iteration
        if(board[row][col] == player || board[row][col] == enemy){
            i--;
            continue;
        }

        // if the current iteration is lesser than size/2 it will be marked as player ship
        // else it will be an enemy ship
        if(i < size / 2) board[row][col] = player;
        else board[row][col] = enemy;
    }
}

// function to print the board
void printBoard(bool printEnemyLoc = false){
    // the gap between two rows
    std::string equals = "==================================================";

    // printing each element of the board as X or 0 or U or blank space
    std::cout << equals << '\n';
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            std::cout << "| ";

            // if current index is:
            // player -> print x
            if(board[i][j] == player) std::cout << 'X';
            // killed -> print 0
            else if(board[i][j] == killed) std::cout << '0';
            // enemy and printing enemy location is allowed -> print U
            else if(board[i][j] == enemy && printEnemyLoc) std::cout << 'U';
            // else print blank
            else std::cout << ' ';

            std::cout << " |";
        }
        std::cout << std::endl << equals << std::endl;
    }
}

// function to print the prologue of the game
void prologue(){
    slowPrint("WELCOME TO DILLUSIONERS BATTLESHIP SIMULATION", 20);
    std::cout << "\n\n";
    slowPrint("[Unit Member] Good morning sir.\n[Unit Member] Soldiers on standby have detected an unknown ship.\n");
    slowPrint("[Unit Member] We don\'t know yet where those ship could be, but they are in a 10km radius from where we are.\n");
    slowPrint("[Unit Member] Here is a rough sketch of the radius.\n");
    printBoard();
    slowPrint("\n[Unit Member] The X marks are our ships on standby which have noticed the attackers.\n");
    slowPrint("[Player] Alright. Alert everyone in the proximity and bring me 10 missiles.\n");
    slowPrint("[Player] I will try my best to shoot them off of the area, they should know what we are.\n");
    slowPrint("[Unit Member] Understood, seargant.\n");
    std::cout << "\n\nStarting the game";
    slowPrint(".............", 250);
}

// program execution starts from here
int main(int argc, char** argv){
    // variables declared and prologue spoken
    loadBoard();
    int row, col, tries;
    prologue();

    // looping for 10 times, as there are 10 tries to shoot
    for(tries = 0; tries < 10; tries++){
        // printing the current enemy location with index, and asking user for the row and coloumn number to shoot
        std::cout << "\n\n";
        printBoard();
        std::cout << "X -> Friendly, 0 -> Killed\n\n";
        std::cout << "Enter the row number: ";
        std::cin >> row;
        std::cout << "Enter the coloumn number: ";
        std::cin >> col;
        std::cout << std::endl;

        // row and coloumn are reduced as array indexing starts from 0 in c++
        --row, --col;

        // if the location is not in array
        if(row < 0 || row >= size || col < 0 || col >= size){
            std::cout << "You hit outside the bounds of the map! Surprising!!!!!!!!!!!!";
            continue;
        }

        // switch-case on the value of the chosen square
        switch(board[row][col]){
            case 0: { // empty area
                std::cout << "You have missed your shot.";
                continue;
            }

            case player: { // a friend was shot
                std::cout << "Are you crazy? You just shot down your comrades!";
                board[row][col] = killed;
                continue;
            }

            case enemy: { // an enemy was shot
                std::cout << "Perfect aim! You successfully show down an enemy ship.";
                board[row][col] = killed;
                continue;
            }

            case killed: { // a killed location was shot
                std::cout << "Ships aren\'t grouped together. There were no ships in the vicinity.";
                continue;
            }
        }
    }

    // printing the ending text
    printBoard(true);
    std::cout << "X -> Friendly, 0 -> Killed, U -> Alive Enemy.\n";
    slowPrint("\n\n[Player] Another day at work........\n[Player] Atleast they will know not to mess with us.\n");

    return 0;
}
