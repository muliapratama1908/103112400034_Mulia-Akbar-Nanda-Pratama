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