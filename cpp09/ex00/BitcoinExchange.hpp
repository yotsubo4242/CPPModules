#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <cctype>
# include <string>

class BitcoinExchange
{
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        bool loadExchangeRates(const std::string& filename);
        void processInput(const std::string& filename);

    private:
        std::map<std::string, double> _exchangeRates;

        void        exchange(const std::string& date, double amount);
        bool        isValidDate(const std::string& date) const;
        bool        isValidValue(const std::string& str, double& value) const;
        std::string trim(const std::string& s) const;
};

#endif
