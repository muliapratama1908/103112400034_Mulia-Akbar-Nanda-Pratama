#include "Doublylist.h"

using namespace std;

int main() {
    List L;
    CreateList(L);
    address P;
    
    P = alokasi({"D001", "hitam", 90});
    insertLast(L, P);

    P = alokasi({"D003", "putih", 70});
    insertLast(L, P);

    P = alokasi({"D004", "kuning", 90});
    insertLast(L, P);
    
    cout << "DATA LIST 1" << endl;
    printInfo(L);
    cout << endl;

    string nopolCari;
    cout << "Masukkan Nomor Polisi yang dicari : ";
    cin >> nopolCari;

    P = findElm(L, nopolCari);
    
    if (P != Nil) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna : " << P->info.warna << endl;
        cout << "Tahun : " << P->info.nopol << endl;
    } else {
        cout << "Data dengan nomor polisi " << nopolCari << " tidak ditemukan." << endl;
    }
    cout << endl;

    return 0;
}