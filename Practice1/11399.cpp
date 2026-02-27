#include <iostream>

void InsertionSort(int array[], int length)
{
	if (length <= 1)
		return;

	for (int i = 1; i < length; ++i)
	{
		int key = array[i];
		int j = i - 1;
		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			--j;
		}
		array[j + 1] = key;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n;
	std::cin >> n;

	int arr[1000];
	for (int i = 0; i < n; ++i)
	{
		int p;
		std::cin >> p;
		arr[i] = p;
	}
	InsertionSort(arr, n);
	// p1*n + p2*(n-1) + ... p(n-1)*2 + pn*1
	int answer = 0;
	for (int i = 0; i < n; ++i)
	{
		answer += arr[i] * (n - i);
	}
	std::cout << answer;

	return 0;
}