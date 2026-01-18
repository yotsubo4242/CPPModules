#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed {
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed(const int i_value);
		Fixed(const float f_value);
		~Fixed();
		Fixed			&operator=(const Fixed &other);
		bool			operator>(const Fixed &other) const;
		bool			operator<(const Fixed &other) const;
		bool			operator>=(const Fixed &other) const;
		bool			operator<=(const Fixed &other) const;
		bool			operator==(const Fixed &other) const;
		bool			operator!=(const Fixed &other) const;
		Fixed			operator+(const Fixed &other) const;
		Fixed			operator-(const Fixed &other) const;
		Fixed			operator*(const Fixed &other) const;
		Fixed			operator/(const Fixed &other) const;
		Fixed			&operator++();			// Prefix increment
		Fixed			operator++(int);		// Postfix increment
		Fixed			&operator--();			// Prefix decrement
		Fixed			operator--(int);		// Postfix decrement
		static Fixed	&min(Fixed &a, Fixed &b);
		static Fixed	const	&min(const Fixed &a, const Fixed &b);
		static Fixed	&max(Fixed &a, Fixed &b);
		static Fixed	const	&max(const Fixed &a, const Fixed &b);
		int				getRawBits(void) const;
		void			setRawBits(int const raw);
		float			toFloat(void) const;
		int				toInt(void) const;

	private:
		static const int	fractional_bits = 8;
		int			raw;
};

std::ostream	&operator<<(std::ostream &os, const Fixed &value);

#endif
