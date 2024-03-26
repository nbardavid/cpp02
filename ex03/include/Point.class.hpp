/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:34:43 by nbardavi          #+#    #+#             */
/*   Updated: 2024/03/26 15:06:21 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_CLASS_HPP
# define POINT_CLASS_HPP

#include "Fixed.class.hpp"

class Point {
public:

	// ************************************************
	// *                 Constructors                 *
	// ************************************************

	Point();
	Point(const float& nb1, const float& nb2);
	Point(const Point& other);

	Point &operator=(Point &&);
	Point &operator=(const Point &);
	~Point();

	const Fixed getX();
	const Fixed getY();

private:
	const Fixed _x;
	const Fixed _y;
};

	// ************************************************
	// *                 Constructors                 *
	// ************************************************
Point::Point(): _x(0), _y(0){
}

Point::Point(const float& nb1, const float& nb2): _x(nb1), _y(nb2){
}

Point::Point(const Point& other): _x(other._x), _y(other._y){
}

Point::~Point() {
}

const Fixed Point::getX(){
	return (this->_x);
}

const Fixed Point::getY(){
	return (this->_y);
}

#endif
