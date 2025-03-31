//
// Created by Emil Ebert on 30.03.25.
//

#include "Dog.h"
#include "colors.h"
#include <iostream>

Dog::Dog() : Animal("Dog") {
    std::cout << GREEN << "Dog default constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
    std::cout << CYAN << "Dog copy constructor called" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
    std::cout << YELLOW << "Dog copy assignment operator called" << RESET << std::endl;
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << RED << "Dog destructor called" << RESET << std::endl;
}

void Dog::makeSound() const {
    std::cout << BOLD << BLUE << "Woof!" << RESET << std::endl;
}