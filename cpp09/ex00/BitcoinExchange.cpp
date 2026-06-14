#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : _exchangeRates(other._exchangeRates) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        _exchangeRates = other._exchangeRates;
    return *this;
}

std::string BitcoinExchange::trim(const std::string& s) const
{
    size_t start = s.find_first_not_of(" \t\r\n");
    if (start == std::string::npos)
        return "";
    size_t end = s.find_last_not_of(" \t\r\n");
    return s.substr(start, end - start + 1);
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
    if (date.size() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) continue;
        if (!std::isdigit(date[i]))
            return false;
    }
    int month = std::atoi(date.substr(5, 2).c_str());
    int day   = std::atoi(date.substr(8, 2).c_str());
    return (month >= 1 && month <= 12 && day >= 1 && day <= 31);
}

bool BitcoinExchange::isValidValue(const std::string& str, double& value) const
{
    if (str.empty())
        return false;
    char* end;
    value = std::strtod(str.c_str(), &end);
    return (end != str.c_str() && *end == '\0');
}

bool BitcoinExchange::loadExchangeRates(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl;
        return false;
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos)
            continue;
        std::string date = trim(line.substr(0, commaPos));
        double rate = std::strtod(line.substr(commaPos + 1).c_str(), NULL);
        _exchangeRates[date] = rate;
    }
    return true;
}

void BitcoinExchange::exchange(const std::string& date, double amount)
{
    std::map<std::string, double>::iterator it = _exchangeRates.lower_bound(date);

    if (it == _exchangeRates.end() || it->first != date) {
        if (it == _exchangeRates.begin()) {
            std::cerr << "Error: bad input => " << date << std::endl;
            return;
        }
        --it;
    }
    std::cout << date << " => " << amount << " = " << amount * it->second << std::endl;
}

void BitcoinExchange::processInput(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date     = trim(line.substr(0, pipePos));
        std::string valueStr = trim(line.substr(pipePos + 1));

        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        double value;
        if (!isValidValue(valueStr, value)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        exchange(date, value);
    }
}
