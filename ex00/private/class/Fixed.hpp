/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 20:37:07 by jodufour          #+#    #+#             */
/*   Updated: 2022/03/02 17:41:12 by jodufour         ###   ########.fr       */
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

	// Destructors
	virtual ~Fixed(void);

	// Accessors
	int		getRawBits(void) const;

	void	setRawBits(int const val);

	// Operators
	Fixed	&operator=(Fixed const &rhs);
};

#endif
