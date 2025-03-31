#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "WrongAnimal.h"
#include "WrongCat.h"
#include "colors.h"
#include <iostream>

int main() {
    std::cout << BOLD << BLUE << "=== Basic Animal Tests ===" << RESET << std::endl;

    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "J Type: " << j->getType() << std::endl;
    std::cout << "I Type: " << i->getType() << std::endl;

    std::cout << "I sound: "; i->makeSound();
    std::cout << "J sound: "; j->makeSound();

    delete j;
    delete i;

    std::cout << BOLD << BLUE << "\n=== Wrong Animal Tests ===" << RESET << std::endl;

    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << "WrongCat Type: " << wrongCat->getType() << std::endl;

    std::cout << "WrongCat sound: "; wrongCat->makeSound(); // Should use WrongAnimal's makeSound
    std::cout << "WrongAnimal sound: "; wrongAnimal->makeSound();

    delete wrongAnimal;
    delete wrongCat;

    std::cout << BOLD << BLUE << "\n=== Animal Array Test ===" << RESET << std::endl;

    const int arraySize = 50;
    Animal* animals[arraySize];

    // Create half dogs and half cats
    for (int i = 0; i < arraySize; i++) {
        if (i < arraySize / 2) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
    }

    // Make sounds to demonstrate polymorphism
    for (int i = 0; i < arraySize; i++) {
        std::cout << "Animal " << i << " (" << animals[i]->getType() << ") says: ";
        animals[i]->makeSound();
    }

    // Clean up the array
    for (int i = 0; i < arraySize; i++) {
        delete animals[i];
    }

    std::cout << BOLD << BLUE << "\n=== Deep Copy Tests ===" << RESET << std::endl;

    // Test copy constructor
    Dog* originalDog = new Dog();
    Dog* copiedDog = new Dog(*originalDog);

    std::cout << "Original Dog: "; originalDog->makeSound();
    std::cout << "Copied Dog: "; copiedDog->makeSound();

    delete originalDog;
    std::cout << GREEN << "Original dog deleted. Copied dog should still work:" << RESET << std::endl;
    std::cout << "Copied Dog (after original deletion): "; copiedDog->makeSound();

    delete copiedDog;

    // Test assignment operator
    Cat* cat1 = new Cat();
    Cat* cat2 = new Cat();

    *cat2 = *cat1; // Using assignment operator

    delete cat1;
    std::cout << GREEN << "First cat deleted. Second cat should still work:" << RESET << std::endl;
    std::cout << "Second Cat (after first deletion): "; cat2->makeSound();
    delete cat2;

    return 0;
}