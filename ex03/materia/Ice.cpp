//
// Created by Emil Ebert on 01.04.25.
//

#include "Ice.h"
#include <iostream>


Ice::Ice(): AMateria("ice") {
    std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(Ice const &other): AMateria(other) {
    (void)other;
    std::cout << "Ice copy constructor called" << std::endl;
}

Ice::~Ice() {
    std::cout << "Ice destructor called" << std::endl;
}

Ice &Ice::operator=(Ice const &other) {
    (void)other;
    std::cout << "Ice assignment operator called" << std::endl;
    return *this;
}

AMateria *Ice::clone() const {
    std::cout << "Ice clone called" << std::endl;
    return new Ice(*this);
}

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
