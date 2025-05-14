#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>

#define MAX 8

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
public:
    void setFirstName(const std::string firstName);
    void setLastName(const std::string lastName);
    void setNickname(const std::string nickname);
    void setPhoneNumber(const std::string phoneNumber);
    void setDarkestSecret(const std::string darkestSecret);
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
    void printContact() const;
    Contact();
    ~Contact();
};

class PhoneBook {
    private:
        Contact contacts[MAX];
        void addContact();
        void searchContact();
        void exitPhoneBook();
        void printContactList();
public:
    PhoneBook();
    ~PhoneBook();
};

#endif
