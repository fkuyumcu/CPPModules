#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <cctype>

class BitcoinExchange
{
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        void    loadDb(const std::string &filename);
        void    processInput(const std::string &filename);

    private:
        std::map<std::string, float> db;

        float   getRate(const std::string &date) const;
        bool    isValidDate(const std::string &date) const;
        bool    isValidValue(const std::string &value, float &out) const;
};

#endif