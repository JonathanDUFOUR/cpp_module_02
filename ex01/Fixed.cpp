/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 21:04:08 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/26 01:20:09 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "Fixed.hpp"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

Fixed::Fixed(void) :
	_val(0)
{
	std::cout
	<< "Default constructor called"
	<< std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout
	<< "Copy constructor called"
	<< std::endl;
	*this = src;
}

Fixed::Fixed(int const val) :
	_val(val << _dotPos)
{
	std::cout
	<< "Int construtor called"
	<< std::endl;
}

Fixed::Fixed(float const val) :
	_val(roundf(val * (1 << _dotPos)))
{
	std::cout
	<< "Float constructor called"
	<< std::endl;
}

// ************************************************************************* //
//                                Destructors                                //
// ************************************************************************* //

Fixed::~Fixed(void)
{
	std::cout
	<< "Destructor called"
	<< std::endl;
}

// ************************************************************************* //
//                                 Accessors                                 //
// ************************************************************************* //

int	Fixed::getRawBits(void) const
{
	std::cout
	<< "getRawBits member function called"
	<< std::endl;
	return this->_val;
}

void	Fixed::setRawBits(int const val)
{
	std::cout
	<< "setRawBits member function called"
	<< std::endl;
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

// ************************************************************************** //
//                             Operator Overloads                             //
// ************************************************************************** //

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	std::cout
	<< "Copy assignement operator called"
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
