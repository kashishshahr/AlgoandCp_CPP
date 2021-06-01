#include "BinaryTree.h"
#include<queue>

template<typename T> BTree<T>::BTree()
{
	count = 0;
	root = nullptr;
}
template<typename T> BTree<T>::~BTree()
{
	destroy_tree();
}

template<typename T> void BTree<T>::
destroy_tree(Node<T>* leaf)
{
	if (leaf != nullptr)
	{
		destroy_tree(leaf->leftChild);
		destroy_tree(leaf->rightChild);
		delete leaf;
	}
}
template<typename T> void BTree<T>::insert(T key, Node<T>* leaf)
{
	if (key < leaf->value)
	{
		if (leaf->leftChild != nullptr)
		{
			insert(key, leaf->leftChild);
		}
		else
		{
			leaf->leftChild = new Node<T>(key);
		}
	}
	else if (key >= leaf->value)
	{
		if (leaf->rightChild != nullptr)
		{
			insert(key, leaf->rightChild);
		}
		else
		{
			leaf->rightChild = new Node<T>(key);
		}
	}
}
template<typename T> Node<T>* BTree<T>::deleteNode(T key, Node<T>* leaf)
{
	//base case
	if (leaf == nullptr)
	{
		return leaf;
	}
	if (key < leaf->value) {
		leaf->leftChild = deleteNode(key, leaf->leftChild);
	}
	else if (key > leaf->value) {
		leaf->rightChild = deleteNode(key, leaf->rightChild);
	}
	else
	{
		if (leaf->leftChild == nullptr && leaf->rightChild == nullptr)
		{
			delete leaf;
			leaf = nullptr;
			/*return leaf;*/
		}
		else if (leaf->leftChild == nullptr)
		{
			struct Node<T>* temp = leaf;
			leaf = leaf->rightChild;
			delete temp;
			//return leaf;
		}
		else if (leaf->rightChild == nullptr)
		{
			struct Node<T>* temp = leaf;
			leaf = leaf->leftChild;
			delete temp;
			//return leaf;
		}
		else
		{
			struct Node<T>* temp = findMin(leaf->rightChild);
			leaf->value = temp->value;
			leaf->rightChild = deleteNode(leaf->value, leaf->rightChild);

		}
	}
	return leaf;
}


