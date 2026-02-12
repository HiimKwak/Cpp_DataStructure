#include <iostream>
#include <cassert>
#include <array>

template<typename T, size_t size = 10>
class Array
{
public:
	size_t Size() const
	{
		return size;
	}

	T& operator[](size_t index)
	{
		assert(index < 0 || index >= size); // 에러 검출용 코드, debugbreak 내장

		return data[index];
	}

	const T& operator[](size_t index) const
	{
		return data[index];
	}

private:
	T data[size] = {};
};

int main()
{
	Array<int, 5> array;
	//array[3] = 20;

	const auto& arrayReference = array;

	std::cin.get();
}