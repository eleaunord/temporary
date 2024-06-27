#include "PhoneBook.hpp"

std::string get_input_field(std::string prompt){

    std::string user_input;
    while (user_input.empty())
    {
        std::cout << prompt;
        std::getline(std::cin, user_input);
    }
    return user_input;
}

void PhoneBook::add(){

    static int i = 0;

    std::cout << "Fill in the info of your new contact." << std::endl;
    contacts[i].set_field("first name", get_input_field("First name :"));
    contacts[i].set_field("last name", get_input_field("Last name :"));
    contacts[i].set_field("nickname", get_input_field("Nickname:"));
	contacts[i].set_field("phone number", get_input_field("Phone number:"));
	contacts[i].set_field("darkest secret", get_input_field("Darkest secret:"));
    if (i + 1 == MAX_CONTACTS)
        i = 0;
    else
        i++;
}

void	print_cell(std::string str)
{
	if (str.length() > 10)
	{
		str.resize(9);
		str += ".";
	}
	std::cout << std::setw(10);
	std::cout << str << "|";
}

void PhoneBook::display_contacts()
{
    // Check if Phone book is empty
    if (contacts[0].get_field("first name").empty())
    {
        std::cout << "Your phonebook is empty." << std::endl;
        return ;
    }

    // Print headers for the contact list table
    print_cell("index");
	print_cell("first name");
	print_cell("last name");
	print_cell("nickname");

    // Newline for each row of data
    std::cout << std::endl;
    
    // Iterates though contacts and print details
    for (int i = 0; i < MAX_CONTACTS; i++){
        if (!contacts[i].get_field("first_name").empty()){
            // Print index i
            std::cout << std::setw(10);
            std::cout << i << "|";
            // Print data
        	print_cell(contacts[i].get_field("first name"));
			print_cell(contacts[i].get_field("last name"));
			print_cell(contacts[i].get_field("nickname"));
            std::cout << std::endl;
        }
    } 
}

int PhoneBook::get_index(){

    int index;
    int max;

    max = 0;

    while (max < MAX_CONTACTS && !contacts[max].get_field("first name").empty())
        max++;
    max--;

    if (max == -1)
        return max;

    std::string line;
    while (1) {
        std::cout << "Enter the index of the contact: ";
        if (!std::getline(std::cin, line)) {
            // Handle end-of-file or read error
            std::cout << "Error reading input. Please try again." << std::endl;
            std::cin.clear(); // Clear any error flags
            continue;
        }

        // Check if the input line is empty or contains only whitespace
        std::istringstream iss(line);
        if (!(iss >> index)) {
            std::cout << "Must be an integer between 0 and " << max << std::endl;
            continue;
        }

        if (index >= 0 && index <= max) {
            break;
        } else {
            std::cout << "Must be an integer between 0 and " << max << std::endl;
        }
    }

    return index;
}

void	PhoneBook::print_info(int index)
{
	std::cout << "First name: " << contacts[index].get_field("first name") << std::endl;
    std::cout << "Last name: " << contacts[index].get_field("last name") << std::endl;
    std::cout << "Nickname: " << contacts[index].get_field("nickname") << std::endl;
    std::cout << "Phone number: " << contacts[index].get_field("phone number") << std::endl;
	std::cout << "Darkest secret: " << contacts[index].get_field("darkest secret") << std::endl;
}

