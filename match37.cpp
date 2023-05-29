# include <iostream>
# include <map>

// stores the flights of the user
std::map<std::string, float> flights;

// function to initialize the flights
void init(){
    flights["Ohio"] = 69420;
    flights["Paris"] = 320.49;
    flights["North Korea"] = 4140.99;
    flights["Florida"] = 294.89;
    flights["London"] = 2475.74;
    flights["Brazil"] = 4755.37;
    flights["Iceland"] = 482.44;
    flights["Vinland"] = 6856.75;
    flights["Hong Kong"] = 3796.44;
    flights["Kiro\'s Basement"] = 2147483647;
}

// function to view all flights
void viewFlights(){
    // iterating through the flights and printing each member with their price
    for(auto itr = flights.begin(); itr != flights.end(); itr++){
        std::cout << "Flight to " << itr->first << " at the rate of $" << itr->second << std::endl;
    }
}

// function to book a flight
void bookFlight(){
    // ignoring /n from cin and declaring variables
    std::cin.ignore(1, '\n');
    std::string name;
    int people;
    float cost;

    // asking for the flight name
    std::cout << "Enter the flight name: ";
    std::getline(std::cin, name);

    // if flight name is not found
    if(flights.find(name) == flights.end()){
        std::cout << "Error: Flight not found.";
        return;
    }

    // asking for the total number of people
    std::cout << "Enter the number of people going: ";
    std::cin >> people;

    // if peope amount is 0 or lesser
    if(people <= 0){
        std::cout << "Not your Quantum Physics class.";
        return;
    }

    // calculating the cost
    cost = flights.at(name) * people;

    // printing the total cost
    std::cout << "Your total cost is $" << cost << "\nSuccessfully booked your flight.";
}

// searching for the flight provided by the user
void searchFlight(){
    // ignoring /n from cin and declaring variables
    std::cin.ignore(1, '\n');
    std::string name;

    // asking for the flight name
    std::cout << "Enter the flight name: ";
    std::getline(std::cin, name);

    // if the flight is not found
    if(flights.find(name) == flights.end()){
        std::cout << "Error: Flight not found.";
        return;
    }

    // printing the flight name and the prize
    std::cout << "Flight name: " << name << "\nFlight Cost: " << flights.at(name);
}

// program execution starts from here
int main(int argc, char** argv){
    // variables declared
    init();
    int choice;
    bool running = true;

    // printing welcome message and running until the user stops
    std::cout << "WELCOME TO DILLUSIONERS AIRLINES\n";
    while(running){
        // printing menu and asking for user chouce
        std::cout << "\nTravel Agency Menu:\n";
        std::cout << "1. View Flights\n2. Book Flight\n3. Search a Flight\n4. Exit Menu\n>> ";
        std::cin >> choice;
        std::cout << std::endl;

        // switch-case on user choice
        switch(choice){
            // view flights
            case 1: {
                viewFlights();
                break;
            }

            // book flight
            case 2: {
                bookFlight();
                std::cout << std::endl;
                break;
            }

            // search flight
            case 3: {
                searchFlight();
                std::cout << std::endl;
                break;
            }
            
            // exit menu
            case 4: {
                running = false;
                break;
            }

            // if invalid integer is provided
            default: {
                std::cout << "Invalid input provided.";
            }
        }
    }

    return 0;
}