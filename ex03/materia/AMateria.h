//
// Created by Emil Ebert on 31.03.25.
//

#ifndef AMATERIA_H
#define AMATERIA_H

#include <string>
#include "ICharacter.h"


class AMateria {
protected:
    std::string type;

public:
    AMateria();
    AMateria(std::string const &type);

    AMateria(AMateria const &other);
    virtual ~AMateria();
    AMateria &operator=(AMateria const &other);
    std::string const &getType() const;
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);
};


#endif //AMATERIA_H
