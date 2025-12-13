# <h1 align="center"> Laporan Praktikum Modul 13 - Multi Linked List </h1>
<p align="center">Mulia Akbar Nanda Pratama - 103112400034</p>

## Dasar Teori
Multi linked list merupakan bagian dari linked list yang di mana setiap node dapat memiliki lebih dari satu pointer yang memuat arah hubungan atau urutan lain di dalam struktur data. Di dalam multi linked list, setiap node tidak hanya menyimpan satu pointer ke elemen berikutnya, tetapi memiliki beberapa pointer yang menghubungkannya ke node lain [1]. Pada multi linked list, setiap node bisa memiliki lebih dari satu data field dan lebih dari satu pointer field [2].

Contoh struktur node multi linked list:

```c++
struct node {
    int data1, data2;
    struct node *next1, *next2;
};
```
Pada program di atas, setiap node memiliki 2 data field dan 2 pointer yang memungkinkan satu node terhubung ke beberapa node lain secara bersamaan [2].

### Karakteristik Multi Linked list
1. Pointer ganda: setiap node dapat memiliki lebih dari satu pointer yang mengarah pada node lain, memungkinkan hubbungan data lebih kompleks dalam satu struktur [2].
2. Multi urutan: multi linked list bisa digunakan untuk mewakili berbagai urutan data tanpa duplikasi karena setiap pointer dapat menelusuri urutan berbeda [2].
3. Dinamis: multi linked list dinamis sehingga ukuran dan struktur bisa berubah saat program berjalan [2].

### Kelebihan dan Kekurangan Multi Linked list
1. Kelebihan [1]
- Fleksibel dalam representasi data,  karna dengan lebih dari satu pointer per node, multi linked list dapat memodelkan data yang memiliki hubungan ganda atau multi arah.
- Efisiensi operasi terhadap relasi kompleks.
2. Kekurangan [1]
- Kompleksitas pemrograman, pointer yang banyak membuat implementasi mll lebih rumit dibandingkan struktur data yang lain.
- Pemeliharaan struktur, karna kesalahan operasi pointer dapat dengan mudah menyebabkan kebocoran memori atau kesalahan logika program.





## Guided
### 1. Implementasi Stuktur Data Multi Linked List

### multilist.h
```C++
#ifndef MULTILIST_H
#define MULTILIST_H

#include <iostream>
using namespace std;

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct  nodeChild{
    string idMakanan;
    string namaMakanan;
    NodeChild next;
    NodeChild prev;
};

struct listAnak{
    NodeChild first;    
    NodeChild last;
};

struct nodeParent{
 string idKategoriMakanan;
 string namaKategoriMakanan;
 NodeParent next;
 NodeParent prev;
 listAnak L_Anak;
};

struct listInduk{
    NodeParent first;
    NodeParent last;
};

void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &Lanak);

NodeParent alokasiNodeParent(string idkategoriMakanan, string namaKategoriMakanan);
void dealokasiNodeParent(NodeParent &NodeInduk);

NodeChild alokasiNodeChild(string idmakanan, string namamakanan);
void dealokasiNodeChild(NodeChild &NodeAnak);

void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void hapusListAnak(listAnak &LAnak);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);

void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev); 
void findChildByID(listInduk &LInduk, string IDCari);

void printStrukturMLL(listInduk &LInduk);

#endif
```

### multilist.cpp
```C++
#include "multilist.h"
#include <iostream>

using namespace std;

void createListInduk(listInduk &LInduk){
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak){
    LAnak.first = LAnak.last = NULL;
}

NodeParent alokasiNodeParent(string idKategoriMakanan, string namaKategoriMakanan){
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->idKategoriMakanan = idKategoriMakanan;
    nodeBaruParent->namaKategoriMakanan = namaKategoriMakanan;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

void dealokasiNodeParent(NodeParent &nodeInduk){
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

NodeChild alokasiNodeChild(string idMakanan, string namaMakanan){
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->idMakanan = idMakanan;
    nodeBaruChild->namaMakanan = namaMakanan;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak){
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent){
    if(LInduk.first == NULL) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->namaKategoriMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void hapusListAnak(listAnak &LAnak){
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->namaKategoriMakanan << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild){
    if(LAnak.first == NULL) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(LAnak.first == NULL){
        cout << "List anak kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findChildByID(listInduk &LInduk, string IDCari){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->namaKategoriMakanan << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child (ID Makanan) : " << nodeBantuChild->idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent (ID Kategori Makanan): " << nodeBantuParent->idKategoriMakanan << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

void printStrukturMLL(listInduk &LInduk){
    if(LInduk.first == NULL) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori Makanan : " << nodeBantuParent->idKategoriMakanan << endl;
            cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;

            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}
```

