
#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"



int main(void)
{
	PhoneBook phoneBook;
	std::string command;
	std::cout << "Welcome to fkuyumcu's PhoneBook!" << std::endl;
	
	while (true)
	{
	std::cout << "Please enter a command (ADD, SEARCH, EXIT): ";
	if (!getline(std::cin, command)) 
		break;

	if(command == "ADD")
	{
			Contact contact;
			std::string input;
			std::cout << "Enter first name: ";
			std::getline(std::cin, input);
			if (input.empty()) 
			{
				std::cout << "First name cannot be empty." << std::endl;
				continue;
			}
			contact.setFirstName(input);
			std::cout << "Enter last name: ";
			std::getline(std::cin, input);
			if (input.empty())
			{
				std::cout << "Last name cannot be empty." << std::endl;
				continue;
			}
			contact.setLastName(input);
			std::cout << "Enter nickname: ";
			std::getline(std::cin, input);
			if (input.empty()) 
			{
				std::cout << "Nickname cannot be empty." << std::endl;
				continue;
			}
			contact.setNickname(input);
			std::cout << "Enter phone number: ";
			getline(std::cin, input);
			if (input.empty() || input.find_first_not_of("+0123456789") != std::string::npos)  
			{
				std::cout << "Phone number cannot be empty and it could only be digits." << std::endl;
				continue;
			}
			contact.setPhoneNumber(input);
			std::cout << "Enter darkest secret: ";
			getline(std::cin, input);
			if (input.empty()) 
			{
				std::cout << "Darkest secret cannot be empty." << std::endl;
				continue;
			}
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
