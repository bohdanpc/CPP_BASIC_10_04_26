#pragma once
#include <cmath>

template<class Type>
class Vector2d
{
public:
	Type GetLength() const;
	bool operator==(const Vector2d<Type>& other) const;

private:
	Type x;
	Type y;
};


template<class Type>
Type Vector2d<Type>::GetLength() const
{
	return std::sqrt(x * x + y * y);
}

template<class Type>
bool Vector2d<Type>::operator==(const Vector2d<Type>& other) const
{
	return x == other.x && y == other.y;
}