### main.cpp
```C++
#include "multilist.h"
#include <iostream>
using namespace std;

int main(){
    listInduk LInduk;
    createListInduk(LInduk);

    NodeParent k01 = alokasiNodeParent("K01", "Makanan Berat");
    insertLastParent(LInduk, k01);
    NodeParent k02 = alokasiNodeParent("K02", "Minuman");
    insertLastParent(LInduk, k02);
    NodeParent k03 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(LInduk, k03);
    cout<<endl;

    NodeChild M01 = alokasiNodeChild("M01", "Nasi Goreng");
    insertLastChild(k01->L_Anak, M01);
    NodeChild M02 = alokasiNodeChild("M02", "Ayam Bakar Madu");
    insertLastChild(k01->L_Anak, M02);  
    NodeChild D02 = alokasiNodeChild("D02", "Jus Alpukat");
    insertLastChild(k02->L_Anak, D02);
    NodeChild D03 = alokasiNodeChild("D03", "Jus Alpukat");
    insertLastChild(k02->L_Anak, D03);
    NodeChild S01 = alokasiNodeChild("DS01", "Puding Coklat");
    insertLastChild(k03->L_Anak, S01);
    cout << endl;  

    printStrukturMLL(LInduk);
    cout << endl;

    findChildByID(LInduk, "D01");
    cout << endl;
    deleteAfterChild(k01->L_Anak, M01);
    cout<< endl;
    deleteAfterParent(LInduk, k02);
    cout << endl;
    printStrukturMLL(LInduk);
    cout << endl;
    
    return 0;
}
```
Deskripsi: Program tersebut merupakan implementasi multi linked list dengan struktur parent dan child dengan menggunakan double linked list untuk parent dan child nya tersebut. Terdapat struktur *listInduk* yang berfungsi sebagai penyimpanan utama untuk menyimpan seluruh node parent. Setiap node parent yang ada di dalam *listInduk* merepresentasikan sebuah kategori makanan yang memiliki aribut ID kategori dan nama kategori. Setiap node parent juga memiliki struktur sendiri yaitu *listAnak* yang menampung multiple node child. Node child sendiri merepresentasikan makanan individual dengan atribut ID makanan dan nama makanan. Dengan metode ini, satu kategori makanan dapat memiliki banyak item makanan yang terkait dan menciptakan hubungan one to many antara parent dan child. Lalu implementasi double linked list memberikan fleksibilitas dalam melakukan operasi traversal. Setiap node parent maupun child, memiliki poiner next untuk menunjuk ke node berikutnya dan pointer prev untuk menunjuk ke node sebelumnya yang memungkinkan program untuk melakukan penelusuran maju dan mundur dengan lebih efisien.



## Unguided 

### 1. ADT multi linked list golongan hewan 
### main.cpp
```C++
#include "MultiLL.h"
int main() {
    listParent LP;
    createListParent(LP);
    NodeParent P1 = allocNodeParent("G001", "Aves");
    insertLastParent(LP, P1);
    NodeChild C1_1 = allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
    insertLastChild(P1->L_Child, C1_1);
    NodeChild C1_2 = allocNodeChild("AV002", "Bebek", "Air", true, 2);
    insertLastChild(P1->L_Child, C1_2);
    NodeParent P2 = allocNodeParent("G002", "Mamalia");
    insertLastParent(LP, P2);
    NodeChild C2_1 = allocNodeChild("M001", "Harimau", "Hutan", true, 200);
    insertLastChild(P2->L_Child, C2_1);
    NodeChild C2_2 = allocNodeChild("M003", "Gorila", "Hutan", false, 160);
    insertLastChild(P2->L_Child, C2_2);
    NodeChild C2_3 = allocNodeChild("M002", "Kucing", "Darat", true, 4);
    insertLastChild(P2->L_Child, C2_3);
    NodeParent P3 = allocNodeParent("G003", "Pisces");
    insertLastParent(LP, P3);
    NodeParent P4 = allocNodeParent("G004", "Amfibi");
    insertLastParent(LP, P4);
    NodeChild C4_1 = allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2);
    insertLastChild(P4->L_Child, C4_1);
    NodeParent P5 = allocNodeParent("G005", "Reptil");
    insertLastParent(LP, P5);
    printMLLStructure(LP);
    return 0;
}
```

