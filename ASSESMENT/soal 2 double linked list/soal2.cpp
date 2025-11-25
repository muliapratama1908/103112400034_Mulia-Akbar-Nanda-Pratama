#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
};
Node* head = nullptr;
Node* tail = nullptr;
void insertAkhir(int nilai) {
    Node* baru = new Node;
    baru->data = nilai;
    baru->prev = nullptr;
    baru->next = nullptr;

    if (head == nullptr) {
        head = tail = baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
}
void deleteTerakhir() {
    if (tail == nullptr) return;

    if (head == tail) {
        delete tail;
        head = tail = nullptr;
    } else {
        Node* hapus = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete hapus;
    }
}
void viewDepan() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void reverseList() {
    Node* temp = head;
    while (temp != nullptr) {
        Node* swap = temp->next;
        temp->next = temp->prev;
        temp->prev = swap;
        temp = swap;
    }

    Node* tukar = head;
    head = tail;
    tail = tukar;
}
int main() {
    int pilih;
    int nilai;

    while (true) {
        cout << "1. insert: " ;
        cout << "2. delete: " ;
        cout << "3. view: " ;
        cout << "4. reverse dan view depan: " ;
        cout << "0. exit: " ;
        cin >> pilih;

        if (pilih == 1) {
            cin >> nilai;
            insertAkhir(nilai);
        }
        else if (pilih == 2) {
            deleteTerakhir();
        }
        else if (pilih == 3) {
            viewDepan();
        }
        else if (pilih == 4) {
            reverseList();
            viewDepan();
        }
        else if (pilih == 0) {
            break;
        }
    }
    return 0;
}
