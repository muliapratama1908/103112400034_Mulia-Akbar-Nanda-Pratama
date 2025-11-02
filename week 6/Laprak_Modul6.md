# <h1 align="center">Laporan Praktikum Modul 6 - Doubly Linked List (Bagian Pertama) </h1>
<p align="center">Mulia Akbar Nanda Pratama - 103112400034</p>

## Dasar Teori
Doubly Linked List (DLL) merupakan struktur data yang terdiri dari node-node yang terhubung
secara berpasangan, di mana setiap node memiliki pointer ke node sebelumnya (prev) dan node
berikutnya (next). DLL menawarkan beberapa keunggulan dibandingkan dengan Single Linked List
(SLL), terutama dalam hal operasi insertion dan deletion. Operasi insertion pada DLL dapat
dilakukan lebih efisien di berbagai posisi, baik di awal, tengah, maupun akhir list. Hal ini karena
DLL memungkinkan akses data dari dua arah, sehingga memungkinkan untuk menyisipkan node
baru tanpa harus melalui seluruh list.
Operasi deletion pada DLL juga lebih fleksibel dibandingkan dengan SLL. DLL memungkinkan
untuk menghapus node di berbagai posisi, termasuk node pertama, node terakhir, dan node di tengah
list. Selain itu, DLL juga memungkinkan untuk menghapus node tanpa harus mengetahui nilai node
tersebut, hanya dengan mengetahui pointer ke node tersebut. [2]

### Implementasi dasar double linked list
## A. struktur node  ganda
Double linked list merupakan salah satu jenis linked list yang setiap node-nya memiliki dua referensi: satu menunjuk ke node sebelumnya dan satu lagi menunjuk ke node berikutnya. Ini berbeda dengan Single Linked List yang hanya memiliki satu referensi yang menunjuk ke node berikutnya. Struktur node ganda ini memungkinkan traversal dua arah, yaitu dari awal ke akhir (forward) dan dari akhir ke awal (backward) [1].

## Definisi struktur node  ganda
Struktur node pada double linked list terdiri dari tiga komponen utama:
1. *Data*: Komponen yang menyimpan nilai atau informasi yang disimpan dalam node.
2. *Pointer ke Node Sebelumnya*: Referensi yang menunjuk ke node sebelumnya dalam linked list.
3. *Pointer ke Node Berikutnya*: Referensi yang menunjuk ke node berikutnya dalam linked list. [1]

## Implementasi dalam bahasa pemrograman
```c++
struct Node {
    int data;           // Menyimpan data node
    struct Node* prev;  // Menunjuk ke node sebelumnya
    struct Node* next;  // Menunjuk ke node berikutnya
};
```
## Keuntungan menggunakan double linked list
Struktur node ganda pada double linked list memberikan beberapa keuntungan dibandingkan dengan single linked list:

1. **Traversal Dua Arah**: Kita dapat dengan mudah menavigasi linked list dari awal ke akhir atau dari akhir ke awal. Ini sangat berguna untuk operasi seperti pencarian atau penghapusan elemen.
2. **Penghapusan Efisien**: Menghapus node di tengah linked list menjadi lebih efisien karena kita memiliki referensi langsung ke node sebelumnya dan berikutnya.
3. **Fleksibilitas Manipulasi Data**: Double linked list memberikan fleksibilitas lebih dalam menambah, menghapus, atau memodifikasi data karena kita dapat mengakses node dari kedua arah.

Meskipun memiliki kelebihan ini, double linked list juga memerlukan memori lebih banyak karena setiap node menyimpan dua referensi. Oleh karena itu, penting untuk mempertimbangkan kebutuhan spesifik dari aplikasi saat memilih antara single dan double linked list. [1]

## B. Penambahan elemen di awal 
Penambahan elemen di awal double linked list merupakan salah satu operasi dasar yang penting. Operasi ini melibatkan penambahan node baru sebagai elemen pertama dari linked list, sehingga node baru tersebut menjadi head atau kepala dari linked list. Penambahan elemen di awal double linked list memerlukan beberapa langkah spesifik untuk memastikan referensi antar node tetap konsisten. [1]

