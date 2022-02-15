/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 03:25:44 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/15 05:38:41 by jodufour         ###   ########.fr       */
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
	if (DBG)
		std::cout
		<< "Creating Point"
		<< std::endl;
}

Point::Point(Point const &src)
{
	if (DBG)
		std::cout
		<< "Creating Point"
		<< std::endl;
	*this = src;
}

Point::Point(float const x, float const y) :
	_x(Fixed(x)),
	_y(Fixed(y))
{
	if (DBG)
		std::cout
		<< "Creating Point"
		<< std::endl;
}

// ************************************************************************* //
//                                Destructors                                //
// ************************************************************************* //

Point::~Point(void)
{
	if (DBG)
		std::cout
		<< "Destroying Point"
		<< std::endl;
}

// ************************************************************************* //
//                                 Accessors                                 //
// ************************************************************************* //

Fixed	Point::x(void) const
{
	if (DBG)
		std::cout
		<< "Calling Point::x()"
		<< std::endl;
	return this->_x;
}

Fixed	Point::y(void) const
{
	if (DBG)
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
	if (DBG)
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
