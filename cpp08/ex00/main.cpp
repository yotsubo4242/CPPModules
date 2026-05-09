#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec;
    for (int i = 0; i < 10; i++)
        vec.push_back(i);
    
    std::vector<int>::iterator it = easyfind(vec, 5);
    std::cout << "Searching for 5 in vector: " << std::endl;
    if (it != vec.end())
        std::cout << "Found: " << *it << std::endl;
    else
        std::cout << "Not found" << std::endl;

    std::cout << std::endl;
    
    std::vector<int>::iterator it2 = easyfind(vec, 15);
    std::cout << "Searching for 15 in vector: " << std::endl;
    if (it2 != vec.end())
        std::cout << "Found: " << *it2 << std::endl;
    else
        std::cout << "Not found" << std::endl;

    return 0;
}
