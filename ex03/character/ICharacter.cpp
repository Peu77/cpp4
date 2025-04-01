//
// Created by Emil Ebert on 31.03.25.
//

#include "ICharacter.h"
#include <iostream>

ICharacter::ICharacter() {
    std::cout << "Character default constructor called" << std::endl;
}

ICharacter::ICharacter(ICharacter const &other) {
    (void)other; // Avoid unused parameter warning
    std::cout << "Character copy constructor called" << std::endl;
}

ICharacter &ICharacter::operator=(ICharacter const &other) {
    (void)other; // Avoid unused parameter warning
    std::cout << "Character assignment operator called" << std::endl;
    return *this;
}
