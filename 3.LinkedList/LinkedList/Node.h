#pragma once

template<typename T>
class Node
{
	template<typename T>
	friend class LinkedList;

private:
	Node() : data(), next(nullptr) {}
	Node(T data) : data(data), next(nullptr) {}

private:
	T data;
	Node* next = nullptr;
};