//
// Created by Emil Ebert on 31.03.25.
//

#include "Character.h"

#include <AMateria.h>
#include <iostream>

Character::Character(std::string name) : name(std::move(name)) {
    for (auto &i: inventory) {
        i = nullptr;
    }
}

Character::Character(Character const &other) : ICharacter(other), name(other.name){
    for (int i = 0; i < inventorySize; ++i) {
        if (other.inventory[i]) {
            inventory[i] = other.inventory[i]->clone();
        } else {
            inventory[i] = nullptr;
        }
    }
}

Character::~Character() {
    for (auto &i: inventory) {
        delete i;
    }
}

Character &Character::operator=(Character const &other) {
    if (this != &other) {
        name = other.name;
        for (int i = 0; i < inventorySize; ++i) {
            delete inventory[i];
            if (other.inventory[i]) {
                inventory[i] = other.inventory[i]->clone();
            } else {
                inventory[i] = nullptr;
            }
        }
    }
    return *this;
}

std::string const &Character::getName() const {
    return name;
}

void Character::equip(AMateria *m) {
    for (auto & i : inventory) {
        if (!i) {
            i = m;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < inventorySize) {
        delete inventory[idx];
        inventory[idx] = nullptr;
    }
}

void Character::use(int idx, ICharacter &target) {
    if (idx < 0 || idx >= inventorySize) {
        std::cout << "Index " << idx << " is out of bounds" << std::endl;
        return;
    }

    if (inventory[idx] == nullptr) {
        std::cout << "No materia equipped at index " << idx << std::endl;
        return;
    }
    inventory[idx]->use(target);
}