Langkah-langkah Penambahan Elemen di Awal:
1. Membuat Node Baru:
- Langkah pertama adalah membuat node baru dengan data yang ingin disimpan. Node baru ini juga harus memiliki referensi ke node berikutnya (yang akan menjadi node yang sebelumnya adalah head).
2. Mengatur Referensi Node Baru:
- Node baru harus menunjuk ke node yang saat ini menjadi head sebagai node berikutnya.
- Karena node baru akan menjadi elemen pertama, referensi ke node sebelumnya harus disetel ke null.
3. Mengubah Referensi Head Lama:
- Jika linked list tidak kosong, node yang saat ini menjadi head harus memperbarui referensinya untuk menunjuk ke node baru sebagai node sebelumnya.
4. Mengatur Node Baru sebagai Head:
- Akhirnya, head dari linked list diperbarui untuk menunjuk ke node baru. [1]

## Implementasi dalam bahasa pemrograman
```c++ 
void addAtBeginning(struct Node** head_ref, int new_data) {
    // 1. Alokasikan node baru
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    // 2. Masukkan data
    new_node->data = new_data;

    // 3. Setel prev dari node baru sebagai NULL karena ini akan menjadi elemen pertama
    new_node->prev = NULL;

    // 4. Setel next dari node baru sebagai head saat ini
    new_node->next = (*head_ref);

    // 5. Ubah prev dari head saat ini ke node baru, jika head tidak NULL
    if ((*head_ref) != NULL) {
        (*head_ref)->prev = new_node;
    }

    // 6. Pindahkan head ke node baru
    (*head_ref) = new_node;
}
```
## Manfaat dan Pertimbangan

Penambahan elemen di awal linked list sangat efisien karena hanya memerlukan perubahan beberapa referensi, menjadikannya operasi O(1). Namun, perlu diperhatikan bahwa setiap perubahan pada referensi node harus dilakukan dengan hati-hati untuk menghindari inkonsistensi dalam linked list. Hal ini terutama penting dalam konteks double linked list karena setiap node memiliki dua referensi yang perlu dikelola.

Dengan mengikuti langkah-langkah yang benar dan memastikan bahwa semua referensi diperbarui dengan tepat, penambahan elemen di awal double linked list dapat dilakukan dengan mudah dan efisien, memungkinkan pengelolaan data yang dinamis dan fleksibel.

## C. Penambahan elemen di akhir 
Penambahan elemen di akhir double linked list adalah salah satu operasi dasar yang sering digunakan. Operasi ini melibatkan penambahan node baru sebagai elemen terakhir dari linked list, sehingga node baru tersebut menjadi tail atau ekor dari linked list. Penambahan elemen di akhir double linked list memerlukan beberapa langkah spesifik untuk memastikan referensi antar node tetap konsisten. [1]

Langkah-langkah Penambahan Elemen di Akhir:

1. Membuat Node Baru:
Langkah pertama adalah membuat node baru dengan data yang ingin disimpan. Node baru ini akan menjadi node terakhir, jadi referensi ke node berikutnya harus disetel ke null.
2. Mengatur Referensi Node Baru:
Node baru harus menunjuk ke node sebelumnya, yang saat ini adalah node terakhir (tail) dari linked list.
3. Menemukan Node Terakhir:
Jika linked list tidak kosong, kita perlu menelusuri dari head hingga mencapai node terakhir. Node terakhir adalah node yang referensi ke node berikutnya adalah null.
4. Mengatur Referensi Node Terakhir Lama:
Setelah menemukan node terakhir, referensi ke node berikutnya dari node ini harus diperbarui untuk menunjuk ke node baru.
5. Mengatur Node Baru sebagai Node Terakhir:
Akhirnya, node baru menjadi node terakhir, atau tail, dari linked list. 

