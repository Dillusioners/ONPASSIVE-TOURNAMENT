# include <iostream>
# include <unordered_set>
# include <random>


// method to print the sudoku board
void printBoard(std::unordered_set<int> &board){
    // stores the current index of the board
    auto index = board.begin();

    // looping 9 times
    for(int i = 0; i < 9; i++){
        // if the board is empty print 0, else print the element in the index pointer
        if(board.empty()) std::cout << "| 0 |";
        else std::cout << "| " << ((!board.empty())? *index : 0) << " |";

        // if i is divisible by 3, print a space
        if((i + 1) % 3 == 0) std::cout << std::endl;
        // if board is not empty, append the index
        if(!board.empty()) index++;
    }
}

// function to solve a sudoku board
void solve(std::unordered_set<int> &board){
    // random number generator seeded with random seed
    std::random_device rd;
    std::mt19937 mt(rd());

    // running until the board size is 9
    while(board.size() != 9){
        int val = (mt() % 9) + 1; // random value generated

        // if the value is not in the board, insert it
        if(board.find(val) == board.end()) board.insert(val);
    }
}

// program execution starts from here
int main(int argc, char** argv){
    std::unordered_set<int> board; // the main board of the program

    // printing board before it is solved
    std::cout << "Sudoku board unsolved: \n";
    printBoard(board);

    // solving the sudoku board and then printing the result
    std::cout << "\nSudoku board solved:\n";
    solve(board);
    printBoard(board);
    
    return 0;
}
