//
// Created by Emil Ebert on 01.04.25.
//

#ifndef ICE_H
#define ICE_H

#include "AMateria.h"
#include "ICharacter.h"

class Ice: public AMateria {
public:
    Ice();
    Ice(Ice const &other);
    ~Ice() override;
    Ice &operator=(Ice const &other);
    AMateria *clone() const override;
    void use(ICharacter &target) override;
};



#endif //ICE_H
