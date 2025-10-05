# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++  (Bagian Kedua)</h1>
<p align="center">Mulia Akbar Nanda Pratama - 103112400034</p>

## Dasar Teori
Array adalah sebuah variabel yang menyimpan sekumpulan data yang memiliki tipe sama atau biasa disebut juga sebagai kumpulan dari nilai-nilai data bertipe sama dalam urutan tertentu yang menggunakan sebuah nama yang sama. Setiap data tersebut menempati alamat memori atau lokasi yang berbeda dan selanjutnya disebut elemen array [1]. Pointer adalah salah satu konsep yanng sangat penting dan khas dalam C++. Secara sederhana, pointer adalah variabel yang menyimpan alamat memori dari suatu nilai atau objek. Ini memungkinkan kita untuk mengakses dan memanipulasi nilai atau objek tersebut dengan cara yang lebih efisien [3]. Array terbagi menjadi beberapa jenis, diantara nya sebagai berikut.

### A. Array 1 dimensi <br/>
Array 1 dimensi adalah array yang terdiri dari n buah kolom. Setiap elemen array 1 dimensi dapat diakses melalui indeks yang terdapat di dalamnya [1].

``` C++
 tipe_data  nama_array  [jumlah_elemen];
```

### B. Array 2 dimensi 
Dalam C++, dapat menginisialisasi array2 dimensi sekaligus mendeklarasikannya. Metode yang paling umum yaitu dengan menggunakan kurung kurawal ({}) untuk menentukan nilai setiap baris [2].

``` C++ 
int arr[4][2] = {
    {1234, 56},
    {1212, 33},
    {1434, 80},
    {1312, 78}
} ;
```
atau dapat juga seperti berikut 
``` C++
int arr[4][2] = {1234, 56, 1212, 33, 1434, 80, 1312, 78};
```

### C. Arrnpointer 
Di dalam bahasa pemrograman C++, setiap tipe data memiliki pointer yang sesuai. Artinya, Kamu dapat membuat pointer untuk tipe data dasar seperti int, float, char, dan sebagainya. Tujuan utama dari pointer tipe data adalah untuk menunjuk ke lokasi memori tempat nilai tipe data tersebut disimpan. Misalnya, pointer int akan menunjuk ke alamat memori yang menyimpan nilai bilangan bulat. Contoh deklarasi dan inisialisasi pointer menggunakan bahasa C++ [3].

``` C++
int angka = 42; int *ptr = &angka; // Inisialisasi pointer dengan alamat variabel angka
```



## Guided 

### 1. Array 1 dimensi

```c++ #include <iostream>
using namespace std;

int main() {
    int arr[5];

    for (int i = 0; i < 5; i++) {
        cout << "masukkan value indeks ke-" << i << " : ";
        cin >> arr[i];
    }
    int j = 0;
    while(j < 5) {
        cout << "isi indeks ke-" << j << " : " << arr[j] << endl;
        j++;
    }
    return 0;
}
```
Program yang meminta input berupa bilangan integer sebanyak 5 inputan, lalu program akan menampilkan kembali nilai-nilai yang sudah di inputkan.

### 2. Array 2 dimensi 

```c++ #include<iostream>
using namespace std;

void tampilkanhasil(int arr[2][2]){
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int arrA[2][2] = {
        {1, 2},
        {3, 4}
    };
    int arrB[2][2] = {
        {2, 3},
        {4, 5}
    };  
    int arrC[2][2] = {0};
    int arrD[2][2] = {0};
    
    // Penjumlahan matriks 2x2
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }
    
    cout<<"Hasil Penjumlahan: "<<endl;
    tampilkanhasil(arrC);

    cout<<endl;

    // Perkalian matriks 2x2
    for (int i = 0; i < 2; i++){            //Perulangan baris 
        for (int j = 0; j < 2; j++){        //Perulangan kolom  
            for (int k = 0; k < 2; k++){    //Perulangan perkalian
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout<<"Hasil Perkalian: "<<endl;
    tampilkanhasil(arrD);

    return 0;
}
```
Program yang mendemonstrasikan penjummlahan dan perkalian matriks 2x2.

### 3. Arrnpointer

```c++ #include <iostream>
using namespace std;

int main(){
    int arr[]={10,20,30,40,50};
    int*ptr=arr; //pointer yang menunjuk ke elemen pertama array

    //mengakses elemen array menggunakan pointer
    for (int i = 0; i < 5; i++){
        cout<<"elemen array ke-"<< i+1<<" menggunakan pointer: "<<*(ptr+i)<<endl;
    }

    //mengakses elemen array menggunakan indeks
    for (int i = 0; i < 5; i++){
        cout<<"Elemen array ke-"<< i+1 <<" menggunakan indeks: "<<arr[i]<<endl;
    }
    return 0;
}
```
Program C++ di atas menunjukkan dua cara yang berbeda untuk mengakses elemen-elemen dalam sebuah array, yaitu menggunakan pointer dan indeks.

### 4. Fungsi prosedur 

