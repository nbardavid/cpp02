/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:34:36 by nbardavi          #+#    #+#             */
/*   Updated: 2024/03/27 10:47:26 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.class.hpp"

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

	// ************************************************
	// *                  Fonctions                   *
	// ************************************************

const Fixed Point::getX() const{
	return (this->_x);
}

const Fixed Point::getY() const{
	return (this->_y);
}
