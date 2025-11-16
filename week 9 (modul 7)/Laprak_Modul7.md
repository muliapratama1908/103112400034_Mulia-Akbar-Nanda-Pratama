# <h1 align="center"> Laporan Praktikum Modul 7 - Stack </h1>
<p align="center">Mulia Akbar Nanda Pratama - 103112400034</p>

## Dasar Teori
Stack merupakan struktur data dasar dalam pemrograman yang bekerja seperti tumpukan barang: elemen yang terakhir masuk akan keluar lebih dulu. Secara sederhana, stack adalah struktur data linier yang digunakan untuk menyimpan sekumpulan objek atau variabel [1]. Setiap penambahan data (push) dan penghapusan data (pop) terjadi di ujung atas tumpukan. Sifat khas stack adalah LIFO (last in, first out): data yang paling terakhir masuk akan menjadi data yang paling awal keluar [1]. Stack sering digunakan dalam berbagai konteks, misalnya pada saat panggilan fungsi dan rekursi, setiap pemanggilan fungsi disimpan dalam stack hingga fungsi tersebut selesai dieksekusi [1]. Perlu diketahui, dalam struktur data stack ada dua kondisi yang perlu dihindari, yaitu underflow dan overflow [2]. Stack underflow itu di mana keadaan kita mencoba untuk mengakses atau menghapus elemen data pada stack yang kosong [2]. Dan untuk stack overflow itu keadaan ruang memori yang dialokasikan untuk struktur data stack sudah penuh namun masih dilakukan operasi penyisipan elemen [2].

## Karakteristik dan operasi stack. Karakteristik utama stack adalah aturan LIFO. Berikut operasi  yang biasa digunakan pada stack:
1. Push: menambahkan elemen baru ke bagian atas stack. Misalnya, menumpuk buku baru di atas tumpukan.
2. Pop: menghapus elemen di paling atas stack dan mengembalikan nilainya. Artinya, buku yang paling atas diambil keluar.
3. Peek/Top: melihat atau mengintip elemen paling atas tanpa menghapusnya. Seperti mengintip buku paling atas tanpa mengambilnya.
4. IsEmpty: memeriksa apakah stack kosong atau tidak.
5. Size: mengembalikan jumlah elemen ddalam stack. Berguna untuk mengetahui seberapa tinggi tumpukan saat ini [1].

Operasi-operasi di atas dijalankan dari satu sisi stack (ujung atas). Contohnya, operasi push tidak boleh menambah data di bagian bawah tumpukan, dan pop hanya bisa menghapus dari atas. Hal ini membuat stack berbeda dengan struktur lain (misalnya queue) yang dapat menghapus dari ujung depan. Misalnya pada stack, hanya elemen terakhir yang dapat diakses atau dikeluarkan tanpa membongkar seluruh data di bawahnya.

Karakteristik LIFO juga berarti stack tidak mendukung akses acak. Untuk mengambil elemen tertentu, kita harus mengeluarkan semua elemen di atasnya terlebih dahulu. Kekurangan ini merupakan batasan yang wajar karena desain stack memang fokus pada penyimpanan sementara untuk urutan tugas tertentu (misalnya dalam pemanggilan fungsi) [1].

## Implementasi Stack
Dalam pemrograman, stack bisa diimplementasikan menggunakan berbagai cara. Dua cara umum adalah menggunakan array atau menggunakan linked list. Pilihan implementasi tergantung pada kebutuhan memori, fleksibilitas, dan kemudahan penggunaan [1].

## Implementasi Stack dengan Array
Implementasi stack dengan array adalah salah satu yang paling sederhana. Kita menggunakan array dengan ukuran tetap untuk menampung elemen stack, serta variabel top untuk menunjuk indeks elemen teratas [1].

## Jenis-jenis stack
Berdasarkan kemampuan menyimpan data stack sendirri itu dapat dibagi menjadi 2 jenis yaitu register stack dan memory stack [2]. Register stack sendiri merupakan stack yang hanya mampu menampung data dalam jumlah  yang kecil. Keadalaman maksimum pada register cenderung dibatasi karena ukuran unit memorinya itu kecil dibandingkan dengan jenis stack yang lain [2]. Yang kedua itu ada memory stack, pada jenis stack ini kedalaman dari stack lebih fleksibel dan mampu menangani dalam skala yang lebih besar dibandingkan dengan jenis sebelumnya [2].