### MultiLL.cpp
```C++
#include "MultiLL.h"

bool isEmptyParent(listParent L) { return L.first == NULL; }
bool isEmptyChild(listChild L) { return L.first == NULL; }

void createListParent(listParent &L) { L.first = NULL; L.last = NULL; }
void createListChild(listChild &L) { L.first = NULL; L.last = NULL; }

NodeParent allocNodeParent(string id, string nama) {
    NodeParent P = new nodeParent;
    P->isidata = {id, nama};
    P->next = NULL; P->prev = NULL;
    createListChild(P->L_Child);
    return P;
}

NodeChild allocNodeChild(string id, string nama, string hab, bool ekor, float brt) {
    NodeChild C = new nodeChild;
    C->isidata = {id, nama, hab, ekor, brt};
    C->next = NULL; C->prev = NULL;
    return C;
}

void deallocNodeParent(NodeParent &P) { delete P; P = NULL; }
void deallocNodeChild(NodeChild &C) { delete C; C = NULL; }

void insertFirstParent(listParent &L, NodeParent P) {
    if (isEmptyParent(L)) L.first = L.last = P;
    else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastParent(listParent &L, NodeParent P) {
    if (isEmptyParent(L)) L.first = L.last = P;
    else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void deleteFirstParent(listParent &L) {
    if (isEmptyParent(L)) return;
    NodeParent P = L.first;
    if (L.first == L.last) {
        L.first = L.last = NULL;
    } else {
        L.first = P->next;
        L.first->prev = NULL;
        P->next = NULL;
    }
    deallocNodeParent(P);
}

void deleteAfterParent(listParent &L, NodeParent Pre) {
    if (Pre == NULL || Pre->next == NULL) return;
    NodeParent P = Pre->next;
    Pre->next = P->next;
    if (P->next == NULL) L.last = Pre;
    else P->next->prev = Pre;
    P->next = NULL; P->prev = NULL;
    deallocNodeParent(P);
}

void insertFirstChild(listChild &L, NodeChild C) {
    if (isEmptyChild(L)) L.first = L.last = C;
    else {
        C->next = L.first;
        L.first->prev = C;
        L.first = C;
    }
}

void insertLastChild(listChild &L, NodeChild C) {
    if (isEmptyChild(L)) L.first = L.last = C;
    else {
        L.last->next = C;
        C->prev = L.last;
        L.last = C;
    }
}

void deleteFirstChild(listChild &L) {
    if (isEmptyChild(L)) return;
    NodeChild C = L.first;
    if (L.first == L.last) {
        L.first = L.last = NULL;
    } else {
        L.first = C->next;
        L.first->prev = NULL;
        C->next = NULL;
    }
    deallocNodeChild(C);
}

void deleteAfterChild(listChild &L, NodeChild Pre) {
    if (Pre == NULL || Pre->next == NULL) return;
    NodeChild C = Pre->next;
    Pre->next = C->next;
    if (C->next == NULL) L.last = Pre;
    else C->next->prev = Pre;
    C->next = NULL; C->prev = NULL;
    deallocNodeChild(C);
}

void deleteListChild(listChild &L) {
    while (!isEmptyChild(L)) deleteFirstChild(L);
}

void printMLLStructure(listParent L) {
    NodeParent P = L.first;
    int i = 1;
    while (P != NULL) {
        cout << "=== Parent " << i++ << " ===" << endl;
        cout << "ID Golongan : " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;
        
        if (isEmptyChild(P->L_Child)) cout << "(tidak ada child)" << endl;
        else {
            NodeChild C = P->L_Child.first;
            int j = 1;
            while (C != NULL) {
                cout << " - Child " << j++ << " :" << endl;
                cout << "     ID Hewan : " << C->isidata.idHewan << endl;
                cout << "     Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "     Habitat : " << C->isidata.habitat << endl;
                cout << "     Ekor : " << C->isidata.ekor << endl;
                cout << "     Bobot : " << C->isidata.bobot << endl;
                C = C->next;
            }
        }
        cout << endl;
        P = P->next;
    }
}
```

### MultiLL.h
```C++
#ifndef MULTILL_H
#define MULTILL_H

#include <iostream>
#include <string>

using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);

void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);

void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);

void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);

void printMLLStructure(listParent LParent);
void deleteListChild(listChild &LChild);

#endif
```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided1_1](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week3/Screenshot%20Output%20Unguided1.png)

