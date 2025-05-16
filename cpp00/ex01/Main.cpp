
#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"



int main(void)
{
	PhoneBook phoneBook;
	std::string command;
	std::cout << "Welcome to fkuyumcu PhoneBook!" << std::endl;
	
	while (true)
	{
	std::cout << "Please enter a command (ADD, SEARCH, EXIT): ";
	if (!getline(std::cin, command)) {
		break;
    }
	if(command == "ADD")
	{
			Contact contact;
			std::string input;
			std::cout << "Enter first name: ";
			std::getline(std::cin, input);
			contact.setFirstName(input);
			std::cout << "Enter last name: ";
			std::getline(std::cin, input);
			contact.setLastName(input);
			std::cout << "Enter nickname: ";
			std::getline(std::cin, input);
			contact.setNickname(input);
			std::cout << "Enter phone number: ";
			getline(std::cin, input);
			contact.setPhoneNumber(input);
			std::cout << "Enter darkest secret: ";
			getline(std::cin, input);
			contact.setDarkestSecret(input);
			phoneBook.addContact(contact);
			
	}
 	else if(command == "SEARCH")
		phoneBook.searchContact();
 	else if(command == "EXIT")
		break;
	else
		std::cout << "Invalid command." << std::endl;
	
}

}
