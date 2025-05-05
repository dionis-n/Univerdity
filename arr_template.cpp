#include <iostream>
#include <string>
#include <algorithm>

template <typename T> const T findMax(T arr[], size_t size)
{
    T max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

template <typename T> const T findMin(T arr[], size_t size)
{
    T min = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

//AV
template <typename T> const T findAverage(T arr[], size_t size)
{
    T arr2[size];
    std::copy(arr, arr + size, arr2);
    std::sort(arr2, arr2 + size);
    return arr2[size/2];
}

/*template<>
const float findAverage(int arr[], size_t size)
{
    float sum = 0.f;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum/size;
}*/

template<>
const float findAverage(float arr[], size_t size)
{
    float sum = 0.f;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum/size;
}

//AV

template <typename T> void print(T arr[], size_t size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int array_int[6] = {5, 2, 9, 4, 7, 0};
    float array_float[3] = {2.1f, 7.9f, 0.3f};
    char array_char[5] = {'a', 'b', 'c', 'd', 'e'};
    std::string array_string[3] = {"First", "Second", "Third"};

    std::cout << "ALL MAX:" << std::endl;
    std::cout << findMax(array_int, 6) << std::endl;
    std::cout << findMax(array_float, 3) << std::endl;
    std::cout << findMax(array_char, 5) << std::endl;
    std::cout << findMax(array_string, 3) << std::endl;

    std::cout << std::endl << "ALL MIN:" << std::endl;
    std::cout << findMin(array_int, 6) << std::endl;
    std::cout << findMin(array_float, 3) << std::endl;
    std::cout << findMin(array_char, 5) << std::endl;
    std::cout << findMin(array_string, 3) << std::endl;

    std::cout << std::endl << "ALL AVERAGE:" << std::endl;
    std::cout << findAverage(array_int, 6) << std::endl;
    std::cout << findAverage(array_float, 3) << std::endl;
    std::cout << findAverage(array_char, 5) << std::endl;
    std::cout << findAverage(array_string, 3) << std::endl;

    std::cout << std::endl << "ALL PRINT:" << std::endl;
    print(array_int, 6);
    print(array_float, 3);
    print(array_char, 5);
    print(array_string, 3);

    return 0;
}
