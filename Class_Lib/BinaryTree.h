#pragma once
#include<iostream>
using namespace std;
//https://www.cprogramming.com/tutorial/lesson18.html
template<typename T> struct Node {
	T value;
	struct Node<T>* leftChild;
	struct Node<T>* rightChild;
	Node<T>(T val)
	{
		this->value = val;
		leftChild = rightChild = nullptr;
	}
	
};
template<typename T> class BTree {
	Node<T>* root;
	int count;
	void destroy_tree(Node<T>* leaf);
	void insert(T key, Node<T>* leaf);
	Node<T>* search(T key, Node<T>* leaf);
	void findPredecessor(Node<T>* node,T key,Node<T>*& pred);	
	void findSuccessor(Node<T>* node,T key,Node<T>*& succ);	
	
	
public:
	BTree();
	~BTree();
	void insert(T key);
	Node<T>* search(T key);
	void destroy_tree();
	Node<T>* findMinimum();
	Node<T>* findMaximum();
	Node<T>* findPredecessor(T key);
	Node<T>* findSuccessor(T key);
	void Print()
	{
		cout << root;
	}
	friend ostream operator <<(ostream& out, Node<T>* node);
};
template<typename T>ostream& operator <<(ostream& out, Node<T>* node)
{
	if (node != nullptr)
	{
		out << node->leftChild;
		out << node->value << ",";
		out << node->rightChild;
		
	}
	return out;
}