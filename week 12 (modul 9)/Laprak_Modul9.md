# <h1 align="center"> Laporan Praktikum Modul 9 - TREE </h1>
<p align="center">Mulia Akbar Nanda Pratama - 103112400034</p>

## Dasar Teori
Tree merupakan sekumpulan node yang saling terhubung satu sama lain dalam satu kesatuan yang membentuk layaknya struktur sebuah pohon [1]. Struktur pohon merupakan suatu cara merepresentasikan suatu struktur hirarki secara grafis yang mirip sebuah pohon [1]. Ada beberapa jenis TREE di antaranya ada:

## Jenis- jenis tree
# Binary tree
tree dengan syarat bahwa tiap node hanya boleh memiliki maksimal dua sub pohon dan kedua subpohon harus terpisah, kelebihannya itu mudah dalam penyusunan algoritma sorting, searching data relatif cepat, fleksibel dalam penambahan dan penghapusan data [2]
# Full binary tree
semua node, kecuali leaf pasti memiliki 2 anak dan tiap subpohon memiliki panjang path yang sama [2]
# Complete binary tree
tree yang mirip dengan full binary tree, tapi tiap subtree boleh memiliki panjang path yang berbeda dan tiap node (kecuali leaf) memiliki 2 anak [2]
# Skewed binary tree
binary tree yang semua node nya (kecuali leaf) hanya memiliki satu anak [2]

## Contoh pemrograman tree sederhana di C++
```c++
#include<stdio.h>
typedef struct node{
char data;
node *kiri;
node *kanan;
};

node *akar=NULL;
addNode(node **akar, char isi) {
if((*akar)==NULL){
node *baru;
baru= new node;
baru->data = isi;
baru->kiri = NULL;
baru->kanan = NULL;
(*akar)=baru;
}
}

preOrder(node *akar) {
if(akar !=NULL) {
printf(“%c “, akar->data);
preOrder(akar->kiri);
preOrder(akar->kanan);
}
}

inOrder(node *akar) {
if(akar !=NULL) {
inOrder(akar->kiri);
printf(“%c “, akar->data);
inOrder(akar->kanan);
}
}

postOrder(node *akar) {
if(akar !=NULL) {
postOrder(akar->kiri);
postOrder(akar->kanan);
printf(“%c “, akar->data);
}
}

main(){
char abjad;
printf(“\n\n\tPosisi Awal Tree:\n\n”);
printf(“\t       R\n\t      / \\\n\t     A   E\n\t    /\n\t   S\n\t  / \\\n\t I   T\n\n”);
addNode(&akar,abjad=’R’);
addNode(&akar->kiri,abjad=’A’);
addNode(&akar->kanan,abjad=’E’);
addNode(&akar->kiri->kiri,abjad=’S’);
addNode(&akar->kiri->kiri->kiri,abjad=’I’);
addNode(&akar->kiri->kiri->kanan,abjad=’T’);
printf(“Tampilan PreOrder  : “);
preOrder(akar);
printf(“\nTampilan InOrder   : “);
inOrder(akar);
printf(“\nTampilan PostOrder : “);
postOrder(akar);
}
```
## ISTILAH DALAM TREE
1. predecesor: node yang berada di atas node tertentu [2]
2. succesor: node yang berada di bawah node tertentu [2]
3. ancestor: seluruh node yang terletak sebellum node tertentu dan terletak pada jalur yang sama [2]
3. descendant: seluruh node yang terletak setelah node tertentu dan terletak pada jalur yang sama [2]
4. parent: predecesor saatu level ddi atas suatu node [2]
5. child: sucesor satu level di bawah suatu node [2]
6. sibling: node-node yang memiliki parent yang sama [2]
7. subtree: suatu node beserta descendantnya [2]
8. size: banyaknya  node dalam suatu tree [2]
9. height: banyaknya tingkatan dalam suatu tree [2]
10. root: node khusus yang tidak memiliki predecessor [2]
11. leaf: node-node dalam tree yang tidak memiliki sucsesor [2]
12. degree: banyaknya child dalam suatu node [2]

