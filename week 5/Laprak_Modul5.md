# <h1 align="center">Laporan Praktikum Modul 5 - Singly Linked List (Bagian Kedua) </h1>
<p align="center">Mulia Akbar Nanda Pratama - 103112400034</p>

## Dasar Teori
Linked list merupakan salah satu bentuk struktur data yang berisi kumpullan data yang tersusun secara sekuensial, saling bersambungan, dinamis dan terbatas. Linked list adalah suatu simpul atau node yang dikaitkan dengan simpul lain dalam suatu urutan tertentu [1]. 

## Searching
Searching dalam pemrograman adalah proses yang sangat fundamental untuk mencari data tertentu dalam sekumpulan data tentunya yang memiliki tipe yang sama. Pencarian diperlikan untuk mencari informasi khusus dari tabel/kumpulan data pada saat lokasi yang pasti dari informasi tersebut sebelumnya tidak diketahui. Data pada tabel biasa nya pakai array yang di mana memungkinkan untuk menyimpan nilai yang bertipe sama. Ada metode pencarian beruntun atau sequential search/linear search dan ada juga metode pencarian bagi dua atau binary search. [3]

### Sequential/linier search  
Merupakan sebuah metode pencarian yang konsepnya membandingkan sekumpulan elemen data yang ada dengan mengecek satu persatu dari awal sampai akhir apakah data itu ditemukan atau tidak. Adapun cara kerjanya setiap data di array akan dibandingkan dengan kunci sampai pada data yang akhir (kasus terburuk (***worst case***)). [3]

### Binary search
Metode dengan melakukan proses pembagian ruang pencarian berulang-ulang sampai data ditemukan. Metode ini memperkecil jumlah operasi pembandingan yang harus dilakukan antara data yang dicari dengan data yang ada pada tabel, khususnya untuk jumlah data yang sangat besar ukurannya. Syarat untuk metode ini adalah data nya sudah terurut naik ascending. [3]

### Operasi-operasi Linked List
1. *Insert*: menambahkan sebuah simpul baru ke dalam suatu linked list [1]
2. *IsEmpty*: fungsi untuk menentukan apakah linked list kosong atau tidak [1]
3. *Find first*: untuk mencari elemen pertama dari linked list [1]
4. *Find next*: untuk mencari elemen sesudah elemen yang ditunjuk now [1]
5. *Retrieve*: fungsi untuk mengambil elemen yang ditunjuk oleh now. Elemen tersebut lalu dikembalikan oleh fungsi [1]
6. *Update*: fungsi untuk mengubah elemen yang ditunjuk dengan isi dari sesuatu [1]
7. *Delete now*: untuk menghapus elemen [1]
8. *Delete head*: untuk menghapus  elemen yang ditunjuk oleh head. Head berpindah ke elemen sesudahnya [1]
9. *Clear*: untuk menghapus elemen yang sudah ada [1]

### Jenis-jenis Linked List
1. *Singly Linked List* 
    Daftar terhubung yang setiap simpul pembentukannya mempunyai satu rantai (link) ke simpul lainnya. Simpul yang saling terhubung satu sama lain dengan menggunakan pointer. Setiap simpul dalam singly linked list memiliki dua bagian, yaitu data dan pointer yang menunjuk ke simpul berikutnya. Singly linked list hanya memiliki satu arah, yaitu dari simpul awal (head) ke simpul akhir (tail). [2]

2. *Doubly Linked List*
    Suatu bentuk struktur data yang terdiri dari simpul-simpul yang saling terhubung satu sama lain dengan menggunakan dua pointer, memungkinkan traversal daftar yang efisien di kedua arah.[2]

3. *Singly Circular Linked List*
    Simpul terakhir dari daftar yang menunjuk ke simpul pertama dari daftar dan karenanya membentuk sebuah lingkaran. Setiap node tertaut melingkar terdiri dari dua bagian: data dan penunjuk ke node berikutnya. [2]

4. *Doubly Circular Linked List*
    Struktur data linear, yang elemen-elemennya disimpan dalam bentuk simpul. Setiap simpul berisi tiga sub-elemen. [2]



