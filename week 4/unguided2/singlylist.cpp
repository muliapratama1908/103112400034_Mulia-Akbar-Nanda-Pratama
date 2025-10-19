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
    while (current != nullptr) {
        cout << current->info << " ";
        current = current->next;
    }
    cout << endl;
}

void deleteFirst(List &L) {
    if (L.First != nullptr) {
        address P = L.First;
        L.First = P->next;
        dealokasi(P);
    }
}

void deleteLast(List &L) {
    if (L.First == nullptr) {
        return;
    }
    if (L.First->next == nullptr) {
        deleteFirst(L);
        return;
    }
    address last = L.First;
    address prev = nullptr;

    while (last->next != nullptr) {
        prev = last;
        last = last->next;
    }

    prev->next = nullptr;
    dealokasi(last);
}

void deleteAfter(List &L, address Prec) {
    if (Prec != nullptr && Prec->next != nullptr) {
        address Pdel = Prec->next;
        Prec->next = Pdel->next;
        dealokasi(Pdel);
    }
}

int nbList(List L) {
    int count = 0;
    address current = L.First;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void deleteList(List &L) {
    while (L.First != nullptr) {
        deleteFirst(L);
    }
}