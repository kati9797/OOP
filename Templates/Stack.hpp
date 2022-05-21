#pragma once
#include <iostream>

template <typename T>
class Stack
{
private:
	T* data;
	size_t size;
	size_t capacity;

	void resize();
	void copyFrom(const Stack<T>&);
	void free();

public:
	Stack();
	Stack(const Stack<T>&);
	Stack<T>& operator=(const Stack<T>&);
	~Stack();

	void push(const T&);
	void push(const T&&);
	void pop();
	const T& top() const;
	bool isEmpty() const;
};

template<typename T>
inline void Stack<T>::resize()
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
inline void Stack<T>::copyFrom(const Stack<T>& other)
{
	size = other.size;
	capacity = other.capacity;
	for (int i = 0; i < capacity; i++)
	{
		data[i] = other.data[i];
	}
}

template<typename T>
inline void Stack<T>::free()
{
	delete[] data;
}

template<typename T>
inline Stack<T>::Stack()
{
	size = 0;
	capacity = 4;
	data = new T[capacity];
}

template<typename T>
inline Stack<T>::Stack(const Stack<T>& other)
{
	copyFrom(other);
}

template<typename T>
inline Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename T>
inline Stack<T>::~Stack()
{
	free();
}

template<typename T>
inline void Stack<T>::push(const T& obj)
{
	if (capacity == size)
	{
		resize();
	}
	data[size++] = obj;
}

template<typename T>
inline void Stack<T>::push(const T&& obj)
{
	if (capacity == size)
	{
		resize();
	}
	data[size++] = std::move(obj);
}

template<typename T>
inline void Stack<T>::pop()
{
	if (isEmpty())
	{
		throw std::logic_error("Empty stack!");
	}
	size--;
}

template<typename T>
inline const T& Stack<T>::top() const
{
	if (isEmpty())
	{
		throw std::logic_error("Empty stack!");
	}
	return data[size - 1];
}

template<typename T>
inline bool Stack<T>::isEmpty() const
{
	return size == 0;
}
