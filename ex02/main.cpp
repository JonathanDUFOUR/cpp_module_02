/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 20:14:51 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/26 03:20:27 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Fixed.hpp"

int	main(void)
{
	Fixed	a(4.2f);
	Fixed	b(3.141592653589793f);
	Fixed	c(0);
	Fixed	d(-21);

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "a + b: " << a + b << std::endl;
	std::cout << "c - d: " << c - d << std::endl;
	std::cout << "a * c: " << a * c << std::endl;
	std::cout << "b / d: " << b / d << std::endl;
	std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;
	std::cout << "max(c, d): " << Fixed::max(c, d) << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "++c: " << ++c << std::endl;
	std::cout << "--b: " << --b << std::endl;
	std::cout << "d--: " << d-- << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "a > 1: " << (a > Fixed(1) ? "true" : "false") << std::endl;
	std::cout << "d < -1: " << (d < Fixed(-1) ? "true" : "false") << std::endl;
	std::cout << "b >= b + 1 - 1 * 1: " << (b >= b + Fixed(1) - Fixed(1) * Fixed(1) ? "true" : "false") << std::endl;
	std::cout << "c <= c - 1: " << (c <= c - Fixed(1) ? "true" : "false") << std::endl;
	std::cout << "c == 1: " << (c == Fixed(1) ? "true" : "false") << std::endl;
	std::cout << "a != b: " << (a != b ? "true" : "false") << std::endl;
	return EXIT_SUCCESS;
}
