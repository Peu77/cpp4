//
// Created by Emil Ebert on 31.03.25.
//

#ifndef BRAIN_H
#define BRAIN_H

#include <string>

class Brain {
private:
    std::string ideas[100];

public:
    Brain();

    Brain(const Brain &other);

    Brain &operator=(const Brain &other);

    ~Brain();
};


#endif //BRAIN_H
