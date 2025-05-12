#pragma once

template <typename T1, typename T2> class Pair
{
private:
    T1 first_;
    T2 second_;
public:
    Pair(T1& first, T2& second): first_(first), second_(second) {}

    T1 first()
    {
        return first_;
    }

    T2 second()
    {
        return second_;
    }
};
