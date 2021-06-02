#include "../Class_Lib/Graph.cpp"


void _main()
{
	Graph<string> AdjMatrixGraph(14);
	Vertex<string>* root;
	Vertex<string>* pVertex;


	/* create the following graph in memory, position of the * represents the direction of edges
	   e.g  Edges are as following in the graph represented in the Adjacency Matrix A->B, A->C, B->D, D->C
				(A)
			   /   \
			  *     *
			 (B)   (C)
			  \     *
			   *   /
				(D)
	*/

	// Add vertices in memory
	root = new Vertex<string>("A");			// 0
	AdjMatrixGraph.addVertex(root);
	pVertex = new Vertex<string>("B");		// 1
	AdjMatrixGraph.addVertex(pVertex);
	pVertex = new Vertex<string>("C");		// 2
	AdjMatrixGraph.addVertex(pVertex);
	pVertex = new Vertex<string>("D");		// 3
	AdjMatrixGraph.addVertex(pVertex);
	pVertex = new Vertex<string>("E");		// 4
	AdjMatrixGraph.addVertex(pVertex);
	pVertex = new Vertex<string>("F");			// 5
	AdjMatrixGraph.addVertex(pVertex);
	pVertex = new Vertex<string>("G");		// 6
	AdjMatrixGraph.addVertex(pVertex);
	pVertex = new Vertex<string>("H");		// 7
	AdjMatrixGraph.addVertex(pVertex);
	pVertex = new Vertex<string>("I");		// 8
	AdjMatrixGraph.addVertex(pVertex);
	
	AdjMatrixGraph.addEdge(0, 1, 1);//1
	AdjMatrixGraph.addEdge(0, 3, 1);//2
	AdjMatrixGraph.addEdge(1, 2, 1);//3
	AdjMatrixGraph.addEdge(2, 3, 1);//4
	AdjMatrixGraph.addEdge(2, 4, 1);//5
	AdjMatrixGraph.addEdge(4, 3, 1);//6
	AdjMatrixGraph.addEdge(3, 6, 1);//7
	AdjMatrixGraph.addEdge(6, 5, 1);//8
	AdjMatrixGraph.addEdge(6, 8, 1);//9
	AdjMatrixGraph.addEdge(8, 5, 1);//10
	AdjMatrixGraph.addEdge(5, 4, 1);//11
	AdjMatrixGraph.addEdge(7, 3, 1);//12
	AdjMatrixGraph.addEdge(7, 6, 1);//13



	AdjMatrixGraph.printMatrix();
	AdjMatrixGraph.BFS(root);
	AdjMatrixGraph.DFS(root);

	cout << endl;
};