##### Output 2
![Screenshot Output Unguided1_1](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week3/Screenshot%20Output%20Unguided1.png)

Program tersebut mengimplementasikan struktur data mmulti linked list yang di mana digunakan untuk mengellola data hewan yang dikelompokkan berdasarkan golongan. Struktur data ini mempunyai dua level yaitu parent list yang berisikan golongan hewan, dan child yang berisikan hewan hewan individual dalam setiap golongan. Di struktur data parent, tiap node nya menyimpan informasi golongan hewan seperti ID dan nama golongan. Serta parent list diimplementasikan sebagai double linked list yang di mana setiap node memiliki pointer ke node sebelumnya dan sesudahnya, serta pointer first dan last untuk akses cepat ke awal dan akhir list. Untuk tiap parent node juga punya child list masing masing yang menyimpan nama nama hewan yang termasuk ke dalam golongan tersebut. Child list di contohkan sebagai double linked list yang di mana setiap node nya menyimpan data lengkap hewan, habitat, keberadaan, dan bobot.




### 2. Prosedur pencarian hewan berdasarkan ekor false

### main.cpp
```C++
#include "MultiLL.h"
int main() {
    listParent LP;
    createListParent(LP);
    NodeParent P1 = allocNodeParent("G001", "Aves");
    insertLastParent(LP, P1);
    NodeChild C1_1 = allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
    insertLastChild(P1->L_Child, C1_1);
    NodeChild C1_2 = allocNodeChild("AV002", "Bebek", "Air", true, 2);
    insertLastChild(P1->L_Child, C1_2);
    NodeParent P2 = allocNodeParent("G002", "Mamalia");
    insertLastParent(LP, P2);
    NodeChild C2_1 = allocNodeChild("M001", "Harimau", "Hutan", true, 200);
    insertLastChild(P2->L_Child, C2_1);
    NodeChild C2_2 = allocNodeChild("M003", "Gorila", "Hutan", false, 160);
    insertLastChild(P2->L_Child, C2_2);
    NodeChild C2_3 = allocNodeChild("M002", "Kucing", "Darat", true, 4);
    insertLastChild(P2->L_Child, C2_3);
    NodeParent P3 = allocNodeParent("G003", "Pisces");
    insertLastParent(LP, P3);
    NodeParent P4 = allocNodeParent("G004", "Amfibi");
    insertLastParent(LP, P4);
    NodeChild C4_1 = allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2);
    insertLastChild(P4->L_Child, C4_1);
    NodeParent P5 = allocNodeParent("G005", "Reptil");
    insertLastParent(LP, P5);
    printMLLStructure(LP);
    cout << endl << ">>> HASIL PENCARIAN HEWAN (EKOR = FALSE) <<<" << endl;
    searchHewanByEkor(LP, false);
    return 0;
}
```