## Karakteristik stack
- Stack digunakan pada  banyak algoritma yang berbeda seperti Tower of Hanoi, Tree traversal, rekursi dll [2].
- Stack diimplementasikan dengan struktur data array atau linked list [2].
- Mengikuti prinsip operasi Last In First Out, yaitu elemen yang dimasukkan pertama akan muncul terakhir dan sebaliknya [2].
- Penyisipan dan penghapusan terjadi di satu ujung yaitu dari atas tumpukan [2].
- Apabila ruang memori yang dialokasikan untuk struktur data stack sudah penuh namun masih dilakukan operasi penyisipan elemen maka akan terjadi stack overflow [2].
- Apabila struktur data tidak memiliki elemen data atau kosong, namun tetap dilakukan operasi penghapusan maka akan terjadi stack underflow [2]



## Guided
### 1. Guided 1

### main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```

### stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        int data = nodeHapus->dataAngka;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  data << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi <= 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){ //mencetak dari tumpukan paling atas ke tumpukan paling bawah
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```

### stack.h
```C++
#ifndef STACK_H
#define STACK_H
#define Nil NULL    

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);
void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif 
```
Deskripsi: Program tersebut mengimplementasikan stack dengan menggunakan linked list. Stack sendiri merupakan struktur data bertipe LIFO (Last In, First Out), yang artinya elemen yang paling akhir masuk maka itu elemen yang paling awal diambil. Implementasi tersebut menggunakan pointer untuk menghubungkan node satu dengan yg lain, yang di setiap node tersebut menyimpan sebuah angka dan pointer yang menunjuk ke elemen atau node setelahnya. Dan di program tersebut terdapat beberapa fungsi utama diantaranya createStack(), alokasi(), push(), pop(), update(), view(), dan searchData().



### 2. Guided 2

### maincpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    cout << "Stack Awal:" << endl;
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    cout << "Stack Setelah dibalik:" << endl;
    printInfo(S);

    return 0;
}
```

### stack.cpp
```C++
#include "stack.h"
using namespace std;
// Fungsi untuk membuat stack baru dengan menginisialisasi top = Nil
void CreateStack(Stack &S) {
    S.top = Nil;  // Inisialisasi top dengan nilai Nil mendakan stack kosong
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(Stack S) {
    return S.top == Nil;  // Mengembalikan true jika top bernilai Nil, false jika tidak
}

// Fungsi untuk mengecek apakah stack penuh
bool isFull(Stack S) {
    return S.top == MaxEl - 1;  // Mengembalikan true jika top mencapai batas maksimum (MaxEl-1)
}

// Fungsi untuk menambah elemen ke dalam stack (push)
void push(Stack &S, infotype x) {
    if (!isFull(S)) {  // Cek apakah stack belum penuh
        S.top++;  // Increment nilai top
        S.info[S.top] = x;  // Masukkan nilai x ke array info pada indeks top
    } else {
        cout << "Stack Penuh!" << endl;  // Tampilkan pesan jika stack penuh
    }
}

// Fungsi untuk mengambil elemen teratas dari stack (pop)
infotype pop(Stack &S) {
    infotype x = -999;  // Inisialisasi nilai default jika stack kosong
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        x = S.info[S.top];  // Ambil nilai teratas
        S.top--;  // Decrement nilai top
    } else {
        cout << "Stack Kosong!" << endl;  // Tampilkan pesan jika stack kosong
    }
    return x;  // Kembalikan nilai yang diambil
}

// Fungsi untuk menampilkan isi stack
void printInfo(Stack S) {
    if (isEmpty(S)) {  // Cek apakah stack kosong
        cout << "Stack Kosong" << endl;  // Tampilkan pesan jika kosong
    } else {
        cout << "[TOP] ";  // Tampilkan penanda posisi top
        for (int i = S.top; i >= 0; i--) {  // Loop dari top sampai dasar stack
            cout << S.info[i] << " ";  // Tampilkan setiap elemen
        }
        cout << endl;  // Pindah baris setelah selesai
    }
}

// Fungsi untuk membalik urutan elemen dalam stack
void balikStack(Stack &S) {
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        Stack temp1, temp2;  // Deklarasi dua stack temporary
        CreateStack(temp1); CreateStack(temp2);  // Inisialisasi kedua stack temporary

        while (!isEmpty(S)) { push(temp1, pop(S)); }  // Pindahkan semua elemen ke temp1 (urutan terbalik)

        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }  // Pindahkan ke temp2 (urutan terbalik lagi)

        while (!isEmpty(temp2)) { push(S, pop(temp2)); }  // Kembalikan ke stack asal (urutan sudah benar)
    }
}

```

