#pragma once

#include "Node.h"
#include <iostream>

template<typename T>
class LinkedList
{
	using NodeType = Node<T>*;

public:
	LinkedList() : head(nullptr), count(0) {}
	~LinkedList()
	{
		NodeType current = head;
		NodeType trail = nullptr;

		while (current)
		{
			next = current->next;
			delete current;
			current = next;
		}
		head = nullptr;
		count = 0;
	}

	void Insert(const T& data)
	{
		NodeType newNode = new Node<T>(data);

		if (!head)
			head = newNode;
		else
		{
			NodeType current = head;
			NodeType trail = nullptr;

			while (current)
			{
				if (current->data >= data)
					break;

				trail = current;
				current = current->next;
			}

			if (current == head)
			{
				newNode->next = head;
				head = newNode;
			}
			else
			{
				newNode->next = current;
				trail->next = newNode;
			}
		}


		count++;
	}

	void Delete(const T& data)
	{
		if (!head)
		{
			std::cout << "no data to delete" << std::endl;
			return;
		}

		NodeType current = head;
		NodeType trail = nullptr;

		while (current)
		{
			if (current->data == data)
				break;

			trail = current;
			current = current->next;
		}

		if (!current)
		{
			std::cout << "Failed to find the node" << std::endl;
			return;
		}

		if (head == current)
			head = head->next;
		else
			trail->next = current->next;

		delete current;
		--count;
	}

	void Print()
	{
		NodeType current = head;

		while (current)
		{
			std::cout << "Data: " << current->data << std::endl;

			current = current->next;
		}
	}
private:
	NodeType head = nullptr;
	int count = 0;
};