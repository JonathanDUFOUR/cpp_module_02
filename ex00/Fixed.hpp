/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 20:37:07 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/26 01:18:18 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int					_val;
	static int const	_dotPos;

protected:

public:
	// Constructors
	Fixed(void);
	Fixed(Fixed const &src);

	// Destructors
	~Fixed(void);

	// Accessors
	int		getRawBits(void) const;

	void	setRawBits(int const val);

	// Operator overloads
	Fixed	&operator=(Fixed const &rhs);
};

#endif
