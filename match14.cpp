# include <iostream>
# include <chrono>
# include <thread>
# include <random>
# include <string>
# include <algorithm>


// function to say the opening text for the game
void prologue(){
    std::cout << "WELCOME TO THE MASTERMINDS.\n\n";
    std::cout << "The rules are as follows: \n";
    std::cout << "I will be creating a secret code which will be of 13 character length.\n";
    std::cout << "Your job is to find the secret code within 10 tries.\n";
    std::cout << "After each try, I will tell you how much accurate you were.\n";
    std::cout << "If you reach a 100% accuracy, you will win. If you run out of guesses, I win.\n";
    std::cout << "Note that the code is not a word in the english dictionary. No numbers and duplicate characters are used.\n";
    std::cout << "Starting the game......\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
}

// function to generate a new secret code
std::string newCode(){
    // random generator declared here
    std::random_device rd;
    std::mt19937 mt(rd());
    // string with all english characters
    std::string str = "abcdefghijklmnopqrstuvwxyz";

    // shuffling the string
    std::shuffle(str.begin(), str.end(), mt);

    // returning first thirteen characters of the string
    return std::string(str.begin(), str.begin() + 13);
}

// program execution starts from here
int main(int argc, char** argv){
    // variables declared here
    int guess = 10, accuracy = 0;
    std::string input, code = newCode();
    // printing the prologue
    prologue();

    // while the user doesnot run out of guessess
    for(int tries = guess; tries > 0; tries--, accuracy = 0){
        // asking for text input
        std::cout << std::endl;
        std::cout << "Enter your string: ";
        std::cin >> input;

        // iterating through the input
        for(auto elem : input){
            // if the character is found, increase the accuracy
            if(code.find(elem) < code.size()) accuracy++;
        }

        // if all the 13 characters have matched
        if(accuracy == (int)code.size()){
            std::cout << "You have successfully cracked the code.\n";
            return 0;
        }

        // printing the accuracy of the user
        std::cout << "\nYour accuracy is " << (accuracy/(float)code.size()) * 100 << "%.";
        std::cout << std::endl;
    }

    // closing text
    std::cout << "You have run out of guesses!\nThe correct key was " << code << '\n';
    return 0;
}
