#include "RedBlackTree.h"
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

Node* RedBlackTree::GrandParent(Node* nodes)//parent of parent of node
{
	return nodes->parent->parent;
}
void RedBlackTree::ReColorFamily(Node* node)//In cases Change Color without rotation
{
	if (node->parent != nullptr)
	{
		node->color = Red;
	}
	node->left->color = Black;
	node->right->color = Black;
}
void RedBlackTree::RotateLeft(Node* x, bool flipFlag)
{
	Node* y = x->parent;
	x->parent = y->parent;
	if (y->parent == nullptr)
	{
		x->parent = nullptr;
		root = x;
	}
	else if (y->parent->left == y)
	{
		x->parent->left = x;
	}
	else {
		x->parent->right = x;
	}
	y->right = x->left;
	if (x->left != nullptr)
	{
		x->left->parent = y;
	}
	y->parent = x;
	x->left = y;
	if (flipFlag)
	{
		y->color = Red;
		x->color = Black;
	}
}
void RedBlackTree::RotateRight(Node* x, bool flipFlag)
{
	Node* y = x->parent;
	x->parent = y->parent;
	if (y->parent == nullptr)
	{
		x->parent = nullptr;
		root = x;
	}
	else if (y->parent->left==y)
	{
		x->parent->left = x;
	}
	else
	{
		x->parent->right = x;
	}
	y->left = x->right;
	if (x->right!= nullptr)
	{
		x->right->parent = y;
	}
	y->parent = x;
	x->right = y;
	if (flipFlag)
	{
		y->color = Red;
		x->color = Black;
	}
}
void RedBlackTree::FixRedBlackTree(Node* node, Node* root)//to fix tree after insertion
{
	if (node == root)
	{
		root->color = Black;
		return;
	}
	if (node->parent->color == Black)
	{
		return;
	}
	if (IsSiblingOfParentNullorBlack(node))
	{
		if (node == node->parent->left && GrandParent(node)->left == node->parent)
		{
			//ll -> R
			//Flip COlors
			RotateRight(node->parent, true);
		}
		else if (node == node->parent->right && GrandParent(node)->right == node->parent)
		{
			//rr -> L
			RotateLeft(node->parent, true);
		}
		else if (node == node->parent->left && GrandParent(node)->right == node->parent)
		{
			//lr -> RL
			RotateRight(node, false);
			RotateLeft(node, true);
		}
		else  if (node == node->parent->right && GrandParent(node)->left == node->parent)
		{
			//rl -> LR
			RotateLeft(node, false);
			RotateRight(node, true);
		}
	}
	else {
		ReColorFamily(GrandParent(node));
		FixRedBlackTree(GrandParent(node), root);
	}


}
void RedBlackTree::Insert(int info)
{
	Node* newNode = new Node(info);
	root = Insert(newNode, root);
	FixRedBlackTree(newNode, root);
	InOrderTraversal(root);
	cout << "\n";
}
Node* RedBlackTree::Insert(Node* node, Node* root)
{
	if (root == nullptr)
	{
		root = node;
	}
	else if (node->info >= root->info)
	{
		root->right = Insert(node, root->right);
		root->right->parent = root;
	}
	else if (node->info < root->info)
	{
		root->left = Insert(node, root->left);
		root->left->parent = root;
	}
	return root;
}
void RedBlackTree::InOrderTraversal(Node* root)
{

	if (root != nullptr)
	{
		InOrderTraversal(root->left);
		
		string color = "color " + to_string(root->color); //converting number to a string

		const char const* cc = color.c_str(); //converting string to char Array
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), root->color);
		
		cout << root->info << " ";
		InOrderTraversal(root->right);
	}
}
bool RedBlackTree::IsSiblingOfParentNullorBlack(Node* node)
{
	Node* grandParent = GrandParent(node);
	if (grandParent->left == node->parent)
	{
		return grandParent->right == NULL || grandParent->right->color == Black;
	}
	else {
		return grandParent->left == NULL || grandParent->left->color == Black;
	}

}