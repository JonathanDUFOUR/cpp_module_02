/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 05:43:51 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/29 00:39:33 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/Point.hpp"

static Fixed	__area(Point const a, Point const b, Point const c)
{
	return Fixed::abs((a.x() * (b.y() - c.y()) + b.x() * (c.y() - a.y()) + c.x() * (a.y() - b.y())) / Fixed(2.0f));
}

bool	bsp(Point const a, Point const b, Point const c, Point const p)
{
	Fixed const	abc = __area(a, b, c);
	Fixed const	abp = __area(a, b, p);
	Fixed const	acp = __area(a, c, p);
	Fixed const	bcp = __area(b, c, p);

	return abp != 0 && acp != 0 && bcp != 0 && Fixed::abs(abc - (abp + acp + bcp)) < 1;
}
