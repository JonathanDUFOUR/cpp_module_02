/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 21:04:08 by jodufour          #+#    #+#             */
/*   Updated: 2022/03/02 21:01:56 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// ************************************************************************** //
//                             Private Attributes                             //
// ************************************************************************** //

uint const	Fixed::_dotPos(8U);
