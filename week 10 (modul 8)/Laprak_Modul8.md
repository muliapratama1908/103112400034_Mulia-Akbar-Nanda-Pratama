# <h1 align="center"> Laporan Praktikum Modul 8 - QUEUE </h1>
<p align="center">Mulia Akbar Nanda Pratama - 103112400034</p>

## Dasar Teori
Queue dalam bahasa Indonesia berarti antrian. Queue adalah struktur data yang menyusun elemen-elemen data dalam urutan linier [1]. Prinsip dasar dari queue adalah "First In, First Out" atau disingkat FIFO yang berarti elemen yang pertama masuk maka akan menjadi yang pertama juga untuk dikeluarkan [1]. Prinsip kerja FIFO pada queue itu sama seperti jejeran orang yang sedang menunggu antrean di bank yang di mana orang yang pertama data maka orang tersebut lah yang akan dilayani terlebih dahulu. Pada struktur data ini, urutan pertama atau data yang akan dikeluarkan disebut dengan front atau head. Sebaliknya, data pada urutan terakhir atau data yang baru saja ditambahkan biasa disebut dengan back, rear, atau tail. Proses untuk menambahkan data pada antrean disebut dengan enqueue, sedangkan proses untuk menghapus data dari antrean disebut dengan dequeue [1]. Fungsi dan kegunaan queue adalah queue banyak digunakan untuk menangani lalu lintas traffic situs web [2]. Queue dapat membantu untuk mempertahankan playlist yang ada pada aplikasi pemutar musik [2]. Queue juga igunakan dalam sistem operasi untuk menangani interupsi [2].


## Berikut adalah implementasi queue dalam bahasa c++ [2].

```C++
#include <iostream>
#define SIZE 5

using namespace std;

class Queue {
   private:
  int items[SIZE], front, rear;

   public:
  Queue() {
    front = -1;
    rear = -1;
  }

  bool isFull() {
    if (front == 0 && rear == SIZE - 1) {
      return true;
    }
    return false;
  }

  bool isEmpty() {
    if (front == -1)
      return true;
    else
      return false;
  }

  void enQueue(int element) {
    if (isFull()) {
      cout << "Queue is full";
    } else {
      if (front == -1) front = 0;
      rear++;
      items[rear] = element;
      cout << endl
         << "Inserted " << element << endl;
    }
  }

  int deQueue() {
    int element;
    if (isEmpty()) {
      cout << "Queue is empty" << endl;
      return (-1);
    } else {
      element = items[front];
      if (front >= rear) {
        front = -1;
        rear = -1;
      } /* Q has only one element, so we reset the queue after deleting it. */
      else {
        front++;
      }
      cout << endl
         << "Deleted -> " << element << endl;
      return (element);
    }
  }

  void display() {
    /* Function to display elements of Queue */
    int i;
    if (isEmpty()) {
      cout << endl
         << "Empty Queue" << endl;
    } else {
      cout << endl
         << "Front index-> " << front;
      cout << endl
         << "Items -> ";
      for (i = front; i <= rear; i++)
        cout << items[i] << "  ";
      cout << endl
         << "Rear index-> " << rear << endl;
    }
  }
};

int main() {
  Queue q;

  //deQueue is not possible on empty queue
  q.deQueue();

  //enQueue 5 elements
  q.enQueue(1);
  q.enQueue(2);
  q.enQueue(3);
  q.enQueue(4);
  q.enQueue(5);

  // 6th element can't be added to because the queue is full
  q.enQueue(6);

  q.display();

  //deQueue removes element entered first i.e. 1
  q.deQueue();

  //Now we have just 4 elements
  q.display();

  return 0;
} 
```


## Jenis-jenis queue
Secara umum ada 4 jenis struktur data queue, diantaranya:
- Simple queue: struktur data queue paling dasar yang di mana penyisipan item dilakukan di simpul belakang dan  penghapusan terjadi disimpul depan [2].

- Circular queue: simpul terakhir terhubung ke simpul pertama. Queue jenis ini juga dikenal sebagai ring buffer karena semua ujungnya terhubung ke ujung yang lain. Penyisipan terjadi di akhir antrian dan penghapusan terjadi di depan antrian [2].

- Priority queue: struktur data queue yang di mana simpul akan memiliki beberapa prioritas yang telah ditentukan. Simpul dengan priortitas terbesar akan menjadi yang pertama dihapus dari antrian. Sedangkan penyisipan item terjadi sesuai urutan kedatangannya. 

- Double ended queue (dequeue): operasi penyisipan dapat terjadi di ujung depan dan belakang dari queue [2].

