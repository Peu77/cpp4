//
// Created by Emil Ebert on 30.03.25.
//

#ifndef CAT_H
#define CAT_H
#include "Animal.h"


class Cat: public Animal {
public:
    Cat();
    Cat(const Cat &other);
    Cat &operator=(const Cat &other);
    ~Cat() override;
    void makeSound() const override;
};



#endif //CAT_H
