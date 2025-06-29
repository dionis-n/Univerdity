#pragma once

template <typename T>
class Optional
{
    private:
        T* value;
    public:
        Optional(): value(nullptr) {}
        Optional(T value1): value(new T{value1}) {}

        Optional(const Optional& other)
        {
            value = new T;
            *value = *other.value;
        }

        Optional& operator=(const Optional& other)
        {
            if (this != & other)
            {
                delete value;

                value = new T;
                *value = *other.value;
            }
            return *this;
        }

        Optional(Optional&& other) noexcept
        {
            value = other.value;

            other.value = nullptr;
        }
        
        Optional& operator=(Optional&& other) noexcept
        {
            if (this != &other)
            {
                delete value;

                value = other.value;
                other.value = nullptr;
            }
            return *this;
        }

        T get_value()
        {
            if (value == nullptr)
            {
                throw 1;
            }
            return *value;
        }

        T value_or(T value1)
        {
            if (value == nullptr)
            {
                return value1;
            }
            else
            {
                return *value;
            }
        }


        bool is_value()
        {
            if (value == nullptr)
            {
                return false;
            }
            else
            {
                return true;
            }
        }

        void reset()
        {
            if (value != nullptr)
            {
                value = nullptr;
            }
        }

        ~Optional()
        {
            delete value;
        }
       
};
