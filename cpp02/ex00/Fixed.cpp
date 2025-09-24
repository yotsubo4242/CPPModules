#include <Fixed.hpp>

Fixed::Fixed(): raw(0) {
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	this->raw = other.getRawBits();
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


