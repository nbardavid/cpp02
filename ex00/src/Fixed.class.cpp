/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:24:13 by nbardavi          #+#    #+#             */
/*   Updated: 2024/04/08 11:56:07 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.class.hpp"
#include "../include/colors.h"
#include <iostream>

const int Fixed::bits = 8;

Fixed::Fixed():number(0) {
	std::cout << GREEN << "Default constructeur called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed& other) : number(other.getRawBits()) {
	std::cout << GREEN << "Copy constructeur called" << RESET << std::endl;
}

Fixed::~Fixed() {
	std::cout << RED << "Destructor called" << RESET << std::endl;
}    

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << GREEN << "Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {
		this->number = other.getRawBits();
	}
	return *this;
}

void	Fixed::setRawBits( int const raw){
	this->number = raw;
}

int Fixed::getRawBits( void )const{
	std::cout << BLUE << "getRawBits member function called" << RESET << std::endl;
	return(this->number);
}