## Keuntungan dan keterbatasan
- Keuntungan
1. Data berjumlah besar dapat dikelola dengan mudah dan efisien [1].
2. Proses insert dan delete data dapat dilakukan dengan mudah karena mengikuti aturan first in first out (FIFO) [1].
3. Efisien dalam menangani tugas    berdasarkan urutan kedatangan [1].

- Keterbatasan
1. Tidak efisien untuk pencarian elemen tertentu dalam antrean [1].
2. Memerlukan alokasi memori yang cukup untuk menyimpan antrean [1].

## Operasi dasar pada queue
- enqueue: menambahkan elemen ke akhir antrian [2].
```C++
procedure enqueue (data)
 

if queue is full

return overflow

endif

rear ← rear + 1

queue[rear] ← data

return true

end procedure
```
- dequeue: menghapus elemen dari depan antrian [2].
```C++
procedure dequeue
 

if queue is empty

return underflow

end if

data = queue[front]

front ← front + 1

return true

end procedure
```

- isempty: memeriksa apakah ada antrian kosong [2].
- isfull: memeriksa apakah antrian sudah penuh [2].
- peek: mendapatkan nilai bagian depan antrian tanpa menghapusnya [2].
- initialize: membuat antrian baru tanpa elemen data atau kosong [2].




## Guided
### 1. Guided 1

### main.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main(){
    queue Q;
    address nodeA, nodeB, nodeC, nodeD, nodeE = NIL;
    createQueue(Q);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3); 
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    enQueue(Q, nodeA);
    enQueue(Q, nodeB);
    enQueue(Q, nodeC);
    enQueue(Q, nodeD);
    enQueue(Q, nodeE);
    cout << endl;

    cout << "--- Queue setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Queue setelah deQueue 2 kali ---" << endl;
    viewQueue(Q);
    cout << endl;

    updateQueue(Q, 2);
    updateQueue(Q, 1);
    updateQueue(Q, 4);
    cout << endl;

    cout << "--- Queue setelah update ---" << endl;
    viewQueue(Q);
    cout << endl;

    searchData(Q, 4);
    searchData(Q, 9);
    return 0;
}
```

### queue.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == NIL){
        return true;
    } else {
        return false;
    }
}

void createQueue(queue &Q){
    Q.head =  Q.tail = NIL;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = NIL;
}

void dealokasi(address &node){
    node->next = NIL;
    delete node;
}

void enQueue(queue &Q, address nodeBaru){
    if(isEmpty(Q) == true){
        Q.head = Q.tail = nodeBaru;
    } else {
        Q.tail->next = nodeBaru;
        Q.tail = nodeBaru;
    }
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q){
    address nodeHapus;
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        nodeHapus = Q.head;
        Q.head = Q.head->next;
        nodeHapus->next = NIL;
        if(Q.head == NIL){
            Q.tail = NIL;
        }
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari queue!" << endl;
    }
}

void updateQueue(queue &Q, int posisi){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = Q.head;
            int count = 1;
            bool found = false;
            while(nodeBantu != NIL){
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

void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        while(nodeBantu != NIL){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(queue Q, int data){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != NIL){
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
            cout << "Data " << data << " tidak ditemukan didalam queue!" << endl;
            cout << endl;
        }
    }
}
```

### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define NIL NULL  

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct queue{
    address head;
    address tail;
};

bool isEmpty(queue Q);
void createQueue(queue &Q);
address alokasi(int angka);
void dealokasi(queue &node);

void enQueue(queue &Q, address nodeBaru);
void deQueue(queue &Q);
void updateQueue(queue &Q, int posisi);
void viewQueue(queue Q);
void searchData(queue Q, int data);

#endif
```
Deskripsi: Program tersebut merupakan implementasi queue menggunakan linked list. Struktur queue diartikan dengan dua penunjuk yaitu head dan tail yang mengacu pada node pertama dan terakhir dalam antrian. Setiap node nya bisa menyimpan berupa data integer dan penunjuk ke node selanjutnya atau next. Program tersebut menyediakan berbagai fungsi dasar dalam struktur data queue seperti createQueue, isEmpty, alokasi, dealokasi.



### 2. Guided 2

### maincpp
```C++
#include<iostream>
#include "queue.h"
using namespace std;

