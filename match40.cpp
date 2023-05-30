# include <iostream>
# include <limits>
# include <vector>

// three vectors to contain the three types of tasks
std::vector<std::string> tasks, deadline_tasks, reminders;

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

// function to print out all the members of a vector
inline void printVec(std::vector<std::string> &vec){
    // iterating through the vector and printing all the members
    for(auto itr = vec.begin(); itr != vec.end(); itr++){
        std::cout << *itr << '\n';
    }
}

// function to schedule a new task
void schedule_task(){
    // ignoring the \n character from cin
    std::cin.ignore(1, '\n');
    std::string task;

    // asking for user input
    std::cout << "Enter the task you want to insert: ";
    std::getline(std::cin, task);

    // adding the new task
    std::cout << "Successfully added task.\n";
    tasks.push_back(task);
}

// function to schedule a new deadline task
void deadline_task(){
    // ignoring the \n character from cin
    std::cin.ignore(1, '\n');
    std::string task;

    // asking for user input
    std::cout << "Enter the deadlined task you want to insert: ";
    std::getline(std::cin, task);

    // adding the new task
    std::cout << "Successfully added deadlined task.\n";
    deadline_tasks.push_back(task);
}

// function to schedule a new reminder
void set_reminder(){
    // ignoring the \n character from cin
    std::cin.ignore(1, '\n');
    std::string rem;

    // asking for user input
    std::cout << "Enter the reminder you want to insert: ";
    std::getline(std::cin, rem);

    // adding the new task
    std::cout << "Successfully added reminder.\n";
    reminders.push_back(rem);
}

// function to view all the tasks
void viewall(){
    // printing all regular tasks
    std::cout << "All Tasks:\n";
    printVec(tasks);

    // printing all deadline task
    std::cout << "\nAll Deadline Tasks:\n";
    printVec(deadline_tasks);

    // printing all reminders
    std::cout << "\nAll Reminders:\n";
    printVec(reminders);
}

// function to remove a task from the lists
void remove_task(){
    // ignoring \n from std::cin
    std::cin.ignore(1, '\n');
    std::string name;

    // asking for the task to remove
    std::cout << "Enter your task/reminder name: ";
    std::getline(std::cin, name);

    // iterating through the first vector
    for(auto itr = tasks.begin(); itr != tasks.end(); itr++){
        // if the task is found, remove it
        if(*itr == name){
            std::cout << "Successfully removed the regular task.";
            tasks.erase(itr);
            return;
        }
    }

    // iterating through the second vector
    for(auto itr = deadline_tasks.begin(); itr != deadline_tasks.end(); itr++){
        // if the task is found, remove it
        if(*itr == name){
            std::cout << "Successfully removed the deadlined task.";
            deadline_tasks.erase(itr);
            return;
        }
    }

    // iterating througn the third vector
    for(auto itr = reminders.begin(); itr != reminders.end(); itr++){
        // if the task is found, remove it
        if(*itr == name){
            std::cout << "Successfully removed the reminder.";
            reminders.erase(itr);
            return;
        }
    }

    // runs when the task is not found in three vectors
    std::cout << "Could not find your task/reminder!";
}

// main program starts from here
int main(int argc, char const *argv[]){
    int choice;
    bool run = true;

    // running until the user stops the program
    while(run){
        // printing the meny and asking for user input
        std::cout << "\nTask Manager:\n";
        std::cout << "1. Schedule Task\n2. Set Deadlined Task\n3. Set Reminders\n";
        std::cout << "4. View Everything\n5. Remove a task/reminder\n6. Exit\n>> ";
        std::cin >> choice;
        fix_std_cin();
        std::cout << std::endl;

        switch(choice){
            // schedule task
            case 1: {
                schedule_task();
                break;
            }

            // schedule deadline
            case 2: {
                deadline_task();
                break;
            }

            // set a reminder
            case 3: {
                set_reminder();
                break;
            }

            // view everything
            case 4: {
                viewall();
                break;
            }

            // remove a task/reminder
            case 5: {
                remove_task();
                break;
            }

            // exit
            case 6: {
                run = false;
                break;
            }

            // invalid value
            default: {
                std::cout << "Invalid Input Provided";
            }
        }
    }
    return 0;
}
