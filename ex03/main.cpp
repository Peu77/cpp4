#include <Character.h>
#include <Cure.h>
#include <Ice.h>
#include <IMateriaSource.h>
#include <MateriaSource.h>
#include <iostream>
#include "colors.h"

int main()
{
    std::cout << BOLD << BLUE << "=== BASIC FUNCTIONALITY TESTS ===" << RESET << std::endl;

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << YELLOW << "\nCreating characters..." << RESET << std::endl;
    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");

    std::cout << YELLOW << "\nEquipping materias..." << RESET << std::endl;
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    std::cout << YELLOW << "\nUsing materias..." << RESET << std::endl;
    me->use(0, *bob);
    me->use(1, *bob);

    std::cout << BOLD << BLUE << "\n=== INVENTORY MANAGEMENT TESTS ===" << RESET << std::endl;

    std::cout << YELLOW << "Creating additional materias..." << RESET << std::endl;
    AMateria* ice1 = src->createMateria("ice");
    AMateria* ice2 = src->createMateria("ice");
    AMateria* cure1 = src->createMateria("cure");

    std::cout << YELLOW << "Filling inventory..." << RESET << std::endl;
    me->equip(ice1);  // Position 2
    me->equip(ice2);  // Position 3

    std::cout << YELLOW << "Testing full inventory..." << RESET << std::endl;
    me->equip(cure1); // Should not be equipped (inventory full)

    std::cout << YELLOW << "Using all equipped materias..." << RESET << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << CYAN << "Using materia at position " << i << ": " << RESET;
        me->use(i, *bob);
    }

    std::cout << YELLOW << "Unequipping materia at position 1..." << RESET << std::endl;
    me->unequip(1);

    std::cout << YELLOW << "Re-equipping another materia..." << RESET << std::endl;
    me->equip(cure1);

    std::cout << YELLOW << "Using materia at position 1 again..." << RESET << std::endl;
    me->use(1, *bob);

    std::cout << BOLD << BLUE << "\n=== DEEP COPY TESTS ===" << RESET << std::endl;

    std::cout << YELLOW << "Creating a copy of 'me' character..." << RESET << std::endl;
    Character* originalChar = new Character("original");
    originalChar->equip(src->createMateria("ice"));
    originalChar->equip(src->createMateria("cure"));

    std::cout << MAGENTA << "\nTesting copy constructor:" << RESET << std::endl;
    Character* copiedChar = new Character(*originalChar);

    std::cout << YELLOW << "Original character using materias:" << RESET << std::endl;
    originalChar->use(0, *bob);
    originalChar->use(1, *bob);

    std::cout << YELLOW << "Copied character using materias:" << RESET << std::endl;
    copiedChar->use(0, *bob);
    copiedChar->use(1, *bob);

    std::cout << YELLOW << "Changing original character's materias..." << RESET << std::endl;
    originalChar->unequip(0);
    originalChar->equip(src->createMateria("cure"));

    std::cout << YELLOW << "Original character after changes:" << RESET << std::endl;
    originalChar->use(0, *bob);

    std::cout << YELLOW << "Copied character should remain unchanged:" << RESET << std::endl;
    copiedChar->use(0, *bob);

    std::cout << MAGENTA << "\nTesting assignment operator:" << RESET << std::endl;
    Character assignChar("assign");
    assignChar = *originalChar;

    std::cout << YELLOW << "Assigned character using materias:" << RESET << std::endl;
    assignChar.use(0, *bob);
    assignChar.use(1, *bob);

    std::cout << BOLD << BLUE << "\n=== EDGE CASE TESTS ===" << RESET << std::endl;

    std::cout << YELLOW << "Using invalid materia index:" << RESET << std::endl;
    me->use(-1, *bob);
    me->use(10, *bob);

    std::cout << YELLOW << "Creating invalid materia type:" << RESET << std::endl;
    AMateria* invalid = src->createMateria("unknown");
    if (invalid)
        std::cout << RED << "Error: Should not create unknown materia" << RESET << std::endl;
    else
        std::cout << GREEN << "Success: Correctly returned nullptr for unknown materia" << RESET << std::endl;

    std::cout << BOLD << RED << "\n=== CLEANUP ===" << RESET << std::endl;
    delete bob;
    delete me;
    delete src;
    delete originalChar;
    delete copiedChar;

    std::cout << GREEN << "All tests completed!" << RESET << std::endl;
    return 0;
}