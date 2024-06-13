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

int main()
{
	BinaryTree x;
	while (true)
	{
		cout << "\nMenu" << endl;
		cout << "1. Implement insert operation" << endl;
		cout << "2. perform inorder traversal" << endl;
		cout << "3. perform preorder traversal" << endl;
		cout << "4. perform postorder traversal" << endl;
		cout << "exit" << endl;
		cout << "\nEnter your choice (1-5)" << endl;

		char ch;
		cin >> ch;
		cout << endl;

		switch (ch)
		{
		case '1':
		{
			cout << "Enter a word: ";
			string word;
			cin >> word;
			x.insert(word);
			break;
		}
		case '2':
		{
			x.inorder(x.ROOT);
			break;
		}
		case '3':
		{
			x.preorder(x.ROOT);
			break;
		}
		case '4':
		{
			x.postorder(x.ROOT);
			break;
		}
		case '5':
		{
			break;
		}
		default:
		{
			cout << "Invalid" << endl;
			break;
		}
		}
	}
}