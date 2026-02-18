#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>

Base *generate(void)
{
    unsigned long now = std::time(0);
    int random = static_cast<int>(now % 3);

    switch (random)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return NULL;
    }
}
