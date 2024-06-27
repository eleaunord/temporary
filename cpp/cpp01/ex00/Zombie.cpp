#include "Zombie.hpp"

/*
    this : pointer to the object currently being operqted
    assigns value of the paramter to the private member variable
    _name of the current object.
    Acces the _name attribute of the current object.

*/

Zombie::Zombie(std::string name) : _name(name) {
    this->_name = name;
}

Zombie::~Zombie() {
    std::cout << this->_name << " defeated." << std::endl;
}

void Zombie::announce(void) {

    std::cout << _name << " : BraiiiiiiinnnzzzZ..."  << std::endl;
 }
