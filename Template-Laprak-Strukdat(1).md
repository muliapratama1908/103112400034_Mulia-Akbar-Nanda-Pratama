# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Mulia Akbar Nanda Pratama - 103112400034</p>

## Dasar Teori
Bahasa C++ adalah bahasa pemrograman komputer yang strongly-typed dan fleksibel, serta banyak digunakan untuk pengembangan perangkat lunak dan sistem komputer [1]. C++ merupakan bahasa pemrograman komputer yang dibuat oleh Bjarne Stroustrup, yang merupakan perkembangan dari bahasa C dikembangkan di Bong Labs (Dennis Ritchie) pada awal tahun 1970an [2]. C++ terdapat beberapa fitur-fitur canggih seperti pemrograman berorientasi objek (OOP) untuk membangun program yang terstruktur dan efisien [3]. Dengan konsep OOP, programmer dapat membuat program yang modular, dapat digunakan kembali, dan mudah dipelihara [4]. Kemampuan ini menjadilan C++ pilihan utama dalam pengembangan aplikasi kompleks seperti game, pengembangan perangkat lunak, dan program-program berkinerja tinggi [5]. 

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
Program di atas merupakan 

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
penjelasan singkat guided 2

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
penjelasan singkat guided 3

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
penjelasan singkat

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
penjelasan

## Unguided 

### 1. (isi dengan soal unguided 1)

```C++

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 1_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 1 

### 2. (isi dengan soal unguided 2)

```C++
source code unguided 2
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 2

### 3. (isi dengan soal unguided 3)

```C++
source code unguided 3
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 3_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 3

## Kesimpulan
...

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
