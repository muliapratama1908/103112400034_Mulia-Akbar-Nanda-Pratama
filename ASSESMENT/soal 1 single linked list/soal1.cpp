#include <iostream>
#include <string>
using namespace std;
struct Node {
    string nama;
    Node* next;
    Node(string n) : nama(n), next(nullptr) {}
};
Node* head = nullptr, *tail = nullptr;
void insertAkhir(const string& nama) {
    Node* n = new Node(nama);
    if (!head) head = tail = n;
    else tail->next = n, tail = n;
}
bool deleteNama(const string& nama) {
    Node *cur = head, *prev = nullptr;
    while (cur) {
        if (cur->nama == nama) {
            if (cur == head) head = head->next;
            else prev->next = cur->next;
            if (cur == tail) tail = prev;
            delete cur;
            return true;
        }
        prev = cur; cur = cur->next;
    }
    return false;
}
void view() {
    if (!head) cout << "list kosong";
    else for (Node* cur = head; cur; cur = cur->next)
        cout << cur->nama << (cur->next ? " -> " : "\n");
}
void hitungGenap() {
    int count = 0;
    for (Node* cur = head; cur; cur = cur->next)
        if (cur->nama.length() % 2 == 0) ++count;
    cout << "jumlah nama yg hurufnya genap " << count << "\n";
}
int main() {
    int pilihan;
    string inputNama;
      do {
        cout << "1. insert";
        cout << "2. delete";
        cout << "3. view";
        cout << "4. hitung genap";
        cout << "0. exitr";
        cout << "Pilih menu: ";
        cin >> pilihan;
        if (pilihan == 1) {
            cout << "Masukkan nama: ";
            cin >> inputNama;
            insertAkhir(inputNama);
        }     
        else if (pilihan == 2) {
            cout << "Nama yang ingin dihapus: ";
            cin >> inputNama;
            deleteNama(inputNama);
        }      
        else if (pilihan == 3) {
            view();
        }        
        else if (pilihan == 4) {
            hitungGenap();
        }        
        else if (pilihan == 0) {
            cout << "Program selesai.\n";
        } 
        else {
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);
    return 0;
}