## Implementasi dalam bahasa pemrograman
```c++
void addAtEnd(struct Node** head_ref, int new_data) {
    // 1. Alokasikan node baru
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node* last = *head_ref; // Gunakan untuk menemukan node terakhir

    // 2. Masukkan data
    new_node->data = new_data;

    // 3. Setel next dari node baru sebagai NULL karena ini akan menjadi node terakhir
    new_node->next = NULL;

    // 4. Jika linked list kosong, maka node baru menjadi head
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    // 5. Temukan node terakhir
    while (last->next != NULL) {
        last = last->next;
    }

    // 6. Ubah next dari node terakhir menjadi node baru
    last->next = new_node;

    // 7. Setel prev dari node baru sebagai node terakhir
    new_node->prev = last;
}
```
## Manfaat dan Pertimbangan

Penambahan elemen di akhir linked list sangat berguna untuk situasi di mana kita ingin mempertahankan urutan elemen yang sudah ada dan menambahkan elemen baru sebagai yang terakhir. Operasi ini biasanya memerlukan O(n) waktu dalam double linked list karena kita harus menelusuri hingga node terakhir, kecuali jika kita menjaga referensi langsung ke tail, yang dapat mengurangi waktu operasi menjadi O(1).

Dengan mengikuti langkah-langkah yang benar dan memastikan bahwa semua referensi diperbarui dengan tepat, penambahan elemen di akhir double linked list dapat dilakukan dengan mudah dan efisien. Ini memungkinkan pengelolaan data yang dinamis dan fleksibel, serta mempermudah implementasi algoritma yang memerlukan penambahan elemen di akhir struktur data.

## Guided
### 1. Double list dengan operasi insert dan update 

### main.cpp
```C++
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeC);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    return 0;
}
```

### listMakanan.cpp
```C++
#include "listMakanan.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node selanjutnya (nodeNext) tidak valid!" << endl;
        }
    }
}
```

### listMakanan.h
```C++
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

#endif
```
Program yang mengimplementasikan double linked list untuk menyimpan dan mengelola data makanan. Program tersebut memungkinkan pengguna untuk melakukan penambahan, pengubahan, dan penampilan data secara dinamis tanpa batasan ukuran tertentu.



### 2. Doubly linked list dengan search dan delete

### Doublylist.cpp
```C++
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) { //blm ada elemen
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) { //fs alokasi elemen baru
    address P = new ElmList; //alokasi memori untuk elemen baru
    P->info = x; //mengisi bagian info dengan data x
    P->next = Nil; //ini jadi nill karena gak terhubung ke list manapun
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P; //menghapus elemen yang ditunjuk oleh P dan mengembalikan memori ke sistem
}

void insertLast(List &L, address P) {
    if (L.first == Nil) { // List kosong
        L.first = P; // elemen pertama dan terakhir sama dengan P
        L.last = P;
    } else { // List ada isi
        P->prev = L.last; // prev P menunjuk ke elemen terakhir saat ini
        (L.last)->next = P; // next elemen terakhir saat ini menunjuk ke P
        L.last = P; // update last menjadi P
    }
}

// Searching
address findElm(List L, string nopol) {
    address P = L.first; // mulai dari elemen pertama
    while (P != Nil) {
        //Bandingkan nopol yang dicari dengan nopol di elemen saat ini
        if (P->info.nopol == nopol) {
            return P; // Ketemu
        }
        P = P->next; // Lanjut ke elemen berikutnya kalau g cocok
    }
    return Nil; // Tidak ketemu
}

// Delete
void deleteByNopol(List &L, string nopol) {
    // Cari elemen dengan nopol yang sesuai
    address P = findElm(L, nopol);
    if (P == Nil) { // Tidak ditemukan
        cout << "Nomor polisi " << nopol << " tidak ditemukan.\n";
    } else { // Ditemukan
        if (P == L.first && P == L.last) { // Kasus 1: Hanya 1 elemen di list
            L.first = Nil; L.last = Nil;
        } else if (P == L.first) { // Kasus 2: Hapus elemen pertama tapi bukan satu-satunya
            L.first = P->next; // update first ke elemen berikutnya
            (L.first)->prev = Nil; // update prev elemen pertama barumenjadi nil
        } else if (P == L.last) { // Kasus 3: Hapus elemen terakhir
            L.last = P->prev; // update last ke elemen sebelumnya
            (L.last)->next = Nil; P->prev = Nil; // update next elemen terakhir baru menjadi nil
        } else { // Kasus 4: Hapus elemen di tengah
            address Prec = P->prev; // elemen sebelum P
            address Succ = P->next; // elemen setelah P
            Prec->next = Succ; Succ->prev = Prec; // hubungkan Prec ke Succ
            P->next = Nil; P->prev = Nil; // putuskan hubungan P dari list
        }
        dealokasi(P); // dealokasi elemen P
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n";
    }
}


void printInfo(List L) { //menampilkan isi list
    address P = L.first; //mulai dari elemen pertama
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "no polisi: " << P->info.nopol << endl;
            cout << "warna    : " << P->info.warna << endl;
            cout << "tahun    : " << P->info.thnBuat << endl << endl;
            P = P->next;
        }
    }
}
```

