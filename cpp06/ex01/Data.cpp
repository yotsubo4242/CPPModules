#include "Data.hpp"

Data::Data() : _str("") {}

Data::Data(std::string str) : _str(str) {}

Data::Data(const Data &other) : _str(other._str) {}

Data::~Data() {}

Data &Data::operator=(const Data &other)
{
    if (this != &other)
        _str = other._str;
    return *this;
}

std::string Data::getStr() const
{
    return _str;
}

void Data::setStr(const std::string &str)
{
    _str = str;
}
