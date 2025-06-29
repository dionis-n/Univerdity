#include <iostream>
using namespace std;

// ����������� ����� (����� ����� ����������� �������)
class Animal {
public:
    // ����������� ������� (����� ���� ��������������)
    virtual void makeSound() {
        cout << "Some animal sound\n";
    }

    // ����� ����������� ������� (������ ����� �����������)
    virtual void move() = 0;

    // ����������� ���������� (����� ��� ����������� �������� �����������)
    virtual ~Animal() {}
};

// ��������� 1
class Dog : public Animal {
public:
    void makeSound() override {  // ��������������� ����������� �������
        cout << "Woof!\n";
    }

    void move() override {  // ������������ ���������� ����� ����������� �������
        cout << "Dog runs on four legs\n";
    }
};

// ��������� 2
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
    // Animal animal;  // ������! Animal � ����������� �����

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