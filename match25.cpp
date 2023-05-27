# include <iostream>
# include <map>

// vector which stores the recipes
std::map<std::string, std::string> recipies;

// function to initialize the vector with all of the recipies.
void init(){
    recipies.insert({"Potato Chips", "1. Get a potato\n2. Get chips\n3. Potato Chips"});
    recipies.insert({"SuperB", "1. Do something illegal\n2. Make sure Wamis sees\n3. Let him cook"});
    recipies.insert({"Bedwars", "1. Get a bed\n2. Go to North Korea\n3. Bedwars"});
    recipies.insert({"Gun", "1. This is Dillusioners, not America"});
    recipies.insert({"Life", "1. Wait until it is midday\n2. Go outside\n3. Touch Grass"});
}

// program execution starts from here
int main(int argc, char** argv){
    // variables declared and initialised
    init();
    int choice;
    bool run = true;

    std::cout << "WELCOME TO DILLUSIONERS RECIPE BOOK";

    // running until user stops the program
    while(run){
        // prompting the menu and asking for input
        std::cout << "\n\n";
        std::cout << "The following list of options are avaliable:\n";
        std::cout << "1. View Recipies\n2. Search Recipe\n3. Exit\n>> ";
        std::cin >> choice;
        std::cout << std::endl;

        // switch ladder based on user choice
        switch(choice){
            // view recipies
            case 1: {
                // iterating through the vector and printing out all of the members
                for(auto itr = recipies.begin(); itr != recipies.end(); itr++){
                    std::cout << "Topic: " << itr->first << "\nProcedure:\n" << itr->second << "\n\n";
                }
                continue;
            }

            // search recipe
            case 2: {
                // ignoring \n from std::cin
                std::cin.ignore(1, '\n');
                std::string name;

                // asking user for recipe name
                std::cout << "Enter the name/keyword for the recipe: ";
                std::getline(std::cin, name);

                // iterating through the vector
                for(auto itr = recipies.begin(); itr != recipies.end(); itr++){
                    // if the name matches with the recipie, print it
                    if(name == itr->first){
                        std::cout << "The recipe for the topic is as follows: ";
                        std::cout << "\n" << itr->second << "\n";
                        break;
                    }
                }

                continue;
            }

            // exit
            case 3: {
                run = false;
                break;
            }

            // invalid value
            default: {
                std::cout << "Invalid value provided. Try again.";
                continue;
            }
        }
    }
}
