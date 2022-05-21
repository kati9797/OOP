#pragma once
#include <iostream>

template <typename T,typename D>
class Pair
{
private:
	T first;
	D second;

public:
	Pair() = default;
	Pair(const T& newFirst, const D& newSecond);

	void setFirst(const T& newFirst);
	void setSecond(const D& newSecond);
	const T& getFirst() const;
	const D& getSecond() const;
};

template <typename T, typename D>
Pair<T,D> :: Pair(const T& newFirst, const D& newSecond)
{
	setFirst(newFirst);
	setSecond(newSecond);
}

template <typename T, typename D>
void Pair<T,D> :: setFirst(const T& newFirst)
{
	first = newFirst;
}

template <typename T, typename D>
void Pair<T, D> :: setSecond(const D& newSecond)
{
	second = newSecond;
}

template <typename T, typename D>
const T& Pair<T, D> :: getFirst() const
{
	return first;
}

template <typename T, typename D>
const D& Pair<T, D> :: getSecond() const
{
	return second;
}
