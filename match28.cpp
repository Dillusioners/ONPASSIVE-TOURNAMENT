# include <iostream>
# include <map>

// all of the expenses
std::map<std::string, int> expenses;

// function to view all the expenses
void viewExpenses(){
    // iterating through the map
    for(auto itr = expenses.begin(); itr != expenses.end(); itr++){
        // printing the expense with the cosr
        std::cout << "Expense: " << itr->first << std::endl;
        std::cout << "Cost: $" << itr->second << std::endl << std::endl;
    }
}

// function to add a new expense
void addExpense(){
    std::string expense;
    int prize;

    // asking user for the expense and the prize of it
    std::cout << "Enter the name of the expense: ";
    std::cin >> expense;
    std::cout << "Enter the prize of the expense in $: ";
    std::cin >> prize;

    // if the prize is 0 or negative
    if(prize <= 0){
        std::cout << "Invalid prize provided.";
        return;
    }

    // adding the new expense
    std::cout << "Successfully added a new expense.\n";
    expenses.insert({expense, prize});
}

// function to remove an expense
void removeExpense(){
    std::string expense;

    // asking user for the expense name
    std::cout << "Enter the expense name: ";
    std::cin >> expense;

    // if the expense is found in the map
    if(expenses.find(expense) != expenses.end()){
        // removing the expense
        std::cout << "Successfully removed your expense.\n";
        expenses.erase(expense);
    }

    // if the expense doesnot exist
    else std::cout << "Expense doesnot exist.\n";
}

// program execution starts from here
int main(int argc, char** argv){
    // variables declared
    int choice;
    bool run = true;

    // running until user stops
    while(run){
        // printing the menu and asking user choice
        std::cout << std::endl;
        std::cout << "Expense Manager:\n";
        std::cout << "1. Show All Expenses\n2. Add Expense\n3. Remove Expense\n4. Exit\n>> ";
        std::cin >> choice;
        std::cout << std::endl;

        // switch-case on user-choice
        switch(choice){
            // view all expenses
            case 1: {
                viewExpenses();
                break;
            }

            // add a new expense
            case 2: {
                addExpense();
                break;
            }

            // remove an expense
            case 3: {
                removeExpense();
                break;
            }

            // exit
            case 4: {
                run = false;
                break;
            }

            // invalid value
            default: {
                std::cout << "Invalid code typed!";
            }
        }
    }
}