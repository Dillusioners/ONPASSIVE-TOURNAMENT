# include <iostream>
# include <vector>
# include <algorithm>
# include <string>
# include <random>

// function to reduce syntax for input
inline std::string input(std::string msg){
	std::string inp; // to store the input
	
	// asking user for the input
	std::cout << msg;
	std::cin >> inp;
	
	// returning the input
	return inp;
}

// program execution starts from here
int main(int argc, char** argv){
    // all variables declared here
    int choice;
    std::string name;
    bool running = true;
    std::random_device rd;
    std::mt19937 mt(rd());
    std::vector<std::string> songs;

    std::cout << "WELCOME TO DILLUSIONERS PLAYLIST MANAGER.";

    // running until the user stops
    while(running){
        // prompting the menu and asking for input
        std::cout << "\n\n";
        std::cout << "The following list of options are avaliable:\n";
        std::cout << "1. View Playlist\n2. Add Song\n3. Remove Song\n4. Shuffle\n5. Exit\n>> ";
        std::cin >> choice;
        std::cout << std::endl;

        // running a switch-case based on the user-choice
        switch(choice){
            // view playlist
            case 1: {
                // iterating through the array and printing all the members
                for(unsigned int i = 0; i < songs.size(); i++){
                    // if i is 0, print "Currently Playing " else print "i. "
                    std::cout << ((i == 0)? "Currently Playing " : std::to_string(i) + ". ") << songs[i] << std::endl;
                }
                continue;
            }

            // add song
            case 2: {
                // asking user for song and then adding it to the vector
                name = input("Enter the song name using camel casing (eg. WhatIsLove): ");
                songs.push_back(name);
                std::cout << "Added your song to the playlist.";
                continue;
            }

            // remove song
            case 3: {
                // asking user for the song
                name = input("Enter the song name using camelCasing: ");

                // iterating through the array
                for(auto itr = songs.begin(); itr != songs.end(); itr++){
                    // if the mentioned song is found
                    if(*itr == name){
                        // erasing the song
                        songs.erase(itr);
                        std::cout << "Successfully deleted the song from the playlist.";
                        break;
                    }
                }

                continue;
            }

            // shuffle song
            case 4: {
                // shuffling the array
                std::shuffle(songs.begin(), songs.end(), mt);
                std::cout << "Shuffled your playlist.";
                continue;
            }

            // exit
            case 5: {
                running = false;
                break;
            }

            // invalid value
            default: {
                std::cout << "Invalid value provided. Try again.";
            }
        }
    }

    return 0;
}
