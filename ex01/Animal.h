//
// Created by Emil Ebert on 30.03.25.
//

#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {
protected:
    std::string type;

public:
    Animal();
    Animal(const std::string &type);
    Animal(const Animal &other);
    Animal &operator=(const Animal &other);
    virtual ~Animal();

    virtual void makeSound() const;
    std::string getType() const;
};



#endif //ANIMAL_H
