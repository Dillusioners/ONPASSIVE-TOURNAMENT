# include <iostream>
# include <map>
# include <string>

// stores all of the movies
std::map<std::string, std::pair<std::string, std::string>> movies;

// function to initialize the map with movies
void init(){
    movies.insert({"Toy Story", {"3+", "23-08-11"}});
    movies.insert({"Avengers", {"13+", "11-02-06"}});
    movies.insert({"Minecraft - The Movie", {"10+", "17-02-25"}});
    movies.insert({"Interstellar", {"14+", "06-05-13"}});
    movies.insert({"Inception", {"16+", "31-01-15"}});
    movies.insert({"Star Wars", {"10+", "19-11-08"}});
    movies.insert({"Avatar", {"12+", "27-05-18"}});
    movies.insert({"Ginormo", {"10+", "17-05-23"}});
    movies.insert({"Cindrella", {"14+", "01-08-06"}});
    movies.insert({"SuperB", {"0+", "99-99-99"}});
}

// searching for a movie
void search(){
    std::cin.ignore(1, '\n');
    std::string name;

    // asking for the movie name
    std::cout << "Enter the name of the movie: ";
    std::getline(std::cin, name);

    // if movie is not found
    if(movies.find(name) == movies.end()){
        std::cout << "Movie not added in databse yet.";
        return;
    }

    // printing the movie details
    auto details = movies[name];
    std::cout << name << '\n' << details.first << " movie. Released at " << details.second << std::endl;
}

// browsing the movie map
void browse(){
    // iterating through the map and printing all the elements
    for(auto itr = movies.begin(); itr != movies.end(); itr++){
        std::cout << "Name: "<< itr->first << '\n' 
                  << itr->second.first << " movie. Released at " << itr->second.second << "\n\n";
    }
}

// program execution starts from here
int main(int argc, char** argv){
    // variables declared here
    init();
    int choice;
    bool run = true;

    std::cout << "DILLUSIONERS MOVIES DATABASE";

    // running until user cancels the program
    while(run){
        // printing out all of the user choices
        std::cout << "\n\nThe following are your options:\n";
        std::cout << "1. Search a movie\n2. Browse all movies\n3. Exit\n>> ";
        std::cin >> choice;
        std::cout << std::endl;

        // switch-case based on the choices
        switch(choice){
            // search up a movie
            case 1: {
                search();
                continue;
            }

            // browse a movie
            case 2: {
                browse();
                continue;
            }

            // exit
            case 3: {
                run = false;
                break;
            }

            // invalid value
            default: {
                std::cout << "Invalid input. Try again!";
            }
        }
    }
    return 0;
}
