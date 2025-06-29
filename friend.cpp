#include <iostream>
using namespace std;

class Box {
private:
    int width;

public:
    Box(int w) : width(w) {}

    // ��������� ������������� �������
    friend void printWidth(const Box& box);
};

// ������������� ������� (����� ���������� � private-�����)
void printWidth(const Box& box) {
    cout << "Box width: " << box.width << endl;
}

int main() {
    Box box(10);
    printWidth(box);  // Box width: 10

    return 0;
}