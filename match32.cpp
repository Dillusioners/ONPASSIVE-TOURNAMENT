# include <iostream>

// converts USD or Euros to pounds
constexpr float toPound(float amt, bool usd){
    // if the amount is USD
    if(usd) return amt * 0.81;
    else return amt * 0.87;
}

// converts USD or pounds to Euros
constexpr float toEuros(float amt, bool usd){
    // if the amount is in USD
    if(usd) return amt * 0.93;
    else return amt * 1.15;
}

// converts Pound or Euros to USD
constexpr float toUSD(float amt, bool pounds){
    // if the amount is in Pounds
    if(pounds) return amt * 1.23;
    else return amt * 1.07;
}

// program execution starts from here
int main(int argc, char** argv){
    // variables declared here
    int choice;
    std::string currency;
    float result, amount;
    bool run = true;

    // running until the user stops
    while(run){
        // promping user with the menu and asking for input
        std::cout << std::endl;
        std::cout << "Menu Heading: ";
        std::cout << "1. USD to Pound\n2. Pound to USD\n3. USD to Euros\n4. Euros to USD\n5. Pound to Euros\n6. Euros to Pound";
        std::cout << "\n7. Exit\n>> ";
        std::cin >> choice;

        // if the user has decided to exit
        if(choice == 7){
            run = false;
            break;
        }

        // asking user for the amount of money
        std::cout << std::endl << "Enter your amount: ";
        std::cin >> amount;
        std::cout << std::endl;

        // Pound to USD or Euros to USD
        if(choice == 2 || choice == 4){
            // calculating result and setting the currency symbol
            result = toUSD(amount, (choice == 2));
            currency = "$";
        }
        // USD to Pound or Euros to Pound
        else if(choice == 1 || choice == 6){
            // calculating result and setting the currency symbol
            result = toPound(amount, (choice == 1));
            currency = "£";    
        }
        // USD to Euros or Pound to Euros
        else if(choice == 3 || choice == 5){
            // calculating result and setting the currency symbol
            result = toEuros(amount, (choice == 3));
            currency = "€";
        }
        // invalid argument provided
        else{
            std::cout << "Invalid argument provided.";
            continue;
        }

        // printing the resulting amount
        std::cout << "The resulting amount is " << currency << amount << std::endl;
    }
    return 0;
}