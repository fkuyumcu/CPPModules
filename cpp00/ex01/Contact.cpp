#include "PhoneBook.hpp"

void Contact::setFirstName(const std::string firstName) {
    this->firstName = firstName;

}
void Contact::setLastName(const std::string lastName) {
    this->lastName = lastName;

}
void Contact::setNickname(const std::string nickname) {
    this->nickname = nickname;

}
void Contact::setPhoneNumber(const std::string phoneNumber) {
    this->phoneNumber = phoneNumber;

}
void Contact::setDarkestSecret(const std::string darkestSecret) {
    this->darkestSecret = darkestSecret;

}
std::string Contact::getFirstName(){
    return firstName;
}
std::string Contact::getLastName(){
    return lastName;
}
std::string Contact::getNickname(){
    return nickname;
}
std::string Contact::getPhoneNumber(){
    return phoneNumber;
}
std::string Contact::getDarkestSecret(){
    return darkestSecret;
}
void Contact::printContact(){
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
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
