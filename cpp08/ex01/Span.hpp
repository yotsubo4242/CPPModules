#ifndef SPAN_HPP
# define SPAN_HPP

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
	private:
		unsigned int _N;
		unsigned int _size;
		int* _array;
};

#endif