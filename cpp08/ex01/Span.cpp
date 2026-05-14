#include "Span.hpp"

Span::Span() : _N(0), _size(0), _array(NULL) {}

Span::Span(unsigned int N) : _N(N), _size(0), _array(new int[N]) {}

Span::Span(const Span& other) : _N(other._N), _size(other._size), _array(new int[other._N])
{
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = other._array[i];
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		delete[] _array;
		_N = other._N;
		_size = other._size;
		_array = new int[_N];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
	return *this;
}

Span::~Span()
{
	delete[] _array;
}

void Span::addNumber(int num)
{
	if (_size >= _N)
		throw std::out_of_range("Span is full");
	_array[_size] = num;
	_size++;
}


int	Span::shortestSpan()
{
	if (_size < 2)
		throw std::out_of_range("Not enough numbers to find a span");
	int minSpan = INT_MAX;
	for (unsigned int i = 0; i < _size - 1; i++)
	{
		for (unsigned int j = i + 1; j < _size; j++)
		{
			int span = std::abs(_array[i] - _array[j]);
			if (span < minSpan)
				minSpan = span;
		}
	}
	return minSpan;
}

int	Span::longestSpan()
{
	if (_size < 2)
		throw std::out_of_range("Not enough numbers to find a span");
	int min = INT_MAX;
	int max = INT_MIN;
	for (unsigned int i = 0; i < _size; i++)
	{
		if (_array[i] < min)
			min = _array[i];
		if (_array[i] > max)
			max = _array[i];
	}
	return max - min;
}
