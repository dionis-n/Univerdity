#include <iostream>

class DynamicArray
{
    private:
        int *array;
        int size;
    public: 
        DynamicArray(): size(0), array(nullptr) {}
        DynamicArray(int size): size(size), array(new int[size]{}) {}
        
        DynamicArray(const DynamicArray& other)
        {
            size = other.size;
            array = new int[size];
            for (int i = 0; i < size; i++)
            {
                array[i] = other.array[i];
            }
        }

        DynamicArray& operator=(const DynamicArray& other)
        {
            if (this != &other)
            {
                size = other.size;

                delete[] array;
                array = new int[size];
                for(int i = 0; i < size; i++)
                {
                    array[i] = other.array[i];
                }
            }
            return *this;
        }

        DynamicArray(DynamicArray&& other) noexcept
        {
            size = other.size;
            
            array = other.array;

            other.size = 0;
            other.array = nullptr;
        }

        DynamicArray& operator=(DynamicArray&& other) noexcept
        {
            if (this != &other)
            {
                size = other.size;
                delete[] array;
                    
                array = other.array;

                other.size = 0;
                other.array = nullptr;
            }
            return *this;
        }

        int sizze()
        {
            return size;
        }

        int& at(int i)
        {
            if (i < 0 || i >= size)
            {
                throw std::out_of_range("IOR");
            }
                return array[i];
        }

        void print()
        {
            if (array != nullptr && size > 0)
            {
                for (int i = 0; i < size; i++)
                {
                    std::cout << array[i] << std::endl;
                }
            }
        }

        ~DynamicArray()
        {
            delete[] array;
        }

};

int main()
{
    DynamicArray arr1(5);
    for (int i = 0; i < 5; i++)
    {
        arr1.at(i) = i * 10;
    }

    arr1.print();

    return 0;
}
