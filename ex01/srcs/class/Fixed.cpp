/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 21:04:08 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/15 05:50:30 by jodufour         ###   ########.fr       */
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
	if (DBG)
		std::cout
		<< "Creating Fixed"
		<< std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	if (DBG)
		std::cout
		<< "Creating Fixed"
		<< std::endl;
	*this = src;
}

Fixed::Fixed(int const val) :
	_val(val << _dotPos)
{
	if (DBG)
		std::cout
		<< "Creating Fixed"
		<< std::endl;
}

Fixed::Fixed(float const val) :
	_val(roundf(val * (1 << _dotPos)))
{
	if (DBG)
		std::cout
		<< "Creating Fixed"
		<< std::endl;
}

// ************************************************************************* //
//                                Destructors                                //
// ************************************************************************* //

Fixed::~Fixed(void)
{
	if (DBG)
		std::cout
		<< "Destroying Fixed"
		<< std::endl;
}

// ************************************************************************* //
//                                 Accessors                                 //
// ************************************************************************* //

int	Fixed::getRawBits(void) const
{
	if (DBG)
		std::cout
		<< "Calling Fixed::getRawBits()"
		<< std::endl;
	return this->_val;
}

void	Fixed::setRawBits(int const val)
{
	if (DBG)
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
	if (DBG)
		std::cout
		<< "Calling Fixed::toInt()"
		<< std::endl;
	return this->_val >> _dotPos;
}

float	Fixed::toFloat(void) const
{
	if (DBG)
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
	if (DBG)
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
