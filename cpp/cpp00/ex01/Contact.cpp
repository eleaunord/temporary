#include "Contact.hpp"

std::string Contact::get_field(std::string field)
{
    if (field == "first name")
        return (first_name);
    else if (field == "last name")
        return (last_name);
    else if (field == "nickname")
        return (nickname);
    else if (field == "phone number")
        return (phone_number);
    else if (field == "darkest secret")
        return (darkest_secret);
    return ("Field does not exists");
}

void Contact::set_field(std::string field, std::string user_input)
{
    if (field == "first name")
        first_name = user_input;
    else if (field == "last name")
        last_name = user_input;
    else if (field == "nickname")
        nickname = user_input;
    else if (field == "phone number")
        phone_number = user_input;
    else if (field == "darkest secret")
        darkest_secret = user_input;
}
