//
// Created by Emil Ebert on 01.04.25.
//

#include "MateriaSource.h"

MateriaSource::MateriaSource() {
    for (int i = 0; i < inventorySize; i++)
        materia[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource &src) {
    for (int i = 0; i < inventorySize; i++) {
        if (materia[i] != nullptr)
            delete materia[i];
        materia[i] = src.materia[i]->clone();
    }
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < inventorySize; i++) {
        if (materia[i] != nullptr)
            delete materia[i];
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src) {
    if (this != &src) {
        for (int i = 0; i < inventorySize; i++) {
            if (materia[i] != nullptr)
                delete materia[i];
            materia[i] = src.materia[i]->clone();
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
    for (auto & i : materia) {
        if (i == nullptr) {
            i = m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < inventorySize; i++) {
        if (materia[i] != nullptr && materia[i]->getType() == type)
            return materia[i]->clone();
    }
    return nullptr;
}