### MultiLL.cpp
```C++
#include "MultiLL.h"

bool isEmptyParent(listParent L) { return L.first == NULL; }
bool isEmptyChild(listChild L) { return L.first == NULL; }

void createListParent(listParent &L) { L.first = NULL; L.last = NULL; }
void createListChild(listChild &L) { L.first = NULL; L.last = NULL; }
NodeParent allocNodeParent(string id, string nama) {
    NodeParent P = new nodeParent;
    P->isidata = {id, nama};
    P->next = NULL; P->prev = NULL;
    createListChild(P->L_Child);
    return P;
}
NodeChild allocNodeChild(string id, string nama, string hab, bool ekor, float brt) {
    NodeChild C = new nodeChild;
    C->isidata = {id, nama, hab, ekor, brt};
    C->next = NULL; C->prev = NULL;
    return C;
}
void deallocNodeParent(NodeParent &P) { delete P; P = NULL; }
void deallocNodeChild(NodeChild &C) { delete C; C = NULL; }

void insertFirstParent(listParent &L, NodeParent P) {
    if (isEmptyParent(L)) L.first = L.last = P;
    else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}
void insertLastParent(listParent &L, NodeParent P) {
    if (isEmptyParent(L)) L.first = L.last = P;
    else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}
void deleteFirstParent(listParent &L) {
    if (isEmptyParent(L)) return;
    NodeParent P = L.first;
    if (L.first == L.last) {
        L.first = L.last = NULL;
    } else {
        L.first = P->next;
        L.first->prev = NULL;
        P->next = NULL;
    }
    deallocNodeParent(P);
}
void deleteAfterParent(listParent &L, NodeParent Pre) {
    if (Pre == NULL || Pre->next == NULL) return;
    NodeParent P = Pre->next;
    Pre->next = P->next;
    if (P->next == NULL) L.last = Pre;
    else P->next->prev = Pre;
    P->next = NULL; P->prev = NULL;
    deallocNodeParent(P);
}
void insertFirstChild(listChild &L, NodeChild C) {
    if (isEmptyChild(L)) L.first = L.last = C;
    else {
        C->next = L.first;
        L.first->prev = C;
        L.first = C;
    }
}
void insertLastChild(listChild &L, NodeChild C) {
    if (isEmptyChild(L)) L.first = L.last = C;
    else {
        L.last->next = C;
        C->prev = L.last;
        L.last = C;
    }
}
void deleteFirstChild(listChild &L) {
    if (isEmptyChild(L)) return;
    NodeChild C = L.first;
    if (L.first == L.last) {
        L.first = L.last = NULL;
    } else {
        L.first = C->next;
        L.first->prev = NULL;
        C->next = NULL;
    }
    deallocNodeChild(C);
}
void deleteAfterChild(listChild &L, NodeChild Pre) {
    if (Pre == NULL || Pre->next == NULL) return;
    NodeChild C = Pre->next;
    Pre->next = C->next;
    if (C->next == NULL) L.last = Pre;
    else C->next->prev = Pre;
    C->next = NULL; C->prev = NULL;
    deallocNodeChild(C);
}
void deleteListChild(listChild &L) {
    while (!isEmptyChild(L)) deleteFirstChild(L);
}
void searchHewanByEkor(listParent LParent, bool tail) {
    NodeParent P = LParent.first;
    int iP = 1;
    while (P != NULL) {
        NodeChild C = P->L_Child.first;
        int iC = 1;
        while (C != NULL) {
            if (C->isidata.ekor == tail) {
                cout << "Data ditemukan pada list anak dari node parent " << P->isidata.namaGolongan << " pada posisi ke-" << iC << "!" << endl;
                cout << "--- Data Child ---" << endl;
                cout << "ID Child : " << C->isidata.idHewan << endl;
                cout << "Posisi dalam list anak : posisi ke-" << iC << endl;
                cout << "Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "Habitat : " << C->isidata.habitat << endl;
                cout << "Ekor : " << C->isidata.ekor << endl;
                cout << "Bobot : " << C->isidata.bobot << endl;
                cout << "------------------------" << endl;
                cout << "--- Data Parent ---" << endl;
                cout << "ID Parent : " << P->isidata.idGolongan << endl;
                cout << "Posisi dalam list induk : posisi ke-" << iP << endl;
                cout << "Nama golongan : " << P->isidata.namaGolongan << endl;
                cout << "------------------------" << endl;
            }
            C = C->next;
            iC++;
        }
        P = P->next;
        iP++;
    }
}
void printMLLStructure(listParent L) {
    NodeParent P = L.first;
    int i = 1;
    while (P != NULL) {
        cout << "=== Parent " << i++ << " ===" << endl;
        cout << "ID Golongan : " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;
        
        if (isEmptyChild(P->L_Child)) cout << "(tidak ada child)" << endl;
        else {
            NodeChild C = P->L_Child.first;
            int j = 1;
            while (C != NULL) {
                cout << " - Child " << j++ << " :" << endl;
                cout << "     ID Hewan : " << C->isidata.idHewan << endl;
                cout << "     Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "     Habitat : " << C->isidata.habitat << endl;
                cout << "     Ekor : " << C->isidata.ekor << endl;
                cout << "     Bobot : " << C->isidata.bobot << endl;
                C = C->next;
            }
        }
        cout << endl;
        P = P->next;
    }
    
}
```

### MultiLL.h
```C++
#ifndef MULTILL_H
#define MULTILL_H
#include <iostream>
#include <string>
using namespace std;
struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};
struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;
struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};
struct listChild {
    NodeChild first;
    NodeChild last;
};
struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};
struct listParent {
    NodeParent first;
    NodeParent last;
};
bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);
NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);
void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);
void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);
void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);
void printMLLStructure(listParent LParent);
void deleteListChild(listChild &LChild);
void searchHewanByEkor(listParent LParent, bool tail);
#endif
```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided2](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week3/Screenshot%20Output%20Unguided2.png)

