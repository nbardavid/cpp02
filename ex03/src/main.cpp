/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:24:15 by nbardavi          #+#    #+#             */
/*   Updated: 2024/03/27 11:02:00 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Fixed.class.hpp"
#include "../include/Point.class.hpp"

#include <cmath> // Pour std::abs

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    
	float area = 0.5 * std::abs(
		a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) +
		b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) +
		c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())
	);
	float area1 = 0.5 * std::abs(
		point.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) +
		b.getX().toFloat() * (c.getY().toFloat() - point.getY().toFloat()) +
		c.getX().toFloat() * (point.getY().toFloat() - b.getY().toFloat())
	);
	float area2 = 0.5 * std::abs(
		a.getX().toFloat() * (point.getY().toFloat() - c.getY().toFloat()) +
		point.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) +
		c.getX().toFloat() * (a.getY().toFloat() - point.getY().toFloat())
	);
	float area3 = 0.5 * std::abs(
		a.getX().toFloat() * (b.getY().toFloat() - point.getY().toFloat()) +
		b.getX().toFloat() * (point.getY().toFloat() - a.getY().toFloat()) +
		point.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())
	);
	if (area == area1 + area2 + area3)
		return (true);
	else
	 return (false);
}

int main( void ) {
	Point a(2, 2);
	Point b(8, 2);
	Point c(2, 8);
	Point out(-2.2, 5.5);
	Point in(4, 3.5);

	std::cout << bsp( a,b,c, out) << std::endl;
	std::cout << bsp( a,b,c, in) << std::endl;
    return 0;
}
