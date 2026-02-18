#ifndef DATA_HPP
# define DATA_HPP

# include <string>

class Data
{
    public:
        Data();
        Data(std::string str);
        Data(const Data &other);
        ~Data();
        Data &operator=(const Data &other);
        std::string getStr() const;
        void setStr(const std::string &str);
    
    private:
        std::string _str;
};

#endif
