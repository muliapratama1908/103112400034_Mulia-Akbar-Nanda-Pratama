#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    address root;
    createTree(root); 
    insertNode(root, 6); 
    insertNode(root, 4);
    insertNode(root, 7);
    insertNode(root, 2);
    insertNode(root, 5);
    insertNode(root, 1);
    insertNode(root, 3);
    cout << "Hasil Pre-Order : ";
    printPreOrder(root);
    cout << endl;
    cout << "Hasil Post-Order : ";
    printPostOrder(root);
    cout << endl;
    
    return 0;
}