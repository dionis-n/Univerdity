#include <iostream>
#include <string>
#include <cmath>

template <typename T> const T _pow(const T& x, int n)
{
    return pow(x, n);
}

template<>
const std::string _pow(const std::string& x, int n)
{
    std::string ss = "";
    for (int i = 0; i < n; i++)
    {
        ss += x;
    }
    return ss;
}

int main()
{
    std::cout << _pow(5, 3) << std::endl;
    std::string str = "one";
    std::cout << _pow(str, 5) << std::endl;
    return 0;
}
