#include <Fixed.hpp>

Fixed::Fixed(): raw(0) {
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
};

Fixed::Fixed(const int i_value) {
	std::cout << "Int constructor called" << std::endl;
	this->raw = i_value << this->fractional_bits;
};

Fixed::Fixed(const float f_value) {
	std::cout << "Float constructor called" << std::endl;
	const float scaled = f_value * static_cast<float>(1 << this->fractional_bits);
	this->raw = static_cast<int>(scaled + (scaled >= 0.0f ? 0.5f : -0.5f));
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
	return (this->raw);
};

void	Fixed::setRawBits(const int raw) {
	this->raw = raw;
};

float	Fixed::toFloat() const {
	return static_cast<float>(this->raw)
	/ static_cast<float>(1 << this->fractional_bits);
};

int	Fixed::toInt() const {
	return (this->raw >> this->fractional_bits);
};

std::ostream	&operator<<(std::ostream &os, const Fixed &value) {
	os << value.toFloat();
	return (os);
}