```c++ #include <iostream>
using namespace std;

 int main(){
    int angka1;
    cout << "masukan angka1 : ";
    cin >> angka1;

    for (int i = 0; i  < angka1; i++){
      cout << i << " - ";
    }
    cout << endl;

    int j = 10;
    while (j > angka1){
      cout << j << " - ";
      j--;
    }

    cout << endl;
    int k = 10;
    do {
      cout << k << " - ";
    }while (k < angka1);

     return  0;
 }
```
Program C++ yang menunjukkan 3 jenis perulangan yaitu for, while, dan do-while berdasarkan satu angka yang diinputkan oleh pengguna.


## Unguided 

### 1. Matriks 3x3

```C++
#include <iostream>
using namespace std;

int matriksA[3][3] = {
    {7, 12, 22},
    {31, 6, 41},
    {15, 19, 36}
};

int matriksB[3][3] = {
    {11, 34, 7},
    {3, 25, 41},
    {5, 18, 33}
};

int hasil[3][3] = {0};

void jumlahMatriks(int matriksA[3][3], int matriksB[3][3], int hasil[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            hasil[i][j] = matriksA[i][j] + matriksB[i][j];
        }
    }
    cout << "Hasil Penjumlahan: " << endl;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << hasil[i][j] << " ";
        }
        cout << endl;
    }
}

void kurangMatriks(int matriksA[3][3], int matriksB[3][3], int hasil[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            hasil[i][j] = matriksA[i][j] - matriksB[i][j];
        }
    }
    cout << "Hasil Pengurangan: " << endl;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << hasil[i][j] << " ";
        }
        cout << endl;
    }
}

void kaliMatriks(int matriksA[3][3], int matriksB[3][3], int hasil[3][3]){
    for (int i = 0; i < 3; i++){           
        for (int j = 0; j < 3; j++){        
            for (int k = 0; k < 3; k++){    
                hasil[i][j] += matriksA[i][k] * matriksB[k][j];
            }
        }
    }
    cout << "Hasil Perkalian: " << endl;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << hasil[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int pilihan;

    do {
        cout << "\n Menu " << endl;
        cout << "1. Penjumlahan matriks" << endl;
        cout << "2. Pengurangan matriks" << endl;
        cout << "3. Perkalian matriks" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih operasi (1-4): ";
        cin >> pilihan;

         switch (pilihan) {
            case 1:
                jumlahMatriks(matriksA, matriksB, hasil);
                break;
            case 2:
                kurangMatriks(matriksA, matriksB, hasil);
                break;
            case 3:
                kaliMatriks(matriksA, matriksB, hasil);
                break;
            case 4:
                cout << "Keluar." << endl;
                break;
            default:
                cout << "Tidak ada pilihan" << endl;
        }
        cout << endl; 
    } while (pilihan != 4);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![output unguided1_1.png](https://github.com/muliapratama1908/103112400034_Mulia-Akbar-Nanda-Pratama/blob/main/week%202/output%20unguided1_1.png)

##### Output 2
![output unguided1_2.png](https://github.com/muliapratama1908/103112400034_Mulia-Akbar-Nanda-Pratama/blob/main/week%202/output%20unguided1_2.png)


Program yang menghitung operasi aritmatika menggunakan matriks 3x3, ada penjumlahan, pengurangan, dan perkalian. User dapat memilih salah satu menu yang ditampilkan, lalu akan muncul outputnya.


### 2. Hitung luas dan keliling persegi 

```C++ 
#include <iostream>

using namespace std;

int main() {
    int p = 10;
    int lbr = 5;
    int l = 0;
    int k= 0;

    cout << " nilai awal " << endl;
    cout << "Panjang: " << p << endl;
    cout << "Lebar: " << lbr << endl;
    cout << endl;

    int *ptrPanjang = &p;
    int *ptrLebar = &lbr;

    l = (*ptrPanjang) * (*ptrLebar);
    k= 2 * ((*ptrPanjang) + (*ptrLebar));

    cout << " hasil " << endl;
    cout << "Luas Persegi Panjang: " << l << endl;
    cout << "Keliling Persegi Panjang: " << k<< endl;
    cout << endl;

    *ptrPanjang = 12;
    *ptrLebar = 6;

    cout << " nilai setelah diubah " << endl;
    cout << "Panjang Baru: " << p<< endl;
    cout << "Lebar Baru: " << lbr<< endl;

    l = (*ptrPanjang) * (*ptrLebar);
    k = 2 * ((*ptrPanjang) + (*ptrLebar));
    cout << "Luas Baru: " << l << endl;
    cout << "Keliling Baru: " << k << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![output unguided2.png](https://github.com/muliapratama1908/103112400034_Mulia-Akbar-Nanda-Pratama/blob/main/week%202/output%20unguided2.png)


Program yang menghitung luas dan keliling persegi panjang menggunakan pointer. 


## Kesimpulan
Dari laporan praktikum di atas kita dapat mendemonstrasikan implementasi konsep-konsep dasar dalam bahasa C++, terutama struktur data array dan mmanipulasi memori menggunakan pointer. Kombinasi keduanya merupakan fondasi penting dalam pemrograman C++ untuk mengimplementasikan struktur data dan algoritma yang kompleks.

## Referensi
[1] https://www.materidosen.com/2017/06/array-satu-dimensi-c-lengkap-contoh.html
<br> [2] https://www.digitalocean.com/community/tutorials/two-dimensional-array-in-c-plus-plus
<br>  [3] https://www.domainesia.com/berita/pointer-adalah/

