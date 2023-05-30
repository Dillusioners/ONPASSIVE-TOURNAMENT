# include <iostream>
# include <limits>
# include <vector>

// the vector which contains all the songs
std::vector<std::string> songs;
// iterator pointing to the currently playing song
auto playing = songs.begin() + 0;

// function to fix std::cin if corrupted
void fix_std_cin(){
    // if std::cin status is showing failed
    if(std::cin.fail()){
        // setting cin status to good
        std::cin.clear();
        // clearing all bad input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

// function to add a playlist
void addPlaylist(){
    // dropping the \n character from std::cin
    std::cin.ignore(1, '\n');
    std::string name;

    // asking user for the song name
    std::cout << "Enter your song name: ";
    std::getline(std::cin, name);

    // adding the song to the playlist
    std::cout << "Successfully added the song in the playlist.";
    playing = songs.begin();
    songs.push_back(name);
}

// function to print all the members of the playlist
void viewPlaylist(){
    // iterating through the playlist with a numbering index
    int index = 1;
    for(auto itr = songs.begin(); itr != songs.end(); itr++, index++){
        // if the current song is playing, print currently playing, else print the regular index
        // printing the song
        std::cout << ((itr == playing)? "Currently Playing " : std::to_string(index) + ". ") << *itr << '\n';
    }
}

// function to remove a song from the playlist
void removePlaylist(){
    // dropping the \n character from std::cin
    std::cin.ignore(1, '\n');
    std::string name;

    // asking user for the song name
    std::cout << "Enter your song name: ";
    std::getline(std::cin, name);

    // iterating through the vector
    for(auto itr = songs.begin(); itr != songs.end(); itr++){
        // if the song is found
        if(*itr == name){
            // removing the song from the index
            std::cout << "Successfully deleted your song.";
            songs.erase(itr);
            playing = songs.begin();
            return;
        }
    }

    // if the song is not found
    std::cout << "Unable to find your song!";
}

// function to play a song
void playSong(){
    int pos;

    // asking user for the song position in playlist
    std::cout << "Enter the position of the song in the playlist (in Integers): ";
    std::cin >> pos;
    fix_std_cin();
    pos--; // subtracting pos as vector indexing starts from 0 in c++

    // if the pos is out of bounds, return the function
    if(pos < 0 || pos >= (int)(songs.size())){
        std::cout << "Invalid position is provided.";
        return;
    }

    // updating the currently playing song
    playing = songs.begin() + pos;
    std::cout << "Currently playing: " << songs[pos];
}

// main program execution starts from here
int main(int argc, char const *argv[]){
    int choice;
    bool run = true;

    // running until user stops the program
    while(run){
        // printing the menu and asking user for their choice
        std::cout << "\nMusic Streaming Services:\n";
        std::cout << "1. Add to Playlist\n2. View Playlist\n3. Remove from Playlist\n4. Play Song in Playlist\n5. Exit\n>> ";
        std::cin >> choice;
        fix_std_cin();
        std::cout << std::endl;

        // switch case based on the user choice
        switch(choice){
            // add a song to the playlist
            case 1: {
                addPlaylist();
                std::cout << '\n';
                break;
            }

            // view the playlist
            case 2: {
                viewPlaylist();
                break;
            }

            // remove a song from the playlist
            case 3: {
                removePlaylist();
                std::cout << '\n';
                break;
            }

            // playing the user selected song
            case 4: {
                playSong();
                std::cout << '\n';
                break;
            }

            // exit
            case 5: {
                run = false;
                break;
            }

            // invalid input provided
            default: {
                std::cout << "Invalid Input Provided.\n";
            }
        }
    }
    
    return 0;
}