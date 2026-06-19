#pragma once

#include <cmath>
#include <cstddef>

template<class Type, unsigned int DIMENSIONS>
class VectorNd
{
public:
    Type GetLength() const
    {
        double sum = 0.0;
        for (std::size_t i = 0; i < DIMENSIONS; ++i)
        {
            sum += static_cast<double>(m_coordinates[i]) * static_cast<double>(m_coordinates[i]);
        }
        return static_cast<Type>(std::sqrt(sum));
    }

private:
    Type m_coordinates[DIMENSIONS];
};