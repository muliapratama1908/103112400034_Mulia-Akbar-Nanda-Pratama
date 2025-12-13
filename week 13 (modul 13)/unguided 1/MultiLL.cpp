#include "MultiLL.h"

bool isEmptyParent(listParent L) { return L.first == NULL; }
bool isEmptyChild(listChild L) { return L.first == NULL; }

void createListParent(listParent &L) { L.first = NULL; L.last = NULL; }
void createListChild(listChild &L) { L.first = NULL; L.last = NULL; }

NodeParent allocNodeParent(string id, string nama) {
    NodeParent P = new nodeParent;
    P->isidata = {id, nama};
    P->next = NULL; P->prev = NULL;
    createListChild(P->L_Child);
    return P;
}

NodeChild allocNodeChild(string id, string nama, string hab, bool ekor, float brt) {
    NodeChild C = new nodeChild;
    C->isidata = {id, nama, hab, ekor, brt};
    C->next = NULL; C->prev = NULL;
    return C;
}

void deallocNodeParent(NodeParent &P) { delete P; P = NULL; }
void deallocNodeChild(NodeChild &C) { delete C; C = NULL; }

void insertFirstParent(listParent &L, NodeParent P) {
    if (isEmptyParent(L)) L.first = L.last = P;
    else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastParent(listParent &L, NodeParent P) {
    if (isEmptyParent(L)) L.first = L.last = P;
    else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void deleteFirstParent(listParent &L) {
    if (isEmptyParent(L)) return;
    NodeParent P = L.first;
    if (L.first == L.last) {
        L.first = L.last = NULL;
    } else {
        L.first = P->next;
        L.first->prev = NULL;
        P->next = NULL;
    }
    deallocNodeParent(P);
}

void deleteAfterParent(listParent &L, NodeParent Pre) {
    if (Pre == NULL || Pre->next == NULL) return;
    NodeParent P = Pre->next;
    Pre->next = P->next;
    if (P->next == NULL) L.last = Pre;
    else P->next->prev = Pre;
    P->next = NULL; P->prev = NULL;
    deallocNodeParent(P);
}

void insertFirstChild(listChild &L, NodeChild C) {
    if (isEmptyChild(L)) L.first = L.last = C;
    else {
        C->next = L.first;
        L.first->prev = C;
        L.first = C;
    }
}

void insertLastChild(listChild &L, NodeChild C) {
    if (isEmptyChild(L)) L.first = L.last = C;
    else {
        L.last->next = C;
        C->prev = L.last;
        L.last = C;
    }
}

void deleteFirstChild(listChild &L) {
    if (isEmptyChild(L)) return;
    NodeChild C = L.first;
    if (L.first == L.last) {
        L.first = L.last = NULL;
    } else {
        L.first = C->next;
        L.first->prev = NULL;
        C->next = NULL;
    }
    deallocNodeChild(C);
}

void deleteAfterChild(listChild &L, NodeChild Pre) {
    if (Pre == NULL || Pre->next == NULL) return;
    NodeChild C = Pre->next;
    Pre->next = C->next;
    if (C->next == NULL) L.last = Pre;
    else C->next->prev = Pre;
    C->next = NULL; C->prev = NULL;
    deallocNodeChild(C);
}

void deleteListChild(listChild &L) {
    while (!isEmptyChild(L)) deleteFirstChild(L);
}

void printMLLStructure(listParent L) {
    NodeParent P = L.first;
    int i = 1;
    while (P != NULL) {
        cout << "=== Parent " << i++ << " ===" << endl;
        cout << "ID Golongan : " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;
        
        if (isEmptyChild(P->L_Child)) cout << "(tidak ada child)" << endl;
        else {
            NodeChild C = P->L_Child.first;
            int j = 1;
            while (C != NULL) {
                cout << " - Child " << j++ << " :" << endl;
                cout << "     ID Hewan : " << C->isidata.idHewan << endl;
                cout << "     Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "     Habitat : " << C->isidata.habitat << endl;
                cout << "     Ekor : " << C->isidata.ekor << endl;
                cout << "     Bobot : " << C->isidata.bobot << endl;
                C = C->next;
            }
        }
        cout << endl;
        P = P->next;
    }
}