Kode ini merupakan pengembangan dari implementasi Multi-Linked List sebelumnya dengan penambahan fitur pencarian hewan berdasarkan karakteristik ekor. Struktur data tetap menggunakan arsitektur dua level dengan parent list untuk golongan hewan dan child list untuk data hewan individual, namun kali ini dilengkapi dengan fungsi pencarian yang lebih spesifik. Fungsi baru yang ditambahkan adalah searchHewanByEkor yang menerima parameter listParent dan nilai boolean tail untuk mencari semua hewan yang memiliki atau tidak memiliki ekor sesuai kriteria pencarian. Fungsi ini bekerja dengan melakukan traversal nested loop, dimana loop luar menelusuri setiap parent node (golongan hewan) dan loop dalam menelusuri setiap child node (hewan) dalam golongan tersebut. Setiap kali menemukan hewan yang sesuai dengan kriteria ekor yang dicari, fungsi akan menampilkan informasi lengkap baik data child maupun data parent-nya. Output dari fungsi pencarian menampilkan informasi secara terstruktur dan detail, mencakup posisi ditemukannya data dalam list, ID dan nama hewan, habitat, status ekor, bobot hewan, serta informasi parent berupa ID golongan, posisi dalam list induk, dan nama golongan. Sistem pencatatan posisi menggunakan counter yang diinisialisasi dari 1 dan bertambah setiap kali pointer berpindah ke node berikutnya.



### 3. Operasi delete

### main.cpp
```C++
#include "MultiLL.h"

int main() {
    listParent LP;
    createListParent(LP);
    NodeParent P1 = allocNodeParent("G001", "Aves");
    insertLastParent(LP, P1);
    insertLastChild(P1->L_Child, allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(P1->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2));
    NodeParent P2 = allocNodeParent("G002", "Mamalia");
    insertLastParent(LP, P2);
    insertLastChild(P2->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200));
    insertLastChild(P2->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160));
    insertLastChild(P2->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4));
    insertLastParent(LP, allocNodeParent("G003", "Pisces"));
    NodeParent P4 = allocNodeParent("G004", "Amfibi");
    insertLastParent(LP, P4);
    insertLastChild(P4->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));
    insertLastParent(LP, allocNodeParent("G005", "Reptil"));
    cout << ">>> DATA AWAL <<<" << endl;
    printMLLStructure(LP);
    cout << endl << ">>> HASIL PENCARIAN HEWAN (EKOR = FALSE) <<<" << endl;
    searchHewanByEkor(LP, false);
    cout << endl << ">>> DATA SETELAH DELETE PARENT G004 <<<" << endl;
    deleteParent(LP, "G004");
    printMLLStructure(LP);
    return 0;
}
```

