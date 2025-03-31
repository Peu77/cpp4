//
// Created by Emil Ebert on 30.03.25.
//

#include "WrongCat.h"
#include "colors.h"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("Cat") {
    std::cout << GREEN << "WrongCat default constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
    std::cout << CYAN << "WrongCat copy constructor called" << RESET << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
    std::cout << YELLOW << "WrongCat copy assignment operator called" << RESET << std::endl;
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    return *this;
}

WrongCat::~WrongCat(){
    std::cout << RED << "WrongCat destructor called" << RESET << std::endl;
}

void WrongCat::makeSound() const{
    std::cout << BOLD << MAGENTA << "Meow!" << RESET << std::endl;
}