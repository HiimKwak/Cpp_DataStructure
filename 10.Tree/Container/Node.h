#pragma once

#include <vector>

template<typename T>
void SafeDelete(T*& t)
{
	if (t)
	{
		delete t;
		t = nullptr;
	}
}

template<typename T>
class Node
{
public:
	Node() : data() {}
	Node(const T& data) : data(data) {}
	~Node()
	{
		data = T();
		parent = nullptr;
		children.clear();
	}

public:
	void AddChild(const T& data)
	{
		AddChild(new Node<T>(data));
	}
	void AddChild(Node<T>* newChild)
	{
		newChild->SetParent(this);
		children.emplace_back(newChild);
	}

	void RemoveChild(Node<T>* child)
	{
		RemoveChildRecursive(child);
	}

	inline T GetData() const { return data; }
	inline std::vector<Node<T>*>& GetChildren() { return children; }
	inline Node<T>* GetParent() const { return parent; }
	inline void SetParent(Node<T>* newParent) { parent = newParent; }
private:
	void RemoveChildRecursive(Node<T>* child)
	{
		if (!child) return;

		std::vector<Node<T>*>& children = child->GetChildren();

		if (children.size() == 0)
		{
			auto& parentVector = child->GetParent()->GetChildren();

			auto childIterator = std::find(
				parentVector.begin(),
				parentVector.end(),
				child
			);

			if (childIterator != parentVector.end()) parentVector.erase(childIterator);

			SafeDelete(child);
			return;
		}

		while (children.size() > 0)
			RemoveChildRecursive(children[0]);

		auto& parentVector = child->GetParent()->GetChildren();

		auto childIterator = std::find(
			parentVector.begin(),
			parentVector.end(),
			child
		);

		if (childIterator != parentVector.end()) parentVector.erase(childIterator);

		SafeDelete(child);
	}

private:
	T data;
	Node<T>* parent = nullptr;
	std::vector<Node<T>*> children;
};
