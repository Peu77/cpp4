//
// Created by Emil Ebert on 30.03.25.
//

#include "Cat.h"
#include "colors.h"
#include <iostream>

Cat::Cat() : Animal("Cat") {
    std::cout << GREEN << "Cat default constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << CYAN << "Cat copy constructor called" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
    std::cout << YELLOW << "Cat copy assignment operator called" << RESET << std::endl;
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

Cat::~Cat(){
    std::cout << RED << "Cat destructor called" << RESET << std::endl;
}

void Cat::makeSound() const{
    std::cout << BOLD << MAGENTA << "Meow!" << RESET << std::endl;
}