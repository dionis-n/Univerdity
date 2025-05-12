#include <iostream>
#include <vector>
#include "Matrix_template.h"

int main()
{
    Matrix<int, 3> m1({1, 2, 3, 4 ,5, 6, 7, 8 ,9});
    
    Matrix<float, 2> m2 ({1.5f, 2.5f, 3.5f, 4.5f});

    std::cout << m1 + m1 << std::endl;
    std::cout << m2 << std::endl;

    return 0;
}