int main() {
    Queue Q;
    createQueue(Q);
    printInfo(Q);

    cout<<"\n enqueue 3 elemen"<< endl;
    enqueue(Q, 5);
    printInfo(Q);
    enqueue(Q, 2);
    printInfo(Q);
    enqueue(Q, 7);
    printInfo(Q);
    cout<<"\n dequeue 1 elemen"<< endl;
    cout<<"elemen keluar"<< dequeue(Q)<< endl;
    printInfo(Q);
    cout<<"\n enqueue 1 elemen"<< endl;
    enqueue(Q, 4);
    printInfo(Q);
    cout<<"\n dequeue 2 elemen"<<endl;
    cout<< "elemen keluar"<< dequeue(Q) <<endl;
    cout<< "elemen keluar"<<dequeue(Q)<< endl;
    printInfo(Q);
    return 0;

}
```

### queue.cpp
```C++
#include "queue.h" 
#include <iostream>

using namespace std;

void createQueue(Queue &Q) {
    Q.head = 0; 
    Q.tail = 0; 
    Q.count = 0;
}

bool isEmpty(Queue Q) {
    return Q.count == 0; //Kembalikan true jika jumlah elemen adalah 0
}

bool isFull(Queue Q) {
    return Q.count == MAX_QUEUE; // Kembalikan true jika jumlah elemen sama dengan maks
}

// Definisi prosedur untuk menambahkan elemen (enqueue)
void enqueue(Queue &Q, int x) {
    if (!isFull(Q)) { 
        Q.info[Q.tail] = x; // Masukkan data (x) ke posisi ekor (tail)
        // Pindahkan ekor secara circular (memutar)
        Q.tail = (Q.tail + 1) % MAX_QUEUE; 
        Q.count++; //Tambah jumlah elemen
    } else { 
        cout << "Antrean Penuh!" << endl;
    }
}

//Definisi fungsi untuk menghapus elemen (dequeue)
int dequeue(Queue &Q) {
    if (!isEmpty(Q)) { 
        int x = Q.info[Q.head]; // Ambil data di posisi  (head)
        Q.head = (Q.head + 1) % MAX_QUEUE;
        Q.count--; // Kurangi jumlah elemen
        return x;
    } else {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
}

// Definisi prosedur untuk menampilkan isi queue 
void printInfo(Queue Q) {
    cout << "Isi Queue: [ ";
    if (!isEmpty(Q)) { 
        int i = Q.head; // Mulai dari head
        int n = 0; //Penghitung elemen yang sudah dicetak
        while (n < Q.count) { // Ulangi sebanyak jumlah elemen
            cout << Q.info[i] << " "; // Cetak info
            i = (i + 1) % MAX_QUEUE; // Geser i secara circular
            n++; // Tambah penghitung
        }
    }
    cout << "]" << endl;
}
```

### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define MAX_QUEUE 5

struct Queue{
    int info[MAX_QUEUE];
    int head;
    int tail;
    int count;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int x);
int dequeue(Queue &Q);
void printInfo(Queue Q);
#endif
```
Deskripsi: Program tersebut merupakan implementasi queue menggunakan array statis dengan mekanisme circular queue. Struktur queue diartikan untuk menampung data integer info dalam array yang berukuran tetap (MAX_QUEUE = 5) dengan menggunakan 3 variabel interger yaitu head sebagai penunjuk elemen di awal, tail sebagai penunjuk elemen di akhir dan count untuk melihat jumlah elemen yang ada saat ini.



## Unguided 

### 1. Queue alternatif 1 (head diam, tail bergerak)
### main.cpp
```C++
#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    cout << "hello world" << endl;
    Queue Q;
    createQueue(Q);

    cout << "------------------------------" << endl;
    cout << " H - T \t| queue info" << endl;
    cout << "------------------------------" << endl;

    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);

    return 0;
}
```

### queue.cpp
```C++
#include "queue.h"
void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}
bool isEmptyQueue(Queue Q) {
    return (Q.head == -1);
}
bool isFullQueue(Queue Q) {
    return (Q.tail == MAX - 1);
}
void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "queue penuh!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
            Q.info[0] = x;
        } else {
            Q.tail++;
            Q.info[Q.tail] = x;
        }
    }
}
infotype dequeue(Queue &Q) {
    infotype val = -1;
    if (isEmptyQueue(Q)) {
        cout << "queue kosong!" << endl;
    } else {
        val = Q.info[Q.head];
        if (Q.head == Q.tail) {
            createQueue(Q);
        } else {
            for (int i = 0; i < Q.tail; i++) {
                Q.info[i] = Q.info[i + 1];
            }
            Q.tail--;
        }
    }
    return val;
}
void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " \t: ";
    if (isEmptyQueue(Q)) {
        cout << "queue kosong" << endl;
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}
```

### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;
#define MAX 5

typedef int infotype;

struct Queue {
    infotype info[MAX];
    int head;
    int tail;
};
void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);
#endif
```
Program implementasi ADT queue dengan memanfaatkan array statis yang berkapasitas maks 5 elemen. 

### Output Unguided 1 :

##### Output 1
![op1](https://github.com/muliapratama1908/103112400034_Mulia-Akbar-Nanda-Pratama/blob/main/week%2010%20(modul%208)/op1.jpeg)



### 2. Alternatif 2 (head bergerak, tail bergerak)

### main.cpp
```C++
#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    cout << "hello world" << endl;
    Queue Q;
    createQueue(Q);

    cout << "------------------------------" << endl;
    cout << " H - T \t| queue info" << endl;
    cout << "------------------------------" << endl;

    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);

    return 0;
}
```

### queue.cpp
```C++
#include "queue.h"
void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == MAX - 1);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue Full!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
            Q.info[0] = x;
        } else {
            Q.tail++;
            Q.info[Q.tail] = x;
        }
    }
}

