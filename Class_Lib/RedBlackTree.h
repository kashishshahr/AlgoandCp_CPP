#pragma once
enum Color
{
	Red=4,
	Black=1
};

struct RBNode
{
	int info;//int info
	struct RBNode* left;
	struct RBNode* right;
	struct RBNode* parent;
	enum Color color;
	RBNode(int info)
	{
		this->info = info;
		left =right=parent= nullptr;
		color = Red;
	}

};
typedef struct RBNode Node;

class RedBlackTree
{
public:
	Node* root;
	RedBlackTree()
	{
		root = nullptr;
	}
	Node* GrandParent(Node* node);
	//parent of parent of node
	Node* Insert(Node* node, Node* root);//insert in TREE(REGular bst)
	void Insert(int info);//
	//Node* FindNode(int info,Node* root);//node ptr is retruned
	void ReColorFamily(Node* node);//In cases Change Color without rotation
	bool IsSiblingOfParentNullorBlack(Node* node);//
	void RotateLeft(Node* node,bool flipFlag);
	void RotateRight(Node* node, bool flipFlag);
	void FixRedBlackTree(Node* node, Node* root);//to fix tree after insertion
	//void VisitNode(Node* root);
	void InOrderTraversal(Node* root);//lRr

};

