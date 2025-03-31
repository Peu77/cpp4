//
// Created by Emil Ebert on 30.03.25.
//

#ifndef DOG_H
#define DOG_H
#include "Animal.h"
#include "Brain.h"


class Dog: public Animal {
private:
    Brain *brain;

public:
    Dog();
    Dog(const Dog &other);
    Dog &operator=(const Dog &other);
    ~Dog() override;
    void makeSound() const override;
};



#endif //DOG_H