### MultiLL.cpp
```C++
#include "MultiLL.h"
bool isEmptyParent(listParent L) { return L.first == NULL; }
bool isEmptyChild(listChild L) { return L.first == NULL; }
void createListParent(listParent &L) { L.first = NULL; L.last = NULL; }
void createListChild(listChild &L) { L.first = NULL; L.last = NULL; }
NodeParent allocNodeParent(string id, string nama) {
    NodeParent P = new nodeParent;
    P->isidata = {id, nama};
    P->next = NULL; P->prev = NULL;
    createListChild(P->L_Child);
    return P;
}
NodeChild allocNodeChild(string id, string nama, string hab, bool ekor, float brt) {
    NodeChild C = new nodeChild;
    C->isidata = {id, nama, hab, ekor, brt};
    C->next = NULL; C->prev = NULL;
    return C;
}
void deallocNodeParent(NodeParent &P) { delete P; P = NULL; }
void deallocNodeChild(NodeChild &C) { delete C; C = NULL; }
void insertFirstParent(listParent &L, NodeParent P) {
    if (isEmptyParent(L)) L.first = L.last = P;
    else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}
void insertLastParent(listParent &L, NodeParent P) {
    if (isEmptyParent(L)) L.first = L.last = P;
    else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}
void deleteFirstParent(listParent &L) {
    if (isEmptyParent(L)) return;
    NodeParent P = L.first;
    if (L.first == L.last) {
        L.first = L.last = NULL;
    } else {
        L.first = P->next;
        L.first->prev = NULL;
        P->next = NULL;
    }
    deallocNodeParent(P);
}
void deleteAfterParent(listParent &L, NodeParent Pre) {
    if (Pre == NULL || Pre->next == NULL) return;
    NodeParent P = Pre->next;
    Pre->next = P->next;
    if (P->next == NULL) L.last = Pre;
    else P->next->prev = Pre;
    P->next = NULL; P->prev = NULL;
    deallocNodeParent(P);
}
void deleteParent(listParent &L, string id) {
    NodeParent P = L.first;
    if (P != NULL && P->isidata.idGolongan == id) {
        deleteListChild(P->L_Child);
        deleteFirstParent(L);
        return;
    }
    while (P != NULL && P->next != NULL) {
        if (P->next->isidata.idGolongan == id) {
            deleteListChild(P->next->L_Child);
            deleteAfterParent(L, P);
            return;
        }
        P = P->next;
    }
}
void insertFirstChild(listChild &L, NodeChild C) {
    if (isEmptyChild(L)) L.first = L.last = C;
    else {
        C->next = L.first;
        L.first->prev = C;
        L.first = C;
    }
}
void insertLastChild(listChild &L, NodeChild C) {
    if (isEmptyChild(L)) L.first = L.last = C;
    else {
        L.last->next = C;
        C->prev = L.last;
        L.last = C;
    }
}
void deleteFirstChild(listChild &L) {
    if (isEmptyChild(L)) return;
    NodeChild C = L.first;
    if (L.first == L.last) {
        L.first = L.last = NULL;
    } else {
        L.first = C->next;
        L.first->prev = NULL;
        C->next = NULL;
    }
    deallocNodeChild(C);
}
void deleteAfterChild(listChild &L, NodeChild Pre) {
    if (Pre == NULL || Pre->next == NULL) return;
    NodeChild C = Pre->next;
    Pre->next = C->next;
    if (C->next == NULL) L.last = Pre;
    else C->next->prev = Pre;
    C->next = NULL; C->prev = NULL;
    deallocNodeChild(C);
}
void deleteListChild(listChild &L) {
    while (!isEmptyChild(L)) deleteFirstChild(L);
}
void printMLLStructure(listParent L) {
    NodeParent P = L.first;
    int i = 1;
    while (P != NULL) {
        cout << "=== Parent " << i++ << " ===" << endl;
        cout << "ID Golongan : " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;
        
        if (isEmptyChild(P->L_Child)) cout << "(tidak ada child)" << endl;
        else {
            NodeChild C = P->L_Child.first;
            int j = 1;
            while (C != NULL) {
                cout << " - Child " << j++ << " :" << endl;
                cout << "     ID Hewan : " << C->isidata.idHewan << endl;
                cout << "     Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "     Habitat : " << C->isidata.habitat << endl;
                cout << "     Ekor : " << C->isidata.ekor << endl;
                cout << "     Bobot : " << C->isidata.bobot << endl;
                C = C->next;
            }
        }
        cout << "--------------------" << endl;
        P = P->next;
    }
}
void searchHewanByEkor(listParent L, bool tail) {
    NodeParent P = L.first;
    int iP = 1;
    while (P != NULL) {
        NodeChild C = P->L_Child.first;
        int iC = 1;
        while (C != NULL) {
            if (C->isidata.ekor == tail) {
                cout << "Data ditemukan pada list anak dari node parent " << P->isidata.namaGolongan << " pada posisi ke-" << iC << "!" << endl;
                cout << "--- Data Child ---" << endl;
                cout << "ID Child : " << C->isidata.idHewan << endl;
                cout << "Posisi dalam list anak : posisi ke-" << iC << endl;
                cout << "Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "Habitat : " << C->isidata.habitat << endl;
                cout << "Ekor : " << C->isidata.ekor << endl;
                cout << "Bobot : " << C->isidata.bobot << endl;
                cout << "------------------------" << endl;
                cout << "--- Data Parent ---" << endl;
                cout << "ID Parent : " << P->isidata.idGolongan << endl;
                cout << "Posisi dalam list induk : posisi ke-" << iP << endl;
                cout << "Nama golongan : " << P->isidata.namaGolongan << endl;
                cout << "------------------------" << endl;
            }
            C = C->next;
            iC++;
        }
        P = P->next;
        iP++;
    }
}
```

### MultiLL.h
```C++
#ifndef MULTILL_H
#define MULTILL_H
#include <iostream>
#include <string>
using namespace std;
struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};
struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};
typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;
struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};
struct listChild {
    NodeChild first;
    NodeChild last;
};
struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};
struct listParent {
    NodeParent first;
    NodeParent last;
};
bool isEmptyParent(listParent L);
bool isEmptyChild(listChild L);
void createListParent(listParent &L);
void createListChild(listChild &L);
NodeParent allocNodeParent(string id, string nama);
NodeChild allocNodeChild(string id, string nama, string hab, bool ekor, float brt);
void deallocNodeParent(NodeParent &P);
void deallocNodeChild(NodeChild &C);
void insertFirstParent(listParent &L, NodeParent P);
void insertLastParent(listParent &L, NodeParent P);
void deleteFirstParent(listParent &L);
void deleteAfterParent(listParent &L, NodeParent Pre);
void deleteParent(listParent &L, string id);
void insertFirstChild(listChild &L, NodeChild C);
void insertLastChild(listChild &L, NodeChild C);
void deleteFirstChild(listChild &L);
void deleteAfterChild(listChild &L, NodeChild Pre);
void deleteListChild(listChild &L);
void printMLLStructure(listParent L);
void searchHewanByEkor(listParent L, bool tail);
#endif
```

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided2](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week3/Screenshot%20Output%20Unguided2.png)

