#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>

class BitcoinExchange
{
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        void exchange(const std::string& date, double amount);
        void loadExchangeRates(const std::string& filename);
        void printValues() const;
    
    private:
        std::map<std::string, double> exchangeRates;
        std::map<std::string, double> values;
};

#endif
