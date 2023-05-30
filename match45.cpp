# include <iostream>
# include <map>

// function which stores all recipies
std::map<std::string, std::string> recipies;

// function to reduce syntax for input
inline std::string input(std::string msg){
	std::string inp; // to store the input
	
	// asking user for the input
	std::cout << msg;
	std::cin >> inp;
	
	// returning the input
	return inp;
}

// initializing the recipies map
void init(){
    recipies.insert({"Potato Chips", "1. Get a potato\n2. Get chips\n3. Potato Chips"});
    recipies.insert({"SuperB", "1. Do something illegal\n2. Make sure Wamis sees\n3. Let him cook"});
    recipies.insert({"Life", "1. Wait until it is midday\n2. Go outside\n3. Touch Grass"});
    recipies.insert({"Girlfriend", "1. Get rizz\n2. Use Persuation 100 Potion\n3. Repeat Step 1 and 2"});
    recipies.insert({"Pride Flag", "1. Join the LGBTQ Community\n2. Become a femboy\n3. Spread your gay wisdom"});
    recipies.insert({"Laptop", "1. Get some money\n2. Go to the nearest store\n3. Buy a laptop"});
    recipies.insert({"Ohio Potion", "1. Enter the backrooms\n2. Beat the final Boss\n3. Leave Ohio... Wait, When did you even enter Ohio?"});
    recipies.insert({"Diet Coke", "1. Go to the nearest store\n2. Use Persuation 100 Potion\n3. Buy 100 cans for free"});
}

// main program execution starts from here
int main(int argc, char const *argv[]){
    // variables declared here
    int dailyCalories;
    std::string inp;
    bool touchGrass, gay, hasPotatoes, tiktok;

    // asking for user calories
    dailyCalories = std::stoi(input("How many calories a day?: "));

    // asking if user touched grass
    inp = input("Do you touch grass?[Y/n]: ");
    touchGrass = std::tolower(inp[0]) == 'y';

    // asking if user is gay
    inp = input("Are you gay?[Y/n]: ");
    gay = std::tolower(inp[0]) == 'y';

    // asking if the user has potatoes
    inp = input("Do you have potatoes?[Y/n]: ");
    hasPotatoes = std::tolower(inp[0]) == 'y';

    // asking if the user watch tiktok
    inp = input("Do you watch TikTok?[Y/n]: ");
    tiktok = std::tolower(inp[0]) == 'y';

    // if doesnot touch grass
    if(!touchGrass)
        std::cout << "The recipe for you is Life:\n" << recipies["Life"];

    // if is gay
    else if(gay)
        std::cout << "The recipe for you is Pride Flag:\n" << recipies["Pride Flag"];

    // if has potatoes
    else if(hasPotatoes)
        std::cout << "The recipe for you is Potato Chips:\n" << recipies["Potato Chips"];

    // if uses tiktok
    else if(tiktok)
        std::cout << "The recipe for you is Girlfriend:\n" << recipies["Girlfriend"];

    // if daily calories is more than 2500
    else if(dailyCalories > 2500)
        std::cout << "The recipe for you is Ohio Potion:\n" << recipies["Ohio Potion"];

    // if daily calories is more than 1000
    else if(dailyCalories > 1000)
        std::cout << "The recipe for you is SuperB:\n" << recipies["SuperB"];

    return 0;
}
