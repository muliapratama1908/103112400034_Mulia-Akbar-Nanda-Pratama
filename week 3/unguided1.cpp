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