##### Output 2
![Screenshot Output Unguided2](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week3/Screenshot%20Output%20Unguided2.png)

Fungsi baru yang menjadi fokus utama adalah deleteParent yang menerima parameter listParent dan string ID untuk mencari dan menghapus parent node tertentu. Fungsi ini dirancang dengan logika yang cermat untuk menangani berbagai kasus penghapusan: jika node yang akan dihapus berada di posisi pertama, fungsi akan memanggil deleteFirstParent, sedangkan untuk posisi lainnya akan menggunakan deleteAfterParent. Yang sangat penting adalah sebelum menghapus parent node, fungsi ini terlebih dahulu memanggil deleteListChild untuk menghapus semua child node yang terkait, memastikan tidak ada memory leak dan menjaga integritas struktur data. Proses pencarian node dilakukan dengan traversal linear dari awal list hingga menemukan node dengan ID yang sesuai. Program utama mendemonstrasikan tiga operasi utama secara berurutan untuk memberikan gambaran lengkap tentang fungsionalitas sistem. Pertama, program menampilkan data awal yang berisi lima golongan hewan dengan berbagai anggotanya menggunakan fungsi printMLLStructure. Kedua, program melakukan pencarian hewan yang tidak memiliki ekor dengan memanggil searchHewanByEkor dan parameter false, yang akan menemukan Gorila dari golongan Mamalia dan Kodok dari golongan Amfibi. Ketiga, program menghapus golongan Amfibi dengan ID "G004" menggunakan fungsi deleteParent, yang secara otomatis juga menghapus Kodok sebagai anggota satu-satunya dari golongan tersebut.


## Kesimpulan
Multi Linked List merupakan struktur data lanjutan yang memungkinkan setiap node memiliki lebih dari satu pointer, sehingga mampu merepresentasikan hubungan data yang kompleks dan hierarkis. Dalam praktikum ini, implementasi Multi Linked List diterapkan pada sistem pengelolaan data hewan yang diorganisir berdasarkan golongan, dengan menggunakan arsitektur dua level yaitu parent list untuk golongan hewan dan child list untuk data hewan individual. Struktur data ini diimplementasikan menggunakan doubly linked list baik untuk parent maupun child, yang memberikan fleksibilitas dalam melakukan traversal dua arah dan efisiensi dalam operasi insert serta delete. Setiap parent node tidak hanya menyimpan informasi golongan hewan, tetapi juga memiliki child list tersendiri yang menampung multiple hewan dengan atribut lengkap seperti ID, nama, habitat, status ekor, dan bobot. Keunggulan Multi Linked List terletak pada fleksibilitasnya dalam merepresentasikan relasi one-to-many antara parent dan child, kemampuan menelusuri data melalui berbagai jalur pointer, dan efisiensi dalam mengelola data hierarkis. Meskipun lebih kompleks dalam implementasi dan pemeliharaan dibandingkan struktur data sederhana, Multi Linked List sangat efektif untuk aplikasi yang memerlukan representasi hubungan data yang rumit seperti sistem kategorisasi, database relasional sederhana, atau struktur organisasi bertingkat.




## Referensi
<br>[1] S. H. K. Patel and A. J. Mahariba, “Word Search Puzzle using Multi-Linked Lists,” International Journal of Engineering and Advanced Technology (IJEAT), vol. 8, no. 4S2, pp. 12–18, Apr. 2019, doi:10.35940/ijeat.D1005.0484S219. :contentReference[oaicite:16]{index=16}

<br>[2]Patel, S. H. K., & Mahariba, A. J. (2019). Word Search Puzzle using Multi-Linked Lists. International Journal of Engineering and Advanced Technology (IJEAT), 8(4S2), 12–18. https://doi.org/10.35940/ijeat.D1005.0484S219 :contentReference[oaicite:17]{index=17}