## OPERASI-OPERASI YANG ADA DI TREE
- create untuk membentuk sebuah tree baru yang kosong [1]
- insert untuk menambahkan node ke dalam tree. Jika data yang akan dimasukkan lebih besar daripada elemen root, maka akan diletakkan di node sebelah kanan, sebaliknya jika lebih kecil maka akan diletakkan di node sebelah kiri. Untuk data pertama akan menjadi elemen root [1]
- preorder untuk mencetak node yang dikunjungim kunjungi left, kunjungi right [1]
- inorder untuk mengunjungi left, cetak node yang dikunjungi, kunjungi riight [1]
- postorder untuk mengunjungi left, kunjungi right, cetak node yang dikunjungi [1]
- 


## Guided
### 1. Guided 1
```c++
#include <iostream>

using namespace std;

int pangkat_2(int x){
    if (x == 0){
        return 1;
    } else if (x > 0){
        return 2 * pangkat_2(x-1);
    }
}

int main(){
    cout << "=== REKURSIF PANGKAT 2 ===" << endl;

    int x;
    cout << "Masukan nilai x:";
    cin >> x;
    cout << endl;
    cout << "Pangkat 2 dari " << x << " adalah " << pangkat_2(x) << endl;


    return 0;
}
```
program rekursif pangkat 2


### 2. Guided 2

### bst1.cpp
```C++
#include "bst1.h"
#include <iostream>

using namespace std;

//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}
```

### bst1.h
```C++
#ifndef bst1_H
#define bst1_H
#include <iostream>
using namespace std;

typedef int infotype;
typedef struct Node *address;
struct Node {
    infotype info;
    address left;
    address right;
};
bool IsTreeEmpty(address root);
void createTree(address &root);
address newNode(infotype x);
address insertNode(address root, infotype x);
void preOrder(address root);
void inOrder(address root);
void postOrder(address root);
int countNodes(address root);
int treeDepth(address root);
#endif
```

### main.cpp
```C++
#include <iostream>
#include "bst1.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "Binary Search Tree Insert & Traversal" << endl;
    cout << endl;

    root = insertNode(root, 20); // Root awal
    insertNode(root, 10);
    insertNode(root, 35);
    insertNode(root, 5);
    insertNode(root, 18);
    insertNode(root, 40);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << "Hasil PreOrder Traversal : ";
    preOrder(root);
    cout << endl;

    cout << "Hasil PostOrder Traversal : ";
    postOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;


    return 0;
}
```
Deskripsi: program implementasi dari binary search tree dengan menggunakan operasi dasar penyisipan dan penelusuran data. Program ini membuat struktur dua pohon biner yang terurut yang di mana setiap node memiliki aturan yaitu nilai di sebelah kiri selalu lebih kecil dan nilai yang sebelah kanan selalu lebih besar dari node induknya.


### 3. Guided 3

### bst2.cpp
```C++
#include "bst2.h"
#include <iostream>
using namespace std;

//FUNCTION & PROSEDUR SEBELUMNYA
//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}


//FUNCTION & PROSEDUR BARU
//searching
void searchByData(address root, infotype x) { //function untuk melakukan searching data tertentu
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        address nodeBantu = root;
        address parent = NULL;
        bool ketemu = false;
        while(nodeBantu != NULL){
            if(x < nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(x > nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(x == nodeBantu->info){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam BST!" << endl;
            cout << "Data Angka : " << nodeBantu->info << endl;

            //menampilkan parentnya & pengecekan sibling
            address sibling = NULL;
            if(parent != NULL){
                cout << "Parent : " << parent->info << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != NULL){
                cout << "Sibling : " << sibling->info << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != NULL){
                cout << "Child kiri : " << nodeBantu->left->info << endl;
            } else if(nodeBantu->left == NULL){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != NULL){
                cout << "Child kanan : " << nodeBantu->right->info << endl;
            } else if(nodeBantu->right == NULL){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}


//mostleft & mostright
address mostLeft(address root) { //function untuk menampilkan mostleft atau node paling kiri (node dengan nilai terkecil) didalam BST
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}

address mostRight(address root) { //function untuk menampilkan mostright atau node paling kanan (node dengan nilai terbesar) didalam BST
    while (root->right != NULL){
        root = root->right;
    }
    return root;
}


//delete
bool deleteNode(address &root, infotype x) { //function untuk menghapus node tertentu didalam BST (menghapus berdasarkan parameter infotype)
    if (root == NULL) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (x < root->info) {
            return deleteNode(root->left, x);
        } else if (x > root->info) {
            return deleteNode(root->right, x);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (root->left == NULL && root->right == NULL) {
                address temp = root;
                root = NULL;
                delete temp;
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (root->left == NULL) {
                address temp = root;
                root = root->right;
                delete temp;
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (root->right == NULL) {
                address temp = root;
                root = root->left;
                delete temp;
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                address successor = mostLeft(root->right);
                //salin data successor ke node saat ini
                root->info = successor->info;
                //hapus successor pada subtree kanan
                return deleteNode(root->right, successor->info);
            }
            return true; //berhasil dihapus
        }
    }
}

void deleteTree(address &root) { //prosedur untuk menghapus BST (menghapus seluruh node BST)
    if(root == NULL){
        return;
    } else {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = NULL;
    }
}
```

