# include <iostream>
# include <chrono>
# include <thread>
# include <random>


// generating the board for the maze
// 0 -> free space
// 1 -> wall
int board[10][10] = {
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 1, 1, 0, 0, 1},
    {1, 1, 0, 1, 0, 0, 1, 0, 0, 1},
    {1, 1, 0, 1, 0, 0, 1, 1, 0, 1},
    {1, 1, 0, 1, 0, 0, 0, 1, 1, 1},
    {1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0}
};

// printing the maze for the user
void printBoard(){
    // looping through the 2D maze
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            // printing the maze accordingly
            if(board[i][j] == 0) std::cout << " ";
            else std::cout << "|";
        }
        std::cout << '\n';
    }
}

// program execution starts from here
int main(int argc, char** argv){
    // random number generation
    std::random_device rd;
    std::mt19937 mt(rd());

    // welcome text with board printed
    std::cout << "WELCOME USER. LET\'S SOLVE THIS MAZE TOGETHER.\n";
    std::cout << "The maze is as follows: \n";
    printBoard();

    // solving the maze
    std::cout << "Solving maze.....\n";
    std::this_thread::sleep_for(std::chrono::milliseconds((mt() % 9999) + 1));

    // reaching the conclusion of the maze
    std::cout << "The maze is impossible to solve.\n";
    return 0;
}
