/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:24:13 by nbardavi          #+#    #+#             */
/*   Updated: 2024/04/05 09:42:38 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.class.hpp"
#include "../include/colors.h"
#include <cmath>


const int Fixed::bits = 8;

	// ************************************************
	// *                Constructors                  *
	// ************************************************

Fixed::Fixed(const Fixed& other) : number(other.getRawBits()) {
	std::cout << GREEN << "Copy constructeur called" << RESET << std::endl;
}

Fixed::Fixed(int const num):number(num << bits){
	std::cout << GREEN << "Int constructeur called" << RESET << std::endl;
}

Fixed::Fixed(float const num):number(roundf(num * (1 << bits))){
	std::cout << GREEN << "Float constructeur called" << RESET << std::endl;
}

Fixed::Fixed():number(0) {
	std::cout << GREEN << "Default constructeur called" << RESET << std::endl;
}

	// ************************************************
	// *                Destructors                   *
	// ************************************************

Fixed::~Fixed() {
	std::cout << RED << "Destructor called" << RESET << std::endl;
}    

	// ************************************************
	// *                Operator Overloads            *
	// ************************************************

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << GREEN << "Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {
		this->number = other.getRawBits();
	}
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& f) {
    out << f.toFloat();
    return out;
}

    // ************************************************
    // *                Member Functions              *
    // ************************************************


void	Fixed::setRawBits( int const raw){
	// std::cout << BLUE << "setRawBits member function called" << RESET << std::endl;
	this->number = raw;
}

int Fixed::getRawBits( void )const{
	// std::cout << BLUE << "getRawBits member function called" << RESET << std::endl;
	return(this->number);
}

float Fixed::toFloat(void) const{
	// std::cout << BLUE << "toFloat member function called" << RESET << std::endl;
	return ( static_cast<float>(getRawBits()) / (1 << bits) );
}

int Fixed::toInt(void) const{
	// std::cout << BLUE << "toInt member function called" << RESET << std::endl;
	return (getRawBits() >> 8);
}