### bst2.h
```C++
#ifndef bst2_H
#define bst2_H

#include <iostream>
using namespace std;

typedef int infotype; //alias infotype untuk data integer
typedef struct node *address;

struct node {
    infotype info;
    address left;
    address right;
};

bool isEmpty(address root); 
void createTree(address &root);

address newNode(infotype x);
address insertNode(address root, infotype x);

// fungsi traversal
void preOrder(address root); // tengah - kiri - kanan atau rood - child kiiri - child kanan
void inOrder(address root); // kiri - tengah - kanan atau child kiri - root - child kanan
void postOrder(address root); // kiri - kanan - tengah atau child kiri - child kanan - root

// utilities
int countNodes(address root); // menghitung jumlah node pada level tree
int treeDepth(address root); // menghitung height/kedalaman level tree

void searchByData(address root, infotype x);

// mostleft & mostright
address mostLeft(address root); // function menampilkan node paling kiri
                                // node dgn nilai terkecil
address mostRight(address root); // function menampilkan node paling kanan
                                // node dgn nilai terbesar

bool deleteNode(address &root, infotype x); // hapus berdasar parameter infotype
void deleteTree(address &root); // menghapus seluruh node bst

#endif
```

### main.cpp
```c++
#include <iostream>
#include "bst2.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "=== Binary Search Tree ==" << endl;
    cout << endl;

    root = insertNode(root, 30); // Root awal
    insertNode(root, 15);
    insertNode(root, 35);
    insertNode(root, 11);
    insertNode(root, 17);
    insertNode(root, 20);
    insertNode(root, 38);
    insertNode(root, 16);
    insertNode(root, 22);
    insertNode(root, 33);
    insertNode(root, 18);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;

    cout << endl;
    searchByData(root, 17);
    
    cout << endl;
    cout << "Node mostleft : " << mostLeft(root)->info << endl;
    cout << "Node mostright : " << mostRight(root)->info << endl;

    cout << endl;
    infotype angkaHapus;
    cout << "Masukkan angka yang ingin dihapus: ";
    cin >> angkaHapus;
    //misal angka yang dihapus adalah angka 17
    if(deleteNode(root, angkaHapus)){
        cout << "Data " << angkaHapus << " berhasil dihapus!" << endl;
    } else {
        cout << "Data " << angkaHapus << " tidak ditemukan!" << endl;
    }
    cout << endl;

    searchByData(root, 17);
    cout << endl;
    searchByData(root, 18);

    cout << endl;
    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    deleteTree(root);
    cout << "Seluruh tree berhasil dihapus!" << endl;

    cout << endl;
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        cout << "Hasil InOrder Traversal : ";
        inOrder(root);
    }

    return 0;
}
```
Deskripsi: Program ini mengimplementasikan BST dengan operasi lengkap termasuk search, delete, mostLeft, dan mostRight.


## Unguided 

