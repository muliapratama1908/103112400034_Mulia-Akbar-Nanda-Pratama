#include <iostream>
#include "StackMahasiswa.h"
using namespace std;
bool isEmpty(StackMahasiswa &StackMHS) {
    return StackMHS.Top == -1;
}
bool isFull(StackMahasiswa &StackMHS) {
    return StackMHS.Top == MAX - 1;
}
void createStack(StackMahasiswa &StackMHS) {
    StackMHS.Top = -1;
}
void Push(StackMahasiswa &StackMHS) {
    if (isFull(StackMHS)) {
        cout << "Stack penuh!" << endl;
        return;
    }
    Mahasiswa m;
    cout << "Nama        : ";
    cin >> m.Nama;
    cout << "NIM         : ";
    cin >> m.NIM;
    cout << "Nilai Tugas : ";
    cin >> m.NilaiTugas;
    cout << "Nilai UTS   : ";
    cin >> m.NilaiUTS;
    cout << "Nilai UAS   : ";
    cin >> m.NilaiUAS;
    StackMHS.Top++;
    StackMHS.dataMahasiswa[StackMHS.Top] = m;
    cout << "Data berhasil ditambahkan." << endl;
}
void Pop(StackMahasiswa &StackMHS) {
    if (isEmpty(StackMHS)) {
        cout << "Stack kosong!" << endl;
        return;
    }

    StackMHS.Top--;
    cout << "Data teratas berhasil dihapus." << endl;
}
void Update(StackMahasiswa &StackMHS, int posisi) {
    if (isEmpty(StackMHS)) {
        cout << "Stack kosong!" << endl;
        return;
    }

    if (posisi < 1 || posisi > StackMHS.Top + 1) {
        cout << "Posisi tidak valid." << endl;
        return;
    }
    int index = posisi - 1;
    cout << "Update data mahasiswa ke-" << posisi << endl;
    cout << "Nama baru        : ";
    cin >> StackMHS.dataMahasiswa[index].Nama;
    cout << "NIM baru         : ";
    cin >> StackMHS.dataMahasiswa[index].NIM;
    cout << "Nilai Tugas baru : ";
    cin >> StackMHS.dataMahasiswa[index].NilaiTugas;
    cout << "Nilai UTS baru   : ";
    cin >> StackMHS.dataMahasiswa[index].NilaiUTS;
    cout << "Nilai UAS baru   : ";
    cin >> StackMHS.dataMahasiswa[index].NilaiUAS;
    cout << "Data berhasil diperbarui." << endl;
}
void View(StackMahasiswa &StackMHS) {
    if (isEmpty(StackMHS)) {
        cout << "Stack kosong!" << endl;
        return;
    }
    cout << "\nIsi Stack Mahasiswa:\n";
    for (int i = StackMHS.Top; i >= 0; i--) {
        cout << "Nama  : " << StackMHS.dataMahasiswa[i].Nama << endl;
        cout << "NIM   : " << StackMHS.dataMahasiswa[i].NIM << endl;
        cout << "Tugas : " << StackMHS.dataMahasiswa[i].NilaiTugas << endl;
        cout << "UTS   : " << StackMHS.dataMahasiswa[i].NilaiUTS << endl;
        cout << "UAS   : " << StackMHS.dataMahasiswa[i].NilaiUAS << endl;
    }
}
void SearchNilaiAkhir(StackMahasiswa &StackMHS, float NilaiAkhirMin, float NilaiAkhirMax) {
    if (isEmpty(StackMHS)) {
        cout << "Stack kosong!" << endl;
        return;
    }
    cout << "\nMahasiswa dengan rentang nilai akhir " 
         << NilaiAkhirMin << " - " << NilaiAkhirMax << endl;

    bool found = false;

    for (int i = 0; i <= StackMHS.Top; i++) {
        float akhir = (0.2 * StackMHS.dataMahasiswa[i].NilaiTugas) +
                      (0.4 * StackMHS.dataMahasiswa[i].NilaiUTS) +
                      (0.4 * StackMHS.dataMahasiswa[i].NilaiUAS);

        if (akhir >= NilaiAkhirMin && akhir <= NilaiAkhirMax) {
            cout << "Nama  : " << StackMHS.dataMahasiswa[i].Nama << endl;
            cout << "NIM   : " << StackMHS.dataMahasiswa[i].NIM << endl;
            cout << "Nilai Akhir : " << akhir << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Tidak ada mahasiswa dalam rentang nilai tersebut." << endl;
    }
}
