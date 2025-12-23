#include "BST.h"
Node* root = NULL;
void createTree() { root = NULL; }
bool isEmpty() { return root == NULL; }
Node* newNode(string nama, float berat, string tier) {
    Node* n = new Node{nama, tier, berat, NULL, NULL};
    return n;
}
Node* insertNode(Node* current, string nama, float berat, string tier) {
    if (!current) return newNode(nama, berat, tier);
    if (berat < current->beratBadan) current->left = insertNode(current->left, nama, berat, tier);
    else if (berat > current->beratBadan) current->right = insertNode(current->right, nama, berat, tier);
    return current;
}
void inOrder(Node* current) {
    if (current) {
        inOrder(current->left);
        cout << current->beratBadan << " - ";
        inOrder(current->right);
    }
}
void mostLeft() {
    Node* b = root;
    while (b && b->left) b = b->left;
    if(b) cout << "node mosleft : " << b->beratBadan << endl;
}
void mostRight() {
    Node* b = root;
    while (b && b->right) b = b->right;
    if(b) cout << "node mostright: " << b->beratBadan << endl;
}
void cetak(Node* n) {
    if (!n) { cout << "tidak ada\n"; return; }
    cout << "nama member : " << n->namaMember << "berat badan\n: " << n->beratBadan << "tier member\n : " << n->tierMember << endl;
}
void searchByBeratBadan(float cari) {
    Node *curr = root, *parent = NULL;
    while (curr && curr->beratBadan != cari) {
        parent = curr;
        curr = (cari < curr->beratBadan) ? curr->left : curr->right;
    }
    if (!curr) { cout << "data tidak ditemukan\n"; return; }

    cout << "data ditemukan di dalam bst\n"; cetak(curr);
    cout << "data parent\n"; (parent) ? cetak(parent) : (void)(cout << "Root");
    cout << "sibling\n";
    if (parent) {
        Node* sib = (parent->left == curr) ? parent->right : parent->left;
        cetak(sib);
    } else cout << "tidak ada sibling";
    cout << "data child kiri\n"; cetak(curr->left);
    cout << "data child kanan\n"; cetak(curr->right);
}