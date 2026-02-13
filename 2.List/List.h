#pragma once

#include <iostream>
#include <cassert>

template<typename T>
class List
{
public:
	List()
	{
		//Reallocate(capacity);
		data = new T[capacity];
		memset(data, 0, sizeof(T) * capacity);
	}
	~List()
	{
		if (data)
		{
			delete[] data;
		}
	}

	void Add(const T& value)
	{
		// 크기 부족한지 확인
		if (size == capacity)
			Reallocate(capacity * 2);

		data[size++] = value;
	}

	void Add(T&& value)
	{
		if (size == capacity)
			Reallocate(capacity * 2);

		data[size] = std::move(value);
		++size;
	}

	T& operator[](int index)
	{
		assert(index >= 0 && index < size); // assert는 통과 조건을 넣어줘야 함
		return data[index];
	}

	int Size() const { return size; }
	int Capcacity() const { return capacity; }

private:
	void Reallocate(int newCapacity)
	{
		T* newBlock = new T[newCapacity];
		memset(newBlock, 0, sizeof(T) * newCapacity);

		if (newCapacity < size)
		{
			size = newCapacity;
		}

		memcpy(newBlock, data, sizeof(T) * capacity); // or for loop
		capacity = newCapacity;

		delete[] data;
		data = newBlock;
		capacity = newCapacity;
	}

private:
	T* data = nullptr;
	int size = 0;
	int capacity = 2;
};
