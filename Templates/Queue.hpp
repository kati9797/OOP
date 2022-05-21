#include <iostream>
#include <exception>
template <typename T>
class MyQueue
{
	T* data;
	size_t capacity;
	size_t size;

	size_t get;
	size_t put;

	void resize();

	void copyFrom(const MyQueue<T>& other);
	void free();
public:
	MyQueue();

	MyQueue(const MyQueue<T>& other);
	MyQueue<T>& operator=(const MyQueue<T>& other);

	void push(const T& obj);
	void push(T&& obj);
	void pop();

	const T& peek() const;
	bool isEmpty() const;

	~MyQueue();

};

template <typename T>
MyQueue<T>::MyQueue()
{
	capacity = 4;
	data = new T[capacity];
	size = 0;
	get = put = 0;
}

template <typename T>
void MyQueue<T>::push(const T& obj)
{
	if (size == capacity)
		resize();

	data[put] = obj;
	(++put) %= capacity;
	size++;
}

template <typename T>
void MyQueue<T>::push(T&& obj)
{
	if (size == capacity)
		resize();

	data[put] = std::move(obj);
	(++put) %= capacity;
	size++;
}

template <typename T>
bool MyQueue<T>::isEmpty() const
{
	return size == 0;
}


template <typename T>
const T& MyQueue<T>::peek() const
{
	if (isEmpty())
		throw std::logic_error("Empty queue!");

	return data[get];
}

template <typename T>
void MyQueue<T>::pop()
{
	if (isEmpty())
		throw std::logic_error("Empty queue!");
	(++get) %= capacity;
	size--;
}

template <typename T>
void MyQueue<T>::resize()
{
	T* resizedData = new T[capacity * 2];
	for (size_t i = 0; i < size; i++)
	{
		resizedData[i] = data[get];
		(++get) %= capacity;
	}
	capacity *= 2;
	delete[] data;
	data = resizedData;
	get = 0;
	put = size;
}


template <typename T>
void MyQueue<T>::copyFrom(const MyQueue<T>& other)
{
	data = new T[other.capacity];
	for (int i = 0; i < other.capacity; i++)
		data[i] = other.data[i];

	get = other.get;
	put = other.put;

	size = other.size;
	capacity = other.capacity;

}

template <typename T>
void MyQueue<T>::free()
{
	delete[] data;
}

template <typename T>
MyQueue<T>::MyQueue(const MyQueue<T>& other)
{
	copyFrom(other);

}

template <typename T>
MyQueue<T>& MyQueue<T>::operator=(const MyQueue<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

template <typename T>
MyQueue<T>::~MyQueue()
{
	free();
}

template <typename T>
class kPriorityQueue
{
private:
	MyQueue<T>* pQueue;
	size_t kPriority;
	size_t countElements = 0;

	void copyFrom(const kPriorityQueue<T>&);
	void free();

public:
	kPriorityQueue(size_t);
	kPriorityQueue(const kPriorityQueue<T>&);
	kPriorityQueue<T>& operator=(const kPriorityQueue<T>&);
	~kPriorityQueue();

	void push(const T&, size_t);
	void push(const T&&, size_t);
	void pop();
	const T& peek() const;
	bool isEmpty() const;
};

template<typename T>
inline void kPriorityQueue<T>::copyFrom(const kPriorityQueue<T>& other)
{
	pQueue = new MyQueue<T>[other.kPriority];
	kPriority = other.kPriority;
	for (int i = 0; i < kPriority; i++)
	{
		pQueue[i] = other.pQueue[i];
	}
}

template<typename T>
inline void kPriorityQueue<T>::free()
{
	delete[] pQueue;
}

template<typename T>
kPriorityQueue<T>::kPriorityQueue(size_t maxPriority)
{
	if (maxPriority == 0)
	{
		throw std::logic_error("Cannot create priority queue with no priorities!");
	}

	pQueue = new MyQueue<T>[maxPriority];
	kPriority = maxPriority;
}

template<typename T>
kPriorityQueue<T>::kPriorityQueue(const kPriorityQueue<T>& other)
{
	copyFrom(other);
}

template<typename T>
kPriorityQueue<T>& kPriorityQueue<T>::operator=(const kPriorityQueue<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
kPriorityQueue<T>::~kPriorityQueue()
{
	free();
}

template<typename T>
void kPriorityQueue<T>::push(const T& obj, size_t priority)
{
	if (priority >= kPriority)
	{
		throw std::logic_error("Invalid priority!");
	}

	pQueue[priority].push(obj);
	countElements++;
}

template<typename T>
void kPriorityQueue<T>::push(const T&& obj, size_t priority)
{
	if (priority >= kPriority)
	{
		throw std::logic_error("Invalid priority!");
	}

	countElements++;
	pQueue[priority].push(std::move(obj));
}

template<typename T>
void kPriorityQueue<T>::pop()
{
	if (isEmpty())
	{
		throw std::logic_error("Priority queue is empty!");
	}

	for (int i = kPriority - 1; i >= 0; i--)
	{
		if (!pQueue[i].isEmpty())
		{
			pQueue[i].pop();
			countElements--;
			return;
		}
	}
}

template<typename T>
const T& kPriorityQueue<T>::peek() const
{
	if (isEmpty())
	{
		throw std::logic_error("Priority queue is empty!");
	}

	for (int i = kPriority - 1; i >= 0; i--)
	{
		if (!pQueue[i].isEmpty())
		{
			return pQueue[i].peek();
		}
	}
}

template<typename T>
bool kPriorityQueue<T>::isEmpty() const
{
	return countElements == 0;
}
