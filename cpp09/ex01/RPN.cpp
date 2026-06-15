#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) {
    *this = other;
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

int RPN::calculate(const std::string& formula) {
    for (size_t i = 0; i < formula.length(); ++i) {
        char c = formula[i];
        if (isDigit(c)) {
            _stack.push(c - '0');
        } else if (isOperator(c)) {
            if (_stack.size() < 2) {
                throw std::runtime_error("Invalid expression");
            }
            int b = _stack.top(); _stack.pop();
            int a = _stack.top(); _stack.pop();
            int result = performOperation(c, a, b);
            _stack.push(result);
        } else if (c != ' ') {
            throw std::runtime_error("Invalid character in expression");
        }
    }
    if (_stack.size() != 1) {
        throw std::runtime_error("Invalid expression");
    }
    return _stack.top();
}

bool RPN::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool RPN::isDigit(char c) {
    return c >= '0' && c <= '9';
}

int RPN::performOperation(char op, int a, int b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) {
                throw std::runtime_error("Division by zero");
            }
            return a / b;
        default:
            throw std::runtime_error("Invalid operator");
    }
}
