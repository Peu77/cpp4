//
// Created by Emil Ebert on 01.04.25.
//

#ifndef CURE_H
#define CURE_H

#include "AMateria.h"
#include "ICharacter.h"

class Cure: public AMateria {
public:
    Cure();
    Cure(Cure const &other);
    ~Cure() override;
    Cure &operator=(Cure const &other);
    AMateria *clone() const override;
    void use(ICharacter &target) override;
};



#endif //CURE_H
