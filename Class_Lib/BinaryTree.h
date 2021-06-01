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
	}Node<T>() = default;

};
template<typename T> class BTree {
	Node<T>* root;
	int count;
	void destroy_tree(Node<T>* leaf);
	void insert(T key, Node<T>* leaf);
	Node<T>* deleteNode(T key, Node<T>* leaf);
	Node<T>* search(T key, Node<T>* leaf);
	void findPredecessor(Node<T>* node, T key, Node<T>*& pred);
	void findSuccessor(Node<T>* node, T key, Node<T>*& succ);
	void findClossetNode(Node<T>* ptr, T key, int& diff, Node<T>*& closestNode);
	
	int getSize(Node<T>* leaf);
	Node<T>* Select(Node<T>* t,T k);

public:
	BTree();
	~BTree(); 
	T Select(T k);
	void insert(T key);
	void deleteNode(T key);
	Node<T>* search(T key);
	int getRank(T x);
	int getRank(Node<T>* node);
	int getSize(T key);
	int getSize();
	void BFSTraversal();
	void BFSTraversal(Node<T>* node);
	void DFSTraversal();
	void DFSTraversal(Node<T>* node);
	void destroy_tree();
	void printPostorder(Node<T>* node);
	void printPreorder(Node<T>* node);
	void printInorder(Node<T>* node);
	Node<T>* findMinimum();
	Node<T>* findMin(Node<T>* r);
	Node<T>* findMaximum();
	Node<T>* findPredecessor(T key);
	Node<T>* findSuccessor(T key);
	T findClossetNode(T key);
	void Print()
	{
			cout<<root;
		
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