#include "BST.h"
#include "TreeNode.h"
#include<iostream>
using namespace std;

int main()
{
    BST<int> b;
    b.insertNode(3);
    b.insertNode(1);
    b.insertNode(2);
    b.insertNode(10);
    b.insertNode(20);
    b.insertNode(21);
    b.insertNode(15);
    b.insertNode(17);
    b.insertNode(18);

    cout << "contains: " << (b.searchNode(99) ? "found it" : "not in tree") << endl;
    b.insertNode(99);
    cout << "contains: " << (b.searchNode(99) ? "found it" : "not in tree") << endl;
    b.deleteNode(3);

    b.printTree();

    //cout << "Max: " << (b.getMax()) << endl;

    return 0;

}