### main.cpp
```C++
#include "Doublylist.h"

using namespace std;

int main() { // penggunaan fungsi-fungsi dalam Doublylist
    List L; // deklarasi list
    CreateList(L); // buat list kosong
    address P; // deklarasi pointer elemen list
    infotype data; // deklarasi variabel info kendaraan

    data = {"D001", "hitam", 90}; P = alokasi(data); insertLast(L, P);
    data = {"D003", "putih", 70}; P = alokasi(data); insertLast(L, P);
    data = {"D004", "kuning", 90}; P = alokasi(data); insertLast(L, P);

    cout << "DATA LIST AWAL" << endl;
    printInfo(L);


    string cariNopol = "D001";
    cout << "MENCARI NOPOL " << cariNopol << " -" << endl;
    address found = findElm(L, cariNopol); //Manggil fungsi pencarian di Doublylist.cpp
    if (found != Nil) { // Ketemu
        cout << "Ditemukan: " << found->info.nopol << ", Warna: " << found->info.warna << endl << endl;
    } else {
        cout << cariNopol << " tidak ditemukan." << endl << endl;
    }

    string hapusNopol = "D003";
    cout << "MENGHAPUS NOPOL " << hapusNopol << " -" << endl;
    deleteByNopol(L, hapusNopol); //Manggil fungsi delete di Doublylist.cpp
    cout << endl;

    cout << "DATA LIST SETELAH HAPUS" << endl;
    printInfo(L);

    // Contoh delete elemen pertama
    cout << "MENGHAPUS ELEMEN PERTAMA " << endl;
    deleteByNopol(L, L.first->info.nopol); //Menghapus elemen pertama
    cout << endl;
    printInfo(L);


    return 0;
}
```

### Doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

// Tipe data info (kendaraan)
struct kendaraan { //struktur untuk menyimpan info kendaraan
    string nopol; 
    string warna;
    int thnBuat;
};
typedef kendaraan infotype;

// Tipe address dan elemen list
typedef struct ElmList *address;
struct ElmList {
    infotype info; // info kendaraan
    address next;
    address prev;
};

// Tipe list
struct List {
    address first; //pointer ke elemen pertama
    address last;  //pointer ke elemen terakhir
};

// Prototypes
void CreateList(List &L); //ngebuat list kosong
address alokasi(infotype x); //alokasi elemen baru/nambah elemen baru
void dealokasi(address &P); //dealokasi elemen/hapus elemen

// Insert Last
void insertLast(List &L, address P);

// Searching
address findElm(List L, string nopol);

// Delete
void deleteByNopol(List &L, string nopol);

// Tampilkan isi list
void printInfo(List L);

