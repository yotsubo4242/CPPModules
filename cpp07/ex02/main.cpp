#include <iostream>
#include <string>
#include "Array.hpp"

static void printSeparator(const std::string &label) {
    std::cout << "\n--- " << label << " ---" << std::endl;
}

int main(void) {
    // Default construction: empty array
    printSeparator("Default construction");
    Array<int> empty;
    std::cout << "size: " << empty.size() << std::endl;

    // Construction with n: default-initialized elements
    printSeparator("Construction with n (int)");
    Array<int> a(5);
    std::cout << "size: " << a.size() << std::endl;
    for (unsigned int i = 0; i < a.size(); i++)
        a[i] = static_cast<int>(i * 10);
    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << "a[" << i << "] = " << a[i] << std::endl;

    // Copy construction: modifying copy must not affect original
    printSeparator("Copy construction independence");
    Array<int> b(a);
    b[0] = 999;
    std::cout << "a[0] after modifying copy: " << a[0] << " (expected 0)" << std::endl;
    std::cout << "b[0] after modification:   " << b[0] << " (expected 999)" << std::endl;

    // Assignment operator: modifying original must not affect copy
    printSeparator("Assignment operator independence");
    Array<int> c;
    c = a;
    a[1] = 777;
    std::cout << "c[1] after modifying original: " << c[1] << " (expected 10)" << std::endl;
    std::cout << "a[1] after modification:       " << a[1] << " (expected 777)" << std::endl;

    // Out-of-bounds exception
    printSeparator("Out-of-bounds exception");
    try {
        std::cout << a[a.size()] << std::endl;
    } catch (std::exception &e) {
        std::cerr << "caught: " << e.what() << std::endl;
    }
    try {
        empty[0] = 1;
    } catch (std::exception &e) {
        std::cerr << "caught on empty: " << e.what() << std::endl;
    }

    // Default-initialized values (tip: new int() zero-initializes)
    printSeparator("Default initialization (int)");
    Array<int> d(3);
    for (unsigned int i = 0; i < d.size(); i++)
        std::cout << "d[" << i << "] = " << d[i] << " (expected 0)" << std::endl;

    // Test with std::string type
    printSeparator("String type");
    Array<std::string> s(3);
    s[0] = "hello";
    s[1] = "world";
    s[2] = "!";
    Array<std::string> s2(s);
    s2[0] = "goodbye";
    std::cout << "s[0]: " << s[0] << " (expected hello)" << std::endl;
    std::cout << "s2[0]: " << s2[0] << " (expected goodbye)" << std::endl;

    // Const access: read-only through const instance
    printSeparator("Const access");
    const Array<int> constArr(a);
    std::cout << "constArr[0] = " << constArr[0] << std::endl;
    try {
        std::cout << constArr[constArr.size()] << std::endl;
    } catch (std::exception &e) {
        std::cerr << "caught on const: " << e.what() << std::endl;
    }

    return 0;
}

//#define MAX_VAL 750
//int main(int, char**)
//{
//    Array<int> numbers(MAX_VAL);
//    int* mirror = new int[MAX_VAL];
//    srand(time(NULL));
//    for (int i = 0; i < MAX_VAL; i++)
//    {
//        const int value = rand();
//        numbers[i] = value;
//        mirror[i] = value;
//    }
//    //SCOPE
//    {
//        Array<int> tmp = numbers;
//        Array<int> test(tmp);
//    }
//
//    for (int i = 0; i < MAX_VAL; i++)
//    {
//        if (mirror[i] != numbers[i])
//        {
//            std::cerr << "didn't save the same value!!" << std::endl;
//            return 1;
//        }
//    }
//    try
//    {
//        numbers[-2] = 0;
//    }
//    catch(const std::exception& e)
//    {
//        std::cerr << e.what() << '\n';
//    }
//    try
//    {
//        numbers[MAX_VAL] = 0;
//    }
//    catch(const std::exception& e)
//    {
//        std::cerr << e.what() << '\n';
//    }
//
//    for (int i = 0; i < MAX_VAL; i++)
//    {
//        numbers[i] = rand();
//    }
//    delete [] mirror;//
//    return 0;
//}
