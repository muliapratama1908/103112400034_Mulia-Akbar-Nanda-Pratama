# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type (ADT)</h1>
<p align="center">Mulia Akbar Nanda Pratama - 103112400034</p>

## Dasar Teori
Abstrak data type merupakan tipe data yang ditentukan pengguna yang dapat dimanipulasi serupa dengan tipe data yang disediakan sistem, yang memungkinkan pembuatan banyak salinan dan implementasi operasi tanpa mengekspos representasi struktur internal [1]. Ada beberapa model abstrak data type yaitu public functions dan private functions. Model ADT juga memuat struktur data yang digunakan dalam suatu program. Ada tiga jenis utama ADT diantaranya list,  queue. dan stack [2]. 

## Guided
### 1. modular

```C++
#ifndef MAHASISWA_H
#define MAHASISWA_H

//definisi tipe (struct)
struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

//deklarasi primitif(fungsi)
void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

#endif
```

```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "Input NIM: "; 
    cin >> m.nim;
    cout << "Input Nilai 1: "; 
    cin >> m.nilai1;
    cout << "Input Nilai 2: "; 
    cin >> m.nilai2;
}

float rata2(mahasiswa m) {
    return (float)(m.nilai1 + m.nilai2) / 2;
}
```
```C++
#include<iostream>
#include "mahasiswa.h"
#include <cstdlib>

using namespace std;

int main() {
    mahasiswa mhs;

    inputMhs(mhs);

    cout << "rata-rata nilai adalah: " << rata2 (mhs) << endl;
    system("pause");

 return 0;
}
```
Program yang terstruktur dalam bentuk modular untuk kelola data mahasiswa dan input nilai. 

### 2. non modular
```C++
#include <iostream>
using namespace std;
struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};
void inputMhs(mahasiswa &m) {
    cout << "Input NIM: "; 
    cin >> m.nim;
    cout << "Input Nilai 1: "; 
    cin >> m.nilai1;
    cout << "Input Nilai 2: "; 
    cin >> m.nilai2;
}

float rata2(mahasiswa m) {
    return (float)(m.nilai1 + m.nilai2) / 2;
}
int main() {
    mahasiswa mhs;

    inputMhs(mhs);

    cout << "rata-rata nilai adalah: " << rata2 (mhs) << endl;
    system("pause");

 return 0;
}
```
Program yang tidak jauh berbeda dengan guided 1 yaitu menyimpan dua nilai dan NIM kemudian menhitung rata rata.

## Unguided 
### 1. Program Menyimpan Data Mahasiswa

```C++
#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts, uas, tugas;
    float nilai_akhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

int main() {
    Mahasiswa data_mahasiswa[10];
    int jumlah;

    cout << "masukkan jumlah mahasiswa : ";
    cin >> jumlah;

    cout << "input data: ";
    for (int i = 0; i < jumlah; i++) {
        cout << "Mahasiswa ke-" << i + 1 << "\n";
        
        cout << "Nama : ";
        cin >> data_mahasiswa[i].nama; 

        cout << "NIM : ";
        cin >> data_mahasiswa[i].nim;

        cout << "Nilai UTS, UAS, Tugas : ";
        cin >> data_mahasiswa[i].uts >> data_mahasiswa[i].uas >> data_mahasiswa[i].tugas;

        data_mahasiswa[i].nilai_akhir = hitungNilaiAkhir(
            data_mahasiswa[i].uts, 
            data_mahasiswa[i].uas, 
            data_mahasiswa[i].tugas
        );
    }
    
    for (int i = 0; i < jumlah; i++) {
        cout << "Data Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama        : " << data_mahasiswa[i].nama << endl;
        cout << "NIM         : " << data_mahasiswa[i].nim << endl;
        cout << "Nilai Akhir : " << data_mahasiswa[i].nilai_akhir << endl;
    }

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![output_unguided1](https://github.com/muliapratama1908/103112400034_Mulia-Akbar-Nanda-Pratama/blob/main/week%203/output_unguided1.png)

Program yang bisa menyimpan data maksimal 10 ke dalam sebuah array, yang di mana program tersebut berisi inputan nama, nim, dan nilai.

### 2. ADT
```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H
#include <string>

using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran buat_pelajaran(string mapel, string kode);
void tampil_pelajaran(pelajaran pel);

#endif
```

```C++
##include "pelajaran.h"
#include <iostream>
using namespace std;

pelajaran buat_pelajaran(string mapel, string kode) {
    pelajaran p;
    p.namaMapel = mapel;
    p.kodeMapel = kode;
    return p;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
```

```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string mapel = "Struktur Data";
    string kode = "STD";
    
    pelajaran pel = buat_pelajaran(mapel, kode);
    
    tampil_pelajaran(pel);
    
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![output_unguided2](https://github.com/muliapratama1908/103112400034_Mulia-Akbar-Nanda-Pratama/blob/main/week%203/output_unguided2.png)

Program dengan konsep modularitas untuk membuat tipe data pelajaran yang menyimpan kode mapel dan nama, lalu di running di fungsi main.


### 3.Program tukar Array dengan Pointer
```C++
#include <iostream>

using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarNilai(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int *ptrA;
    int *ptrB;
    
    ptrA = &arr1[baris][kolom];
    ptrB = &arr2[baris][kolom];
    
    int temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;
}

int main() {
    int arrayA[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int arrayB[3][3] = {
        {99, 88, 77},
        {66, 55, 44},
        {33, 22, 11}
    };

    cout << "--- KONDISI AWAL ---" << endl;
    cout << "Isi Array A:" << endl;
    tampilArray(arrayA);
    
    cout << "\nIsi Array B:" << endl;
    tampilArray(arrayB);
    
    int baris = 1;
    int kolom = 1;
    
    tukarNilai(arrayA, arrayB, baris, kolom);
    
    cout << "\n--- SETELAH DITUKAR PADA POSISI [" << baris << "][" << kolom << "] ---" << endl;
    cout << "Isi Array A:" << endl;
    tampilArray(arrayA);
    
    cout << "\nIsi Array B:" << endl;
    tampilArray(arrayB);

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![output_unguided3](https://github.com/muliapratama1908/103112400034_Mulia-Akbar-Nanda-Pratama/blob/main/week%203/output_unguided3.png)

Program ini mendemonstrasikan manipulasi data pada dua buah array dua dimensi berukuran 3x3 menggunakan fungsi dan pointer. Program memanggil sebuah fungsi khusus yang menggunakan pointer untuk mengambil nilai dari posisi tengah array A dan menukarnya dengan nilai dari posisi tengah array B. 


## Kesimpulan
Pada praktikum 3 ini bisa dijadikan sebagai pemahaman mendalam tentang konsep Abstract Data Type (ADT) dan pentingnya modularitas dalam pemrograman C++. Melalui perbandingan antara kode non-modular dan modular pada bagian Guided, terlihat jelas bahwa memisahkan deklarasi struct dan fungsi ke dalam file header dari implementasinya yang dapat menghasilkan program yang jauh lebih terstruktur, rapi, dan mudah dikelola.

## Referensi
<br>[1] https://www.sciencedirect.com/topics/computer-science/abstract-data-type
<br>[2] https://www.scholarhat.com/tutorial/datastructures/abstract-data-type