### stack.h
```C++
#ifndef STACK_H
#define STACK_H

#include<iostream>
#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack{
    infotype info[MaxEl];
    int top;
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif
```
Deskripsi: Program yang mengimplementasi struktur data stack dengan menggunakan representasi array statis dengan kapasitas maksimum nya 20 elemen.



## Unguided 

### 1. ADT stack menggunakan array
### main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack S;
    CreateStack(S);
    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);
    cout << "Hello world!:" << endl;
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```

### stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

void CreateStack(Stack &S) {
    S.top = Nil;
}

bool isEmpty(Stack S) {
    return S.top == Nil;
}

bool isFull(Stack S) {
    return S.top == MaxEl - 1;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack Penuh!" << endl;
    }
}

infotype pop(Stack &S) {
    if (!isEmpty(S)) {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    } else {
        return Nil;
    }
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack Kosong" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    if (!isEmpty(S)) {
        Stack temp1, temp2;
        CreateStack(temp1);
        CreateStack(temp2);

        while (!isEmpty(S)) {
            push(temp1, pop(S));
        }

        while (!isEmpty(temp1)) {
            push(temp2, pop(temp1));
        }

        while (!isEmpty(temp2)) {
            push(S, pop(temp2));
        }
    }
}
```

### stack.h
```C++
#ifndef STACK_H
#define STACK_H
#include <iostream>
#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack {
    infotype info[MaxEl];
    int top;
};
void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif
```
Program implementasi stack berbasis array. Program utama berjalan di main.cpp yang melakukan operasi push dan pop sehingga menghasilkan stack dengan isi akhir dari bawah ke atas. Program akan cetak stack tersebut lalu membalikkan urutannya menggunakan fungsi balikStack dan kemudian di cetaknya lagi.

### Output Unguided 1 :

##### Output 1
![un 1](https://github.com/muliapratama1908/103112400034_Mulia-Akbar-Nanda-Pratama/blob/main/week%209%20(modul%207)/un%201.jpeg)



### 2. penambahan prosedur pushAscending

### main.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    CreateStack(S);
    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    
    return 0;
}
```

### stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

void CreateStack(Stack &S) {
    S.top = Nil;
}

bool isEmpty(Stack S) {
    return S.top == Nil;
}

bool isFull(Stack S) {
    return S.top == MaxEl - 1;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack Penuh!" << endl;
    }
}

infotype pop(Stack &S) {
    if (!isEmpty(S)) {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    } else {
        return Nil;
    }
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack Kosong" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    if (!isEmpty(S)) {
        Stack temp1, temp2;
        CreateStack(temp1);
        CreateStack(temp2);

        while (!isEmpty(S)) {
            push(temp1, pop(S));
        }

        while (!isEmpty(temp1)) {
            push(temp2, pop(temp1));
        }

        while (!isEmpty(temp2)) {
            push(S, pop(temp2));
        }
    }
}

void pushAscending(Stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack Penuh!" << endl;
    } else {
        Stack tempStack;
        CreateStack(tempStack);

        while (!isEmpty(S) && S.info[S.top] > x) {
            push(tempStack, pop(S));
        }
        
        push(S, x);
        
        while (!isEmpty(tempStack)) {
            push(S, pop(tempStack));
        }
    }
}
```

