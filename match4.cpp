# include <iostream>
# include <string>
# include <vector>
# include <random>
# include <algorithm>


// function to reduce syntax for input
inline std::string input(std::string msg){
	std::string inp; // to store the input
	
	// asking user for the input
	std::cout << msg;
	std::cin >> inp;
	
	// returning the input
	return inp;
}

// main program execution starts from here
int main(int argc, char** argv){
	// array of words and other variables declared
	std::vector<std::string> words = {
		"banana", "applesauce", "beans", "crispy", "chocolate",
		"potato", "book", "controller", "january", "painting"
	};
	std::string choice, inp; // choice for the word to show user and the input by user
	// random number generator seeded with random_device
	std::random_device rd;
	std::mt19937 mt(rd());
	int points; // the total points scored by the user

	std::cout << "\nDILLUSIONERS WORD GAME\n\n\n"; // welcome text

	for(int i = 0; i < (int)(words.size()); i++){
		// getting the current vector index and then shuffling the characters around
		choice = words[i];
		std::shuffle(choice.begin(), choice.end(), mt);

		// printing and asking for choice
		std::cout << "Your unscrambled word is " << choice << ".\n";
		inp = input("Enter your guess (You have only one try): ");

		// sorting both the choice and the input
		std::sort(choice.begin(), choice.end());
		std::sort(inp.begin(), inp.end());

		// checking if the sorted choice is equal to the sorted input
		if(choice == inp) std::cout << "\nCorrect choice! One point added to your total score.";
		else std::cout << "\nWrong choice! The correct word was " << words[i] << "!. No point was added to the score.";
		std::cout << "\n\n";

		// appending points if the input was correct
		points += (choice == inp);

		// resetting the string variables
		choice = "";
		inp = "";
	}

	std::cout << "Match is over! Your total score was " << points << " points out of 10.\n"; // end text
    return 0;
}
