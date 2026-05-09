#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>

class Array {
    public:
        Array();
        Array(const unsigned int n);
        Array(const Array &other);
        ~Array();
        Array &operator=(const Array &other);
        T &operator[](const unsigned int i);
        const T &operator[](const unsigned int i) const;
        unsigned int    size() const;
    private:
        T *array;
        unsigned int n;
};

#include "Array.tpp"

#endif
