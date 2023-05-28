# include <iostream>
# include <random>

// program execution starts from here
int main(int argc, char** argv){
    // variables declared
    int choice, temp, humidity, wind_speed;
    bool run = true;
    std::random_device rd;
    std::mt19937 mt(rd());

    // running until user stops
    while(run){
        // printing the menu and asking user choice
        std::cout << std::endl;
        std::cout << "American Weather Report:\n";
        std::cout << "1. Ohio\n2. Florida\n3. Arizona\n4. California\n5. Nebraska\n6. New York\n7. New Mexico\n";
        std::cout << "8. Exit\n>> ";
        std::cin >> choice;
        std::cout << std::endl;

        // switch-case on user-choice
        switch(choice){
            // ohio
            case 1: {
                std::cout << "Noone leaves Ohio!!!?!?!!?!!?";
                break;
            }

            // florida
            case 2: {
                std::cout << "Look out for the man with the nuke!!!";
                break;
            }

            // arizona
            case 3: {
                std::cout << "Nice and peaceful city....";
                break;
            }

            // california
            case 4: {
                std::cout << "Why are you guys so slow?";
                break;
            }

            // Nebraska
            case 5: {
                std::cout << "Atleast you can leave this place. (unlike ohio)";
                break;
            }

            // new york
            case 6: {
                std::cout << "GothamChess lives there.";
                break;
            }

            // new mexico
            case 7: {
                std::cout << "Bonjour!";
                break;
            }

            // exit
            case 8: {
                run = false;
                break;
            }

            // invalid value
            default: {
                std::cout << "Invalid code typed!";
            }
        }

        // generating weather details and printing them
        std::cout << std::endl;
        std::cout << "Temperature: " << (mt() % 40) << "°C\n";
        std::cout << "Humidity: " << (mt() % 100) << "%\n";
        std::cout << "Wind Speed: " << (mt() % 50) << "km/h\n";
    }
}