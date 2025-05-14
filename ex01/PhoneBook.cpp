using namespace std;
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    for (int i = 0; i < MAX; i++) 
        contacts[i] = Contact();
}
PhoneBook::~PhoneBook() {
    for (int i = 0; i < MAX; i++)
        contacts[i] = Contact();
}

void PhoneBook::addContact() {
    string firstName, lastName, nickname, phoneNumber, darkestSecret;
    cout << "Enter first name: ";
    cin >> firstName;
    cout << "Enter last name: ";
    cin >> lastName;
    cout << "Enter nickname: ";
    cin >> nickname;
    cout << "Enter phone number: ";
    cin >> phoneNumber;
    cout << "Enter darkest secret: ";
    cin >> darkestSecret;

    for (int i = 0; i < MAX; i++) {
        if (contacts[i].getFirstName() == "") {
            contacts[i].setFirstName(firstName);
            contacts[i].setLastName(lastName);
            contacts[i].setNickname(nickname);
            contacts[i].setPhoneNumber(phoneNumber);
            contacts[i].setDarkestSecret(darkestSecret);
            break;
        }
    }
}

