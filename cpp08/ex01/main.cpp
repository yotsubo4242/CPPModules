#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>

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
	std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
	std::cout << "longestSpan:  " << sp.longestSpan() << std::endl;

	// iterator range fill with vector
	std::vector<int> v;
	for (int i = 0; i < 10000; i++)
		v.push_back(i);
	Span sp2(10000);
	sp2.addNumbers(v.begin(), v.end());
	std::cout << "10000 numbers (vector iterators):" << std::endl;
	std::cout << "shortestSpan: " << sp2.shortestSpan() << std::endl;
	std::cout << "longestSpan:  " << sp2.longestSpan() << std::endl;

	// iterator range fill with list
	std::list<int> lst;
	for (int i = 0; i < 5; i++)
		lst.push_back(i * 3);
	Span sp3(5);
	sp3.addNumbers(lst.begin(), lst.end());
	std::cout << "list iterators:" << std::endl;
	std::cout << "shortestSpan: " << sp3.shortestSpan() << std::endl;
	std::cout << "longestSpan:  " << sp3.longestSpan() << std::endl;

	return 0;
}
