# include <iostream>
# include <random>

// total number of stocks stored for user
int stocks = 0;

// function to track the portfolio
void trackFolio(){
    // random number generator
    std::random_device rd;
    std::mt19937 mt(rd());

    // calculating and estimating the market values and printing them
    std::cout << "Total stocks: " << (mt() % 999) + 1 << "k\n";
    std::cout << "Stock value increase: " << (mt() % 5) + 1 << "%\n";
    std::cout << "Performance in the last 30 days: " << ((mt() % 2)? "Good\n" : "Bad\n");
    std::cout << "Private stocks owned: " << (mt() % 999) << "\n";
    std::cout << "Your stocks: " << stocks << "\n";
}

// function to add a stock to the user
void addStocks(){
    int stock;

    // asking user for the stock count
    std::cout << "How many stocks you want to add?: ";
    std::cin >> stock;

    // adding stocks to the user
    stocks += stock;
    std::cout << "After adding, you have: " << stocks << " stocks.\n";
    // if the user has premature stocks
    if(stocks < 0) std::cout << "Please make sure to pay your premature stocks in time.\n";
}

// function to remove stocks from user
void removeStocks(){
    int stock;

    // asking user for the count
    std::cout << "How many stocks you want to remove?: ";
    std::cin >> stock;

    // subtracting the stocks
    stocks -= stock;
    std::cout << "After subtracting, you have: " << stocks << " stocks\n";
    // if the user has premature stocks
    if(stocks < 0) std::cout << "Please make sure to pay your premature stocks in time.\n";
}

// main program execution starts from here
int main(int argc, char** argv){
    int choice;
    bool run = true;

    // running until the user stops the program
    while(run){
        // printing the menu and asking for user input
        std::cout << "\nStock Portfolio Management:\n";
        std::cout << "1. Track Portfolio\n2. Add Stocks\n3. Remove Stocks\n4. Exit\n>> ";
        std::cin >> choice;
        std::cout << std::endl;

        // switch-case based on the user choice
        switch(choice){
            // track portfolio
            case 1: {
                trackFolio();
                break;
            }

            // add stocks
            case 2: {
                addStocks();
                break;
            }

            // remove stocks
            case 3: {
                removeStocks();
                break;
            }

            // exit
            case 4: {
                run = false;
                break;
            }

            // invalid input
            default: {
                std::cout << "Invalid Input provided!\n";
            }
        }
    }
    return 0;
}