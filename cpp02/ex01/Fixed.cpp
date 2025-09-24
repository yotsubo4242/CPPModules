#include <Fixed.hpp>

Fixed::Fixed(): raw(0) {
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	this->raw = other.getRawBits();
};

Fixed::Fixed(const int i_value) {
	this->raw = i_value << this->fractional_bits;
};

Fixed::Fixed(const float f_value) {
	this->raw = (int)(f_value * (1 << this->fractional_bits));
};

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
};

Fixed	&Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->raw = other.getRawBits();
	}
	return (*this);
};

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->raw);
};

void	Fixed::setRawBits(const int raw) {
	this->raw = raw;
};

float	Fixed::toFloat() const {
	float	res;

	res = this->raw >> this->fractional_bits;
	return (res);
};

int	Fixed::toInt() const {
	int	res;

	res = this->raw >> this->fractional_bits;
	return (res);
};
