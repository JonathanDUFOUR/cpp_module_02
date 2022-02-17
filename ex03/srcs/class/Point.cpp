/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 03:25:44 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/17 10:20:51 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/Point.hpp"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

Point::Point(void) :
	_x(Fixed(0)),
	_y(Fixed(0))
{
	if (DEBUG)
		std::cout
		<< "Creating Point"
		<< std::endl;
}

Point::Point(Point const &src) :
	_x(src._x),
	_y(src._y)
{
	if (DEBUG)
		std::cout
		<< "Creating Point"
		<< std::endl;
}

Point::Point(float const x, float const y) :
	_x(Fixed(x)),
	_y(Fixed(y))
{
	if (DEBUG)
		std::cout
		<< "Creating Point"
		<< std::endl;
}

// ************************************************************************* //
//                                Destructors                                //
// ************************************************************************* //

Point::~Point(void)
{
	if (DEBUG)
		std::cout
		<< "Destroying Point"
		<< std::endl;
}

// ************************************************************************* //
//                                 Accessors                                 //
// ************************************************************************* //

Fixed	Point::x(void) const
{
	if (DEBUG)
		std::cout
		<< "Calling Point::x()"
		<< std::endl;
	return this->_x;
}

Fixed	Point::y(void) const
{
	if (DEBUG)
		std::cout
		<< "Calling Point::y()"
		<< std::endl;
	return this->_y;
}

// ************************************************************************** //
//                             Operators                             //
// ************************************************************************** //

Point	&Point::operator=(Point const &rhs)
{
	if (DEBUG)
		std::cout
		<< "Calling Point::operator=()"
		<< std::endl;
	if (this != &rhs)
	{
		*(Fixed *)&this->_x = rhs._x;
		*(Fixed *)&this->_y = rhs._y;
	}
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Point const &rhs)
{
	o << "{" << rhs.x() << ", " << rhs.y() << "}";
	return o;
}
