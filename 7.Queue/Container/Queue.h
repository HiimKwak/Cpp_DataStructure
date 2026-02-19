#pragma once

#include <iostream>

template<typename T, int Capacity = 10>
class Queue
{
public:
	Queue() : front(0), rear(0), capacity(Capacity + 1) {}

	bool Enqueue(const T& value)
	{
		if (IsFull()) return false;

		rear = (rear + 1) % capacity;
		data[rear] = value;
		return true;
	}

	bool Dequeue(T& outValue) {
		if (IsEmpty()) return false;

		front = (front + 1) % capacity;
		outValue = data[front];
		data[front] = T(); // 자료형 기본 초기화 호출로 큐 한 칸 비우기
		// memset(&data[front], 0, sizeof(T));
		return true;
	}

	T Peek()
	{
		if (IsEmpty()) return false;

		return data[(front + 1) % capacity];
	}

	void Display()
	{
		std::cout << "큐 내용: ";

		int max = (front < rear) ? rear : rear + capacity;
		for (int ix = front + 1; ix <= max; ++ix)
			std::cout << " " << data[ix % capacity];

		std::cout << "\n";
	}

public:
	inline bool IsEmpty() const { return rear == front; }
	inline bool IsFull() const { return (rear + 1) % capacity == front; }
	inline int GetCapacity() const { return capacity; }

private:
	int front, rear, capacity;
	T data[Capacity + 1] = {};
};