### stack.h
```C++
#ifndef STACK_H
#define STACK_H
#include <iostream>
#define MaxEl 20
#define Nil -1
typedef int infotype;
struct Stack {
    infotype info[MaxEl];
    int top;
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);

#endif
```
Program tersebut tidak beda jauh dibanding program sebelumnya, hanya saja program tersebut ditambahkan pushAscending untuk memasukkan elemen baru ke dalam stack namun tetap menjaga agar isinya selalu terurut dari nilai yang besar ke yang terkecil.

### Output Unguided 2 :

##### Output 1
![un 2](https://github.com/muliapratama1908/103112400034_Mulia-Akbar-Nanda-Pratama/blob/main/week%209%20(modul%207)/un%202.jpeg)



### 3. penambahan prosedur getInputStream

### main.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    CreateStack(S);
    getInputStream(S);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    
    return 0;
}
```

### stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

void CreateStack(Stack &S) {
    S.top = Nil;
}

bool isEmpty(Stack S) {
    return S.top == Nil;
}

bool isFull(Stack S) {
    return S.top == MaxEl - 1;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack Penuh!" << endl;
    }
}

infotype pop(Stack &S) {
    if (!isEmpty(S)) {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    } else {
        return Nil;
    }
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack Kosong" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    if (!isEmpty(S)) {
        Stack temp1, temp2;
        CreateStack(temp1);
        CreateStack(temp2);

        while (!isEmpty(S)) {
            push(temp1, pop(S));
        }

        while (!isEmpty(temp1)) {
            push(temp2, pop(temp1));
        }

        while (!isEmpty(temp2)) {
            push(S, pop(temp2));
        }
    }
}

void pushAscending(Stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack Penuh!" << endl;
    } else {
        Stack tempStack;
        CreateStack(tempStack);

        while (!isEmpty(S) && S.info[S.top] > x) {
            push(tempStack, pop(S));
        }
        
        push(S, x);
        
        while (!isEmpty(tempStack)) {
            push(S, pop(tempStack));
        }
    }
}

void getInputStream(Stack &S) {
    char ch;
    infotype value;

    while (cin.get(ch) && ch != '\n') {
        if (ch >= '0' && ch <= '9') {
            value = ch - '0';
            push(S, value);
        }
    }
}
```

### stack.h
```C++
#ifndef STACK_H
#define STACK_H
#include <iostream>
#define MaxEl 20
#define Nil -1
typedef int infotype;
struct Stack {
    infotype info[MaxEl];
    int top;
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);

#endif
```
Program tersebut adalah program untuk membaca serangkaian digit yang diinput oleh pengguna, lalu memasukkannya ke dalam stack. Setelah semua digit masuk lalu program akan mencetak isi stack, lalu membalikkan urutan stack dan mencetaknya kembali dalam urutan yang sudah terbalik.

### Output Unguided 3 :

##### Output 1
![un 3](https://github.com/muliapratama1908/103112400034_Mulia-Akbar-Nanda-Pratama/blob/main/week%209%20(modul%207)/un%203.jpeg)



## Kesimpulan
Berdasarkan laporan di atas, dapat diambil kesimpulan bahwa stack adalah sttruktur data linear yang beroperasi dengan prinsip LIFO, yang di mana elemen yang paling terakhir masuk maka akan menjadi elemen yang paling awal muncul untuk dikeluarkan. Operasi dasar yang sering digunakan adalah push untuk menambahkan elemen dan pop untuk mengambil elemen yang keduanya dilakukan pada satu ujung yang biasa disebut dengan top. Melalui laporan praktikum tersebut, kita dapat mengimplementasikan berbagai fungsionalitas tambahan seperti fungsi balikStack yang berfungsi untuk membalik urutan seluruh elemen, penambahan prosedur pushAscending yang berfungsi untuk memasukkan elemen baru sambil menjaga agar isi stack tetap terurut, dan terakhir ada penambahan prosedur getInputStream yang berfungsi untuk baca serangkaian input digit dari pengguna dan memasukkannya ke dalam stack.


## Referensi
<br>[1] hhttps://www.codepolitan.com/blog/apa-itu-stack-dalam-ilmu-pemrograman/
<br>[2] https://www.trivusi.web.id/2022/07/struktur-data-stack.html


