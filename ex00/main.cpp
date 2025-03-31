#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "colors.h"
#include <iostream>
#include "WrongAnimal.h"
#include "WrongCat.h"

void testBasicFunctionality() {
    std::cout << BOLD << BLUE << "\n===== Basic Functionality Test =====" << RESET << std::endl;

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "Type of j: " << j->getType() << std::endl;
    std::cout << "Type of i: " << i->getType() << std::endl;

    std::cout << BOLD << "Making sounds:" << RESET << std::endl;
    j->makeSound();
    i->makeSound();
    meta->makeSound();

    delete j;
    delete i;
    delete meta;
}

void testCopyConstructors() {
    std::cout << BOLD << BLUE << "\n===== Copy Constructor Test =====" << RESET << std::endl;

    Dog originalDog;
    Cat originalCat;

    std::cout << BOLD << YELLOW << "Creating copies:" << RESET << std::endl;
    Dog copyDog(originalDog);
    Cat copyCat(originalCat);

    std::cout << BOLD << "Testing original and copy sounds:" << RESET << std::endl;
    originalDog.makeSound();
    copyDog.makeSound();
    originalCat.makeSound();
    copyCat.makeSound();
}

void testAssignmentOperators() {
    std::cout << BOLD << BLUE << "\n===== Assignment Operator Test =====" << RESET << std::endl;

    Dog dog1;
    Dog dog2;
    Cat cat1;
    Cat cat2;

    std::cout << BOLD << YELLOW << "Assigning:" << RESET << std::endl;
    dog2 = dog1;
    cat2 = cat1;

    std::cout << BOLD << "Testing after assignment:" << RESET << std::endl;
    dog1.makeSound();
    dog2.makeSound();
    cat1.makeSound();
    cat2.makeSound();
}

void testObjectArray() {
    std::cout << BOLD << BLUE << "\n===== Object Array Test =====" << RESET << std::endl;

    const int arraySize = 4;
    Animal* animals[arraySize];

    std::cout << BOLD << YELLOW << "Creating array of animals:" << RESET << std::endl;
    for (int i = 0; i < arraySize; i++) {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << BOLD << "Testing array elements:" << RESET << std::endl;
    for (int i = 0; i < arraySize; i++) {
        std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
        animals[i]->makeSound();
    }

    std::cout << BOLD << YELLOW << "Cleaning up array:" << RESET << std::endl;
    for (int i = 0; i < arraySize; i++) {
        delete animals[i];
    }
}

void testWrongAnimal() {
    std::cout << BOLD << BLUE << "\n===== Wrong Animal Test =====" << RESET << std::endl;

    const WrongAnimal* meta = new WrongAnimal();
    const WrongAnimal* i = new WrongCat();

    std::cout << "Type of i: " << i->getType() << std::endl;

    std::cout << BOLD << "Making sounds:" << RESET << std::endl;
    // This should call WrongAnimal::makeSound() instead of WrongCat::makeSound()
    // because makeSound() isn't virtual in WrongAnimal
    i->makeSound();
    meta->makeSound();

    // Test direct WrongCat instance to show the difference
    const WrongCat* wrongCat = new WrongCat();
    std::cout << BOLD << "Direct WrongCat instance sound:" << RESET << std::endl;
    wrongCat->makeSound();  // This will call WrongCat::makeSound()

    delete wrongCat;
    delete i;
    delete meta;
}

void testWrongCatCopyAndAssignment() {
    std::cout << BOLD << BLUE << "\n===== WrongCat Copy & Assignment Test =====" << RESET << std::endl;

    // Copy constructor test
    WrongCat originalWrongCat;
    std::cout << BOLD << YELLOW << "Creating copy:" << RESET << std::endl;
    WrongCat copyWrongCat(originalWrongCat);

    std::cout << BOLD << "Testing original and copy sounds:" << RESET << std::endl;
    originalWrongCat.makeSound();
    copyWrongCat.makeSound();

    // Assignment operator test
    WrongCat wrongCat1;
    WrongCat wrongCat2;
    std::cout << BOLD << YELLOW << "Assigning:" << RESET << std::endl;
    wrongCat2 = wrongCat1;

    std::cout << BOLD << "Testing after assignment:" << RESET << std::endl;
    wrongCat1.makeSound();
    wrongCat2.makeSound();
}

int main() {
    std::cout << BOLD << MAGENTA << "==== ANIMAL CLASS TEST SUITE ====" << RESET << std::endl;

    testBasicFunctionality();
    testCopyConstructors();
    testAssignmentOperators();
    testObjectArray();

    std::cout << BOLD << MAGENTA << "\n==== WRONG ANIMAL CLASS TEST SUITE ====" << RESET << std::endl;
    testWrongAnimal();
    testWrongCatCopyAndAssignment();

    std::cout << BOLD << GREEN << "\n==== ALL TESTS COMPLETED ====" << RESET << std::endl;
    return 0;
}