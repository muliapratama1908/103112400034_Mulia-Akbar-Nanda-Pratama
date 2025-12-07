#include "bstree.h"
#include <iostream>
#include <algorithm>
using namespace std;
void createTree(address &root) {
    root = NULL;
}
address alokasi(infotype x) {
    address newNode = new Node;
    newNode->info = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void insertNode(address &root, infotype x) {
    if (root == NULL) {
        root = alokasi(x);
        return;
    }

    if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
}
address findNode(infotype x, address root) {
    if (root == NULL) {
        return NULL;
    }

    if (x == root->info) {
        return root;
    } else if (x < root->info) {
        return findNode(x, root->left);
    } else {
        return findNode(x, root->right);
    }
}
void printInOrder(address root) {
    if (root != NULL) {
        printInOrder(root->left);
        cout << root->info << " ";
        printInOrder(root->right);
    }
}
int hitungJumlahNode(address root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}
int hitungTotalInfo(address root) {
    if (root == NULL) {
        return 0;
    }
    return root->info + hitungTotalInfo(root->left) + hitungTotalInfo(root->right);
}
int hitungKedalaman(address root) {
    if (root == NULL) {
        return -1;
    }
    
    int depthLeft = hitungKedalaman(root->left);
    int depthRight = hitungKedalaman(root->right);
    
    return max(depthLeft, depthRight) + 1;
}