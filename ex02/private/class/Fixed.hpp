/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 20:37:07 by jodufour          #+#    #+#             */
/*   Updated: 2022/03/02 17:43:30 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

# ifndef DEBUG
#  define DEBUG 0
# endif

typedef unsigned int	uint;

class Fixed
{
private:
	int					_val;

	static uint const	_dotPos;

public:
	// Constructors
	Fixed(void);
	Fixed(Fixed const &src);
	Fixed(int const val);
	Fixed(float const val);

	// Destructors
	virtual ~Fixed(void);

	// Accessors
	int		getRawBits(void) const;

	void	setRawBits(int const val);

	// Member functions
	int				toInt(void) const;

	float			toFloat(void) const;

	static Fixed		&max(Fixed &a, Fixed &b);
	static Fixed		&min(Fixed &a, Fixed &b);
	static Fixed const	&max(Fixed const &a, Fixed const &b);
	static Fixed const	&min(Fixed const &a, Fixed const &b);

	// Operators
	Fixed	&operator=(Fixed const &rhs);
	bool	operator>(Fixed const &rhs) const;
	bool	operator<(Fixed const &rhs) const;
	bool	operator>=(Fixed const &rhs) const;
	bool	operator<=(Fixed const &rhs) const;
	bool	operator==(Fixed const &rhs) const;
	bool	operator!=(Fixed const &rhs) const;
	Fixed	operator+(Fixed const &rhs) const;
	Fixed	operator-(Fixed const &rhs) const;
	Fixed	operator*(Fixed const &rhs) const;
	Fixed	operator/(Fixed const &rhs) const;
	Fixed	operator++(int);	// a++
	Fixed	operator--(int);	// a--
	Fixed	&operator++(void);	// ++a
	Fixed	&operator--(void);	// --a
};

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs);

#endif
