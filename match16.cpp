# include <iostream>


// recursive function to print the tower of hanoi
// n -> the number of discs
// from_rod -> the rod which will be moved to the end
// aux_rod -> the middle rod
// to_rod -> the rod where the from_rod will go
void towerOfHanoi(int n,char from_rod, char to_rod, char aux_rod){
    // if only one disc is there, move it to the end
    if(n == 1){
        std::cout << "Move disk 1 from rod " << from_rod << " to rod " << to_rod << std::endl;
        return;
    }

    // finely moving all the other rods to the first rod or the aux rod
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod);

    // moving the last rod to the end
    std::cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << std::endl;   

    // stacking all the rods from other rods to the final rod
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}

// program execution starts from here
int main(int argc, char** argv){ 
    int rods; // the number of rods

    // asking user for the number of rods
    std::cout << "Enter the number of disks: ";
    std::cin >> rods;

    // calling the function
    towerOfHanoi(rods,'A','C','B');
    return 0;
}
