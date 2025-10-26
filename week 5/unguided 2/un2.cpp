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

Node* linearSearch(Node* head, int key) {
    Node* current = head;
    int nodeIndex = 1;

    cout << "Proses Pencarian:" << endl;
    while (current != nullptr) {
        cout << "Memeriksa node " << nodeIndex << ": " << current->data;
        
        if (current->data == key) {
            cout << " (SAMA) - DITEMUKAN!" << endl;
            return current;
        } else {
            cout << " (tidak sama)" << endl;
        }
        
        current = current->next;
        nodeIndex++;
    }

    cout << "Tidak ada node lagi yang tersisa" << endl;
    return nullptr;
}

void printSearchResult(int key, Node* result) {
    if (result != nullptr) {
        cout << "Hasil: Nilai " << key << " DITEMUKAN pada linked list!" << endl;
        cout << "Alamat node: " << result << endl;
        cout << "Data node: " << result->data << endl;
        if (result->next != nullptr) {
            cout << "Node berikutnya: " << result->next->data << endl;
        } else {
            cout << "Node berikutnya: NULL" << endl;
        }
    } else {
        cout << "Hasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!" << endl;
    }
}

int main() {
    Node* head = nullptr;

    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    cout << "LINEAR SEARCH PADA LINKED LIST" << endl;
    cout << "Linked List yang dibuat: ";
    printList(head);

    int key1 = 30;
    cout << "\nMencari nilai: " << key1 << endl;
    Node* result1 = linearSearch(head, key1);
    printSearchResult(key1, result1);

    int key2 = 25;
    cout << "\nMencari nilai: " << key2 << endl;
    Node* result2 = linearSearch(head, key2);
    printSearchResult(key2, result2);

    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}