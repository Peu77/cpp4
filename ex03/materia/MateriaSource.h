//
// Created by Emil Ebert on 01.04.25.
//

#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "AMateria.h"
#include "IMateriaSource.h"

class MateriaSource: public IMateriaSource{
private:
    static constexpr int inventorySize = 4;
    AMateria* materia[inventorySize];

 public:
    MateriaSource();
    MateriaSource(const MateriaSource &src);
    ~MateriaSource();
    MateriaSource &operator=(const MateriaSource &src);

    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);

};



#endif //MATERIASOURCE_H
