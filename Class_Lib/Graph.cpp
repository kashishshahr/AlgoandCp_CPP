
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#define BLACK 0
#define WHITE  1
#define GRAY  2
using namespace std;

template<typename T>class Vertex
{
	T value;
	
public:
	int color;
	Vertex(T v) :value(v) {}
	T Vallue() { return value; }
};
template<typename T>class Graph
{
	vector<Vertex<T>*> vertices;
	vector<vector<int>> edges;
	int numOfVertices;
	int capacity;
	static const int NOT_CONNECTED = 0;
public:
	Graph(int size)
	{
		numOfVertices = 0;
		capacity = size;
		vertices.resize(size);//
		for (int i{ 0 }; i < size; i++)
		{
			vertices[i] = nullptr;
		}
		int rows, cols;
		rows=cols= size;
		edges.resize(rows, vector<int>(cols, 0));
	}
	bool isEmpty()
	{
		if (numOfVertices == 0)
			return true;
		else
			return false;
	}
	bool isFull()
	{
		if (numOfVertices== capacity)
			return true;
		else
			return false;
	}
	void addVertex(Vertex<T>* aVertex)
	{
		vertices[numOfVertices] = aVertex;
		for (int i{ 0 }; i < capacity; i++)
		{
			edges[numOfVertices][i] = NOT_CONNECTED;
			edges[i][numOfVertices] = NOT_CONNECTED;
		}
		numOfVertices++;
	}
	int indexOf(Vertex<T>* aVertex)
	{
		for (int i = 0; i < numOfVertices; i++)
		{
			if (vertices[i] == aVertex)
			{
				return i;
			}
		}
		return -999;
	}
	void addEdge(int fromVertex, int toVertex,int weight)
	{
		int row;
		int col;
		row = indexOf(vertices[fromVertex]);
		col= indexOf(vertices[toVertex]);
		if (row == -999 || col == -999)
		{

		}
		else
		{
			edges[row][col] = weight;
			//edges[col][row] = weight;//remove this to make it directed
		}
	}
	void printMatrix()
	{
		cout << "  ";
		for (int x=0;x<numOfVertices;x++)
		{
			cout << vertices[x]->Vallue() << " ";
				
		}
		cout << "\n";
		for (int i = 0; i < numOfVertices; i++)
		{
			cout << vertices[i]->Vallue()<<" ";
			for (int j = 0; j < numOfVertices; j++)
			{
				cout <<edges[i][j]<<" ";
			}
			cout << "\n";
		}
	}

	void BFS(Vertex<T>* s)
	{
		for (int i{ 0 };i<numOfVertices;i++)
		{
			vertices[i]->color = WHITE;
		}
		queue<Vertex<T>*> q;
		q.push(s);
		s->color = GRAY;
		
		while (!q.empty())
		{
			/* Extracting the front element(node)
			and poping it out of queue. */
			Vertex<T>* u = q.front();
			q.pop();
			cout << u->Vallue()<<" ";
			int ix1 = indexOf(u);
			for (int i=0;i<numOfVertices;i++)
			{
				int ix2 = indexOf(vertices[i]);
				if (edges[ix1][ix2] != NOT_CONNECTED)
				{
					if (vertices[ix2]->color == WHITE)
					{
						vertices[ix2]->color = GRAY;
						q.push(vertices[ix2]);
					}
				}
			}
			u->color = BLACK;
		}
	}
	void DFS(Vertex<T>* root)
	{
		for (int x = 0; x < numOfVertices; x++)
		{
			vertices[x]->color = WHITE;
		}
		_DFS(root);
	}
	void _DFS(Vertex<T>* s)
	{
		
		int ix1,ix2;
		if (s == nullptr)return ;
		cout << "  ";
		stack<Vertex<T>*> S;
		S.push(s);
		s->color = GRAY;
		cout << s->Vallue() << " ";
		ix1 = indexOf(s);
		
		for (int i{ 0 }; i < numOfVertices; i++)
		{
			ix2 = indexOf(vertices[i]);
			if (edges[ix1][ix2] != NOT_CONNECTED)
			{
				if (vertices[i]->color == WHITE)
				{
					S.push(vertices[i]);
					vertices[i]->color = GRAY;
					_DFS(vertices[i]);
				}
			}
		}
		s->color = BLACK;

	}
};

