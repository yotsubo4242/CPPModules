#ifndef SPAN_HPP
# define SPAN_HPP

#include <stdexcept>
#include <climits>
#include <cmath>

class Span {
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();
		void addNumber(int num);
		int shortestSpan();
		int longestSpan();
		void fillWithNums(const int *nums, unsigned int count);
	private:
		unsigned int _N;
		unsigned int _size;
		int* _array;
};

#endif