#endif
```
Program yang mengimplementasikan double linked list yang digunakan untuk menyimpan dan mengelola data kendaraan. Program ini juga menunjukkan penerapan operasi dasar seperti penambahan data, pencarian data, penghapusan data, serta penampilan isi list secara efisien. Struktur seperti ini sangat berguna dalam berbagai aplikasi yang membutuhkan manipulasi data dinamis tanpa batasan ukuran array statis.


## Unguided 

### 1. Doubly list data kendaraan
### Doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

struct kendaraan {
    string nopol; 
    string warna;
    int thnBuat;
};
typedef kendaraan infotype;

typedef struct ElmList *address;
struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);

void insertLast(List &L, address P);

address findElm(List L, string nopol);

void deleteByNopol(List &L, string nopol);

void printInfo(List L);

#endif
```

### Doublylist.cpp
```C++
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void insertLast(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        (L.last)->next = P;
        L.last = P;
    }
}

address findElm(List L, string nopol) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

void deleteByNopol(List &L, string nopol) {
    address P = findElm(L, nopol);
    if (P == Nil) {
        cout << "Nomor polisi " << nopol << " tidak ditemukan.\n";
    } else {
        if (P == L.first && P == L.last) {
            L.first = Nil; L.last = Nil;
        } else if (P == L.first) {
            L.first = P->next;
            (L.first)->prev = Nil;
        } else if (P == L.last) {
            L.last = P->prev;
            (L.last)->next = Nil; P->prev = Nil;
        } else {
            address Prec = P->prev;
            address Succ = P->next;
            Prec->next = Succ; Succ->prev = Prec;
            P->next = Nil; P->prev = Nil;
        }
        dealokasi(P);
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n";
    }
}


void printInfo(List L) {
    address P = L.last;
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "no polisi: " << P->info.nopol << endl;
            cout << "warna    : " << P->info.warna << endl;
            cout << "tahun    : " << P->info.thnBuat << endl;
            P = P->prev;
        }
    }
}
```

### main.cpp
```C++
#include "Doublylist.h"

using namespace std;

int main() {
    List L;
    CreateList(L);
    address P;
    infotype dataIn;
    string tempNopol;

    cout << "masukkan nomor polisi: ";
    cin >> tempNopol;
    cout << "masukkan warna kendaraan: ";
    cin >> dataIn.warna;
    cout << "masukkan tahun kendaraan: ";
    cin >> dataIn.thnBuat;
    
    if (findElm(L, tempNopol) != Nil) {
        cout << "nomor polisi sudah terdaftar" << endl;
    } else {
        dataIn.nopol = tempNopol;
        P = alokasi(dataIn);
        insertLast(L, P);
    }

    cout << "masukkan nomor polisi: ";
    cin >> tempNopol;
    cout << "masukkan warna kendaraan: ";
    cin >> dataIn.warna;
    cout << "masukkan tahun kendaraan: ";
    cin >> dataIn.thnBuat;
    
    if (findElm(L, tempNopol) != Nil) {
        cout << "nomor polisi sudah terdaftar" << endl;
    } else {
        dataIn.nopol = tempNopol;
        P = alokasi(dataIn);
        insertLast(L, P);
    }

    cout << "masukkan nomor polisi: ";
    cin >> tempNopol;
    cout << "masukkan warna kendaraan: ";
    cin >> dataIn.warna;
    cout << "masukkan tahun kendaraan: ";
    cin >> dataIn.thnBuat;
    
    if (findElm(L, tempNopol) != Nil) {
        cout << "nomor polisi sudah terdaftar" << endl;
    } else {
        dataIn.nopol = tempNopol;
        P = alokasi(dataIn);
        insertLast(L, P);
    }

    cout << "masukkan nomor polisi: ";
    cin >> tempNopol;
    cout << "masukkan warna kendaraan: ";
    cin >> dataIn.warna;
    cout << "masukkan tahun kendaraan: ";
    cin >> dataIn.thnBuat;
    
    if (findElm(L, tempNopol) != Nil) {
        cout << "nomor polisi sudah terdaftar" << endl;
    } else {
        dataIn.nopol = tempNopol;
        P = alokasi(dataIn);
        insertLast(L, P);
    }
    cout << endl << "DATA LIST 1" << endl;
    printInfo(L);

    return 0;
}
```
Penjelasan: Program ini adalah implementasi Doubly Linked List dalam C++ yang digunakan untuk menyimpan data kendaraan. 
1. File Doublylist.h mendefinisikan struktur data, termasuk struct kendaraan (untuk nopol, warna, tahun) dan struct ElmList (node yang memiliki pointer next dan prev).
2. File Doublylist.cpp berisi logika untuk semua fungsi, seperti alokasi (membuat node baru), insertLast (menambah data di akhir), findElm (mencari data berdasarkan nopol), deleteByNopol, dan printInfo (yang mencetak list dari akhir ke awal menggunakan pointer prev). 
3. File main.cpp adalah program utama yang meminta pengguna memasukkan data empat kendaraan satu per satu. Sebelum menambahkan, program ini menggunakan findElm untuk memeriksa apakah nomor polisi sudah ada; jika sudah ada, program akan menampilkan pesan "nomor polisi sudah terdaftar", dan jika tidak, data baru akan ditambahkan ke akhir list.

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided1_1](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week3/Screenshot%20Output%20Unguided1.png)



