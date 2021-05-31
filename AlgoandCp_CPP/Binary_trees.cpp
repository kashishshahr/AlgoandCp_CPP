
#include <iostream>

#include "../Class_Lib/BinaryTree.cpp"

int main()
{
    std::cout << "Hello World!\n";
    BTree<int>* tree = new BTree<int>();
    srand(time(0));

    /*for (int i = 0; i < 10; i++)
    {
        tree->insert(rand()%50);
    }*/
    tree->insert(50);
    tree->insert(30);
    tree->insert(20);
    tree->insert(40);
    tree->insert(70);
    tree->insert(60);
    tree->insert(80);
    
    
    tree->Print();
    tree->findMinimum();
    tree->findMaximum();
    tree->findPredecessor(65);
    tree->findSuccessor(65);


}
