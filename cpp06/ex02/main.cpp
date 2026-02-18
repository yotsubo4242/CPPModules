#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base *generate(void);
void    identify(Base *p);
void    identify(Base& p);

int main()
{
    Base *ptr = generate();

    std::cout << "Identifying by pointer: ";
    identify(ptr);

    std::cout << "Identifying by reference: ";
    identify(*ptr);

    delete ptr;
    return 0;
}
