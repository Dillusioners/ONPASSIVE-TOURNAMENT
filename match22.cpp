# include <iostream>
# include <map>
# include <string>

// stores all of the events of the calender
std::map<std::string, std::string> events;

// adding a new event
void add(){
    std::string date, event;

    // asking user for the date of the new event
    std::cout << "Enter the date of the event (DD-MM-YY): ";
    std::cin >> date;
    std::cin.ignore(1, '\n');

    // if the size of the date is invalid
    if(date.size() != 8){
        std::cout << "You have entered an invalid date format!\n";
        std::cout << "The date format for the program should be in DD-MM-YY.\n";
        std::cout << "For example: 28th July 2023 will be represented as 28-07-23.";
        return;
    }

    // if the date is greater than 31 and if the month is greater than 12
    if(std::stoi(std::string(1, date[0])) > 3 || std::stoi(std::string(1, date[3])) > 1){
        std::cout << "Invalid date provided. Please verify your event date.";
        return;
    }

    // asking for a new event
    std::cout << "Enter the event: ";
    std::getline(std::cin, event);

    // inserting the new date-event
    events.insert(std::pair(date, event));
    std::cout << "Successfully added your event in the list.";
}

// to view all the events in the map
void viewall(){
    // iterating through the map
    for(auto itr = events.begin(); itr != events.end(); itr++){
        // printing the elements in the map
        std::cout << itr->first << " => " << itr->second << std::endl;
    }
}

// to edit a previously added event
void edit(){
    std::string date, event;

    // asking for the date
    std::cout << "Enter the date (DD-MM-YY): ";
    std::cin >> date;

    // if the event-date pointer is pointing to the end, or the date is not in map
    if(events.find(date) == events.end()){
        std::cout << "Your provided date doesn\'t exist in the event list.";
        return;
    }

    // asking for new event
    std::cout << "Enter the new event: ";
    std::cin >> event;

    // editing the event
    events[date] = event;
    std::cout << "Successfully edited your event.";
}

// program execution starts from here
int main(int argc, char const *argv[]){
    // variables declared here
    int choice;
    bool run = true;

    std::cout << "DILLUSIONERS CALENDER MANAGER";

    // running until user cancels the program
    while(run){
        // printing out all of the user choices
        std::cout << "\n\nThe following are your options:\n";
        std::cout << "1. Add an Event\n2. View All Events\n3. Edit an Event\n4. Exit\n>> ";
        std::cin >> choice;
        std::cout << std::endl;

        // switch-case based on the choices
        switch(choice){
            // add event
            case 1: {
                add();
                continue;
            }

            // view events
            case 2: {
                viewall();
                continue;
            }

            // edit event
            case 3: {
                edit();
                continue;
            }

            // exit
            case 4: {
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
