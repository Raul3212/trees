#include <iostream>
#include <vector>
#include <list>

#include "AVLNode.h"
#include "BSTree.h"
#include "BinaryTree.h"
#include "AVLTree.h"

using namespace std;

int main()
{

	AVLTree<double> tree(list<double>({3,7,10,2,1,31,14,12}));

    cout << "Testando AVL" << endl;

    cout << tree.getQntNodes() << endl;
    cout << tree.getMenor() << endl;

    cout << BinaryTree<double>::vectorToString(tree.getPreOrder()) << endl;

    return 0;
}

