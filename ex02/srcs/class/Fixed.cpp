/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 21:04:08 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/29 00:29:35 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "class/Fixed.hpp"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

Fixed::Fixed(void) :
	_val(0) {}

Fixed::Fixed(Fixed const &src)
{
	*this = src;
}

Fixed::Fixed(int const val) :
	_val(val << _dotPos) {}

Fixed::Fixed(float const val) :
	_val(roundf(val * (1 << _dotPos))) {}

// ************************************************************************* //
//                                Destructors                                //
// ************************************************************************* //

Fixed::~Fixed(void) {}

// ************************************************************************* //
//                                 Accessors                                 //
// ************************************************************************* //

int	Fixed::getRawBits(void) const
{
	return this->_val;
}

void	Fixed::setRawBits(int const val)
{
	this->_val = val;
}

// ************************************************************************* //
//                          Public Member Functions                          //
// ************************************************************************* //

int	Fixed::toInt(void) const
{
	return this->_val >> _dotPos;
}

float	Fixed::toFloat(void) const
{
	return (float)this->_val / (1 << _dotPos);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return a;
	return b;
}

Fixed const	&Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return a;
	return b;
}

// ************************************************************************** //
//                             Operator Overloads                             //
// ************************************************************************** //

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	if (this != &rhs)
		this->_val = rhs.getRawBits();
	return *this;
}

bool	Fixed::operator>(Fixed const &rhs) const
{
	return this->_val > rhs._val;
}

bool	Fixed::operator<(Fixed const &rhs) const
{
	return this->_val < rhs._val;
}

bool	Fixed::operator>=(Fixed const &rhs) const
{
	return this->_val >= rhs._val;
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
	return this->_val <= rhs._val;
}

bool	Fixed::operator==(Fixed const &rhs) const
{
	return this->_val == rhs._val;
}

bool	Fixed::operator!=(Fixed const &rhs) const
{
	return this->_val != rhs._val;
}

Fixed	Fixed::operator+(Fixed const &rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(Fixed const &rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(Fixed const &rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(Fixed const &rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed	Fixed::operator++(int)
{
	Fixed	n(*this);

	++this->_val;
	return n;
}

Fixed	Fixed::operator--(int)
{
	Fixed	n(*this);

	--this->_val;
	return n;
}

Fixed	&Fixed::operator++(void)
{
	++this->_val;
	return *this;
}

Fixed	&Fixed::operator--(void)
{
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
