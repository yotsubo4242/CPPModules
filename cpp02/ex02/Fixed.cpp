#include <Fixed.hpp>

Fixed::Fixed(): raw(0) {};

Fixed::Fixed(const Fixed &other) {
	this->raw = other.getRawBits();
};

Fixed::Fixed(const int i_value) {
	this->raw = i_value << this->fractional_bits;
};

Fixed::Fixed(const float f_value) {
	const float scaled = f_value * static_cast<float>(1 << this->fractional_bits);
	this->raw = static_cast<int>(scaled + (scaled >= 0.0f ? 0.5f : -0.5f));
};

Fixed::~Fixed() {};

Fixed	&Fixed::operator=(const Fixed &other) {
	if (this != &other) {
		this->raw = other.getRawBits();
	}
	return (*this);
};

bool	Fixed::operator>(const Fixed &other) const {
	return this->raw > other.raw;
};

bool	Fixed::operator<(const Fixed &other) const {
	return this->raw < other.raw;
};

bool	Fixed::operator>=(const Fixed &other) const {
	return this->raw >= other.raw;
};

bool	Fixed::operator<=(const Fixed &other) const {
	return this->raw <= other.raw;
};


bool	Fixed::operator==(const Fixed &other) const {
	return this->raw == other.raw;
};

bool	Fixed::operator!=(const Fixed &other) const {
	return this->raw != other.raw;
};

Fixed	Fixed::operator+(const Fixed &other) const {
	return Fixed(this->toFloat() + other.toFloat());
};


Fixed	Fixed::operator-(const Fixed &other) const {
	return Fixed(this->toFloat() - other.toFloat());
};

Fixed	Fixed::operator*(const Fixed &other) const {
	return Fixed(this->toFloat() * other.toFloat());
};

Fixed	Fixed::operator/(const Fixed &other) const {
	return Fixed(this->toFloat() / other.toFloat());
};

Fixed	&Fixed::operator++() {
	this->raw += 1;
	return (*this);
};

Fixed	Fixed::operator++(int) {
	Fixed	temp(*this);
	this->raw += 1;
	return (temp);
};

Fixed	&Fixed::operator--() {
	this->raw -= 1;
	return (*this);
};

Fixed	Fixed::operator--(int) {
	Fixed	temp(*this);
	this->raw -= 1;
	return (temp);
};


Fixed		&Fixed::min(Fixed &a, Fixed &b) {
	return (a < b ? a : b);
};


Fixed	const &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b ? a : b);
};

Fixed		&Fixed::max(Fixed &a, Fixed &b) {
	return (a > b ? a : b);
};

Fixed	const &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b ? a : b);
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
