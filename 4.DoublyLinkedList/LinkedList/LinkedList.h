#pragma once

#include "Node.h"
#include <iostream>

template<typename T>
class LinkedList
{
public:
	LinkedList() : first(new Node<T>()), last(new Node<T>()), count(0)
	{
		first->next = last;
		last->previous = first;
	}
	~LinkedList()
	{
		Clear();

		delete first;
		delete last;
		first = nullptr;
		last = nullptr;
	}

	void Clear()
	{
		Node<T>* current = first->next;

		while (current && current != last)
		{
			Node<T>* next = current->next;
			delete current;
			current = next;
		}

		count = 0;
		first->next = last;
		last->previous = first;
	}

	Node<T>* Find(const T& data)
	{
		Node<T>* current = first->next;

		while (current && current != last)
		{
			if (current->data == data)
				return current;

			current = current->next;
		}

		std::cout << "Can't find the data.\n";
		return nullptr;
	}

	Node<T>* FindReverse(const T& data)
	{
		Node<T>* current = last->previous;

		while (current && current != first)
		{
			if (current->data == data)
				return current;

			current = current->previous;
		}

		std::cout << "Can't find the data.\n";
		return nullptr;
	}

	void InsertFirst(const T& data)
	{
		Node<T>* newNode = new Node<T>();
		newNode->data = data;

		Node<T>* oldNext = first->next;

		oldNext->previous = newNode;
		newNode->next = oldNext;
		first->next = newNode;
		newNode->previous = first;

		++count;
	}

	void InsertLast(const T& data)
	{
		Node<T>* newNode = new Node<T>();
		newNode->data = data;

		Node<T>* oldPrev = last->previous;

		oldPrev->next = newNode;
		newNode->previous = oldPrev;
		last->previous = newNode;
		newNode->next = last;

		++count;
	}

	// todo: Insert ¸¸µé±â

	void Delete(const T& data)
	{
		if (count == 0)
		{
			std::cout << "List is empty.\n";
			return;
		}

		Node<T>* deleteNode = Find(data);

		if (!deleteNode)
		{
			std::cout << "Failed to find data to delete.\n";
			return;
		}

		Node<T>* prev = deleteNode->previous;
		Node<T>* next = deleteNode->next;

		prev->next = next;
		next->previous = prev;

		delete deleteNode;
		deleteNode = nullptr;
		--count;
	}

	void Print()
	{
		Node<T>* current = first->next;

		std::cout << "List item count: " << count << std::endl;

		while (current != last)
		{
			std::cout << "Item: " << current->data << std::endl;
			current = current->next;
		}
	}

private:
	Node<T>* first = nullptr;
	Node<T>* last = nullptr;
	int count = 0;
};
