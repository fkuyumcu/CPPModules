using namespace std;
#include "PhoneBook.hpp"

void Contact::setFirstName(const string firstName) {
    this->firstName = firstName;
}
void Contact::setLastName(const string lastName) {
    this->lastName = lastName;
}
void Contact::setNickname(const string nickname) {
    this->nickname = nickname;
}
void Contact::setPhoneNumber(const string phoneNumber) {
    this->phoneNumber = phoneNumber;
}
void Contact::setDarkestSecret(const string darkestSecret) {
    this->darkestSecret = darkestSecret;
}
string Contact::getFirstName() const {
    return firstName;
}
string Contact::getLastName() const {
    return lastName;
}
string Contact::getNickname() const {
    return nickname;
}
string Contact::getPhoneNumber() const {
    return phoneNumber;
}
string Contact::getDarkestSecret() const {
    return darkestSecret;
}
void Contact::printContact() const {
    cout << "First Name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;
    cout << "Nickname: " << nickname << endl;
    cout << "Phone Number: " << phoneNumber << endl;
    cout << "Darkest Secret: " << darkestSecret << endl;
}

Contact::Contact() {
    this->firstName = "";
    this->lastName = "";
    this->nickname = "";
    this->phoneNumber = "";
    this->darkestSecret = "";
}
Contact::~Contact() {
    this->firstName = "";
    this->lastName = "";
    this->nickname = "";
    this->phoneNumber = "";
    this->darkestSecret = "";
}