template<typename T> void BTree<T>::insert(T key)
{
	if (root != nullptr)
	{
		insert(key, root);
	}
	else
	{
		root = new Node<T>(key);
	}
	count++;
}
template<typename T> void BTree<T>::deleteNode(T key)
{
	if (root != nullptr)
	{
		deleteNode(key, root);
	}
	else
	{
		return;
	}
	count--;
}
template<typename T> void BTree<T>::BFSTraversal()
{
	BFSTraversal(root);
	cout <<"\n";
}
template<typename T> void BTree<T>::BFSTraversal(Node<T>* node)
{
	queue<Node<T>*> q;
	q.push(node);
	while (q.empty() == false)
	{
		Node<T>* node = q.front();
		cout << node->value<< " ";
		q.pop();
		if (node->leftChild != nullptr)
			q.push(node->leftChild);
		if (node->rightChild != nullptr)
			q.push(node->rightChild);
	}

}
template<typename T> void BTree<T>::DFSTraversal(Node<T>* node)
{
	printPreorder(root);
	cout << "\n";
	printInorder(root);
	cout << "\n";
	printPostorder(root);
	cout << "\n";

}
template<typename T> void BTree<T>::DFSTraversal()
{
	DFSTraversal(root);

}
template<typename T> void BTree<T>::printPostorder(Node<T>* node)
{
	if (node == nullptr)
		return;
	printPostorder(node->leftChild);
	printPostorder(node->rightChild);
	cout << node->value << " ";
}
template<typename T> void BTree<T>::printInorder(Node<T>* node)
{
	if (node == nullptr)
		return;
	printInorder(node->leftChild);
	cout << node->value << " ";
	printInorder(node->rightChild);
}
template<typename T>void BTree<T>::printPreorder(Node<T>* node)
{
	if (node == nullptr)
		return;
	cout << node->value << " ";
	printPreorder(node->leftChild);
	printPreorder(node->rightChild);

}
template<typename T>Node<T>* BTree<T>::search(T key, Node<T>* leaf)
{
	if (leaf != nullptr)
	{
		if (key == leaf->value)
			return leaf;
		if (key < leaf->value)
			return search(key, leaf->leftChild);
		else
			return search(key, leaf->rightChild);
	}
	else return nullptr;
}
template<typename T>Node<T>* BTree<T>::search(T key)
{
	return search(key, root);
}
template<typename T>void BTree<T>::findClossetNode(Node<T>* ptr, T key, int& diff, Node<T>*& closestNode)
{
	if (ptr == nullptr)
	{
		return;
	}
	if (ptr->value == key)
	{
		closestNode = ptr;

	}
	if (diff > abs(ptr->value - key))
	{
		diff = abs(ptr->value - key);
		closestNode = ptr;
	}
	if (key < ptr->value)
		findClossetNode(ptr->leftChild, key, diff, closestNode);
	else
		findClossetNode(ptr->rightChild, key, diff, closestNode);

}
template<typename T>T BTree<T>::findClossetNode(T key)
{
	int diff = INT_MAX;
	Node<T>* node = new Node<T>();
	findClossetNode(root, key, diff, node);
	return node->value;
}
/*
* key =7..diff=1..ptr=6..dif=4
		  5
	   /     \
	 3	       10
   /   \      /   \
   1   4	 9     15
			/ \   / \
		   6  8  11  20
*/
//1,3,4,5,6,9,8,10,11,15,20
template<typename T> int BTree<T>::getSize(
	T key)
{
	Node<T>* n = search(key);
	int sizeOfNode = getSize(n);
	cout<<"\nsize="<<sizeOfNode<<endl;
	return sizeOfNode;
}
template<typename T> int BTree<T>::getSize()
{
	int sizeOfTree = getSize(root);
	
	cout<<"\nsize of tree="<< sizeOfTree <<endl;
	return sizeOfTree;
}
template<typename T> int BTree<T>::getSize(
	Node<T>* leaf)
{
	if (leaf == nullptr)return 0;
	else
		return (getSize(leaf->leftChild) + 1 + (getSize(leaf->rightChild)));
}
template<typename T>int BTree<T>::getRank(T x)
{
	Node<T>* n = search(x);
	if (n != nullptr)
	{
		int rank = getSize(n->leftChild) + 1;
		return rank;
	}
}
template<typename T>int BTree<T>::getRank(Node<T>* node)
{
	if (node != nullptr)
	{
		int rank = getSize(node->leftChild) + 1;
		return rank;
	}
}
template<typename T> T BTree<T>::Select(T k)
{
	if (root != nullptr)
	{
		return Select(root, k)->value;
	}
}
template<typename T> Node<T>* BTree<T>::Select(Node<T>* t, T k)
{
	int r = getRank(t);
	if (k == r)
	{
		return t;
	}
	if (k < r)
	{
		Select(t->leftChild, k);
	}
	else
		Select(t->rightChild, k-r);

}
template<typename T> void BTree<T>::destroy_tree()
{
	destroy_tree(root);
}
template<typename T> Node<T>* BTree<T>::findMinimum() {

	Node<T>* temp = root;
	cout << "\nmin:\n";
	while (temp->leftChild != nullptr)
	{
		temp = temp->leftChild;
	}
	cout << temp->value;
	return temp;
}
template<typename T> Node<T>* BTree<T>::findMin(Node<T>* r) {
	Node<T>* temp = r;
	cout << "\nmin:\n";
	while (temp->leftChild != nullptr)
	{
		temp = temp->leftChild;
	}
	cout << temp->value;
	return temp;
}
template<typename T>Node<T>* BTree<T>::findMaximum() {

	Node<T>* temp = root;
	cout << "\nmin:\n";
	while (temp->rightChild != nullptr)
	{
		temp = temp->rightChild;
	}
	cout << temp->value;
	return temp;
}
template<typename T>void BTree<T>::findPredecessor(Node<T>* node, T key, Node<T>*& pred) {
	if (node == nullptr)
		return;
	if (node->value == key) {
		if (node->leftChild != nullptr)
		{
			Node<T>* temp = node->leftChild;
			while (temp->rightChild)
				temp = temp->rightChild;
			pred = temp;
		}
	}
	if (node->value > key)
	{

		findPredecessor(node->leftChild, key, pred);
	}
	else
	{
		pred = node;
		findPredecessor(node->rightChild, key, pred);
	}
}
template<typename T>void BTree<T>::findSuccessor(Node<T>* node, T key, Node<T>*& suc) {
	if (node == nullptr)
		return;

	if (node->value == key) {
		if (node->rightChild != nullptr) {
			Node<T>* temp = node->rightChild;
			while (temp->leftChild)
				temp = temp->leftChild;
			suc = temp;
		}
	}
	if (node->value > key) {
		suc = node;
		findSuccessor(node->leftChild, key, suc);
	}
	else {
		findSuccessor(node->rightChild, key, suc);
	}
}
template<typename T>Node<T>* BTree<T>::findPredecessor(T key) {
	Node<T>* pred = nullptr;
	findPredecessor(root, key, pred);
	cout << "\nPred is " << pred->value << endl;
	return pred;
}
template<typename T>Node<T>* BTree<T>::
findSuccessor(T key) {
	Node<T>* suc = new Node<T>();
	findSuccessor(root, key, suc);
	cout << "\Suc is " << suc->value << endl;
	return suc;
}