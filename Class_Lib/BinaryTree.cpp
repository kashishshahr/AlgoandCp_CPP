#include "BinaryTree.h"

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
	if (leaf != NULL)
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

template<typename T>Node<T>* BTree<T>::search(T key, Node<T>* leaf)
{
	if (leaf != NULL)
	{
		if (key == leaf->key_value)
			return leaf;
		if (key < leaf->key_value)
			return search(key, leaf->left);
		else
			return search(key, leaf->right);
	}
	else return NULL;
}
template<typename T>Node<T>* BTree<T>::search(T key)
{
	return search(key, root);
}
template<typename T> void BTree<T>::destroy_tree()
{
	destroy_tree(root);
}
template<typename T>Node<T>* BTree<T>::findMinimum() {

	Node<T>* temp = root;
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
		if (node->rightChild != nullptr)
		{
			Node<T>* temp = node->rightChild;
			while (temp->leftChild)
				temp = temp->leftChild;
			suc = temp;
		}
	}
	if (node->value > key)
	{
		suc = node;
		findSuccessor(node->leftChild, key, suc);
	}
	else
	{

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
	Node<T>* suc = nullptr;
	findSuccessor(root, key, suc);
	cout << "\Suc is " << suc->value << endl;
	return suc;
}