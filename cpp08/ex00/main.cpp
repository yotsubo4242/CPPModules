#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
    std::vector<int> vec;
    for (int i = 0; i < 10; i++)
        vec.push_back(i);

    try {
        std::vector<int>::iterator it = easyfind(vec, 5);
        std::cout << "vector: found " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "vector: " << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(vec, 15);
        std::cout << "vector: found " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "vector: " << e.what() << std::endl;
    }

    std::list<int> lst;
    for (int i = 0; i < 5; i++)
        lst.push_back(i * 2);

    try {
        std::list<int>::iterator it = easyfind(lst, 4);
        std::cout << "list: found " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "list: " << e.what() << std::endl;
    }

    try {
        std::list<int>::iterator it = easyfind(lst, 3);
        std::cout << "list: found " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "list: " << e.what() << std::endl;
    }

    return 0;
}
