#include <iostream>
#include "Pair_template.h"

int main()
{
    int a = 10;
    float b = 3.4f;
    Pair<int, float> pair1(a, b);
    /*pair1.first = a;
    pair1.second = b;*/

    std::cout << pair1.first() << " " << pair1.second() << std::endl;

    return 0;
}
