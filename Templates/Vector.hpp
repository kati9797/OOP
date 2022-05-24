#include <iostream>

template <typename T>
class Vector
{
private:
	T* data;
	int size;
	int capacity;

	void resize();
	void copyFrom(const Vector<T>&);
	void free();

public:
	Vector();
	Vector(int);
	Vector(const Vector<T>&);
	Vector<T>& operator=(const Vector<T>&);
	~Vector();

	int getSize() const;
	int getCapacity() const;
	void push(const T&);
	T& operator[](const int);
	const T& operator[](int) const;
};

template<typename T>
inline void Vector<T>::resize()
{
	capacity *= 2;
	T* resizedData = new T[capacity];
	for (int i = 0; i < size; i++)
	{
		resizedData[i] = data[i];
	}
	free();
	data = resizedData;
}

template<typename T>
inline void Vector<T>::copyFrom(const Vector<T>& other)
{
	data = new T[other.capacity];
	capacity = other.capacity;
	size = other.size;
	for (int i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
}

template<typename T>
inline void Vector<T>::free()
{
	delete[] data;
}

template<typename T>
inline Vector<T>::Vector()
{
	size = 0;
	capacity = 4;
	data = new T[capacity];
}

template<typename T>
inline Vector<T>::Vector(int newCapacity)
{
	if (newCapacity > 0)
	{
		capacity = newCapacity;
	}
	size = 0;
	data = new T[capacity];
}

template<typename T>
inline Vector<T>::Vector(const Vector<T>& other)
{
	copyFrom(other);
}

template<typename T>
inline Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename T>
inline Vector<T>::~Vector()
{
	free();
}

template<typename T>
inline int Vector<T>::getSize() const
{
	return size;
}

template<typename T>
inline int Vector<T>::getCapacity() const
{
	return capacity;
}

template<typename T>
inline void Vector<T>::push(const T& obj)
{
	if (size == capacity)
	{
		resize();
	}
	data[size++] = obj;
}

template<typename T>
inline T& Vector<T>::operator[](const int index)
{
	if (index >= 0 && index < size)
	{
		return data[index];
	}
	else
	{
		throw std::logic_error("Invalid index!");
	}
}

template<typename T>
inline const T& Vector<T>::operator[](int index) const
{
	if (index >= 0 && index < size)
	{
		return data[index];
	}
	else
	{
		throw std::logic_error("Invalid index!");
	}
}
