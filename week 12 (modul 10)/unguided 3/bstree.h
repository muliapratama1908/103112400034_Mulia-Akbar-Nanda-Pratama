#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

void createTree(address &root);
address alokasi(infotype x);
void insertNode(address &root, infotype x);

void printPreOrder(address root);
void printPostOrder(address root);

#endif