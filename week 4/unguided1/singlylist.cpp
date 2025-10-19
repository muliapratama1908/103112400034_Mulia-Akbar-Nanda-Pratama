#include "Singlylist.h"

using namespace std;

void CreateList(List &L) {
    L.First = nullptr;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = nullptr;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = nullptr;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

void printInfo(List L) {
    address current = L.First;

    if (current == nullptr) {
        cout << "List kosong" << endl;
        return;
    }

    while (current != nullptr) {
        cout << current->info << " ";
        current = current->next;
    }
    cout << endl;
}