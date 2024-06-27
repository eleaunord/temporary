#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

class Contact{

    public :
        void set_field(std::string field, std::string user_input);
        std::string get_field(std::string field);
    private :
        std::string first_name;
		std::string  last_name;
		std::string  nickname;
		std::string  phone_number;
		std::string  darkest_secret;
};

#endif