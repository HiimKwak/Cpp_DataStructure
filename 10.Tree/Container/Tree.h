#pragma once

#include "Node.h"
#include <vector>
#include <iostream>

template<typename T>
class Tree
{
public:
	Tree(const T& data)
	{
		root = new Node<T>(data);
	}
	~Tree()
	{
			DestroyRecursive(root);
	}

	bool AddChild(const T& parentData, const T& childData)
	{
		Node<T>* outParent = nullptr;
		bool result = FindRecursive(parentData, root, outParent);

		if (result)
		{
			outParent->AddChild(childData);
			return true;
		}

		return false;
	}

	bool Find(const T& data, Node<T>*& outNode)
	{
		return FindRecursive(data, root, outNode);
	}

	bool Remove(const T& data)
	{
		return RemoveRecursive(data, root);
	}

	void PreorderTraversal(int depth = 0)
	{
		PreorderTraversalRecursive(root, depth);
	}

private:
	bool FindRecursive(const T& data, Node<T>* node, Node<T>*& outNode)
	{
		if (!node)
		{
			outNode = nullptr;
			return false;
		}

		if (node->GetData() == data)
		{
			outNode = node;
			return true;
		}

		std::vector<Node<T>*>& children = node->GetChildren();

		const int length = static_cast<int>(children.size());
		for (int ix = 0; ix < length; ++ix)
		{
			bool result = FindRecursive(data, children[ix], outNode);
			if (result)
				return true;
		}

		outNode = nullptr;
		return false;
	}

	bool RemoveRecursive(const T& data, Node<T>* node)
	{
		Node<T>* outNode = nullptr;
		bool result = FindRecursive(data, node, outNode);

		if (result)
		{
			Node<T>* parent = outNode->GetParent();
			if (parent)
			{
				auto it = std::find(
					parent->GetChildren().begin(),
					parent->GetChildren().end(),
					outNode
				);

				parent->GetChildren().erase(it);
			}

			std::vector<Node<T>*>& children = outNode->GetChildren();
			while (children.size() > 0)
				outNode->RemoveChild(children[0]);
			
			SafeDelete(outNode);

			return true;
		}
		return false;
	}

	void PreorderTraversalRecursive(Node<T>* node, int depth = 0)
	{
		if (!node)
			return;

		for (int ix = 0; ix < depth; ++ix)
			std::cout << " ";
		
		std::cout << node->GetData() << "\n";

		std::vector<Node<T>*>& children = node->GetChildren();
		const int length = static_cast<int>(children.size());
		if (length == 0) 
			return;

		for (int ix = 0; ix < length; ++ix)
		{
			Node<T>* child = children[ix];
			PreorderTraversalRecursive(child, depth + 1);
		}
	}

	void DestroyRecursive(Node<T>*& node)
	{
		std::vector<Node<T>*>& children = node->GetChildren();
		while (children.size() > 0)
		{
			DestroyRecursive(children[0]);
		}

		Node<T>* parent = node->GetParent();
		if (parent)
		{
			auto it = std::find(
				parent->GetChildren().begin(),
				parent->GetChildren().end(),
				node
			);

			if (it != parent->GetChildren().end())
				parent->GetChildren().erase(it);
		}
		SafeDelete(node);
	}

private:
	Node<T>* root = nullptr;
};