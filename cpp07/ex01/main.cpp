#include "iter.hpp"
#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RES "\033[0m"

void addOne(int &n)
{
	n += 1;
}

void toUpper(std::string &str)
{
	for (std::size_t i = 0; i < str.length(); i++)
		str[i] = std::toupper(str[i]);
}

int main()
{
	std::cout << GREEN << "Original (integer array)" << RES << std::endl;
	int array[] = {1, 2, 3, 4, 5};
	for (std::size_t i = 0; i < sizeof(array) / sizeof(array[0]); i++)
		std::cout << array[i] << std::endl;
	std::cout << "-----------------" << std::endl;

	std::cout << GREEN << "After iter function (integer array)" << RES << std::endl;
	::iter(array, sizeof(array) / sizeof(array[0]), addOne);
	for (std::size_t i = 0; i < sizeof(array) / sizeof(array[0]); i++)
		std::cout << array[i] << std::endl;

	std::cout << "-----------------" << std::endl;
	std::cout << GREEN << "Original (string array)" << RES << std::endl;
	std::string strArray[] = {"Hello", "World", "!"};
	for (std::size_t i = 0; i < sizeof(strArray) / sizeof(strArray[0]); i++)
		std::cout << strArray[i] << std::endl;
	std::cout << "-----------------" << std::endl;

	std::cout << GREEN << "After iter function (string array)" << RES << std::endl;
	::iter(strArray, sizeof(strArray) / sizeof(strArray[0]), toUpper);
	for (std::size_t i = 0; i < sizeof(strArray) / sizeof(strArray[0]); i++)
		std::cout << strArray[i] << std::endl;

	return 0;
}
