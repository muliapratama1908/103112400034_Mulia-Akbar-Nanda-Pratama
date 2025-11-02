#include "Doublylist.h"

using namespace std;

int main() {
    List L;
    CreateList(L);
    address P;
    infotype dataIn;
    string tempNopol;

    cout << "masukkan nomor polisi: ";
    cin >> tempNopol;
    cout << "masukkan warna kendaraan: ";
    cin >> dataIn.warna;
    cout << "masukkan tahun kendaraan: ";
    cin >> dataIn.thnBuat;
    
    if (findElm(L, tempNopol) != Nil) {
        cout << "nomor polisi sudah terdaftar" << endl;
    } else {
        dataIn.nopol = tempNopol;
        P = alokasi(dataIn);
        insertLast(L, P);
    }

    cout << "masukkan nomor polisi: ";
    cin >> tempNopol;
    cout << "masukkan warna kendaraan: ";
    cin >> dataIn.warna;
    cout << "masukkan tahun kendaraan: ";
    cin >> dataIn.thnBuat;
    
    if (findElm(L, tempNopol) != Nil) {
        cout << "nomor polisi sudah terdaftar" << endl;
    } else {
        dataIn.nopol = tempNopol;
        P = alokasi(dataIn);
        insertLast(L, P);
    }

    cout << "masukkan nomor polisi: ";
    cin >> tempNopol;
    cout << "masukkan warna kendaraan: ";
    cin >> dataIn.warna;
    cout << "masukkan tahun kendaraan: ";
    cin >> dataIn.thnBuat;
    
    if (findElm(L, tempNopol) != Nil) {
        cout << "nomor polisi sudah terdaftar" << endl;
    } else {
        dataIn.nopol = tempNopol;
        P = alokasi(dataIn);
        insertLast(L, P);
    }

    cout << "masukkan nomor polisi: ";
    cin >> tempNopol;
    cout << "masukkan warna kendaraan: ";
    cin >> dataIn.warna;
    cout << "masukkan tahun kendaraan: ";
    cin >> dataIn.thnBuat;
    
    if (findElm(L, tempNopol) != Nil) {
        cout << "nomor polisi sudah terdaftar" << endl;
    } else {
        dataIn.nopol = tempNopol;
        P = alokasi(dataIn);
        insertLast(L, P);
    }
    cout << endl << "DATA LIST 1" << endl;
    printInfo(L);

    return 0;
}