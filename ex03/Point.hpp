/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 03:25:55 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/26 08:47:57 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point
{
private:
	Fixed const	_x;
	Fixed const	_y;

protected:

public:
	// Constructors
	Point(void);
	Point(Point const &src);
	Point(float const x, float const y);
	Point(Fixed const x, Fixed const y);

	// Destructors
	virtual ~Point(void);

	// Accessors
	Fixed	x(void) const;
	Fixed	y(void) const;

	// Operator Overloads
	Point	&operator=(Point const &rhs);
};

std::ostream	&operator<<(std::ostream &o, Point const &rhs);

#endif
