# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Mulia Akbar Nanda Pratama - 103112400034</p>

## Dasar Teori
Bahasa C++ adalah bahasa pemrograman komputer yang strongly-typed dan fleksibel, serta banyak digunakan untuk pengembangan perangkat lunak dan sistem komputer. C++ merupakan bahasa pemrograman komputer yang dibuat oleh Bjarne Stroustrup, yang merupakan perkembangan dari bahasa C dikembangkan di Bong Labs (Dennis Ritchie) pada awal tahun 1970an [1]. C++ terdapat beberapa fitur-fitur canggih seperti pemrograman berorientasi objek (OOP) untuk membangun program yang terstruktur dan efisien. Dengan konsep OOP, programmer dapat membuat program yang modular, dapat digunakan kembali, dan mudah dipelihara. Kemampuan ini menjadikan C++ pilihan utama dalam pengembangan aplikasi kompleks seperti game, pengembangan perangkat lunak, dan program-program berkinerja tinggi [2]. 

### A. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

### B. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

## Guided 

### 1. ...

```c++ #include<iostream>
using namespace std;

int main(){
    int angka;
    cout << "masukkan angka : ";
    cin >> angka;
    cout << "angka yang dimasukkan "<< angka << endl;
    return 0;
}
```
Program sederhana dari bahasa C++ yang di mana program meminta inputan angka dari pengguna, lalu program akan menampilkan kembali di terminal output.

### 2. ...

```c++ #include<iostream>
using namespace std;

int main(){
    int angka1, angka2;
    cout << "masukkan angka 1 :";
    cin >> angka1;
    cout << "masukkan angka 2 :";
    cin >> angka2;

    cout << "penjumlahan : " << angka1 + angka2 << endl;
    cout << "pengurangan : " << angka1 - angka2 << endl;
    cout << "perkalian : " << angka1 * angka2 << endl;
    cout << "pembagian : " << angka1 / angka2 << endl;
    cout << "sisa bagi : " << angka1 % angka2 << endl;

    return 0;
}
```
Program C++ yang di mana program meminta 2 inputan berupa angka, lalu program akan menampilkan hasil dari 2 buah angka yang telah diinputkan. Lalu angka tersebut di jadikan penjumlahan, pengurangan, perkalian, pembagian, dan sisa bagi yang ditampilkan di terminal output.

### 3. ...

```c++ #include<iostream>
using namespace std;

int main(){
    int angka1, angka2;
    cout << "masukkan angka 1 :";
    cin >> angka1;
    cout << "masukkan angka 2 :";
    cin >> angka2;

    if (angka1 < angka2){
        cout << angka1 << " kurang dari " << angka2 << endl;
    } else {
        cout << angka1 << " lebih dari " << angka2 << endl;
    }

    if (angka1 == angka2){
        cout << angka1 << " sama dengan " << angka2 << endl;
    } else if (angka1 != angka2) {
        cout << "angka berbeda" << endl;
    }

    int pilihan;
    cout << "MENU" << endl;
    cout << "1. penjumlahan" << endl;
    cout << "2. pengurangan" << endl;
    cout << "masukkan pilihan: " << endl;
    cin >> pilihan;

    switch(pilihan){
        case 1:
        cout << "penjumlahan : " << angka1 + angka2 << endl;
        break;
        case 2:
        cout << "pengurangan : " << angka1 - angka2 << endl;
        cout << endl;
        break;
        default :
        cout << "pilihan salah" << endl;

    }
    return 0;
}
```
Program yang menerima inputan 2 buah bilangan bulat, lalu program akan membandingkan apakah angka yg diinputkan itu lebih dari atau kurang dari, kemudian program akan mencetak angka berbeda atau sama dengan. Lalu program akan menampilkan menu berupa penjumlahan dan pengurangan, user bisa memilih salah satu agar di proses lagi oleh program.

### 4. ...

```c++ #include<iostream>
using namespace std;

int main(){
    int angka1;
    cout << "masukkan angka 1 : ";
    cin >> angka1;

    for(int i = 0; i < angka1; i++){//increment
        cout << i << " - ";
    }
    cout << endl;

    int j = 10;
    while (j > angka1){
        cout << j << " - ";
        j--; //decrement
    }

    int k = 3;
    do{
        cout << k << " - ";
    } while (k < angka1);

    return 0;
}
```
Program sederhana C++ yang mencetak 3 jenis perulangan (looping)

