//
// Created by Emil Ebert on 31.03.25.
//

#include "AMateria.h"
#include <iostream>

AMateria::AMateria(): type("default") {
    std::cout << "Materia default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type) {
    std::cout << "Materia constructor called" << std::endl;
}

AMateria::AMateria(AMateria const &other) {
    (void)other;
    std::cout << "Materia copy constructor called" << std::endl;
}

AMateria::~AMateria() {
    std::cout << "Materia destructor called" << std::endl;
}

AMateria &AMateria::operator=(AMateria const &other) {
    (void) other;
    std::cout << "Materia assignment operator called" << std::endl;
    return *this;
}

std::string const &AMateria::getType() const {
    return type;
}

void AMateria::use(ICharacter &target) {
    std::cout << "Using materia on " << target.getName() << std::endl;
}

AMateria *AMateria::clone() const {
    std::cout << "Materia clone called" << std::endl;
    return nullptr;
}

