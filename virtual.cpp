#include <iostream>
using namespace std;

// Абстрактный класс (имеет чисто виртуальную функцию)
class Animal {
public:
    // Виртуальная функция (может быть переопределена)
    virtual void makeSound() {
        cout << "Some animal sound\n";
    }

    // Чисто виртуальная функция (делает класс абстрактным)
    virtual void move() = 0;

    // Виртуальный деструктор (важно для корректного удаления наследников)
    virtual ~Animal() {}
};

// Наследник 1
class Dog : public Animal {
public:
    void makeSound() override {  // Переопределение виртуальной функции
        cout << "Woof!\n";
    }

    void move() override {  // Обязательная реализация чисто виртуальной функции
        cout << "Dog runs on four legs\n";
    }
};

// Наследник 2
class Bird : public Animal {
public:
    void makeSound() override {
        cout << "Chirp!\n";
    }

    void move() override {
        cout << "Bird flies\n";
    }
};

int main() {
    // Animal animal;  // Ошибка! Animal — абстрактный класс

    Animal* dog = new Dog();
    Animal* bird = new Bird();

    dog->makeSound();  // Woof!
    dog->move();       // Dog runs on four legs

    bird->makeSound(); // Chirp!
    bird->move();      // Bird flies

    delete dog;
    delete bird;

    return 0;
}