### 5. ...

``` c++ #include<iostream>
using namespace std;

int main(){
    const int MAX = 5;
    struct rapot{
        string nama;
        float nilai;
    };
    rapot siswa[MAX];

    for(int i = 0; i < MAX; i++){
        cout << "masukkan nama siswa : ";
        cin >> siswa[i].nama;
        cout << "masukkan nilai siswa : ";
        cin >> siswa[i].nilai;
         cout << endl;
    }

    int j = 0;
    while(j < MAX){
        cout << "nama siswa : " << siswa[j].nama << ", nilai : " << siswa[j].nilai << endl;
        j++;
    }
    return 0;
}
```
Program yang dibuat untuk menyimpan data rapor siswa dengan menggunakan struct dan array.

## Unguided 

### 1. (program yang menerima inputan dua buah bilangan yang bertipe float, kemudian memberikan outputan hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut)

```C++
#include<iostream>
using namespace std;

int main(){
    float angka1, angka2;
    cout << "masukkan angka pertama : ";
    cin >> angka1;
    cout << "masukkan angka kedua : ";
    cin >> angka2;

    cout << "penjumlahan : " << angka1 + angka2 << endl;
    cout << "pengurangan : " << angka1 - angka2 << endl;
    cout << "perkalian : " << angka1 * angka2 << endl;
    cout << "pembagian : " << angka1 / angka2 << endl;

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 1_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Program yang dibuat untuk menghitung beberapa operasi matematika.


### 2. (program yang menerima masukkan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan)

```C++ #include <iostream>
using namespace std;

string satuan[] = {"nol", "satu", "dua", "tiga", "empat", "lima",
                   "enam", "tujuh", "delapan", "sembilan"};

string angkaKeTulisan(int n) {
    if (n < 10) {
        return satuan[n];
    } else if (n == 10) {
        return "sepuluh";
    } else if (n == 11) {
        return "sebelas";
    } else if (n < 20) {
        return satuan[n - 10] + " belas";
    } else if (n < 100) {
        int puluh = n / 10;
        int sisa = n % 10;
        string hasil = satuan[puluh] + " puluh";
        if (sisa != 0) {
            hasil += " " + satuan[sisa];
        }
        return hasil;
    } else if (n == 100) {
        return "seratus";
    }
}

int main() {
    int angka;
    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    if (angka < 0 || angka > 100) {
        cout << "lebih dari yg ditentukan" << endl;
    } else {
        cout << angka << " : " << angkaKeTulisan(angka) << endl;
    }
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

program yang berfungsi untuk mengkonversi bilangan angka menjadi huruf.

### 3. (buat program sesuai dengan modul)

```C++ #include <iostream>
using namespace std;

int main() {
    int n;
    int x;
    cout << "masukkan: ";
    cin >> n;

    cout << "keluaran:\n";
    for (int i = n; i >= 1; i--) {
        for (int x = 0; x < n - i; x++) {
            cout << "  ";
        }

        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        cout << "* ";

        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }

        cout << endl;
    }

    for (int x = 0; x < n; x++) {
        cout << "  ";
    }
    cout << "*" << endl;

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 3_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

program untuk mencetak pola bintang dan angka agar berbentuk seperti piramida yang muncul di terminal output.

## Kesimpulan
Berasarkan praktikum tersebut, dapat disimpulkan bahwa pemahaman konsep dasar sangat penting sebelum mempelajari pemrograman yang lebih kompleks. Praktikum ini memperkenalkan sintaks dasar C++ mulai dari i/o, operasi aritmatika, percabangan, perulangan,, hinigga penggunaan struktur data sederhana seperti struct dan array.

## Referensi
[1] https://www.dicoding.com/blog/memahami-esensi-bahasa-pemrograman-c/
<br>[2] https://books.google.co.id/books?hl=id&lr=&id=nzJsEAAAQBAJ&oi=fnd&pg=PA18&dq=dasar+pemrograman+c%2B%2B&ots=rb9Kk7ylP4&sig=OjA2F-mHILpxYo2tGBaO5MyG-_g&redir_esc=y#v=onepage&q=dasar%20pemrograman%20c%2B%2B&f=false

