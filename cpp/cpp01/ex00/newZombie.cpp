#include "Zombie.hpp"

/*
    new : operator used to dynamically 
    allocate memory on the heap for an object or array of objects

*/

Zombie* newZombie( std::string name) {

    Zombie *myZombie = new Zombie(name);
    
    return myZombie;
}
