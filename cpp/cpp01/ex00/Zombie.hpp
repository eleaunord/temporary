#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

/*
    Member function : a function defined as part of a class.

    Constructor : special member function called automatically 
    when an object of the class is created. Used to initialize 
    the object.

    Destructor : special member function called automatically 
    when an object of the class is destroyed. Release resources
    that the object may have acquired during its lifetime.

*/
class Zombie {
    private :
        std::string _name;
    public :
        Zombie(std::string name);
        ~Zombie();
        void announce();
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif