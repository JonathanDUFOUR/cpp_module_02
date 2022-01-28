/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 21:04:08 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/29 00:29:10 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/Fixed.hpp"

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
	*this = src;
	std::cout
	<< "Copy constructor called"
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

// ************************************************************************** //
//                             Private Attributes                             //
// ************************************************************************** //

int const	Fixed::_dotPos = 8;
