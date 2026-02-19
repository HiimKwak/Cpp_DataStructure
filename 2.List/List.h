#pragma once

#include <iostream>
#include <cassert>

template<typename List>
class ListIterator
{
public:
	using ValueType = typename List::ValueType; // List 템플릿의 ValueType을 가져온다는 뜻
	using PointerType = ValueType*;
	using ReferenceType = ValueType&;

public:
	ListIterator(PointerType ptr) : ptr(ptr) {}

	ListIterator& operator++() // 전위 증가 연산자
	{
		++ptr;
		return *this;
	}

	ListIterator& operator++(int) // 후위 증가 연산자
	{
		ListIterator iterator = *this; // 현재 반복자 임시 저장

		++(*this); // 내부 포인터 증가처리

		return iterator;
	}

	ListIterator(PointerType ptr) : ptr(ptr) {}

	ListIterator& operator--() // 전위 감소 연산자
	{
		--ptr;
		return *this;
	}

	ListIterator& operator--(int) // 후위 감소 연산자
	{
		ListIterator iterator = *this; // 현재 반복자 임시 저장

		--(*this); // 내부 포인터 감소처리

		return iterator;
	}

	ReferenceType operator[](int index)
	{
		return *(ptr + index);
	}

	ReferenceType operator->()
	{
		return ptr;
	}

	ReferenceType operator*()
	{
		return *ptr;
	}

	bool operator==(const ListIterator& other) const // 비교 연산자 오버로딩
	{
		return ptr == other.ptr;
	}

	bool operator!=(const ListIterator& other) const
	{
		return !(*this == other);
	}

private:
	PointerType ptr = nullptr;
};


template<typename T>
class List
{
public:
	using ValueType = T; // 타입 앨리어싱
	using Iterator = ListIterator<List<T>>;

public:
	List()
	{
		Reallocate(capacity);
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

	Iterator begin()
		//T* begin()
	{
		return Iterator(data);
		//return data;
	}

	Iterator end()
		//T* end()
	{
		return Iterator(data + size);
		//return data + size;
	}

private:
	void Reallocate(int newCapacity)
	{
		T* newBlock = new T[newCapacity];
		memset(newBlock, 0, sizeof(T) * newCapacity);

		if (newCapacity < size)
		{
			size = newCapacity;
		}

		if (data)
		{
			memcpy(newBlock, data, sizeof(T) * size); // or for loop
		}

		delete[] data;
		data = newBlock;
		capacity = newCapacity;
	}

private:
	T* data = nullptr;
	int size = 0;
	int capacity = 2;
};
