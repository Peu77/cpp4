//
// Created by Emil Ebert on 30.03.25.
//

#ifndef CAT_H
#define CAT_H
#include "Animal.h"
#include "Brain.h"


class Cat: public Animal {
private:
    Brain *brain;
public:
    Cat();
    Cat(const Cat &other);
    Cat &operator=(const Cat &other);
    ~Cat() override;
    void makeSound() const override;
};



#endif //CAT_H
