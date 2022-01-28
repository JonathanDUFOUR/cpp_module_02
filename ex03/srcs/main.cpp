/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 20:14:51 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/29 00:39:18 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "class/Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const p);

int	main(void)
{
	Point	a(0.0f, 5.0f);
	Point	b(0.0f, 0.0f);
	Point	c(3.0f, 0.0f);
	Point	p(1.0f, 1.0f);

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "p: " << p << std::endl;
	std::cout << "bsp(a, b, c, p): " << (bsp(a, b, c, p) ? "true" : "false") << std::endl;
	return EXIT_SUCCESS;
}
