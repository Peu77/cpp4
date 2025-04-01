//
// Created by Emil Ebert on 31.03.25.
//

#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.h"

class Character : public ICharacter {
private:
    static constexpr int inventorySize = 4;
    std::string name;
    AMateria *inventory[inventorySize];

public:
    Character(std::string name);

    Character(Character const &other);

    ~Character();

    Character &operator=(Character const &other);

    std::string const &getName() const;

    void equip(AMateria *m);

    void unequip(int idx);

    void use(int idx, ICharacter &target);
};


#endif //CHARACTER_H