## Guided
### 1. Linked list dengan operasi insert dan update 

### main.cpp
```C++
#include "listbuah.h"
#include <iostream>
using namespace std;

int main(){
    linkedList List;
    address nodeA, nodeB, nodeC,nodeD,nodeE;   
    createList(List);

    nodeA=alokasi("jeruk",100,3000);
    nodeB=alokasi("apel",75,4000);
    nodeC=alokasi("pir",87,5000);
    nodeD=alokasi("semangka",43,11500); 
    nodeE=alokasi("durian",15,31450);

    insertFirst(List,nodeA);
    insertLast(List,nodeB);
    insertAfter(List,nodeC,nodeA);
    insertAfter(List,nodeD,nodeC);
    insertLast(List,nodeE);

    cout<<" isi list buat dilakukan insert"<<endl;
    printList(List);
    cout<<"jumlah node:"<<nbList(List)<<endl;
    cout<<endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List,nodeD);

    cout<<" isi list buah setelah dilakukan update"<<endl;
    printList(List);
    cout<<"jumlah node:"<<nbList(List)<<endl;
    cout<<endl;

    return 0;
}   
```

### listBuah.cpp
```C++

#include "listbuah.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedList List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedList &List) {
    List.first = Nil;
}

address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedList &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedList &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedList &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedList &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void printList(linkedList List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedList List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

void deleteList(linkedList &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

//Materi Modul 5 - Update Operations
void updateFirst(linkedList List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedList List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedList List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```

### listBuah.h
```C++
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil nullptr

#include <iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah;
    float harga;
};
typedef buah dataBuah;
typedef struct node *address;
struct node{
    dataBuah isidata;
    address next;
};

struct linkedList{
    address first;
};

bool listEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedList List);
void insertFirst(linkedList &List, address nodebaru);
void insertAfter(linkedList &List, address nodebaru, address Prev);
void insertLast(linkedList &List, address nodebaru);
void deleteFirst(linkedList &List);
void delLast(linkedList &List);
void deleteAfter(address &List, address &nodehapus, address nodeprev);
int nbList(linkedList List);
void deletelist(linkedList &List);

//materi modul 5 (part 1 update)
void updateFirst(linkedList List);
void updateLast(linkedList List);
void updateAfter(linkedList List, address prev);

#endif
```
Singly Linked List adalah cara menyimpan data secara berurutan yang di mana setiap elemen/node menyimpan datanya sendiri dan sebuah penunjuk/pointer ke elemen berikutnya. Program ini dibuat untuk mengelola daftar "buah". Setiap node dalam list menyimpan informasi tentang satu buah: nama, jumlah, dan harga. Program utama (main.cpp) kemudian mendemonstrasikan cara menggunakan linked list ini dengan menambah, mencetak, dan memperbarui data buah.


### 2. Linked List linear dan binary

### binary.cpp
```C++
#include <iostream>
using namespace std;

//Definisi node untuk linked list
struct Node { 
    int data;      // Menyimpan nilai data
    Node* next;    // Pointer ke node selanjutnya
};

// Fungsi untuk menghitung panjang linked list
int getLength(Node* head) {
    int count = 0;
    Node* temp = head;
    while(temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Fungsi binary search untuk linked list (data harus terurut)
// Parameter: head (pointer awal list), key (nilai yang dicari)
// Return: pointer ke node jika ditemukan, nullptr jika tidak
Node* binarySearch(Node* head, int key) {
    int length = getLength(head);      // Hitung panjang list
    int left = 0;
    int right = length - 1;
    
    while(left <= right) {
        int mid = left + (right - left) / 2;  // Cari posisi tengah
        
        // Traverse ke posisi mid
        Node* temp = head;
        for(int i = 0; i < mid; i++) {
            temp = temp->next;
        }
        
        if(temp->data == key) {           // Jika ditemukan
            return temp;
        }
        else if(temp->data < key) {       // Cari di bagian kanan
            left = mid + 1;
        }
        else {                            // Cari di bagian kiri
            right = mid - 1;
        }
    }
    return nullptr;                       // Tidak ditemukan
}

// Fungsi untuk menambahkan node baru di akhir list
void append(Node* &head, int value){
    Node *newNode = new Node{value, nullptr};
    if(!head) head = newNode;
    else{
        Node *temp = head;
        while(temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr;  // Inisialisasi linked list kosong

    // Menambahkan elemen terurut ke linked list (penting untuk binary search!)
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    
    int key = 30;  // Nilai yang dicari
    Node* result = binarySearch(head, key); // Panggil fungsi binary search

    if(result != nullptr) {
        cout << "Nilai " << key << " ditemukan dalam linked list." << endl;
    } else {
        cout << "Nilai " << key << " tidak ditemukan dalam linked list." << endl;
    }

    return 0;
}
```

