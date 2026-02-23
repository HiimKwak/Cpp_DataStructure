#pragma once

#include "Node.h"

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif

template<typename T>
class BinarySearchTree
{
public:
	BinarySearchTree() {}
	~BinarySearchTree()
	{
		Destroy();
	}

	bool InsertNode(const T& newData)
	{
		Node<T>* outNode = nullptr;
		if (SearchNode(newData, outNode))
			return false;

		if (!root)
		{
			root = new Node<T>(newData);
			return true;
		}

		root = InsertNodeRecursive(root, nullptr, newData);
		return true;
	}

	bool DeleteNode(const T& deleteData)
	{
		return DeleteNodeRecursive(root, deleteData, root);
	}

	bool SearchNode(const T& data, Node<T>*& outNode)
	{
		return SearchNodeRecursive(root, data, outNode);
	}

	void PreorderTraverse(int depth = 0)
	{
		std::cout << "============= 전위순회 시작 =============\n";
		PreorderTraverseRecursive(root, depth);
		std::cout << "============= 전위순회 종료 =============\n";
	}
	void InorderTraverse(int depth = 0)
	{
		std::cout << "============= 중위순회 시작 =============\n";
		InorderTraverseRecursive(root, depth);
		std::cout << "============= 중위순회 종료 =============\n";
	}
	void PostorderTraverse(int depth = 0)
	{
		std::cout << "============= 후위순회 시작 =============\n";
		PostorderTraverseRecursive(root, depth);
		std::cout << "============= 후위순회 종료 =============\n";
	}

private:
	void PreorderTraverseRecursive(Node<T>* node, int depth = 0)
	{
		if (!node)
			return;

		for (int ix = 0; ix < depth; ++ix)
			std::cout << " ";

		std::cout << node->data << "\n";
		PreorderTraverseRecursive(node->left, depth + 1);
		PreorderTraverseRecursive(node->right, depth + 1);
	}
	void InorderTraverseRecursive(Node<T>* node, int depth = 0)
	{
		if (!node)
			return;

		InorderTraverseRecursive(node->left, depth + 1);

		for (int ix = 0; ix < depth; ++ix)
			std::cout << " ";

		std::cout << node->data << "\n";

		InorderTraverseRecursive(node->right, depth + 1);
	}
	void PostorderTraverseRecursive(Node<T>* node, int depth = 0)
	{
		if (!node)
			return;

		PostorderTraverseRecursive(node->left, depth + 1);
		PostorderTraverseRecursive(node->right, depth + 1);

		for (int ix = 0; ix < depth; ++ix)
			std::cout << " ";
		std::cout << node->data << "\n";
	}

	Node<T>* InsertNodeRecursive(Node<T>* node, Node<T>* parent, const T& newData)
	{
		if (!node)
			return new Node<T>(newData, parent);

		if (node->data > newData)
			node->left = InsertNodeRecursive(node->left, node, newData);
		if (node->data < newData)
			node->right = InsertNodeRecursive(node->right, node, newData);

		return node;
	}

	bool SearchNodeRecursive(Node<T>* node, const T& data, Node<T>*& outNode)
	{
		if (!node)
		{
			outNode = nullptr;
			return false;
		}

		if (node->data == data)
		{
			outNode = node;
			return true;
		}

		if (node->data > data)
			return SearchNodeRecursive(node->left, data, outNode);
		if (node->data < data)
			return SearchNodeRecursive(node->right, data, outNode);
	}

	bool DeleteNodeRecursive(Node<T>* node, const T& deleteData, Node<T>*& outNode)
	{
		if (!node)
		{
			outNode = nullptr;
			return false;
		}

		if (node->data > deleteData)
			return DeleteNodeRecursive(node->left, deleteData, node->left);
		if (node->data < deleteData)
			return DeleteNodeRecursive(node->right, deleteData, node->right);

		if (!node->left && !node->right)
		{
			delete node;
			outNode = nullptr;
			return true;
		}
		if (node->left && node->right)
		{
			// 왼쪽 서브트리의 가장 큰 노드/오른쪽 서브트리의 가장 작은 노드로 교체
			node->data = SearchMinNode(node->right)->data;
			DeleteNodeRecursive(node->right, node->data, node->right);

			return true;
		}
		else
		{
			if (!node->left)
			{
				Node<T>* right = node->right;
				right->parent = node->parent;
				delete node;

				outNode = right;
				return true;
			}
			else if (!node->right)
			{
				Node<T>* left = node->left;
				left->parent = node->parent;
				delete node;

				outNode = left;
				return true;
			}
		}
		outNode = nullptr;
		return false;
	}

	Node<T>* SearchMinNode(Node<T>* node)
	{
		while (node->left)
			node = node->left;

		return node;
	}

	void Destroy()
	{
		if (!root)
			return;

		DestroyRecursive(root);
	}

	void DestroyRecursive(Node<T>* node)
	{
		if (!node)
			return;

		if (!node->left && !node->right)
			return delete node;

		DestroyRecursive(node->left);
		DestroyRecursive(node->right);
		delete node;
	}

private:
	Node<T>* root = nullptr;
};