infotype dequeue(Queue &Q) {
    infotype val = -1;
    if (isEmptyQueue(Q)) {
        cout << "queue kosong!" << endl;
    } else {
        val = Q.info[Q.head];
        if (Q.head == Q.tail) {
            createQueue(Q);
        } else {
            Q.head++;
        }
    }
    return val;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " \t: ";
    if (isEmptyQueue(Q)) {
        cout << "queue kosong" << endl;
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}
```

### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;
#define MAX 5

typedef int infotype;

struct Queue {
    infotype info[MAX];
    int head;
    int tail;
};
void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);
#endif
```
Program tersebut menunjukkan cara kerja queue dengan array statis yang maksimal elemen nya 5. Data masuk dari belakang dan keluar dari depan, dan pergerakan head-tail mengatur proses FIFO.

### Output Unguided 2 :

##### Output 1
![op2](https://github.com/muliapratama1908/103112400034_Mulia-Akbar-Nanda-Pratama/blob/main/week%2010%20(modul%208)/op2.jpeg)




### 3. Alternatif 3 (head dan tail berputar)

### main.cpp
```C++
#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    cout << "hello world" << endl;
    Queue Q;
    createQueue(Q);

    cout << "------------------------------" << endl;
    cout << " H - T \t| queue info" << endl;
    cout << "------------------------------" << endl;

    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);

    return 0;
}
```

### queue.cpp
```C++
#include "queue.h"
void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1);
}

bool isFullQueue(Queue Q) {
    return ((Q.tail + 1) % MAX == Q.head);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "queue penuh!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
            Q.info[0] = x;
        } else {
            Q.tail = (Q.tail + 1) % MAX;
            Q.info[Q.tail] = x;
        }
    }
}

infotype dequeue(Queue &Q) {
    infotype val = -1;
    if (isEmptyQueue(Q)) {
        cout << "queue kosong!" << endl;
    } else {
        val = Q.info[Q.head];
        if (Q.head == Q.tail) {
            createQueue(Q);
        } else {
            Q.head = (Q.head + 1) % MAX;
        }
    }
    return val;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " \t: ";
    if (isEmptyQueue(Q)) {
        cout << "queue kosong" << endl;
    } else {
        int i = Q.head;
        while (i != Q.tail) {
            cout << Q.info[i] << " ";
            i = (i + 1) % MAX;
        }
        cout << Q.info[i] << endl;
    }
}
```

### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;
#define MAX 5

typedef int infotype;

struct Queue {
    infotype info[MAX];
    int head;
    int tail;
};
void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);
#endif
```
Progam tersebut merupakan program alternatif 3 dari yang sebelumnya dibuat, namun program pada alternatif 3 ini menggunakan circular queue atau antrian melingkar untuk mengatasi pemborosan memori yang terjadi pada model biasa.

### Output Unguided 3 :

##### Output 1
![op3](https://github.com/muliapratama1908/103112400034_Mulia-Akbar-Nanda-Pratama/blob/main/week%2010%20(modul%208)/op3.jpeg)



## Kesimpulan
Dengan seluruh percobaan di atas, bahwa queue merupakan struktur data yang bekerja dengan prinsip FIFO, yang di mana elemen yang pertama masuk akan menjadi elemen pertama yang keluarr juga. Implementasi queue dapat dilakukan dengan menggunakan linked list, array statis, maupun circular queue. Queue berbasis linked list lebih fleksibel karena tidak terbatas ukuran, sedangkan queue berbasis array lebih sederhana namun dibatasi kapasitas. Circular queue menjadi solusi untuk menghindari pemborosan memori pada model linear.


## Referensi
<br>[1] https://www.dicoding.com/blog/struktur-data-queue-pengertian-fungsi-dan-jenisnya/
<br>[2]https://www.trivusi.web.id/2022/07/struktur-data-queue.html


