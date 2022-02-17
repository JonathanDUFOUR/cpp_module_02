/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 20:37:07 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/15 23:59:00 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

# ifndef DEBUG
#  define DEBUG 1
# endif

class Fixed
{
private:
	int					_val;

	static int const	_dotPos;

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
	int		toInt(void) const;

	float	toFloat(void) const;

	// Operators
	Fixed	&operator=(Fixed const &rhs);
};

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs);

#endif
