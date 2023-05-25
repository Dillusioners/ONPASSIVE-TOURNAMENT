# include <iostream>
# include <map>
# include <string>
# include <thread>
# include <chrono>
# include <algorithm>

// syntax reduction
# define map std::map<std::string, std::string>

// program execution starts from here
int main(int argc, char** argv){
    // initializing all the words which will be given to user
    map words = {
        {"python", "__tho_"},
        {"java", "j_v_"},
        {"javascript", "ja___cr__t"},
        {"golang", "g__a_g"},
        {"assembly", "_ss__bl_"},
        {"ruby", "__b_"},
        {"csharp", "_sh__p"},
        {"elixir", "e__xi_r"},
        {"fortran", "f_rt__n"},
        {"kotlin", "k_t_in"},
        {"lua", "l__"},
        {"typescript", "ty___cr_p_"}
    };
    auto pointer = words.begin(); // a pointer to point at the elements of the map
    int points = 0; // total points scored by the user
    std::string input; // for accepting user input

    // welcome text for the game
    std::cout << "WELCOME TO DILLUSIONERS PROGRAMMING KNOWLEDGE.\n\n";
    std::cout << "The rules are as follows:\n\nYou will get an incomplete word, and you have to enter the complete word.\n";
    std::cout << "You will have only one chance to get the correct choice.\nCorrect answer earns one point. No points for wrong answers.\n";
    std::cout << "Note that every provided word will a programming language only, to easy up the game a bit.\n";
    std::cout << "Starting your game........\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));

    // looping through the entire words map
    for(int i = 0; i < (int)(words.size()); i++, pointer++){
        // asking for user input
        std::cout << "\nCurrent jumbled word: " << pointer->second << "\n>> ";
        std::cin >> input;

        // lowercasing the input
        std::transform(input.begin(), input.end(), input.begin(), [](char index){return std::tolower(index);});

        // appending points if the answer is correct, and printing to console accordingly
        points += (input == pointer->first);
        if((input == pointer->first)) std::cout << "\nWell done! You have earned yourself a point!\n";
        else std::cout << "\nYour guess was incorrect. The correct answer is " << pointer->first << '\n';

        input = ""; // resetting the variable
    }

    // closing text
    std::cout << "\nGame Over!\nYour score is " << points << " points out of " << words.size() << ".\n";

    return 0;
}
