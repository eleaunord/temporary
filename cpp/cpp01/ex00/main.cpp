#include "Zombie.hpp"

/*

USE STACK :
    -> when object's lifetime well defined + used in one function/scope
    Small enough to fit w/n stack's limits.
USE HEAP : 
    -> when object's lifetime must go beyond function 
    larger objects / size of objects is not known at compile time or can vary
*/

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Compile with : s -for stack or h -for heap and {your zombie's NAME}" << std::endl;
        return 1;
    }

    std::string name = argv[2];

    if (argv[1][0] == 's') {
        std::cerr << "(STACK)" << std::endl;
        Zombie stackZombie(name); 
        stackZombie.announce();

    } else if (argv[1][0] == 'h') {
        // Heap allocation
        std::cerr << "(HEAP)" << std::endl;
        Zombie* heapZombie = new Zombie(name);
        heapZombie->announce();
        delete heapZombie;
    } else {
        std::cerr << "Invalid option: Use 's' for stack or 'h' for heap." << std::endl;
        return 1;
    }

    return 0;
}
