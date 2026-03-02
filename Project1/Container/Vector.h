#pragma once

template<typename T>
class Vector
{
public:
	Vector(int _size = 5) : size(_size)
	{
		capacity = _size + _size / 2;
		data = new T[capacity];
	}

	~Vector()
	{
		if (data)
		{
			delete[] data;
			data = nullptr;
		}
	}

	void Add(const T& item)
	{
		// 1. check capacity whether full or not
		if (size == capacity)
		{
			// 2. if full expand capacity and move items to new container
			capacity = capacity + capacity / 2;
			T* newHouse = new T[capacity];
			for (int i = 0; i < capacity; ++i)
			{
				newHouse[i] = std::move(data[i]);
			}
			delete data; // 힙에 있는 T배열은 어떻게 지움?
			data = std::move(newHouse);
		}
		
		// 3. if not append on the tail
		data[size + 1] = item;
	}

	void Delete(const T& item)
	{
		if (size == 0)
			return;

		// 1. find delete target recursively and delete it only once
		int targetIndex = 0;
		for (int i = 0; i < size; ++i)
		{
			if (data[i] == item)
			{
				targetIndex = i;
				break;
			}
		}
		if (targetIndex)
		{
			delete data[targetIndex];
			// 2. move left ones forward
			for (int j = targetIndex + 1; j < size; ++j)
				data[j - 1] = std::move(data[j]);
		}

	}

private:
	int size, capacity;
	T* data = nullptr;
};
