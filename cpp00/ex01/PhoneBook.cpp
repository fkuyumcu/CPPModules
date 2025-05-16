
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>


PhoneBook::PhoneBook(){
	nextIndex = 0;
    for (int i = 0; i < MAX; i++) 
        contacts[i] = Contact();
}
PhoneBook::~PhoneBook() {
	nextIndex = 0;
    for (int i = 0; i < MAX; i++)
        contacts[i] = Contact();
}

void PhoneBook::addContact(Contact &contact) {
	contacts[nextIndex] = contact;
    nextIndex = (nextIndex + 1) % MAX;

    }

std::string contactManipulation(const std::string& str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    else
        return std::string(10 - str.length(), ' ') + str;
}

void PhoneBook::printContactList(){
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    for (int i = 0; i < MAX; i++) {
        if (contacts[i].getFirstName() != "") {
            std::cout << "|" << std::setw(10) << i
                      << "|" << contactManipulation(contacts[i].getFirstName())
                      << "|" << contactManipulation(contacts[i].getLastName())
                      << "|" << contactManipulation(contacts[i].getNickname())
                      << "|" << std::endl;
        }
    }
    std::cout << "---------------------------------------------" << std::endl;
}

void PhoneBook::searchContact() {
	printContactList();
	int index = 0;
	std::cout << "Enter the contact index: ";
	std::cin >> index;
	std::cin.ignore();
	if (index < 0 || index >= MAX) {
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	std::cout << "Contact details:" << std::endl;
	contacts[index].printContact();
}
