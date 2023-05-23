# include <iostream>
# include <random>
# include <string>


// drawing the playing board
void drawBoard(int array[3][3]){
    // variable declaration
	int i, j;

    // looping for 3 times...
	std::cout << "===============\n";
	for(i = 0; i != 3; i++){
        // inner loop to print the crosses, circles and board
		for(j = 0; j != 3; j++){
            std::cout << "| ";
			if(array[i][j] == 0) std::cout << " ";
			else if(array[i][j] == 1) std::cout << "X";
			else if(array[i][j] == 2) std::cout << "O";
            std::cout << " |";
		}
		std::cout << "\n===============\n";
	}
	std::cout << std::endl;
}

// checks if the index is filled or not
constexpr bool occupied(int array[3][3], int choice){
    return array[choice / 3][choice % 3 - 1] != 0;
}

// checks if the entire array is filled or not
bool filled(int array[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(array[i][j] == 0) return false;
        }
    }

    return true;
}

// method to apply input either for user or for the ai
void applyInput(int array[3][3], int choice, bool run, bool isPlayer){
    std::random_device rd;
    std::mt19937 mt(rd());

    // running the loop until user provides a proper input
	while(run){
        // if the requested choice is inside the grid and the choice is done in an empty square
        if((choice > 0 && choice < 10) && !occupied(array, choice)){
		    if(isPlayer) array[choice / 3][choice % 3 - 1] = 1;
		    else array[choice / 3][choice % 3 - 1] = 2;
		    run = false;
        }

        // if the input is invalid by user or for applying input for the bot
		else{
			if(isPlayer){
				std::cout << "\nInvalid Choice! Try Again: ";
				std::cin >> choice;
			}
			else choice = (mt() % 9) + 1;
		}
	}
}

// checking if player wins
bool playerWins(int array[3][3]){
    // varialbles declared
	int i, j, count1 = 0, count2 = 0;
    // checking if won diagonally and horizontally and vertically
	for(i = 0; i != 3; i++){
		count1 = 0;
		for(j = 0; j != 2; j++){
			if(array[i][j] == array[i][j+1] && array[i][j] != 0) count1++;
		}
		if(count1 == 2) return true;
	}
	for(i = 0; i != 2; i++){
		if(array[i][j] == array[i+1][j] && array[i][j] != 0) count2++;
	}
	if(count2 == 2) return true;
	return false;
}

int main(int argc, char const *argv[]){
    // variable declaration
	std::string clear;
    std::random_device rd;
    std::mt19937 mt(rd());

    #if defined(_WIN32)
        clear = "cls";
    #else
        clear = "clear";
    #endif

	int game[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	}, choice;
	char wantToPlay;
	bool running, win;

    // asking the user if they want to play
	std::cout << "\n\n\t\tDillusioners Tic Tac Toe Game\n\n\n" 
			  << "\nInstructions:\n\nYou must enter a value between 1 to 9\nwith which your choice will be placed accordingly\n\n"
			  << "1 is top-left, 7 is the bottom-left, 3 is top-right, 9 is bottom-right\nand rest of the values are arranged accordingly\n\n";

	std::cout << "Do you want to play?(Y/n): ";
	std::cin >> wantToPlay;

	if(wantToPlay == 'y' or wantToPlay == 'Y') running = true;
	else std::cout << "Alright! Closing the program.";

    // running the game....
	while(running){
		system(clear.c_str());

		drawBoard(game); // drawing board
		win = playerWins(game); // checking if won
		if(win){std::cout << "You have won the game!"; return 0;}

		std::cout << "Enter your choice(1-9): "; // asking for choice
		std::cin >> choice;

    // applying input
		applyInput(game, choice, running, true);
		choice = mt();
		if(!filled(game)) applyInput(game, choice, running, false);
	}

	return 0;
}
