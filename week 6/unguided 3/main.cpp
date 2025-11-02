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


    string nopolHapus;
    cout << "Masukkan Nomor Polisi yang akan dihapus : ";
    cin >> nopolHapus;

    deleteByNopol(L, nopolHapus);
    cout << endl;

    return 0;
}