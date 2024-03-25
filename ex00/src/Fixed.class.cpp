/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:24:13 by nbardavi          #+#    #+#             */
/*   Updated: 2024/03/25 14:26:13 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.class.hpp"
#include "../include/colors.h"
#include <iostream>

const int Fixed::bits = 8;

Fixed::Fixed():number(0) {
	std::cout << Color::GREEN << "Default constructeur called" << Color::RESET << std::endl;
}

Fixed::Fixed(const Fixed& other) : number(other.getRawBits()) {
	std::cout << Color::GREEN << "Copy constructeur called" << Color::RESET << std::endl;
}

Fixed::~Fixed() {
	std::cout << Color::RED << "Destructor called" << Color::RESET << std::endl;
}    

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << Color::GREEN << "Copy assignment operator called" << Color::RESET << std::endl;
	if (this != &other) {
		this->number = other.getRawBits();
	}
	return *this;
}

void	Fixed::setRawBits( int const raw){
	this->number = raw;
}

int Fixed::getRawBits( void )const{
	std::cout << Color::BLUE << "getRawBits member function called" << Color::RESET << std::endl;
	return(this->number);
}
