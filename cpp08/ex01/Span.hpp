#ifndef SPAN_HPP
# define SPAN_HPP

#include <stdexcept>
#include <climits>
#include <algorithm>
#include <vector>

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

		template <typename Iterator>
		void addNumbers(Iterator begin, Iterator end)
		{
			while (begin != end)
			{
				addNumber(*begin);
				++begin;
			}
		}

	private:
		unsigned int _N;
		unsigned int _size;
		int* _array;
};

#endif
