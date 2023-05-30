# include <iostream>
# include <chrono>
# include <thread>

// function to reduce syntax for input
inline std::string input(std::string msg){
	std::string inp; // to store the input
	
	// asking user for the input
	std::cout << msg;
	std::getline(std::cin, inp);
	
	// returning the input
	return inp;
}

// function to print the introductory speech of the program
void introduction(){
    std::cout << "WELCOME TO DILLUSIONERS MORSE CODE CLASS.\n";
    std::cout << "\nMorse code is a language where only two characters (. and _) are used to represent alphabets.\n";
    std::cout << "Combination of dots and dashes help in representing the enlish alphabets.\n";
    std::cout << "This is more like a code language.\nIt is hard to grasp at first, but if you get used, it will be worth it.\n";
    std::cout << "But don\'t worry. This program will help you get the basics of morse code.\n\n";

    // sleeping the program for 10s 
    std::this_thread::sleep_for(std::chrono::milliseconds(10000));
}

// program execution starts from here
int main(int argc, char** argv){
    std::string inp;

    introduction();

    // giving the user the morse code of A and E
    std::cout << "In morse code, the characters A is shown as ._ and the character E is shown as .\n\n";

    // asking user to spell EA
    std::cout << "Q. Write EA in morse code: ";
    std::getline(std::cin, inp);

    // if the answer is correct
    if(inp == ". ._")
        std::cout << "Indeed! Great Job.";

    // if the answer is close
    else if(inp == ".._")
        std::cout << "Close, but you are wrong, .._ is the morse character U. EA will be . ._";

    // if the answer is wrong
    else std::cout << "Incorrect answer. It will be . ._";
    std::cout << "\n\n";

    
    // giving user the morse code of S and K
    std::cout << "In morse code, the characters S is shown as ... and the character K is shown as _._\n\n";
    // asking user to spell ASK
    std::cout << "Q. Write ASK in morse code: ";
    std::getline(std::cin, inp);

    // if the answer is correct
    if(inp == "._ ... _._")
        std::cout << "Indeed! You are getting good.";

    else std::cout << "Incorrect answer. It will be ._ ... _._";
    std::cout << "\n\n";

    // giving user the morse code of I and o
    std::cout << "In morse code, the characters I is shown as .. and the character O is shown as ___\n\n";
    // asking user to spell OK in morse
    std::cout << "Q. Write OK in morse code: ";
    std::getline(std::cin, inp);

    // if the answer is correct
    if(inp == "___ _._")
        std::cout << "You are getting the hang of it!";

    else std::cout << "Incorrect answer. It will be ___ _._";
    std::cout << "\n\n";

    // final character of today's class is P
    std::cout << "Final Question. In morse code, the character P is shown as .__.\n\n";
    // asking user to spell IP
    std::cout << "Q. Write IP in morse code: ";
    std::getline(std::cin, inp);

    // if the answer is correct
    if(inp == ".. .__.")
        std::cout << "Nice! By the way, your IP is 104.27.178.5";

    else std::cout << "Incorrect answer. It will be .. .__.";
    std::cout << "\n\n";

    // concluding sentense
    std::cout << "Shutting down morse code class....\n";

    return 0;
}