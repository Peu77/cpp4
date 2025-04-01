//
// Created by Emil Ebert on 01.04.25.
//

#include "Cure.h"
#include <iostream>


Cure::Cure(): AMateria("cure") {
    std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(Cure const &other): AMateria(other) {
    (void)other;
    std::cout << "Cure copy constructor called" << std::endl;
}

Cure::~Cure() {
    std::cout << "Cure destructor called" << std::endl;
}

Cure &Cure::operator=(Cure const &other) {
    (void)other;
    std::cout << "Cure assignment operator called" << std::endl;
    return *this;
}

AMateria *Cure::clone() const {
    std::cout << "Cure clone called" << std::endl;
    return new Cure(*this);
}

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() <<"'s wounds *" << std::endl;
}
