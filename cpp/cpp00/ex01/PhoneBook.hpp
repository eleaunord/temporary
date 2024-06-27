#ifndef PHONE_HPP
#define PHONE_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include "Contact.hpp"

class PhoneBook{

    static const int MAX_CONTACTS = 8;

    Contact contacts[MAX_CONTACTS];

    public :
        void    add();
        void    display_contacts();
        int     get_index();
        void    print_info(int index);

};

#endif