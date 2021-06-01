
#include <iostream>

#include "../Class_Lib/BinaryTree.cpp"

int bstmain()
{
    std::cout << "Hello World!\n";
    BTree<int>* tree = new BTree<int>();
    srand(time(0));

    /*for (int i = 0; i < 10; i++)
    {
        tree->insert(rand()%50);
    }*/
    /*
* key =7..diff=1..ptr=6..dif=4
          5
       /     \
     3	       10
   /   \      /   \
   1   4	 9     15
            /    / \
           6    11  20
            \
              8
*/

    tree->insert(5);
    tree->insert(3);
    tree->insert(1);
    tree->insert(4);
    tree->insert(10);
    tree->insert(9);
    tree->insert(15);
    tree->insert(6);
    tree->insert(8);
    tree->insert(11);
    tree->insert(20);
    
    cout<<"\nClosest Node:"<<tree->findClossetNode(51)<<endl;
    tree->getSize(15);

    cout << "\n15 is at rank:" << tree->getRank(15)<<endl;
    tree->getSize(9);
    tree->getSize();

    cout << "\n9 is at rank:" << tree->getRank(9)<<endl;
    cout << "\n6th largest element:" << tree->Select(6)<<endl;

    tree->Print();
    tree->findMinimum();
    tree->findMaximum();
    tree->findPredecessor(65);
    tree->findSuccessor(65);
    tree->BFSTraversal();
    tree->DFSTraversal();

    return 0;
}