### 2. Mencari elemen

### Doublylist.cpp
```C++
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void insertLast(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        (L.last)->next = P;
        L.last = P;
    }
}

address findElm(List L, string nopol) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

void deleteByNopol(List &L, string nopol) {
    address P = findElm(L, nopol);
    if (P == Nil) {
        cout << "Nomor polisi " << nopol << " tidak ditemukan.\n";
    } else {
        if (P == L.first && P == L.last) {
            L.first = Nil; L.last = Nil;
        } else if (P == L.first) {
            L.first = P->next;
            (L.first)->prev = Nil;
        } else if (P == L.last) {
            L.last = P->prev;
            (L.last)->next = Nil; P->prev = Nil;
        } else {
            address Prec = P->prev;
            address Succ = P->next;
            Prec->next = Succ; Succ->prev = Prec;
            P->next = Nil; P->prev = Nil;
        }
        dealokasi(P);
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n";
    }
}


void printInfo(List L) {
    address P = L.last;
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "no polisi: " << P->info.nopol << endl;
            cout << "warna    : " << P->info.warna << endl;
            cout << "tahun    : " << P->info.thnBuat << endl;
            P = P->prev;
        }
    }
}
```

### Doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

struct kendaraan {
    string nopol; 
    string warna;
    int thnBuat;
};
typedef kendaraan infotype;

typedef struct ElmList *address;
struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);

void insertLast(List &L, address P);

address findElm(List L, string nopol);

void deleteByNopol(List &L, string nopol);

void printInfo(List L);

#endif
```

### main..cpp
```C++
#include "Doublylist.h"

using namespace std;

int main() {
    List L;
    CreateList(L);
    address P;
    
    P = alokasi({"D001", "hitam", 90});
    insertLast(L, P);

    P = alokasi({"D003", "putih", 70});
    insertLast(L, P);

    P = alokasi({"D004", "kuning", 90});
    insertLast(L, P);
    
    cout << "DATA LIST 1" << endl;
    printInfo(L);
    cout << endl;

    string nopolCari;
    cout << "Masukkan Nomor Polisi yang dicari : ";
    cin >> nopolCari;

    P = findElm(L, nopolCari);
    
    if (P != Nil) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna : " << P->info.warna << endl;
        cout << "Tahun : " << P->info.nopol << endl;
    } else {
        cout << "Data dengan nomor polisi " << nopolCari << " tidak ditemukan." << endl;
    }
    cout << endl;

    return 0;
}
```
Penjelasan: program yang dibuat berfungsi untuk mencari sebuah plat nomor yang sudah diinputkan pada program yang pertama. Struktur dari program ini juga tidak terlalu berbeda jauh hanya saja di file main.cpp nya ditambahkan createList dan alokasi agar nanti output nya bisa langsung menampilkan plat nomor yang akan dicari.

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided2](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week3/Screenshot%20Output%20Unguided2.png)



### 3. Hapus elemen

### Doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

struct kendaraan {
    string nopol; 
    string warna;
    int thnBuat;
};
typedef kendaraan infotype;

typedef struct ElmList *address;
struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);

void insertLast(List &L, address P);

address findElm(List L, string nopol);

void deleteByNopol(List &L, string nopol);

void printInfo(List L);

#endif
```

