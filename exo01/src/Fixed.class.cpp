/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:24:13 by nbardavi          #+#    #+#             */
/*   Updated: 2024/03/25 17:20:29 by nbardavi         ###   ########.fr       */
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
	std::cout << Color::GREEN << "Copy constructeur called" << Color::RESET << std::endl;
}

Fixed::Fixed(int const num):number(num << bits){
	std::cout << Color::GREEN << "Int constructeur called" << Color::RESET << std::endl;
}

Fixed::Fixed(float const num):number(roundf(num * (1 << bits))){
	std::cout << Color::GREEN << "Float constructeur called" << Color::RESET << std::endl;
}

Fixed::Fixed():number(0) {
	std::cout << Color::GREEN << "Default constructeur called" << Color::RESET << std::endl;
}

	// ************************************************
	// *                Destructors                   *
	// ************************************************

Fixed::~Fixed() {
	std::cout << Color::RED << "Destructor called" << Color::RESET << std::endl;
}    

	// ************************************************
	// *                Operator Overloads            *
	// ************************************************

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << Color::GREEN << "Copy assignment operator called" << Color::RESET << std::endl;
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
	std::cout << Color::BLUE << "setRawBits member function called" << Color::RESET << std::endl;
	this->number = raw;
}

int Fixed::getRawBits( void )const{
	std::cout << Color::BLUE << "getRawBits member function called" << Color::RESET << std::endl;
	return(this->number);
}

float Fixed::toFloat(void) const{
	std::cout << Color::BLUE << "toFloat member function called" << Color::RESET << std::endl;
	return ( static_cast<float>(getRawBits()) / (1 << bits) );
}

int Fixed::toInt(void) const{
	std::cout << Color::BLUE << "toInt member function called" << Color::RESET << std::endl;
	return (getRawBits() >> 8);
}