### 1. Binary search tree dengan menggunakan linked list
### main.cpp
```C++
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    address root;
    createTree(root); 

    cout << "Hello World!" << endl;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6); 
    insertNode(root, 7);

    cout << "Hasil InOrder Traversal : ";
    printInOrder(root);
    cout << endl;
    
    return 0;
}
```

### bstree.cpp
```C++
#include "bstree.h"
#include <iostream>

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
```

### bstree.h
```C++
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
address findNode(infotype x, address root);
void printInOrder(address root);
#endif
```

### Output Unguided 1 :

##### Output 1
![o1](https://github.com/muliapratama1908/103112400034_Mulia-Akbar-Nanda-Pratama/blob/main/week%2012%20(modul%209)/o1.jpeg)

program yang mengimplementasikan bst dengan linked list ddan menggunakan operasi insert dan traversal InOrder. Program ini membuat struktur data tree yang terurut secara otomatis. Setiap kali data dimasukkan, program akan menempatkannya di posisi yang tepat sesuai aturan BST (nilai kecil di kiri, nilai besar di kanan).



### 2. Membuat fungsi untuk meghitung jumlah node 

### main.cpp
```C++
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    address root;
    createTree(root); 

    cout << "Hello World!" << endl;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6); 
    insertNode(root, 7);
    
    printInOrder(root);
    cout << endl;

    cout << "Kedalaman : " << hitungKedalaman(root) << endl;
    cout << "Jumlah Node : " << hitungJumlahNode(root) << endl;
    cout << "Total : " << hitungTotalInfo(root) << endl;
    
    return 0;
}
```

### bstree.cpp
```C++
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
```

### bstree.h
```C++
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
address findNode(infotype x, address root);
void printInOrder(address root);

int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
int hitungKedalaman(address root);

#endif
```

### Output Unguided 2 :

##### Output 1
![o2](https://github.com/muliapratama1908/103112400034_Mulia-Akbar-Nanda-Pratama/blob/main/week%2012%20(modul%209)/o2.jpeg)


program yang menambahkan fungsi hitungJumlahNode, hitungTotalInfo, dan hitungKedalaman



### 3. Tree secar pre order dan post order

### main.cpp
```C++
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
```

### bstree.cpp
```C++
#include "bstree.h"
#include <iostream>

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

void printPreOrder(address root) {
    if (root != NULL) {
        cout << root->info << " ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

void printPostOrder(address root) {
    if (root != NULL) {
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout << root->info << " ";
    }
}
```

### bstree.h
```C++
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
```

### Output Unguided 3 :

##### Output 1
![o3](https://github.com/muliapratama1908/103112400034_Mulia-Akbar-Nanda-Pratama/blob/main/week%2012%20(modul%209)/o3.jpeg)

program binary search yang mengimplementasikan operasi traversal pre order dan post order.


## Kesimpulan
Dari laporan di atas dapat disimpulkan bahwa tree merupakan struktur data non linear yang berfungsi untuk merepresentasikan hubungan antara elemen elemen data yang di mana setiap elemen disebut node. Node ini terhubung membentuk kesatuan yang menyerupai struktur pohon. Ada beberapa sifat dan jenis tree juga diantaranya setiap tree memiliki root sebagai node khusus tanpa predecessor dan leaf sebbagai node tanpa sucessor, lalu ada beberapa jenis binary tree yang membatasi setiap node memiliki maksimal dua sub pohon, termasuk full binary tree, complete binary tree, dan skewed binary tree. Dan ada beberapa operasi dan traversal dari binary search meliputi create untuk membuat tree kosong, dan insert untuk menambahkan node. Penelusuran atau traversal ini merupakan proses mengunjungi setiap node dalam urutan tertentu, yang dilakukan secara rekursif. Selain operasi dasar, binary search tree juga bisa menggunakan fungsi fungsi tambahan untuk analisis seperti hitungJulahNode, hhitungKedalaman, hitungTotalInfo, serta operasi manajemen data seperti searchByData dan deleteNode.




## Referensi
<br>[1] https://www.nblognlife.com/2014/12/tree-pada-c-tree-awal.html
<br>[2]https://reniwulanapriani.wordpress.com/2018/04/18/pengertian-dan-contoh-pemograman-tree-pada-c/


