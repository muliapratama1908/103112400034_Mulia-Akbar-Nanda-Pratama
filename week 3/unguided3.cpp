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