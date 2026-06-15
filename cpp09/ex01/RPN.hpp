#ifndef RPN_HPP
#define RPN_HPP

# include <iostream>
# include <stack>
# include <list>
# include <string>
# include <stdexcept>

class RPN {
    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();

        int calculate(const std::string& expression);
    
    private:
        std::stack<int, std::list<int> > _stack;
        bool isOperator(char c);
        bool isDigit(char c);
        int performOperation(char op, int a, int b);
};

#endif
