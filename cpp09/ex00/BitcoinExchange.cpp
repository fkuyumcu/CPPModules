#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : db(other.db)
{

}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        db = other.db;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{

}


bool BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.size() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;

    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7) continue;
        if (!isdigit(date[i]))
            return false;
    }

    int year  = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day   = atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12)
        return false;

    if (day < 1 || day > 31)
        return false;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        daysInMonth[1] = 29;

    if (day > daysInMonth[month - 1])
        return false;

    return true;
}

bool BitcoinExchange::isValidValue(const std::string &value, float &out) const
{
    if (value.empty())
        return false;

    // strtof ile parse et, endptr kalan kısmı gösterir
    char *endptr;
    out = strtof(value.c_str(), &endptr);

    if (*endptr != '\0')
        return false;

    if (out < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;//throw ile mi yapsam 
        return false;
    }
    if (out > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

float BitcoinExchange::getRate(const std::string &date) const
{
    std::map<std::string, float>::const_iterator it = db.lower_bound(date);

    if (it != db.end() && it->first == date)
        return it->second;

    if (it == db.begin())
        return -1.0f;

    --it;
    return it->second;
}


void BitcoinExchange::loadDb(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open database." << std::endl;
        return;
    }

    std::string line;

    //skipping the header
    std::getline(file, line);

    while (std::getline(file, line))
    {
        if (line.empty()) 
            continue;
        
        std::stringstream ss(line);
        std::string date;
        std::string priceStr;

        //count till comma as date
        if (!std::getline(ss, date, ',')) 
            continue;
        if (!std::getline(ss, priceStr, ','))
            continue;

        float price = strtof(priceStr.c_str(), NULL);
        db[date] = price;
    }
    file.close();
}



void BitcoinExchange::processInput(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        if (line.empty()) continue;

        size_t sep = line.find(" | ");
        if (sep == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date  = line.substr(0, sep);
        std::string value = line.substr(sep + 3);


        while (!date.empty()  && date[date.size() - 1] == ' ')   
            date.erase(date.size() - 1);
        while (!value.empty() && value[0] == ' ')                 
            value.erase(0, 1);

        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        float amount;
        if (!isValidValue(value, amount))
            continue;

        float rate = getRate(date);
        if (rate < 0)
        {
            std::cerr << "Error: date out of range => " << date << std::endl;
            continue;
        }

        std::cout << date << " => " << amount << " = " << amount * rate << std::endl;
    }
    file.close();
}