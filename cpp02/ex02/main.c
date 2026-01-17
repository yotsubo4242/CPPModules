#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    return 0;
}

// int main(void) {
//     Fixed a(0.4f);
//     Fixed const b(10);
//     Fixed c(a);
//     Fixed const d(0.4f);
//     Fixed e(10);

//     std::cout << "\033[32mComparison Operators Test\033[m" << std::endl;
//     std::cout << "a: " << a << ", b: " << b << std::endl;
//     std::cout << "a > b: " << (a > b) << std::endl;
//     std::cout << "a < b: " << (a < b) << std::endl;
//     std::cout << "a >= b: " << (a >= b) << std::endl;
//     std::cout << "a <= b: " << (a <= b) << std::endl;
//     std::cout << "a == b: " << (a == b) << std::endl;
//     std::cout << "a == c: " << (a == c) << std::endl;
//     std::cout << "a != b: " << (a != b) << std::endl;
//     std::cout << "a != c: " << (a != c) << std::endl;
//     std::cout << "a + b: " << (a + b) << std::endl;
//     std::cout << "b - a: " << (b - a) << std::endl;
//     std::cout << "a * b: " << (a * b) << std::endl;
//     std::cout << "b / a: " << (b / a) << std::endl;
//     std::cout << std::endl;
    
//     std::cout << "\033[32mIncrement/Decrement Operators Test\033[m" << std::endl;
//     std::cout << "a: " << a << std::endl;
//     std::cout << "++a: " << ++a << std::endl;
//     std::cout << "a: " << a << std::endl;
//     std::cout << "a++: " << a++ << std::endl;
//     std::cout << "a: " << a << std::endl;
//     std::cout << "--a: " << --a << std::endl;
//     std::cout << "a: " << a << std::endl;
//     std::cout << "a--: " << a-- << std::endl;
//     std::cout << "a: " << a << std::endl;
//     std::cout << std::endl;

//     std::cout << "\033[32mMin/Max Functions Test\033[m" << std::endl;
//     std::cout << "a: " << a << ", e: " << e << std::endl;
//     std::cout << "min(a, e): " << Fixed::min(a, e) << std::endl;
//     std::cout << "max(a, e): " << Fixed::max(a, e) << std::endl;
//     std::cout << "b: " << b << ", d: " << d << std::endl;
//     std::cout << "min(b, d): " << Fixed::min(b, d) << std::endl;
//     std::cout << "max(b, d): " << Fixed::max(b, d) << std::endl;
//     return 0;
// }
