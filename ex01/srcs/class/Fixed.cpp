/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 21:04:08 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/17 10:02:40 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "class/Fixed.hpp"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

Fixed::Fixed(void) :
	_val(0)
{
	if (DEBUG)
		std::cout
		<< "Creating Fixed"
		<< std::endl;
}

Fixed::Fixed(Fixed const &src) :
	_val(src._val)
{
	if (DEBUG)
		std::cout
		<< "Creating Fixed"
		<< std::endl;
}

Fixed::Fixed(int const val) :
	_val(val << _dotPos)
{
	if (DEBUG)
		std::cout
		<< "Creating Fixed"
		<< std::endl;
}

Fixed::Fixed(float const val) :
	_val((int)roundf(val * (1 << _dotPos)))
{
	if (DEBUG)
		std::cout
		<< "Creating Fixed"
		<< std::endl;
}

// ************************************************************************* //
//                                Destructors                                //
// ************************************************************************* //

Fixed::~Fixed(void)
{
	if (DEBUG)
		std::cout
		<< "Destroying Fixed"
		<< std::endl;
}

// ************************************************************************* //
//                                 Accessors                                 //
// ************************************************************************* //

int	Fixed::getRawBits(void) const
{
	if (DEBUG)
		std::cout
		<< "Calling Fixed::getRawBits()"
		<< std::endl;
	return this->_val;
}

void	Fixed::setRawBits(int const val)
{
	if (DEBUG)
		std::cout
		<< "Calling Fixed::setRawBits()"
		<< std::endl;
	this->_val = val;
}

// ************************************************************************* //
//                          Public Member Functions                          //
// ************************************************************************* //

int	Fixed::toInt(void) const
{
	if (DEBUG)
		std::cout
		<< "Calling Fixed::toInt()"
		<< std::endl;
	return this->_val >> _dotPos;
}

float	Fixed::toFloat(void) const
{
	if (DEBUG)
		std::cout
		<< "Calling Fixed::toFloat()"
		<< std::endl;
	return (float)this->_val / (1 << _dotPos);
}

// ************************************************************************* //
//                                 Operators                                 //
// ************************************************************************* //

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	if (DEBUG)
		std::cout
		<< "Calling Fixed::operator=()"
		<< std::endl;
	if (this != &rhs)
		this->_val = rhs.getRawBits();
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return o;
}

// ************************************************************************** //
//                             Private Attributes                             //
// ************************************************************************** //

int const	Fixed::_dotPos = 8;
