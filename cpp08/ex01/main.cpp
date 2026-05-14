#include "Span.hpp"
#include <iostream>

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);

    std::cout << "After adding 1 number:" << std::endl;
    try {
        std::cout << sp.shortestSpan() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    try {
        std::cout << sp.longestSpan() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

    std::cout << "After adding N numbers:" << std::endl;
    try {
        sp.addNumber(15);
    } catch (const std::out_of_range& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

    Span sp2 = Span(10000);
    int nums[10000];
    for (int i = 0; i < 10000; i++)
        nums[i] = 42 + i;
    sp2.fillWithNums(nums, 10000);
    std::cout << "After filling with 10000 numbers:" << std::endl;
    try {
        std::cout << sp2.shortestSpan() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    try {
        std::cout << sp2.longestSpan() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
	return 0;
}
