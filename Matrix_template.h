#pragma once

template <typename T, int n> class Matrix
{
private:
    T matrix[n][n];
public:
    Matrix()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = 0; //matrix[i][j] = T();
            }
        }
    }

    Matrix(const std::vector<T>& vector)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = vector[i * n + j];
            }
        }
    }
    
    T* operator[](int index)
    {
        return matrix[index];
    }

    const T* operator[](int index) const
    {
        return matrix[index];
    }

    Matrix<T, n> operator+(const Matrix<T, n>& other) const
    {
        Matrix<T, n> result;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                result[i][j] = matrix[i][j] + other[i][j];
            }
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix<T, n>& matrixx)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n;j++)
            {
                os << matrixx[i][j];
                if (j != n - 1)
                {
                    os << " ";
                }
            }
            if (i != n - 1)
            {
                os << "\n";
            }
        }
        return os;
    }

};
