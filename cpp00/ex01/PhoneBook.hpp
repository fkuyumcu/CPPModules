#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

#define MAX 8

class PhoneBook {
    private:
        Contact contacts[MAX];
        int nextIndex;
        int currentIndex;
        void printContactList();
        
    public:
        void addContact(Contact contact);
        void searchContact();
        void exitPhoneBook();
        PhoneBook();
        ~PhoneBook();
};

#endif