### Doublylist.cpp
```C++
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void insertLast(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        (L.last)->next = P;
        L.last = P;
    }
}

address findElm(List L, string nopol) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

void deleteByNopol(List &L, string nopol) {
    address P = findElm(L, nopol);
    if (P == Nil) {
        cout << "Nomor polisi " << nopol << " tidak ditemukan.\n";
    } else {
        if (P == L.first && P == L.last) {
            L.first = Nil; L.last = Nil;
        } else if (P == L.first) {
            L.first = P->next;
            (L.first)->prev = Nil;
        } else if (P == L.last) {
            L.last = P->prev;
            (L.last)->next = Nil; P->prev = Nil;
        } else {
            address Prec = P->prev;
            address Succ = P->next;
            Prec->next = Succ; Succ->prev = Prec;
            P->next = Nil; P->prev = Nil;
        }
        dealokasi(P);
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n";
    }
}


void printInfo(List L) {
    address P = L.last;
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "no polisi: " << P->info.nopol << endl;
            cout << "warna    : " << P->info.warna << endl;
            cout << "tahun    : " << P->info.thnBuat << endl;
            P = P->prev;
        }
    }
}
```

### main.cpp
```C++
#include "Doublylist.h"

using namespace std;

int main() {
    List L;
    CreateList(L);
    address P;
    
    P = alokasi({"D001", "hitam", 90});
    insertLast(L, P);

    P = alokasi({"D003", "putih", 70});
    insertLast(L, P);

    P = alokasi({"D004", "kuning", 90});
    insertLast(L, P);
    
    cout << "DATA LIST 1" << endl;
    printInfo(L);
    cout << endl;


    string nopolHapus;
    cout << "Masukkan Nomor Polisi yang akan dihapus : ";
    cin >> nopolHapus;

    deleteByNopol(L, nopolHapus);
    cout << endl;

    return 0;
}
```
Penjelasan: program tersebut merupakan program yang dirancang untuk menghapus sebuah data kendaraan yaitu data plat nomor pada suatu kendaraan. 

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided2](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week3/Screenshot%20Output%20Unguided2.png)



## Kesimpulan
Laporan praktikum ini menyimpulkan bahwa Doubly Linked List (DLL) merupakan struktur data yang nodenya memiliki dua penunjuk, prev (sebelumnya) dan next (berikutnya). Struktur ini memungkinkan penelusuran dua arah (maju dan mundur), yang menjadikannya lebih fleksibel untuk manipulasi data dibandingkan Single Linked List. Dua program utama telah diimplementasikan: pertama, program data makanan untuk mendemonstrasikan operasi insert (First, Last, After, Before) dan update (First, Last, After, Before); kedua, program data kendaraan yang berfokus pada insertLast, pencarian findElm berdasarkan nomor polisi, dan penghapusan deleteByNopol. Program data kendaraan ini juga sukses menggunakan pointer prev pada fungsi printInfo untuk menampilkan list dari data terakhir ke data pertama.


## Referensi
<br>[1] https://rumahcoding.co.id/linked-list-pengertian-dan-implementasi-dasar/
<br>[2] https://jurnalmahasiswa.com/index.php/jriin/article/download/1282/762

