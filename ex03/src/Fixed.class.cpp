/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:24:13 by nbardavi          #+#    #+#             */
/*   Updated: 2024/03/26 14:31:16 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.class.hpp"
#include "../include/colors.h"
#include <cmath>
#include <limits.h>


const int Fixed::_bits = 8;
const int Fixed::_int_bits = 24;


	// ************************************************
	// *                Constructors                  *
	// ************************************************

Fixed::Fixed(const Fixed& other) : _number(other.getRawBits()) {
	std::cout << Color::GREEN << "Copy constructeur called" << Color::RESET << std::endl;
}

Fixed::Fixed(int const num){
	if (num > (1 << (Fixed::_int_bits - 1)) - 1 || num < -(1 << (Fixed::_int_bits - 1))){
		std::cerr << Color::RED << "Overflow, value is set to 0" << Color::RESET << std::endl;
		this->setRawBits(0);
		return;
	}
	std::cout << Color::GREEN << "Int constructeur called" << Color::RESET << std::endl;
	this->setRawBits(num << _bits);
}

Fixed::Fixed(float const num){
	if (num > (1 << (Fixed::_int_bits - 1)) - 1 || num < -(1 << (Fixed::_int_bits - 1))){
		std::cerr << Color::RED << "Overflow, value is set to 0" << Color::RESET << std::endl;
		this->setRawBits(0);
		return;
	}
	std::cout << Color::GREEN << "Float constructeur called" << Color::RESET << std::endl;
	this->setRawBits(roundf(num * (1 << _bits)));
}

Fixed::Fixed():_number(0) {
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
		this->setRawBits( other.getRawBits() );
	}
	return *this;
}

Fixed& Fixed::operator++(){
	if (this->getRawBits() < INT_MAX - 1){
		this->setRawBits(this->getRawBits() + 1);
	}
	else {
		std::cerr << Color::RED << "Overflow, value is set to 0" << Color::RESET << std::endl;
		this->setRawBits(0);
	}
	return *this;
}

Fixed Fixed::operator++(int){
	Fixed copy = *this;
	if (this->getRawBits() < INT_MAX - 1){
		this->setRawBits(this->getRawBits() + 1);
	}
	else {
		std::cerr << Color::RED << "Overflow, value is set to 0" << Color::RESET << std::endl;
		this->setRawBits(0);
	}
	return copy;
}

Fixed& Fixed::operator--(){
	if (this->getRawBits() > INT_MIN + 1){
		this->setRawBits(this->getRawBits() + 1);
	}
	else {
		std::cerr << Color::RED << "Overflow, value is set to 0" << Color::RESET << std::endl;
		this->setRawBits(0);
	}
	return *this;
}

Fixed Fixed::operator--(int){
	Fixed copy = *this;
	if (this->getRawBits() < INT_MIN + 1){
		this->setRawBits(this->getRawBits() + 1);
	}
	else {
		std::cerr << Color::RED << "Overflow, value is set to 0" << Color::RESET << std::endl;
		this->setRawBits(0);
	}
	return copy;
}

Fixed Fixed::operator+( const Fixed &other ){
	if ((this->getRawBits() + other.getRawBits()) < INT_MAX || this->getRawBits() + other.getRawBits() < INT_MIN)
		this->setRawBits(this->getRawBits() + other.getRawBits());
	else {
		std::cerr << Color::RED << "Overflow, value is set to 0" << Color::RESET << std::endl;
		this->setRawBits(0);
	}
	return (*this);
}

Fixed Fixed::operator-( const Fixed &other ){
	if ((this->getRawBits() + other.getRawBits()) < INT_MAX || this->getRawBits() + other.getRawBits() < INT_MIN)
		this->setRawBits(this->getRawBits() - other.getRawBits());
	else {
		std::cerr << Color::RED << "Overflow, value is set to 0" << Color::RESET << std::endl;
		this->setRawBits(0);
	}
	return (*this);
}

Fixed Fixed::operator*( const Fixed& other ){
	const float temp = this->toFloat() * other.toFloat();
	Fixed new_fixed(temp);
	
	if (temp < (1 << (Fixed::_int_bits - 1)) - 1 && temp > -(1 << (Fixed::_int_bits - 1)))
		this->setRawBits(new_fixed.getRawBits());
	else {
		std::cerr << Color::RED << "Overflow, value is set to 0" << Color::RESET << std::endl;
		this->setRawBits(0);
	}
	return (*this);
}

Fixed Fixed::operator/( const Fixed& other ){
	const float temp = this->toFloat() / other.toFloat();
	Fixed new_fixed(temp);
	
	if (temp < (1 << (Fixed::_int_bits - 1)) - 1 && temp > -(1 << (Fixed::_int_bits - 1)))
		this->setRawBits(new_fixed.getRawBits());
	else {
		std::cerr << Color::RED << "Overflow, value is set to 0" << Color::RESET << std::endl;
		this->setRawBits(0);
	}
	return (*this);
}

bool Fixed::operator>( const Fixed &other )const{
	return( this->getRawBits() > other.getRawBits() );
}

bool Fixed::operator>=( const Fixed &other )const{
	return( this->getRawBits() >= other.getRawBits() );
}

bool Fixed::operator<( const Fixed &other )const{
	return( this->getRawBits() > other.getRawBits() );
}

bool Fixed::operator<=( const Fixed &other )const{
	return( this->getRawBits() >= other.getRawBits() );
}

bool Fixed::operator==( const Fixed &other )const{
	return( this->getRawBits() > other.getRawBits() );
}

bool Fixed::operator!=( const Fixed &other )const{
	return( this->getRawBits() >= other.getRawBits() );
}

std::ostream& operator<<(std::ostream& out, const Fixed& f) {
    out << f.toFloat();
    return out;
}

    // ************************************************
    // *                Member Functions              *
    // ************************************************


void	Fixed::setRawBits( int const raw){
	// std::cout << Color::BLUE << "setRawBits member function called" << Color::RESET << std::endl;
	this->_number = raw;
}

int Fixed::getRawBits( void )const{
	// std::cout << Color::BLUE << "getRawBits member function called" << Color::RESET << std::endl;
	return(this->_number);
}

float Fixed::toFloat(void) const{
	// std::cout << Color::BLUE << "toFloat member function called" << Color::RESET << std::endl;
	return ( static_cast<float>(getRawBits()) / (1 << _bits) );
}

int Fixed::toInt(void) const{
	// std::cout << Color::BLUE << "toInt member function called" << Color::RESET << std::endl;
	return (getRawBits() >> 8);
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a.getRawBits() < b.getRawBits()) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a.getRawBits() < b.getRawBits()) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a.getRawBits() > b.getRawBits()) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a.getRawBits() > b.getRawBits()) ? a : b;
}
