/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 21:04:08 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/15 23:59:00 by jodufour         ###   ########.fr       */
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
	*this = src;
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
	_val(roundf(val * (1 << _dotPos)))
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

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (DEBUG)
		std::cout
		<< "Calling Fixed::max()"
		<< std::endl;
	if (a > b)
		return a;
	return b;
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (DEBUG)
		std::cout
		<< "Calling Fixed::min()"
		<< std::endl;
	if (a < b)
		return a;
	return b;
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b)
{
	if (DEBUG)
		std::cout
		<< "Calling Fixed::max()"
		<< std::endl;
	if (a > b)
		return a;
	return b;
}

Fixed const	&Fixed::min(Fixed const &a, Fixed const &b)
{
	if (DEBUG)
		std::cout
		<< "Calling Fixed::min()"
		<< std::endl;
	if (a < b)
		return a;
	return b;
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

bool	Fixed::operator>(Fixed const &rhs) const
{
	if (DEBUG)
		std::cout
		<< "Calling Fixed::operator>()"
		<< std::endl;
	return this->_val > rhs._val;
}

bool	Fixed::operator<(Fixed const &rhs) const
{
	if (DEBUG)
		std::cout
		<< "Calling Fixed::operator<()"
		<< std::endl;
	return this->_val < rhs._val;
}

bool	Fixed::operator>=(Fixed const &rhs) const
{
	if (DEBUG)
		std::cout
		<< "Calling Fixed::operator>=()"
		<< std::endl;
	return this->_val >= rhs._val;
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
	if (DEBUG)
		std::cout
		<< "Calling Fixed::operator<=()"
		<< std::endl;
	return this->_val <= rhs._val;
}

bool	Fixed::operator==(Fixed const &rhs) const
{
	if (DEBUG)
		std::cout
		<< "Calling Fixed::operator==()"
		<< std::endl;
	return this->_val == rhs._val;
}

bool	Fixed::operator!=(Fixed const &rhs) const
{
	if (DEBUG)
		std::cout
		<< "Calling Fixed::operator!=()"
		<< std::endl;
	return this->_val != rhs._val;
}

Fixed	Fixed::operator+(Fixed const &rhs) const
{
	if (DEBUG)
		std::cout
		<< "Calling Fixed::operator+()"
		<< std::endl;
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(Fixed const &rhs) const
{
	if (DEBUG)
		std::cout
		<< "Calling Fixed::operator-()"
		<< std::endl;
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(Fixed const &rhs) const
{
	if (DEBUG)
		std::cout
		<< "Calling Fixed::operator*()"
		<< std::endl;
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(Fixed const &rhs) const
{
	if (DEBUG)
		std::cout
		<< "Calling Fixed::operator/()"
		<< std::endl;
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed	Fixed::operator++(int)
{
	Fixed	n(*this);

	if (DEBUG)
		std::cout
		<< "Calling Fixed::operator++()"
		<< std::endl;
	++this->_val;
	return n;
}

Fixed	Fixed::operator--(int)
{
	Fixed	n(*this);

	if (DEBUG)
		std::cout
		<< "Calling Fixed::operator--()"
		<< std::endl;
	--this->_val;
	return n;
}

Fixed	&Fixed::operator++(void)
{
	if (DEBUG)
		std::cout
		<< "Calling Fixed::operator++()"
		<< std::endl;
	++this->_val;
	return *this;
}

Fixed	&Fixed::operator--(void)
{
	if (DEBUG)
		std::cout
		<< "Calling Fixed::operator--()"
		<< std::endl;
	--this->_val;
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
