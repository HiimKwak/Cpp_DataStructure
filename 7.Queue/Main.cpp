#include "Container/Queue.h"

int main()
{
	Queue<int> queue;
	for (int ix = 0; ix < queue.GetCapacity(); ++ix)
		queue.Enqueue(ix + 1);

	queue.Display();

	int value;
	queue.Dequeue(value);
	queue.Dequeue(value);
	queue.Dequeue(value);

	queue.Display();

	queue.Enqueue(11);
	queue.Enqueue(12);
	queue.Enqueue(13);
	queue.Enqueue(14);

	queue.Display();

	std::cin.get();
}