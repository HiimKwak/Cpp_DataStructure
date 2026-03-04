#pragma once

#include "Pair.h"

template<typename Key, typename Value>
class LinkedList;

template<typename Key, typename Value>
class Node
{
	friend class LinkedList<Key, Value>;

public:
	Node(const Key& key, const Value& value) : data(key, value), next(nullptr) {}

	const Pair<Key, Value>& GetData() const { return data; }
	Node* GetNext() const { return next; }

private:
	Node* next;
	Pair<Key, Value> data;
};

template<typename Key, typename Value>
class LinkedList
{
public:
	LinkedList() : head(nullptr) {}

	~LinkedList()
	{
		Clear();
	}

	void Add(const Key& key, const Value& value)
	{
		Node<Key, Value>* newNode = new Node<Key, Value>(key, value);
		newNode->next = head;
		head = newNode;
	}

	Node<Key, Value>* Find(const Key& key) const
	{
		Node<Key, Value>* current = head;
		while (current)
		{
			if (current->data.GetKey() == key)
				return current;
			current = current->next;
		}
		return nullptr;
	}

	bool Remove(const Key& key)
	{
		// head가 삭제 대상인 경우
		if (head && head->data.GetKey() == key)
		{
			Node<Key, Value>* toDelete = head;
			head = head->next;
			delete toDelete;
			return true;
		}

		Node<Key, Value>* prev = head;
		Node<Key, Value>* current = head ? head->next : nullptr;

		while (current)
		{
			if (current->data.GetKey() == key)
			{
				prev->next = current->next;
				delete current;
				return true;
			}
			// 헤드와 헤드넥스트를 한칸씩 이동시켜가며 삭제 key 탐색
			prev = current;
			current = current->next;
		}

		return false;
	}

	void Clear()
	{
		while (head)
		{
			Node<Key, Value>* temp = head;
			head = head->next;
			delete temp;
		}
	}

	Node<Key, Value>* GetHead() const { return head; }

private:
	Node<Key, Value>* head;
};