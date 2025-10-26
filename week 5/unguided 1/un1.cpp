#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node* &head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int getLength(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

Node* binarySearch(Node* head, int key) {
    int length = getLength(head);
    int left = 0;
    int right = length - 1;
    int iterasi = 1;

    cout << "Proses Pencarian:" << endl;

    while (left <= right) {
        int mid_idx = left + (right - left) / 2;

        Node* mid_node = head;
        for (int i = 0; i < mid_idx; i++) {
            mid_node = mid_node->next;
        }

        cout << "Iterasi " << iterasi++ << ": Mid = " << mid_node->data << " (indeks tengah) - ";

        if (mid_node->data == key) {
            cout << "DITEMUKAN!" << endl;
            return mid_node;
        } else if (mid_node->data < key) {
            cout << "Cari di bagian kanan" << endl;
            left = mid_idx + 1;
        } else {
            cout << "Cari di bagian kiri" << endl;
            right = mid_idx - 1;
        }
    }

    cout << "Tidak ada elemen tersisa" << endl;
    return nullptr;
}

int main() {
    Node* head = nullptr;

    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);

    cout << "BINARY SEARCH PADA LINKED LIST" << endl;
    cout << "Linked List yang dibuat: ";
    printList(head);

    int key1 = 40;
    cout << "\nMencari nilai: " << key1 << endl;
    Node* result1 = binarySearch(head, key1);

    if (result1 != nullptr) {
        cout << "Hasil: Nilai " << key1 << " DITEMUKAN pada linked list!" << endl;
        cout << "Alamat node: " << result1 << endl;
        cout << "Data node: " << result1->data << endl;
        if (result1->next != nullptr) {
            cout << "Node berikutnya: " << result1->next->data << endl;
        } else {
            cout << "Node berikutnya: NULL" << endl;
        }
    } else {
        cout << "Hasil: Nilai " << key1 << " TIDAK DITEMUKAN dalam linked list!" << endl;
    }

    int key2 = 25;
    cout << "Mencari nilai: " << key2 << endl;
    Node* result2 = binarySearch(head, key2);

    if (result2 != nullptr) {
        cout << "Hasil: Nilai " << key2 << " DITEMUKAN pada linked list!" << endl;
        cout << "Alamat node: " << result2 << endl;
        cout << "Data node: " << result2->data << endl;
    } else {
        cout << "Hasil: Nilai " << key2 << " TIDAK DITEMUKAN dalam linked list!" << endl;
    }

    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}