### linear.cpp
```C++
#include <iostream>
using namespace std;

struct Node { 
    int data;
    Node* next;
};

Node *linearSearch(Node* head, int key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void append(Node* &head, int value){
    Node *newNode = new Node{value, nullptr};
    if(!head) head = newNode;
    else{
        Node *temp = head;
        while(temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr;

    append(head, 10);
    append(head, 20);
    append(head, 30);
    
    Node* result = linearSearch(head, 20);

    cout << (result ? "Found" : "Not Found") << endl;

    return 0;
}
```
Program yang mendemonstrasikan metode pencarian menggunakan binary search dan linear search. Linear search bekerja dengan cara mengunjungi setiap elemen satu per satu dari awal (head) sampai menemukan nilai yang dicari atau sampai akhir list. Kalau binary search itu bekerja dengan cara menghitung panjang list secara berulang dan melakukan traversal dari (head) untuk menemukan node tengah pada setiap iterasi.

## Unguided 

### 1.Binary Search

```C++
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node* &head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int getLength(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

Node* binarySearch(Node* head, int key) {
    int length = getLength(head);
    int left = 0;
    int right = length - 1;
    int iterasi = 1;

    cout << "Proses Pencarian:" << endl;

    while (left <= right) {
        int mid_idx = left + (right - left) / 2;

        Node* mid_node = head;
        for (int i = 0; i < mid_idx; i++) {
            mid_node = mid_node->next;
        }

        cout << "Iterasi " << iterasi++ << ": Mid = " << mid_node->data << " (indeks tengah) - ";

        if (mid_node->data == key) {
            cout << "DITEMUKAN!" << endl;
            return mid_node;
        } else if (mid_node->data < key) {
            cout << "Cari di bagian kanan" << endl;
            left = mid_idx + 1;
        } else {
            cout << "Cari di bagian kiri" << endl;
            right = mid_idx - 1;
        }
    }

    cout << "Tidak ada elemen tersisa" << endl;
    return nullptr;
}

int main() {
    Node* head = nullptr;

    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);

    cout << "BINARY SEARCH PADA LINKED LIST" << endl;
    cout << "Linked List yang dibuat: ";
    printList(head);

    int key1 = 40;
    cout << "Mencari nilai: " << key1 << endl;
    Node* result1 = binarySearch(head, key1);

    if (result1 != nullptr) {
        cout << "Hasil: Nilai " << key1 << " DITEMUKAN pada linked list!" << endl;
        cout << "Alamat node: " << result1 << endl;
        cout << "Data node: " << result1->data << endl;
        if (result1->next != nullptr) {
            cout << "Node berikutnya: " << result1->next->data << endl;
        } else {
            cout << "Node berikutnya: NULL" << endl;
        }
    } else {
        cout << "Hasil: Nilai " << key1 << " TIDAK DITEMUKAN dalam linked list!" << endl;
    }

    int key2 = 25;
    cout << "\nMencari nilai: " << key2 << endl;
    Node* result2 = binarySearch(head, key2);

    if (result2 != nullptr) {
        cout << "Hasil: Nilai " << key2 << " DITEMUKAN pada linked list!" << endl;
        cout << "Alamat node: " << result2 << endl;
        cout << "Data node: " << result2->data << endl;
    } else {
        cout << "Hasil: Nilai " << key2 << " TIDAK DITEMUKAN dalam linked list!" << endl;
    }

    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
```

