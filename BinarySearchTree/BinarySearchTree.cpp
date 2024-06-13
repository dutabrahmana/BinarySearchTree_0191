#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
	string info;
	Node* leftchild;
	Node* rightchild;

	Node(string i, Node* l, Node* r)
	{
		info = i;
		leftchild = l;
		rightchild = r;

	}
};

class BinaryTree
{
public:
	Node* ROOT;

	BinaryTree()
	{
		ROOT = nullptr;
	}

	void insert(string element)
	{
		Node* newNode = new Node(element, nullptr, nullptr);
		newNode->info = element;
		newNode->leftchild = nullptr;
		newNode->rightchild = nullptr;

		Node* parent = nullptr;
		Node* currentNode = nullptr;
		search(element, parent, currentNode);

		if (parent == nullptr) // if the parent is NULL (Tree is Empty)
		{
			ROOT = newNode;
			return;
		}

		if (element < parent->info)
		{
			parent->leftchild = newNode;

		}
		else if (element < parent->info)
		{
			parent->rightchild = newNode;
		}
	}

	void search(string element, Node*& parent, Node*& currentNode)
	{
		currentNode = ROOT;
		parent = nullptr;
		while ((currentNode != nullptr) && (currentNode->info != element))
		{
			parent = currentNode;
			if (element < currentNode->info)
				currentNode = currentNode->leftchild;
			else
				currentNode = currentNode->rightchild;
		}
	}

	void inorder(Node* ptr)
	{
		if (ROOT == nullptr)
		{
			cout << "Tree is Empty" << endl;
			return;

			inorder(ptr->leftchild);
			cout << ptr->info << " ";
			inorder(ptr->rightchild);
		}
		
	}
	void preorder(Node* ptr)
	{
		if (ROOT = nullptr)
		{
			cout << "Tree is Empty" << endl;
			return;
		}
		if (ptr != nullptr)
		{
			cout << ptr->info << " ";
			preorder(ptr->leftchild);
			preorder(ptr->rightchild);
		}
	}

	void postorder(Node* ptr)
	{
		if (ROOT = nullptr)
		{
			cout << "Tree is Empty" << endl;
			return;
		}
		if (ptr != nullptr)
		{
			
			postorder(ptr->leftchild);
			postorder(ptr->rightchild);
			cout << ptr->info << " ";
		}
	}
};
	}
}