### Output Unguided 1 :

##### Output 1
![op1](https://github.com/muliapratama1908/103112400034_Mulia-Akbar-Nanda-Pratama/blob/main/week%205/op1.png)

Program yang mendemonstrasikan binary search pada struktur data singly linked list. 
*struct Node*
int data: menyimpan angka integer untuk node.
Node* next: pointer yang simpan alamat memori ke node selanjutnya.
*append(Node* &head, int value)*
-membuat node baru
-mengisi data node baru
*printList(Node* head)*
untuk mencetak seluruh isi 
*getLength(Node* head)*
menghitung dan mengembalikan jumlah node yang ada di dalam linked list.
*binarySearch(Node* head, int key)*
untuk mencari nilai key di dalam linked list yg sudah terurut menggunakan binary search.

### 2. Linear search

```C++
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node* &head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node* linearSearch(Node* head, int key) {
    Node* current = head;
    int nodeIndex = 1;

    cout << "Proses Pencarian:" << endl;
    while (current != nullptr) {
        cout << "Memeriksa node " << nodeIndex << ": " << current->data;
        
        if (current->data == key) {
            cout << " (SAMA) - DITEMUKAN!" << endl;
            return current;
        } else {
            cout << " (tidak sama)" << endl;
        }
        
        current = current->next;
        nodeIndex++;
    }

    cout << "Tidak ada node lagi yang tersisa" << endl;
    return nullptr;
}

void printSearchResult(int key, Node* result) {
    if (result != nullptr) {
        cout << "Hasil: Nilai " << key << " DITEMUKAN pada linked list!" << endl;
        cout << "Alamat node: " << result << endl;
        cout << "Data node: " << result->data << endl;
        if (result->next != nullptr) {
            cout << "Node berikutnya: " << result->next->data << endl;
        } else {
            cout << "Node berikutnya: NULL" << endl;
        }
    } else {
        cout << "Hasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!" << endl;
    }
}

int main() {
    Node* head = nullptr;

    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    cout << "LINEAR SEARCH PADA LINKED LIST" << endl;
    cout << "Linked List yang dibuat: ";
    printList(head);

    int key1 = 30;
    cout << "\nMencari nilai: " << key1 << endl;
    Node* result1 = linearSearch(head, key1);
    printSearchResult(key1, result1);

    int key2 = 25;
    cout << "\nMencari nilai: " << key2 << endl;
    Node* result2 = linearSearch(head, key2);
    printSearchResult(key2, result2);

    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![op2](https://github.com/muliapratama1908/103112400034_Mulia-Akbar-Nanda-Pratama/blob/main/week%205/op2.png)

program yang mendemonstrasikan linear search. Program ini menggunakan struct node dan fungsi append untuk membuat sebuah linked list dengan ditambahkannya elemen di akhir. Pada akhirnya fungsi akan mencetak DITEMUKAN dan mengembalikan pointer ke node.




## Kesimpulan
Jadi, kesimpulannya adalah kita mengimplementasikan singly linked list dengan lengkap. Ada fungsi seperti insert untuk menambah data, update untuk mengubah data dan bisa melakukannya di awal, akhir maupun di tengah list. Selain itu mempelajari dua metode pencarian data yaitu linear search dan binary search. Linear search mencari data dengan cara membandingkan key secara sequensial dari head, dan binary search memerlukan data terurut atau ascending serta implementasi nya lebih rumit karna harus menghitung total panjang list dan melakukan traversal manual dari head supaya menemukan node tengah di setiap iterasinya.


## Referensi
<br>[1] https://elektro.um.ac.id/wp-content/uploads/2016/04/ASD-Modul-6-Linked-List.pdf
<br>[2] https://jurnal.stkippersada.ac.id/jurnal/index.php/jutech/article/download/4263/pdf
<br>[2] https://jurnal.stkippersada.ac.id/jurnal/index.php/jutech/article/view/4263
<br>[3] https://daismabali.medium.com/metode-searching-dalam-struktur-data-dan-implementasi-pemrogramannya-d97582084866
